#include <cub3d.h>

void	sound_brittney(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execlp("afplay", "afplay", "-v", "0.2", "sound/brittney.mp3", NULL);
	}
}

void	sound_nyancat(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execlp("afplay", "afplay", "-v", "0.2", "sound/nyancat.mp3", NULL);
	}
}

void	sound_music(char *title)
{
	printf("%d\n", ft_strcmp(title, "brittney"));
	if (ft_strcmp(title, "brittney") == 0)
		sound_brittney();
	else if (ft_strcmp(title, "nyancat") == 0)
		sound_nyancat();
}

void	sound_kill(void)
{
	const char	*command;

	command = "killall afplay";
	system(command);
}
