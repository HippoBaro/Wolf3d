/*
** my_putchar.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:26:28 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:26:29 2015 Hippolyte Barraud
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
