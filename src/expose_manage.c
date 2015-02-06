/*
** expose_manage.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:20:23 2015 Hippolyte Barraud
** Last update Fri Feb  6 16:02:54 2015 Hippolyte Barraud
*/

#include	<mlx.h>
#include	"wolf3D.h"

int	handle_expose(t_event *event)
{
  back_ground(event->window);
  show_wall(event->window, event->data);
  fps_meter(event, 0);
  return (0);
}
