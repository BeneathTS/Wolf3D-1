/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:13:59 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 15:09:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_sdl_music(Mix_Music **music)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		ft_exit(ERROR_INIT_SDL);
	initAudio();
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	if (!(music[0] = Mix_LoadMUS(SONG_0)))
		ft_exit(ERROR_MSG);
	if (!(music[1] = Mix_LoadMUS(SONG_1)))
		ft_exit(ERROR_MSG);
	if (!(music[2] = Mix_LoadMUS(SONG_2)))
		ft_exit(ERROR_MSG);
	if (!(music[3] = Mix_LoadMUS(SHOT)))
		ft_exit(ERROR_MSG);
}

void			change_music(int flag, Mix_Music **music)
{
	Mix_PauseMusic();
	if (music_flag_0 == flag)
		Mix_PlayMusic(music[0], 10);
	else if (music_flag_1 == flag)
		Mix_PlayMusic(music[1], 10);
	else if (music_flag_2 == flag)
		Mix_PlayMusic(music[2], 10);
	else if (music_flag_3 == flag)
		Mix_PlayMusic(music[3], 10);
}
