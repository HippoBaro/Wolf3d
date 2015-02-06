/*
** put_wall.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:18:27 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:18:28 2015 Hippolyte Barraud
*/

#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

int		pixel_img(t_struct *window, int x, int y, unsigned int couleur)
{
  int		i;

  if (y < 0)
    y = 0;
  if (y > Y)
    y = Y - 1;
  i = ((x * 4) + ((X) * y * 4));
  window->data[i + 0] = couleur;
  window->data[i + 1] = couleur;
  window->data[i + 2] = couleur / RGB24 / RGB24;
  return (0);
}

void	put_wall(int x, float k, t_struct *window, t_data *data)
{
  int	i;
  int	y;

  i = Y / (2 * k);
  y = (Y / 2) + (i / 2);
  x = X - x - 1;
  while (i >= 0)
    {
      if (x >= 0 && y >= 0 && x < X)
	{
	  if (data->wall_type == 2)
	    pixel_img(window, x, y - i, END);
	  if (data->x_v >= 0 && data->wall_type == 0)
	    pixel_img(window, x, y - i, WALL_1);
	  else if (data->y_v >= 0 && data->wall_type == 1)
	    pixel_img(window, x, y - i, WALL_2);
	  else if (data->x_v < 0 && data->wall_type == 0)
	    pixel_img(window, x, y - i, WALL_3);
	  else if (data->y_v < 0 && data->wall_type == 1)
	    pixel_img(window, x, y - i, WALL_4);
	}
      i--;
    }
}
