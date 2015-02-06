/*
** my_tablen.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:28:02 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:28:03 2015 Hippolyte Barraud
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
