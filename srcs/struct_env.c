/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:03:20 by fmadura           #+#    #+#             */
/*   Updated: 2018/10/10 14:32:18 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		fill_obj(t_env *env)
{
	int	x;
	int	y;
	int o_map[24][24]=
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
			{1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
	if (!(env->o_map = (int**)malloc(sizeof(int*) * 24)))
		;//print_error(1, env);
	y = 0;
	while (y < 24)
	{
		if (!(env->o_map[y] = (int*)malloc(sizeof(int) * 24)))
			;//print_error(1, env);
		x = 0;
		while (x < 24)
		{
			env->o_map[y][x] = o_map[y][x];
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Map for wolf, formatted as follow :
** 0xabcd
** a : objects on wall
** b : bullets impact
** c : [wall, floor, object]
** d : texture number
**/
int		fill_tab(t_env *env)
{
	int	x;
	int	y;
	int w_map[24][24]=
		{
			{0x0017, 0x0017, 0x0017, 0x2017, 0x3017, 0x4017, 0x5017, 0x1017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017 ,0x0017},
			{0x0017, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0011, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0011, 0x0012, 0x0013, 0x0013, 0x0014, 0x0014, 0x0012, 0x0016, 0x0017, 0x0017, 0x0000, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0015, 0x0000, 0x2011, 0x0000, 0x1011, 0x0000, 0x0016, 0x0000, 0x0014, 0x0017, 0x0000, 0x0000, 0x0000, 0x0017, 0x0017, 0x0017, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0015, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017, 0x0017, 0x0017, 0x0017},
			{0x0017, 0x0021, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0015, 0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0017, 0x0000, 0x0000, 0x0000, 0x0017, 0x0017, 0x0017, 0x0017},
			{0x0017, 0x0000, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000, 0x0013, 0x0013, 0x0012, 0x0015, 0x0000, 0x0015, 0x0012, 0x0012, 0x0013, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017},
			{0x0017, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0000, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0000, 0x0016, 0x0016, 0x0016, 0x0016, 0x0000, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0016, 0x0017},
			{0x0017, 0x0014, 0x0014, 0x0014, 0x0014, 0x0014, 0x0000, 0x0014, 0x0014, 0x0014, 0x0016, 0x0000, 0x0016, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0012, 0x0013, 0x0013, 0x0013, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0016, 0x0000, 0x0016, 0x0012, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0016, 0x0012, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0012, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0016, 0x0000, 0x0016, 0x0012, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0012, 0x0000, 0x0012, 0x0017},
			{0x0017, 0x0000, 0x0016, 0x0000, 0x0016, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0016, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0016, 0x0000, 0x0016, 0x0012, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0012, 0x0012, 0x0000, 0x0012, 0x0017},
			{0x0017, 0x0000, 0x0016, 0x0000, 0x0016, 0x0000, 0x0000, 0x0000, 0x0000, 0x0014, 0x0016, 0x0000, 0x0016, 0x0012, 0x0000, 0x0000, 0x0015, 0x0000, 0x0000, 0x0012, 0x0000, 0x0000, 0x0000, 0x0017},
			{0x0017, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
			{0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017, 0x0017}
		};
	if (!(env->w_map = (int**)malloc(sizeof(int*) * 24)))
		;//print_error(1, env);
	y = 0;
	while (y < 24)
	{
		if (!(env->w_map[y] = (int*)malloc(sizeof(int) * 24)))
			;//print_error(1, env);
		x = 0;
		while (x < 24)
		{
			env->w_map[y][x] = w_map[y][x];
			x++;
		}
		y++;
	}
	fill_obj(env);
	return (0);
}

int		init_wobj(t_env *env)
{
	env->wobj.hit = 0;
	env->wobj.poster = 0;
	env->wobj.impact = 0;
	env->wobj.is_bullet = 0;
	env->wobj.simpact =
	SDL_CreateRGBSurface(
	0,
	564,
	563,
	32,
	0x000000FF,
	0x0000FF00,
	0x00FF0000,
	0xFF000000);
	return (0);
}

void	bzero_env(t_env *env)
{
	env->is_updn = 0;
	env->cam = 0;
	env->ang = 0;
	env->angle_d = 0;
	env->w_map = NULL;
	env->w_map_2 = NULL;
	env->o_map = NULL;
	env->floor = NULL;
	env->sky = NULL;
	env->gun_impact = NULL;
	env->ld_wp = 0;
	env->is_shootin = 0;
	env->width = 0;
	env->height = 0;
	env->hratio = 0;
	env->is_jump = 0;
}

int		init_env(t_env *env)
{
	bzero_env(env);
	env->width = WIDTH;
	env->height = HEIGHT;
	env->ang = 2.0;
	env->sdl.surface = NULL;
	point_set(&env->pos, 10.0, 10.0);
	point_set(&env->plane, 0.0, 0.66);
	point_set(&env->dir, -1.0, 0.0);
	env->logo.ang = 0.0;
	env->hratio = 2;
	fill_tab(env);
	env->w_map_2 = tab_copy_alloc(env->w_map, 24, 24);;
	img(env);
	init_wobj(env);
	put_poster(env);
	init_thread(env, 8);
	init_sdl(env);
	SDL_SetRenderTarget(env->sdl.renderer, env->sdl.texture);
	return (0);
}
