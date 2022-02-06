#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char const *str1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
