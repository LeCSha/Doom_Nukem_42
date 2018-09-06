/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:03:20 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/05 15:36:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_mlx(t_env *env)
{

	E_MLX = mlx_init();
	E_WIN = mlx_new_window(E_MLX, WIDTH, HEIGHT, "Wolf 3D");
	E_IMG = mlx_new_image(E_MLX, WIDTH, HEIGHT);
	I_IMG = (int *)mlx_get_data_addr(E_IMG, &I_BPP, &I_SZL, &I_END);
}

int		fill_tab(t_env *env)
{
	int	x;
	int	y;
	int w_map[24][24]=
		{
			{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 ,7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 4, 4, 2, 6, 7, 7, 0, 7, 7, 7, 7, 7},
			{7, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 6, 0, 4, 7, 0, 0, 0, 7, 7, 7, 7},
			{7, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7},
			{7, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 7, 7, 7, 7},
			{7, 0, 0, 0, 0, 0, 0, 3, 3, 2, 5, 0, 5, 2, 2, 3, 7, 7, 7, 7, 7, 7, 7, 7},
			{7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
			{7, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7},
			{7, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 7},
			{7, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 7},
			{7, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 7},
			{7, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 7},
			{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
		};
	if (!(env->w_map = (int**)malloc(sizeof(int*) * 24)))
		print_error(1, env);
	y = 0;
	while (y < 24)
	{
		if (!(env->w_map[y] = (int*)malloc(sizeof(int) * 24)))
			print_error(1, env);
		x = 0;
		while (x < 24)
		{
			env->w_map[y][x] = w_map[y][x];
			x++;
		}
		y++;
	}
	return (0);
}

int		init_env(t_env *env)
{
	env->pos.x = 10;
	env->pos.y = 10;
	env->ang = 2.0;
	env->pang = 0.0;
	env->dir.x = -1.0;
	env->dir.y = 0.0;
	env->plane.x = 0.0;
	env->plane.y = 0.66;
	env->w_map = NULL;
	env->is_updn = 0.0;
	env->old.x = 0;
	env->old.y = 0;
	init_mlx(env);
	return (0);
}
