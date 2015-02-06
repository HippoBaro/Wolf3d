/*
** fps_meter.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:47:19 2015 Hippolyte Barraud
** Last update Sun Jan 18 01:55:35 2015 Hippolyte Barraud
*/

#include	<sys/timeb.h>
#include	<stdlib.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<X11/X.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

void		set_smoother(t_event *event)
{
  if (DESIRED_FPS == 0)
    {
      my_putstr("Error : desired fps cannot be set to zero.\n");
      exit(0);
    }
  else if (DESIRED_FPS >= 30 && DESIRED_FPS < 45)
    event->usleep = 25000;
  else if (DESIRED_FPS < 30)
    event->usleep = 45000;
  else if (DESIRED_FPS >= 45 && DESIRED_FPS < 60)
    event->usleep = 15000;
  else if (DESIRED_FPS >= 60 && DESIRED_FPS < 100)
    event->usleep = 10000;
  else
    event->usleep = 5000;
  if (DESIRED_FPS > 60)
    my_putstr("Warning : desired framerate is beyond 60hz, artefacts\
 may appear.\n");
}

void		display_position(t_event *event)
{
  char		string[99];

  sprintf(string, "Player : X=%f - Y=%f | Camera :  X=%f - Y=%f",
	  event->data->x_p, event->data->y_p, event->data->x_v,
	  event->data->y_v);
  mlx_string_put(event->window->mlx_ptr, event->window->win_ptr, 1, 22,
		 BLACK, string);
}

void		vsync(const int fps, t_event *event)
{
  if (fps > DESIRED_FPS)
    event->usleep += (VSYNC_SOFTNESS * (fps - DESIRED_FPS));
  else if (fps < DESIRED_FPS)
    {
      if (VSYNC_SOFTNESS * (DESIRED_FPS - fps) > 0)
	event->usleep -= (VSYNC_SOFTNESS * (DESIRED_FPS - fps));
    }
  if (event->usleep > 500000)
    event->usleep = 0;
}

void		display_fps(int fps, t_event *event, int overrideFPS)
{
  char		string[99];

  if (overrideFPS >= 0)
	  fps = overrideFPS;
  if (VSYNC)
    sprintf(string,
    "FPS : %d | VSYNC : ON (SMOOTHER : %d -- TARGET : %d FPS) | MAP : %s",
	    fps, event->usleep, DESIRED_FPS, event->data->name);
  else
    sprintf(string, "FPS : %d ; VSYNC : OFF ; MAP : %s", fps,
	    event->data->name);
  mlx_string_put(event->window->mlx_ptr, event->window->win_ptr, 1, 10,
		 BLACK, string);
  display_position(event);
}

void		fps_meter(t_event *event, int overrideFPS)
{
  static int	fps = 0;
  static int	fps_disp = 0;
  static time_t	second;
  static int	a = 0;
  struct timeb	time;
  time_t	second2;

  display_fps(fps_disp, event, overrideFPS);
  ftime(&time);
  if (a == 0)
    {
      second = time.time;
      a = 1;
    }
  second2 = time.time;
  if (second == second2)
    fps++;
  else
    {
      if (VSYNC)
	vsync(fps, event);
      fps_disp = fps;
      fps = 0;
      second = second2;
    }
}
