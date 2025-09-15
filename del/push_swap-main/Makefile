N ?= 5
TESTS ?= 100

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
BLUE = \033[0;34m
RESET = \033[0m

EFFI:
	@echo "$(YELLOW)   Testing push_swap efficiency with N=$(N)...$(RESET)"
	@> instr.txt
	@i=0; \
	while [ $$i -lt $(TESTS) ]; do \
	ARG=$$(shuf -i 0-5000 -n $(N) | xargs); \
	COUNT=$$(./plik $$ARG | wc -l); \
	echo $$COUNT >> instr.txt; \
	i=$$((i+1)); \
	done
	@MIN=$$(sort -n instr.txt | head -1); \
	MAX=$$(sort -n instr.txt | tail -1); \
	AVG=$$(awk '{ total += $$1; count++ } END { if (count > 0) printf("%.2f", total/count); }' instr.txt); \
# 	DOM=$$(sort -n instr.txt | uniq -c | sort -nr | head -1 | awk '{print $$2}'); \
	echo "$(GREEN)   Average : $$AVG$(RESET)"; \
	echo "$(BLUE)   Minimum : $$MIN$(RESET)"; \
	echo "$(RED)   Maximum : $$MAX$(RESET)"; \
# 	echo "$(YELLOW)   Dominant: $$DOM$(RESET)";
	@rm -f instr.txt