/*
** my_putstr.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:27:11 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:27:12 2015 Hippolyte Barraud
*/

#include	<unistd.h>
#include	"library.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
