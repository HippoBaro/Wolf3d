/*
** event_manage.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:20:23 2015 Hippolyte Barraud
** Last update Fri Feb  6 16:02:32 2015 Hippolyte Barraud
*/

#include	<features.h>
#include	<unistd.h>
#include	<math.h>
#include	<stdlib.h>
#include	<X11/X.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

int		key_press(int keycode, t_event *event)
{
  if (keycode == UP)
    event->up = 1;
  if (keycode == DOWN)
    event->down = 1;
  if (keycode == LEFT)
    event->left = 1;
  if (keycode == RIGHT)
    event->right = 1;
  return (0);
}

int		key_hook(int keycode, t_event *event)
{
  if (keycode == UP)
    event->up = 0;
  if (keycode == DOWN)
    event->down = 0;
  if (keycode == LEFT)
    event->left = 0;
  if (keycode == RIGHT)
    event->right = 0;
  if (keycode == 65307)
    exit(1);
  return (0);
}

int		loop_hook(t_event *event)
{
  if (event->up == 1)
    move(event, 1);
  if (event->down == 1)
    move(event, -1);
  if (event->right == 1)
    event->data->a = ((int) event->data->a + X_SENSITIVE) % 360;
  if (event->left == 1)
    event->data->a = ((int) event->data->a - X_SENSITIVE) % 360;
  if (event->up == 0 && event->down == 0
      && event->right == 0 && event->left == 0)
    return (0);
  usleep(event->usleep);
  back_ground(event->window);
  show_wall(event->window, event->data);
  fps_meter(event, -1);
  return (0);
}

t_event		*init_event(t_struct *window)
{
  t_event	*event;

  event = malloc(sizeof(t_event));
  event->window = window;
  event->up = 0;
  event->down = 0;
  event->left = 0;
  event->right = 0;
  if (VSYNC)
    set_smoother(event);
  else
    event->usleep = 0;
  return (event);
}

int	event_manage(t_struct *window, t_data *data)
{
  t_event	*event;

  event = init_event(window);
  event->data = data;
  handle_expose(event);
  mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, event);
  mlx_key_hook(window->win_ptr, key_hook, event);
  mlx_expose_hook(window->win_ptr, handle_expose, event);
  mlx_loop_hook(window->mlx_ptr, loop_hook, event);
  mlx_loop(window->mlx_ptr);
  return (0);
}
