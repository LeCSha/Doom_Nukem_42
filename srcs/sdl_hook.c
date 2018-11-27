#include "wolf.h"

int		sdl_exit_wolf(t_env *env, Uint8 keycode)
{
	if (keycode == SDL_SCANCODE_ESCAPE)
	{
		Mix_FreeChunk(env->sounds.shot);
		Mix_CloseAudio();
		SDL_DestroyRenderer(env->sdl.renderer);
		TTF_Quit();
		SDL_Quit();
		env_free(env);
		exit(0);
	}
	return (0);
}

static int sdl_check_pos(t_env *env, t_point mult, float check, char pos)
{
	int x;
	int y;

	if (pos == 'x')
	{
		x = env->pos.x + mult.x * check;
		y = env->pos.y;
		env->w_map[x][y] == 0 ? env->pos.x += mult.x * (check / 2.0) : 0;
	}
	else
	{
		x = env->pos.x;	
		y = env->pos.y + mult.y * check;
		env->w_map[x][y] == 0 ?  env->pos.y += mult.y * (check / 2.0) : 0;
	}
	return (0);
}

int		sdl_move(t_env *env, Uint8 *keycodes)
{	
	if (keycodes[SDL_SCANCODE_W])
	{
		sdl_check_pos(env, env->dir, 0.2, 'x');
		sdl_check_pos(env, env->dir, 0.2, 'y');
	}
	if (keycodes[SDL_SCANCODE_S])
	{
		sdl_check_pos(env, env->dir, -0.2, 'x');
		sdl_check_pos(env, env->dir, -0.2, 'y');
	}
	if (keycodes[SDL_SCANCODE_D])
	{
		sdl_check_pos(env, env->plane, 0.2, 'x');
		sdl_check_pos(env, env->plane, 0.2, 'y');
	}
	if (keycodes[SDL_SCANCODE_A])
	{
		sdl_check_pos(env, env->plane, -0.2, 'x');
		sdl_check_pos(env, env->plane, -0.2, 'y');
	}
	if (keycodes[SDL_SCANCODE_V])
	{
		if (env->hratio <= 1.1)
			env->is_jump = 1;
		if (env->is_jump == 1)
		{
			env->is_updn += 20;
			env->hratio += 0.1;
		}
		else
		{
			env->is_updn -= 20;
			env->hratio -= 0.1;
		}
		if (env->hratio >= 2 && env->is_jump == 1)
			env->is_jump = 0;
	}
	return (0);
}

int		sdl_motion_mouse(t_env *env, int x, int y)
{
	double	mult;

	mult = x < 0 ? 1.0 : -1.0;
	env->dir = point_rotate(env->dir, mult * 3.0);
	env->plane = point_rotate(env->plane, mult * 3.0);
	env->pang += mult;
	env->pang > 358.0 ? env->pang = 0.0 : 0;
	env->pang < 0.0 ? env->pang = 358.0 : 0;
	if (y > 0)
	{
		if (env->is_updn > -400)
			env->is_updn -= 10;
	}
	else if (y < 0)
	{
		if (env->is_updn < 400)
			env->is_updn += 10;
	}
	init_thread(env);
	return (0);
}

int	shooter(t_env *env, Uint8 *keycodes)
{
	if (keycodes[SDL_SCANCODE_X])
	{
		Mix_PlayChannel(-1, env->sounds.shot, 0);
	}
	return (0);
}

int sdl_keyhook(t_env *env, SDL_Event event)
{
	Uint8	keycode;
	const Uint8	*keycodes = SDL_GetKeyboardState(NULL);

	keycode = event.key.keysym.scancode;
	sdl_move(env, (Uint8 *)keycodes);
	shooter(env, (Uint8 *)keycodes);
	sdl_exit_wolf(env, keycode);
	init_thread(env);
	return (0);

}
