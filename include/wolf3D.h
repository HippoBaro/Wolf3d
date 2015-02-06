/*
** wolf3D.h for wolf3d in /home/barrau_h/Desktop/Wolf3D/include
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:01:59 2015 Hippolyte Barraud
** Last update Mon Jan 19 08:52:23 2015 Hippolyte Barraud
*/

#ifndef		_WOLF3D_H_
# define	_WOLF3D_H_

# define		TITLE "Bienvenue dans un labyrinthe pseudo-realiste aux \
couleurs de merde. Made by ArrenKae (barrau_h)"
# define		FINISH "Vous avez triomphé du labyrinthe !"

/*# define	X 1920
# define	Y 1080*/
# define	X 1280
# define	Y 720
# define	VSYNC 1
# define	DESIRED_FPS 60
# define	VSYNC_SOFTNESS 30
# define	ALPHA -90
# define	HIT 0.065
# define	Y_SENSITIVE 0.060
# define	X_SENSITIVE 2
# define	SKY 0x00CCEEFF
# define	FLOOR 0x00555623
# define	WALL_1 0x00404040
# define	WALL_2 0x00505050
# define	WALL_3 0x00606060
# define	WALL_4 0x00353535
# define	RGB24 256
# define 	BLACK 0x000000
# define	END 0x00FF7171
# define	READ_SIZE 200
# define	PI 3.14159265358979323846
# define	ECHAP 65307
# define	UP 65362
# define	DOWN 65364
# define	RIGHT 65363
# define	D 100
# define	Q 113
# define	LEFT 65361
# define	ABS(x, y) (x > y) ? (x - y) : (y - x)
# define	MAX(x, y) (x > y) ? (x) : (y)

typedef struct	s_struct
{
  int		x;
  int		y;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*stage_img;
  void		*stage_data;
  void		*img;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
}		t_struct;

typedef struct	s_data
{
  char		**map;
  char		*name;
  float		*initial;
  float		x_p;
  float		y_p;
  float		x_v;
  float		y_v;
  float		a;
  float		k;
  char		wall_type;
  char		wall_type_x;
  char		wall_type_y;
}		t_data;

typedef struct	s_event
{
  t_struct	*window;
  t_data	*data;
  char		up;
  char		down;
  char		left;
  char		right;
  unsigned int		usleep;
}		t_event;

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
}		t_list;

int		hitbox(char c, t_data *data, float x, float y);
void		simple_move(t_event*, char);
void		move(t_event*, float);
void		check_wall(t_data*, int, t_struct*);
void		put_wall(int, float, t_struct*, t_data*);
void		get_initial_values(t_data *);
void		check_wall(t_data*, int, t_struct*);
char		*get_next_line(const int);
int		back_ground(t_struct*);
int		manage_expose(t_struct*);
int		manage_key(int, t_struct*);
int		handle_expose(t_event *event);
int		get_background(t_struct*);
int		pixel_img(t_struct*, int, int, unsigned int);
int		event_manage(t_struct*, t_data*);
int		show_wall(t_struct*, t_data*);
float		*found_initial(char**);
float		get_the_angle(t_data *);
t_data		*get_the_map(char*);
void		display_fps(int fps, t_event *event, int overrideFPS);
char		**get_the_tab(char*);
char		**get_read(int);
char		*get_next_line(const int);
t_struct	*display(t_data*);
void		fps_meter(t_event *event, int overrideFPS);
void		set_smoother(t_event *event);

#endif /* !_WOLF3D_H_ */
