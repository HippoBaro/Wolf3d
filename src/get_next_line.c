/*
** get_next_line.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:13:16 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:13:17 2015 Hippolyte Barraud
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"library.h"
#include	"wolf3D.h"

int		saving(char *buffer, int i)
{
  static char	save[READ_SIZE + 1];
  int		j;
  int		k;

  j = i;
  k = 0;
  if (buffer[0] == 0)
    {
      while (save[k] != 0)
	{
	  buffer[k] = save[k];
	  k++;
	}
      save[0] = 0;
    }
  else if (buffer[j] == '\n')
    {
      j++;
      while (buffer[j] != 0)
	save[k++] = buffer[j++];
      save[k] = 0;
    }
  return (k);
}

char		*gnl_xrealloc(char *original)
{
  int		i;
  int		j;
  int		k;
  char		*result;

  j = 0;
  i = 0;
  k = 0;
  if (original == NULL)
    return (xmalloc(READ_SIZE + 1));
  while (original[k++]);
  result = xmalloc(READ_SIZE + k);
  while (i < k)
    result[j++] = original[i++];
  i = 0;
  result[j] = 0;
  free(original);
  return (result);
}

char	*clean_and_modify(int *i, int *check, const int fd, char *buffer)
{
  char	*result;
  int	j;

  *check = 1;
  result = NULL;
  j = 0;
  while (*check != 0 && buffer[j] != '\n')
    {
      if ((result = gnl_xrealloc(result)) == NULL)
	return (NULL);
      j = 0;
      *check = saving(buffer, 0);
      if (*check == 0)
	if ((*check = read(fd, buffer, READ_SIZE)) < 0)
	  return (NULL);
      buffer[*check] = 0;
      while (j < *check && buffer[j] != '\n')
	result[(*i)++] = buffer[j++];
      result[*i] = 0;
    }
  return (result);
}

char	*get_next_line(const int fd)
{
  char	*result;
  char	*buffer;
  int	check;
  int	i;
  int	j;

  i = 0;
  j = -1;
  result = NULL;
  if ((buffer = xmalloc(READ_SIZE + 1)) == NULL || READ_SIZE < 0)
    return (NULL);
  buffer[0] = 0;
  if ((result = clean_and_modify(&i, &check, fd, buffer)) == NULL)
    return (NULL);
  while (++j < READ_SIZE && buffer[j] != '\n');
  if (buffer[j] == '\n')
    saving(buffer, j);
  free(buffer);
  if (i != 0 || check != 0)
    return (result);
  return (NULL);
}
