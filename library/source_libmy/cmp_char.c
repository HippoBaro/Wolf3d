/*
** cmp_char.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:24:30 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:24:31 2015 Hippolyte Barraud
*/

int	cmp_char(char c, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	j++;
      i++;
    }
  return (j);
}
