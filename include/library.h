/*
** library.h for libmy in /home/barrau_h/Desktop/Wolf3D/include
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:02:17 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:02:19 2015 Hippolyte Barraud
*/

#ifndef	_LIBRARY_H_
# define _LIBRARY_H_

int	my_strlen(char*);
int	my_tablen(char**);
void	show_tab(char**);
int	cmp_char(char, char*);
int	my_getnbr(char*);
int	my_printf(char*, ...);
int	my_getnbr_base(char*, char*);
char	*my_revstr(char*);
char	*my_strdup(char*);
void	my_putnbr_base(int, char *);
void	manage_sign(int, char*);
void	my_put_unsigned_nbr(unsigned int);
void	*xmalloc(int);
void	*retmalloc(int);
void	my_putstr(char*);
void	my_putchar(char);
void	my_putnbr(int);

#endif /* !_LIBRARY_H_ */
