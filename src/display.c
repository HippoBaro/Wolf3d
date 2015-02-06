/*
** display.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:04:13 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:04:15 2015 Hippolyte Barraud
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	"library.h"
#include	"wolf3D.h"

t_struct	*display_erreur(int option)
{
  if (option == 1)
    my_printf("Error: mlx_init\n");
  return (NULL);
}

t_struct	*display(t_data *data)
{
  t_struct	*window;

  window = xmalloc(sizeof(t_struct));
  if ((window->mlx_ptr = mlx_init()) == NULL)
    return (display_erreur(1));
  if (get_background(window) == -1)
    return (NULL);
  return (window);
}
