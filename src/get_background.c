/*
** get_background.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:05:03 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:43:49 2015 Hippolyte Barraud
*/

#include	<stdlib.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

int	get_background_error(int option)
{
  if (option == 1)
    my_printf("Error: mlx_init\n");
  if (option == 2)
    my_printf("Error: mlx_new_window\n");
  return (-1);
}

int		back_ground(t_struct *window)
{
  int		i;
  unsigned int	sky;
  unsigned int	floor;

  i = 0;
  sky = SKY;
  floor = FLOOR;
  while (i < ((Y * X * 4)) / 2)
    {
      window->data[i + 0] = sky;
      window->data[i + 1] = sky / RGB24;
      window->data[i + 2] = sky / RGB24 / RGB24;
      window->data[i + 3] = 0;
      i = i + 4;
    }
  while (i < (Y * X * 4))
    {
      window->data[i + 0] = floor;
      window->data[i + 1] = floor / RGB24;
      window->data[i + 2] = floor / RGB24 / RGB24;
      window->data[i + 3] = 0;
      i = i + 4;
    }
  return (0);
}

int	get_background(t_struct *window)
{
  if ((window->win_ptr =
       mlx_new_window(window->mlx_ptr, X, Y, TITLE)) == NULL)
    return (get_background_error(2));
  if ((window->img = mlx_new_image(window->mlx_ptr, X, Y)) == NULL)
    return (-1);
  window->data = mlx_get_data_addr(window->img, &(window->bpp),
				   &(window->sizeline), &(window->endian));
  back_ground(window);
  return (0);
}
