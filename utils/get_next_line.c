#include "../includes/minishell.h"

size_t	check_new_line(char *str)
{
	size_t	is_new_line;

	is_new_line = 0;
	if (!str)
		return (is_new_line);
	while (*str != '\0' && is_new_line == 0)
	{	
		if (*str == '\n')
			is_new_line = 1;
		str++;
	}
	return (is_new_line);
}

char	*get_line(char *str)
{
	size_t	l;
	char	*line;
	int		flag;

	l = 0;
	flag = 0;
	while (str[l++] != '\0' && flag == 0)
	{
		if (str[l] == '\n')
			flag = 1;
	}
	line = malloc(sizeof(char) * (l + 1));
	if (!line)
		return (0);
	l = 0;
	flag = 0;
	while (str[l] != '\0' && flag == 0)
	{
		line[l] = str[l];
		if (str[l] == '\n')
			flag = 1;
		l++;
	}
	line[l] = '\0';
	return (line);
}

char	*increment_buffer(char *str)
{
	size_t	i;
	int		l;
	char	*new_buff;

	i = 0;
	l = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (i == ft_strlen(str))
	{
		free(str);
		return (0);
	}
	l = ft_strlen(str);
	new_buff = malloc(sizeof(char) * (l + 1));
	if (!new_buff)
		return (0);
	l = 0;
	while (str[i])
		new_buff[l++] = str[i++];
	new_buff[l] = '\0';
	free(str);
	return (new_buff);
}

int	handle_rs(int rs, char *buff)
{
	int	res;

	res = 0;
	if (rs == -1)
	{
		free(buff);
		return (res);
	}
	res = 1;
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*buff_joined;
	int			rs;

	rs = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (rs > 0 && !check_new_line(buff_joined))
	{
		rs = read(fd, buff, BUFFER_SIZE);
		if (handle_rs(rs, buff) == 0)
			return (0);
		if (rs == 0)
			break ;
		buff[rs] = '\0';
		buff_joined = ft_strjoin(buff_joined, buff);
	}
	free(buff);
	if (!buff_joined || !*buff_joined)
		return (0);
	line = get_line(buff_joined);
	buff_joined = increment_buffer(buff_joined);
	return (line);
}
