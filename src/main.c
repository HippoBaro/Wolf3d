/*
** main.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:16:29 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:16:31 2015 Hippolyte Barraud
*/

#include	<stdlib.h>
#include	"library.h"
#include	"wolf3D.h"

int		main_error(int option)
{
  if (option == 1)
    my_printf("Wrong pathname\n");
  return (-1);
}

int		main(int ac, char **ag)
{
  t_struct	*window;
  t_data	*data;

  if (ac > 1)
    data = get_the_map(ag[1]);
  else
    data = get_the_map(NULL);
  if (data == NULL)
    return (main_error(1));
  if ((window = display(data)) == NULL)
    return (-1);
  event_manage(window, data);
  return (0);
}
