#include "../includes/minishell.h"

void	exec_command(char *cmd, char **envp)
{
	int	end[2];
	pid_t	p;
	char	**sp;

	pipe(end);
	p = fork();
	printf("STDOUT: %d\n", STDOUT_FILENO);
	if (p < 0)
		return (perror("Fork: "));
	if (p == 0)
	{
		close(end[0]);
		sp = ft_split(cmd, ' ');
		dup2(end[1], STDOUT_FILENO);
		close(end[1]);
		if (!access(cmd, X_OK))
			execve(cmd, sp, envp);
		exit(1);
	}
	close(end[1]);
	waitpid(p, NULL, 0);
	char *out = malloc(sizeof(char) * 4096);
	read(end[0], out, 4096);
	printf("OUT: %s\n", out);
	close(end[0]);
}

int main(int argc, char **argv)
{
	char		*inp;
	extern char	**environ;
	
	printf("ARGC: %d\n", argc);
	printf("ARGV[0]: %s\n", argv[0]);
	inp = readline("amnesia@:");
	printf("INP: %s\n", inp);
	exec_command("/usr/bin/whoami", environ);
	//execve("/usr/bin/whoami", cmd, environ);
	//execve("/usr/bin/hostnamectl", cmd, environ);
	/*while (42)
	{
		inp = readline("amnesia@:");
		printf("INP: %s\n", inp);
	}*/
	return (0);
}
