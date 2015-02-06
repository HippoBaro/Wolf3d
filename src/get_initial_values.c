/*
** get_initial_values.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:12:56 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:12:57 2015 Hippolyte Barraud
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"library.h"
#include	"wolf3D.h"

void		get_initial_values(t_data *data)
{
  data->initial = found_initial(data->map);
  data->x_p = data->initial[0];
  data->y_p = data->initial[1];
  data->a = get_the_angle(data);
}
