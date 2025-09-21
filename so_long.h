/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/09/13 20:08:38 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/09/18 18:05:21 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAIL -1
# define SUCCESS 1

# define MAP_CHARS "01CEP"
# define TILE 64

# define TREES "./textures/trees.xpm"
# define EMPTY "./textures/empty.xpm"
# define WITCH_L "./textures/witch-left.xpm"
# define WITCH_R "./textures/witch-right.xpm"
# define CAT "./textures/cat.xpm"
# define DOOR_C "./textures/closed-doors.xpm"
# define DOOR_O "./textures/open-doors.xpm"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_count
{
	int	collectible_parse;
	int	exit_parse;
	int	player_parse;
	int	collectible_flood;
	int	exit_flood;
	int	player_flood;
}	t_map_count;

typedef struct s_map
{
	char		*map_path;
	char		**map;
	t_point		size;
	t_map_count	*map_count;
}	t_map;

typedef struct s_tile
{
	void	*trees;
	void	*empty;
	void	*witch_l;
	void	*witch_r;
	void	*cat;
	void	*door_c;
	void	*door_o;
}	t_tile;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*win;
	t_tile	tile;
	t_point	player;
	void	*player_direction;
	t_point	exit;
	int		to_collect;
	int		collected;
	int		moves;
}	t_game;

void	ft_error(int code);
void	free_game(t_game *game);
int		close_game(t_game *game);

t_point	find_coordinates(char **map, char type);
char	find_type(t_game game, int y, int x);

int		get_map(t_game *game, char *file_path);
char	**create_map(char *map_path);
int		check_map(t_map *map);
int		map_parse(char **map, t_point size, t_map_count *map_count);
int		map_flood(t_map *map);
int		generate_map(t_game *game);

int		key_press(int keycode, t_game *game);
void	print_moves(t_game *game);

#endif