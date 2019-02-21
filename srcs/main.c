/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:41:45 by fmadura           #+#    #+#             */
/*   Updated: 2019/02/21 17:22:31 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					render_env(t_env *env)
{
	copy_sdl(env);
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_KEYUP);
	SDL_FlushEvent(SDL_MOUSEMOTION);
	SDL_RenderClear(env->sdl.renderer);
	SDL_RenderCopy(env->sdl.renderer, env->sdl.texture, NULL, NULL);
	SDL_RenderPresent(env->sdl.renderer);
	return (0);
}

static void inline	loop_frames(t_env *env, int *frame)
{
	static int	jfram;

	if (env->player.actions.is_shooting)
	{
		put_gun_shoot(env, *frame);
		++(*frame);
	}
	else if (env->player.actions.is_loading)
	{
		put_gun_load(env, *frame);
		++(*frame);
	}
	else
	{
		put_gun(env);
		*frame = 0;
	}
	if (env->player.actions.is_jumping)
	{
		env->jumpmod = 200;
		jfram++;
		if (jfram > 15)
		{
			env->player.actions.is_jumping = 0;
			jfram = 0;
			env->jumpmod = 0;
		}
	}
}

static void inline	loop_mouse(t_env *env)
{
	int		x;
	int		y;

	SDL_GetRelativeMouseState(&x, &y);
	if (x || y)
		sdl_motion_mouse(env, x, y);
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(1))
	{
		if (env->wobj.impact < 6)
			env->wobj.impact++;
		env->mouse.x = x;
		env->mouse.y = y;
		sdl_mouse_click(env, x, y);
	}
}

void				loop_menu(t_env *env, Uint8 keycode)
{
	(void)keycode;
	if (env->sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit(0);
			//env->menu.is_active = !env->menu.is_active;
	/*if (env->menu.is_active)
	{
		while (1)
		{
			if (env->sdl.event.type == SDL_KEYDOWN)
			{
				if (keycode == SDL_SCANCODE_DOWN || keycode == SDL_SCANCODE_UP)
					move_button_menu(env, keycode);
				if (keycode == SDL_SCANCODE_RETURN)
					select_button_menu(env, keycode);
				menu(env);
				copy_sdl(env);
				render_env(env);
			}
			SDL_WaitEvent(&env->sdl.event);
			keycode = env->sdl.event.key.keysym.scancode;
			if (!env->menu.is_active)
					break;
		}
	}*/
}

void				loop_env(t_env *env)
{
	int		frame;
	int		fps;
	Uint32	time_a;
	Uint32	time_b;
	(void)loop_frames;

	time_b = 0;
	fps = 0;
	while (1)
	{
		SDL_PollEvent(&env->sdl.event);
		if (env->sdl.event.type == SDL_QUIT)
			break;
		loop_menu(env, env->sdl.event.key.keysym.scancode);
		if ((time_a = SDL_GetTicks()) - time_b > SCREEN_TIC)
		{
			fps = 1000 / (time_a - time_b);
			time_b = time_a;
			if (sdl_keyhook(env, env->sdl.event))
			{
				loop_mouse(env);
				init_thread(env, 8);
				//handle_bots(env);
				loop_frames(env, &frame);
				ui_put_minimap(env);
				ui_put_health(env);
				ui_put_fps(env, fps);
			}
			render_env(env);
		}
	}
}

int					main(int argc, char **argv)
{
	t_env env;

	if (argc != 2)
	{
		ft_putendl_fd("doom_nukem: error: bad args", 2);
		ft_putendl_fd("doom_nukem: usage: wolf3d [map_name]", 2);
		return (0);
	}
	env.menu.is_active = 1;
	init_env(&env, argv[1]);
	loop_env(&env);
	env_free(&env);
	return (0);
}
