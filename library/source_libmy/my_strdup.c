/*
** my_strdup.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:27:38 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:27:39 2015 Hippolyte Barraud
*/

#include	<stdlib.h>
#include	"library.h"

char	*my_strdup(char* str)
{
  char	*result;
  int	i;

  i = 0;
  result = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i])
    {
      result[i] = str[i];
      i++;
    }
  result[i] = 0;
  return (result);
}
