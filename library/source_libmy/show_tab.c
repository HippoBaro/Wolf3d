/*
** show_tab.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:28:21 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:28:22 2015 Hippolyte Barraud
*/

#include	"library.h"

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
