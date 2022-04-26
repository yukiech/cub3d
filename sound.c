/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:49:17 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/04/26 17:50:55 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	sound_music(t_vars *vars, char *title)
{
	if (ft_strcmp(title, "clic") == 0)
		play_sound(vars, "sound/clic.mp3");
	else if (ft_strcmp(title, "wilheim") == 0)
		play_sound(vars, "sound/wilheim.mp3");
	else if (ft_strcmp(title, "door") == 0)
		play_sound(vars, "sound/door.mp3");
	else if (ft_strcmp(title, "choice") == 0)
		play_sound(vars, "sound/choice.mp3");
	else if (ft_strcmp(title, "hurt") == 0)
		play_sound(vars, "sound/hurt.mp3");
	else if (ft_strcmp(title, "map_victory") == 0)
		play_sound(vars, "sound/map_victory.mp3");
	else if (ft_strcmp(title, "pistol") == 0)
		play_sound(vars, "sound/pistol.mp3");
	else if (ft_strcmp(title, "victory") == 0)
		play_sound(vars, "sound/victory.mp3");
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
