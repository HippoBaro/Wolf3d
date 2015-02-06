/*
** my_revstr.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:27:23 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:27:24 2015 Hippolyte Barraud
*/

char	*my_revstr(char *str)
{
  int	i;
  int	cons;
  int	temp;

  i = 0;
  while (str[i + 1] != '\0')
    i++;
  cons = i;
  while (cons - i <  i)
    {
      temp = str [cons - i];
      str[cons - i] = str[i];
      str[i] = temp;
      i--;
    }
  return (str);
}
