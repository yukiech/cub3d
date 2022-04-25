#include <cub3d.h>


void	sound_music(t_vars *vars, char *title)
{
	
	if (ft_strcmp(title, "brittney") == 0)
		play_sound(vars, "sound/brittney.mp3");
	else if (ft_strcmp(title, "nyancat") == 0)
		play_sound(vars, "sound/nyancat.mp3");
	else if (ft_strcmp(title, "imperial") == 0)
		play_sound(vars, "sound/imperial.mp3");
	else if (ft_strcmp(title, "clic") == 0)
		play_sound(vars, "sound/clic.mp3");
	else if (ft_strcmp(title, "wilheim") == 0)
		play_sound(vars, "sound/wilheim.mp3");
	else if (ft_strcmp(title, "door") == 0)
		play_sound(vars, "sound/door.mp3");
	else if (ft_strcmp(title, "choice") == 0)
		play_sound(vars, "sound/choice.mp3");
}

void	play_sound(t_vars *vars, char *path)
{
	pid_t	pid;

	
	if (vars->player.has_sound == 0)
		return ;
	pid = fork();
	if (pid == 0)
	{
		execlp("afplay", "afplay", "-v", "0.2", path, NULL);
	}
}

void	sound_kill(void)
{
	const char	*command;

	command = "killall afplay";
	system(command);
}
