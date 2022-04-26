/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:17 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 15:46:47 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*volume;

	volume = "0.2";
	if (ft_strcmp(path, "./sound/pistol.mp3") == 0)
		volume = "0.8";
	if (vars->player.has_sound == 0)
		return ;
	pid = fork();
	if (pid == 0)
	{
		execlp("afplay", "afplay", "-v", volume, path, NULL);
	}
}

void	sound_kill(void)
{
	const char	*command;

	command = "pkill afplay";
	system(command);
}
