/*
** move.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:16:49 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:17:06 2015 Hippolyte Barraud
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<math.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

void		tab_free(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		get_new_map(t_event *event)
{
  char		*tmp;

  tab_free(event->data->map);
  free(event->data->initial);
  event->data->name[my_strlen(event->data->name) - 1]++;
  tmp = event->data->name;
  free(event->data);
  if ((event->data = get_the_map(tmp)) == NULL)
    {
      my_printf(FINISH);
      exit(1);
    }
  back_ground(event->window);
}

void		move(t_event *event, float i)
{
  t_data	*data;
  float		x;
  float		y;
  float		c_x;
  float		c_y;
  float		angle;

  data = event->data;
  angle = data->a / 180 * PI;
  x = data->x_p + (Y_SENSITIVE * cos(angle) * i);
  c_x = data->x_p + ((Y_SENSITIVE * 4) * cos(angle) * i);
  y = data->y_p + (Y_SENSITIVE * sin(angle) * i);
  c_y = data->y_p + ((Y_SENSITIVE * 4) * sin(angle) * i);
  if (x < 0 || y < 0 || (int)y >= my_tablen(data->map) ||
      (int)x >= my_strlen(data->map[(int)y]))
    return;
  if (c_y >= 0 && c_y < my_tablen(data->map) &&
      c_x >= 0 && c_x < my_strlen(data->map[(int)c_y]) &&
      data->map[(int)c_y][(int)c_x] == '3')
    get_new_map(event);
  else
    hitbox('0', data, x, y);
}
