/*
** xmalloc.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:28:34 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:28:35 2015 Hippolyte Barraud
*/

#include	<stdlib.h>
#include	"library.h"

void	*xmalloc(int size)
{
  void	*str;

  str = malloc(size);
  if (str == NULL)
    {
      my_putstr("Memory error\n");
      exit(1);
    }
  else
    return (str);
}
