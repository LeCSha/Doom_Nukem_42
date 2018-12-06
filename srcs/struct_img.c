/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:18:41 by fmadura           #+#    #+#             */
/*   Updated: 2018/10/04 16:56:39 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

SDL_Surface	*create_surf(char *path)
{
	SDL_Surface* new;
	
	new = IMG_Load(path);
	if (!new)
	{
		printf("Error : %s\n", SDL_GetError());
		return NULL;
	}
	return (new);
}

SDL_Surface	*img_new(char *filename)
{
	SDL_Surface	*new;
	char		*path;

	path = ft_strjoin("./rsrc/img/", filename);
	new = create_surf(path);
	free(path);
	path = NULL;
	return (new);
}

void		ak_img(t_env *env)
{
	env->ak_frms[0] = img_new("weapons/ak_decomposee/ak_1.png");
	env->ak_frms[1] = img_new("weapons/ak_decomposee/ak_02.png");
	env->ak_frms[2] = img_new("weapons/ak_decomposee/frame-03.png");
	env->ak_frms[3] = img_new("weapons/ak_decomposee/frame-04.png");
	env->ak_frms[4] = img_new("weapons/ak_decomposee/frame-05.png");
	env->ak_frms[5] = img_new("weapons/ak_decomposee/frame-06.png");
	env->ak_frms[6] = img_new("weapons/ak_decomposee/frame-07.png");
	env->ak_frms[7] = img_new("weapons/ak_decomposee/frame-08.png");
	env->ak_frms[8] = img_new("weapons/ak_decomposee/frame-09.png");
	env->ak_frms[9] = img_new("weapons/ak_decomposee/frame-10.png");
	env->ak_frms[10] = img_new("weapons/ak_decomposee/frame-11.png");
	env->ak_frms[11] = img_new("weapons/ak_decomposee/frame-12.png");
	env->ak_frms[12] = img_new("weapons/ak_decomposee/frame-13.png");
	env->ak_frms[13] = img_new("weapons/ak_decomposee/frame-14.png");
	env->ak_frms[14] = img_new("weapons/ak_decomposee/frame-15.png");
	env->ak_frms[15] = img_new("weapons/ak_decomposee/frame-16.png");
	env->ak_frms[16] = img_new("weapons/ak_decomposee/frame-17.png");
	env->ak_frms[17] = img_new("weapons/ak_decomposee/frame-18.png");
	env->ak_frms[18] = img_new("weapons/ak_decomposee/frame-19.png");
	env->ak_frms[19] = img_new("weapons/ak_decomposee/frame-20.png");
	env->ak_frms[20] = img_new("weapons/ak_decomposee/frame-21.png");
	env->ak_frms[21] = img_new("weapons/ak_decomposee/frame-22.png");
	env->ak_frms[22] = img_new("weapons/ak_decomposee/frame-23.png");
	env->ak_frms[23] = img_new("weapons/ak_decomposee/frame-24.png");
	env->ak_frms[24] = img_new("weapons/ak_decomposee/frame-25.png");
	env->ak_frms[25] = img_new("weapons/ak_decomposee/frame-26.png");
	env->ak_frms[26] = img_new("weapons/ak_decomposee/frame-27.png");
	env->ak_frms[27] = img_new("weapons/ak_decomposee/frame-28.png");
	env->ak_frms[28] = img_new("weapons/ak_decomposee/frame-29.png");
	env->ak_frms[29] = img_new("weapons/ak_decomposee/frame-30.png");
	env->ak_frms[30] = img_new("weapons/ak_decomposee/frame-31.png");
	env->ak_frms[31] = img_new("weapons/ak_decomposee/frame-32.png");
	env->ak_frms[32] = img_new("weapons/ak_decomposee/frame-33.png");
	env->ak_frms[33] = img_new("weapons/ak_decomposee/frame-34.png");
	env->ak_frms[34] = img_new("weapons/ak_decomposee/frame-35.png");
	env->ak_frms[35] = img_new("weapons/ak_decomposee/frame-36.png");
	env->ak_frms[36] = img_new("weapons/ak_decomposee/frame-37.png");
	env->ak_frms[37] = img_new("weapons/ak_decomposee/frame-38.png");
	env->ak_frms[38] = img_new("weapons/ak_decomposee/frame-39.png");
	env->ak_frms[39] = img_new("weapons/ak_decomposee/frame-40.png");
	env->ak_frms[40] = img_new("weapons/ak_decomposee/frame-41.png");
	env->ak_frms[41] = img_new("weapons/ak_decomposee/frame-42.png");
	env->ak_frms[42] = img_new("weapons/ak_decomposee/frame-43.png");
}

void	stitch(t_env *env)
{
	env->stitch[0] = img_new("enemies/stitch/frame-01.png");
	env->stitch[1] = img_new("enemies/stitch/frame-02.png");
	env->stitch[2] = img_new("enemies/stitch/frame-03.png");
	env->stitch[3] = img_new("enemies/stitch/frame-04.png");
	env->stitch[4] = img_new("enemies/stitch/frame-05.png");
	env->stitch[5] = img_new("enemies/stitch/frame-06.png");
	env->stitch[6] = img_new("enemies/stitch/frame-07.png");
	env->stitch[7] = img_new("enemies/stitch/frame-08.png");
	env->stitch[8] = img_new("enemies/stitch/frame-09.png");
	env->stitch[9] = img_new("enemies/stitch/frame-10.png");
	env->stitch[10] = img_new("enemies/stitch/frame-11.png");
	env->stitch[11] = img_new("enemies/stitch/frame-12.png");
	env->stitch[12] = img_new("enemies/stitch/frame-13.png");
	env->stitch[13] = img_new("enemies/stitch/frame-14.png");
	env->stitch[14] = img_new("enemies/stitch/frame-15.png");
	env->stitch[15] = img_new("enemies/stitch/frame-16.png");
	env->stitch[16] = img_new("enemies/stitch/frame-17.png");
	env->stitch[17] = img_new("enemies/stitch/frame-18.png");
}

void	new_bullet_surf(t_env *env)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		env->bul_surf[i] = SDL_CreateRGBSurface(0,
						564,
						563,
						32,
						0x000000FF,
						0x0000FF00,
						0x00FF0000,
						0xFF000000);
		i++;
	}
}

void	img(t_env *env)
{
	env->walls[0] = img_new("wall_1.png");
	env->walls[1] = img_new("door.png");
	env->walls[2] = img_new("wall_1.png");
	env->walls[3] = img_new("wall_1.png");
	env->walls[4] = img_new("floor_scifi2.png");
	env->walls[5] = img_new("wall_1.png");
	env->walls[6] = img_new("floor_scifi2.png");
	env->walls[7] = img_new("floor_scifi2.png");
	env->enemy = img_new("enemy.png");
	env->wall = env->walls[0];
	env->floor = img_new("floor_scifi.png");
	env->sky = img_new("floor.png");
	env->gun = img_new("weapons/ak_decomposee/ak_1.png");
	env->life.img = img_new("thealth.png");
	env->lscreen.img = img_new("accueil.jpg");
	env->logo.img = img_new("logo.png");
	env->gun_impact = img_new("lilbullet.png");
	env->wobj.posters[1] = img_new("posters/lilstrangerthings.png");
	env->wobj.posters[2] = img_new("posters/lilstarwars.png");
	env->wobj.posters[3] = img_new("posters/lilbisounours.png");
	env->wobj.posters[4] = img_new("posters/fuckbisounours.png");
	env->wobj.posters[5] = img_new("posters/lildukenukem.png");
	ak_img(env);
	stitch(env);
	new_bullet_surf(env);
}