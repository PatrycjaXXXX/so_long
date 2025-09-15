#include <stdio.h>
#include <stdlib.h>

/* ===================== STRUKTURY ===================== */
typedef struct s_node {
    int                 value;  // oryginalna wartość
    int                 rank;   // skompresowana wartość (0..n-1)
    int                 keep;   // 1 jeżeli w LIS (nie ruszamy przy pierwszej fazie)
    struct s_node      *next;
} t_node;

/* ===================== NARZĘDZIA STOSU ===================== */
static int stack_size(t_node *s) {
    int n = 0; while (s) { n++; s = s->next; } return n;
}
static t_node *last_node(t_node *s) {
    if (!s) return NULL; while (s->next) s = s->next; return s;
}

/* ===================== OPERACJE push_swap ===================== */
/* Pojedyncze operacje „niegłośne” (bez printa) */
static void rotate_one(t_node **s) {
    if (!s || !*s || !(*s)->next) return;
    t_node *first = *s, *tail = last_node(*s);
    *s = first->next;
    first->next = NULL;
    tail->next = first;
}
static void rrotate_one(t_node **s) {
    if (!s || !*s || !(*s)->next) return;
    t_node *prev = NULL, *cur = *s;
    while (cur->next) { prev = cur; cur = cur->next; }
    prev->next = NULL;
    cur->next = *s;
    *s = cur;
}
static void swap_one(t_node **s) {
    if (!s || !*s || !(*s)->next) return;
    t_node *a = *s, *b = a->next;
    a->next = b->next;
    b->next = a;
    *s = b;
}

/* Opakowania z wypisem instrukcji */
static void sa(t_node **a){ swap_one(a); printf("sa\n"); }
static void sb(t_node **b){ swap_one(b); printf("sb\n"); }
static void ss(t_node **a, t_node **b){ swap_one(a); swap_one(b); printf("ss\n"); }

static void pa(t_node **a, t_node **b){ // z B do A
    if (!b || !*b) return;
    t_node *t = *b; *b = (*b)->next; t->next = *a; *a = t;
    printf("pa\n");
}
static void pb(t_node **a, t_node **b){ // z A do B
    if (!a || !*a) return;
    t_node *t = *a; *a = (*a)->next; t->next = *b; *b = t;
    printf("pb\n");
}

static void ra(t_node **a){ rotate_one(a); printf("ra\n"); }
static void rb(t_node **b){ rotate_one(b); printf("rb\n"); }
static void rr(t_node **a, t_node **b){ rotate_one(a); rotate_one(b); printf("rr\n"); }

static void rra(t_node **a){ rrotate_one(a); printf("rra\n"); }
static void rrb(t_node **b){ rrotate_one(b); printf("rrb\n"); }
static void rrr(t_node **a, t_node **b){ rrotate_one(a); rrotate_one(b); printf("rrr\n"); }

/* ===================== KOMPRESJA DO RANG ===================== */
static int cmp_int(const void *x, const void *y){
    int a = *(const int*)x, b = *(const int*)y;
    return (a > b) - (a < b);
}
static int rank_of(int v, int *sorted, int n){
    // binsearch
    int L = 0, R = n-1;
    while (L <= R){
        int M = (L+R)/2;
        if (sorted[M] == v) return M;
        if (sorted[M] < v) L = M+1; else R = M-1;
    }
    return -1; // nie powinno się zdarzyć przy unikalnych wartościach
}
static void compress_to_ranks(t_node *a, int n){
    int *arr = (int*)malloc(sizeof(int)*n);
    if (!arr) exit(1);
    t_node *it = a;
    for (int i=0;i<n;i++){ arr[i]=it->value; it=it->next; }
    qsort(arr, n, sizeof(int), cmp_int);
    it = a;
    for (int i=0;i<n;i++){ it->rank = rank_of(it->value, arr, n); it=it->next; }
    free(arr);
}

/* ===================== LIS (O(n^2), stabilne) ===================== */
static void mark_LIS_keep(t_node *a, int n){
    // zbuduj tablicę ranków w kolejności od topu
    int *r = (int*)malloc(sizeof(int)*n);
    t_node **nodes = (t_node**)malloc(sizeof(t_node*)*n);
    if (!r || !nodes) exit(1);
    t_node *it = a;
    for (int i=0;i<n;i++){ r[i]=it->rank; nodes[i]=it; it=it->next; }

    int *dp = (int*)malloc(sizeof(int)*n);
    int *prev = (int*)malloc(sizeof(int)*n);
    if (!dp || !prev) exit(1);

    int best_len = 0, best_end = 0;
    for (int i=0;i<n;i++){
        dp[i]=1; prev[i]=-1;
        for (int j=0;j<i;j++){
            if (r[j] < r[i] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
        if (dp[i] > best_len){ best_len = dp[i]; best_end = i; }
    }

    // wyczyść keep
    for (int i=0;i<n;i++) nodes[i]->keep = 0;
    // odtwórz LIS i oznacz keep=1
    for (int i=best_end; i!=-1; i=prev[i]) nodes[i]->keep = 1;

    free(r); free(nodes); free(dp); free(prev);
}

/* ===================== WYPYCHANIE z A do B (zostawiamy LIS) ===================== */
static void push_non_keep_to_b(t_node **a, t_node **b, int n){
    int pushed = 0;
    int rotations = 0;
    int median = n/2; // do lekkiego „układania” B: większe rangi na górze
    // Przejdź przez maksymalnie n elementów (pełne „okrążenie”)
    while (pushed < n){
        if ((*a)->keep){
            ra(a);
            rotations++;
        } else {
            pb(a, b);
            pushed++;
            // żeby B miał większe elementy bliżej topu: jeśli rank < median -> rb
            if (*b && (*b)->next && (*b)->rank < median) rb(b);
        }
        // jeżeli wykonaliśmy n obrotów bez pb (same keep), to znaczy, że już wszystko keep -> przerwij
        if (rotations > n) break;
    }
}

/* ===================== OBLICZANIE CELU W A DLA ELEMENTU z B ===================== */
static int index_of_min_rank(t_node *a){
    int idx = 0, best = 0, pos = 0, minr = a->rank;
    for (t_node *it=a; it; it=it->next){ if (it->rank < minr){ minr = it->rank; best = pos; } pos++; }
    return best;
}
static int index_of_max_rank(t_node *a){
    int idx = 0, best = 0, pos = 0, maxr = a->rank;
    for (t_node *it=a; it; it=it->next){ if (it->rank > maxr){ maxr = it->rank; best = pos; } pos++; }
    return best;
}
// Zwraca indeks w A, na który powinniśmy ustawić top A (po rotacjach), aby pa wstawiło b_rank we właściwe miejsce.
static int target_index_in_a(t_node *a, int b_rank){
    int n = stack_size(a);
    int min_pos = index_of_min_rank(a);
    int max_pos = index_of_max_rank(a);
    int minr = a->rank, maxr = a->rank;
    // znajdź min i max rank
    for (t_node *it=a; it; it=it->next){ if (it->rank < minr) minr = it->rank; if (it->rank > maxr) maxr = it->rank; }

    // Jeżeli b_rank mniejszy niż minr lub większy niż maxr -> celem jest min (pozycja najmniejszego)
    if (b_rank < minr || b_rank > maxr) return min_pos;

    // w przeciwnym razie znajdź pierwsze miejsce, gdzie curr.rank < b_rank <= next.rank
    t_node *curr = a; int idx = 0;
    while (curr){
        t_node *next = curr->next ? curr->next : a; // „koło”
        if (curr->rank <= b_rank && b_rank <= next->rank){
            // celem jest podnieść A tak, by next był na górze, wtedy pa wstawi b przed nim
            return (curr->next ? idx+1 : 0);
        }
        curr = curr->next;
        idx++;
    }
    // awaryjnie
    return min_pos;
}

/* Liczba kroków rotacji do ustawienia indeksu na top:
   dodatnie -> ra/rb, ujemne -> rra/rrb */
static int steps_to_top(int index, int size){
    if (index <= size/2) return index;
    return index - size; // ujemne
}

/* Koszt łączny rotacji z uwzględnieniem rr/rrr */
static int total_cost(int a_steps, int b_steps){
    if ((a_steps >= 0 && b_steps >= 0) || (a_steps < 0 && b_steps < 0)){
        int aa = a_steps < 0 ? -a_steps : a_steps;
        int bb = b_steps < 0 ? -b_steps : b_steps;
        return (aa > bb) ? aa : bb; // równoległe rr/rrr
    } else {
        int aa = a_steps < 0 ? -a_steps : a_steps;
        int bb = b_steps < 0 ? -b_steps : b_steps;
        return aa + bb;
    }
}

/* Wykonanie rotacji zgodnie z policzonymi krokami, optymalizując rr/rrr */
static void do_rotations(t_node **a, t_node **b, int *a_steps, int *b_steps){
    while (*a_steps > 0 && *b_steps > 0){ rr(a, b); (*a_steps)--; (*b_steps)--; }
    while (*a_steps < 0 && *b_steps < 0){ rrr(a, b); (*a_steps)++; (*b_steps)++; }
    while (*a_steps > 0){ ra(a); (*a_steps)--; }
    while (*a_steps < 0){ rra(a); (*a_steps)++; }
    while (*b_steps > 0){ rb(b); (*b_steps)--; }
    while (*b_steps < 0){ rrb(b); (*b_steps)++; }
}

/* ===================== WSTAWIANIE z B do A: najtańszy ruch ===================== */
static void insert_all_from_b(t_node **a, t_node **b){
    while (*b){
        int best_cost = 1<<30;
        int best_a_steps = 0, best_b_steps = 0;
        int b_size = stack_size(*b);
        int a_size = stack_size(*a);

        // Przejdź po wszystkich elementach B i znajdź najtańszy do wstawienia
        int idx_b = 0;
        for (t_node *it = *b; it; it = it->next, idx_b++){
            int target_a_idx = target_index_in_a(*a, it->rank);
            int a_steps = steps_to_top(target_a_idx, a_size);
            int b_steps = steps_to_top(idx_b, b_size);
            int cost = total_cost(a_steps, b_steps);
            if (cost < best_cost){
                best_cost = cost;
                best_a_steps = a_steps;
                best_b_steps = b_steps;
            }
        }
        // wykonaj obrót i wstaw
        do_rotations(a, b, &best_a_steps, &best_b_steps);
        pa(a, b);
    }
}

/* ===================== FINISH: najmniejszy na górze ===================== */
static void final_align_a(t_node **a){
    int min_idx = index_of_min_rank(*a);
    int n = stack_size(*a);
    int st = steps_to_top(min_idx, n);
    while (st > 0){ ra(a); st--; }
    while (st < 0){ rra(a); st++; }
}

/* ===================== GŁÓWNY ALGORYTM ===================== */
static void push_swap_LIS(t_node **a, t_node **b){
    int n = stack_size(*a);
    if (n <= 1) return;

    compress_to_ranks(*a, n);
    mark_LIS_keep(*a, n);
    push_non_keep_to_b(a, b, n);
    insert_all_from_b(a, b);
    final_align_a(a);
}

/* ===================== LISTA / I/O ===================== */
static t_node* create_list_from_argv(int argc, char **argv){
    t_node *head = NULL;
    for (int i = argc-1; i >= 1; --i){
        t_node *nd = (t_node*)malloc(sizeof(t_node));
        if (!nd) exit(1);
        nd->value = atoi(argv[i]);
        nd->rank = 0; nd->keep = 0;
        nd->next = head;
        head = nd;
    }
    return head;
}
static void free_list(t_node *s){
    while (s){ t_node *t = s; s = s->next; free(t); }
}

/* (opcjonalne) prosta walidacja, że A jest rosnące */
static int is_sorted(t_node *a){
    while (a && a->next){ if (a->value > a->next->value) return 0; a = a->next; }
    return 1;
}

int main(int argc, char **argv){
    if (argc < 2) return 0;
    t_node *a = create_list_from_argv(argc, argv);
    t_node *b = NULL;

    push_swap_LIS(&a, &b);

    // Jeżeli chcesz, możesz odkomentować szybki check (nie wypisuje wtedy nic więcej w standardowym projekcie)
    // if (!is_sorted(a)) fprintf(stderr, "Not sorted!\n");

    free_list(a);
    free_list(b);
    return 0;
}
