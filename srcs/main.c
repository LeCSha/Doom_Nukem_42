/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:38 by fmadura           #+#    #+#             */
/*   Updated: 2019/04/26 20:56:01 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main(int ac, char **av)
{
	t_env	env;

	/* init env */
	init_env(ac, av, &env);
	set_msc_menu(&env, &env.menu.status);
	load_worlds(&env);

	/* mainmenu loop */
	mainmenu_loop(&env);

	/* world loop */
	int iprovisoire = 0;
	while (/**env.level*/iprovisoire < 3)
	{
		env.finish = 0;

		// display text start
		loop_intro(&env, iprovisoire, 1);

		/* load level */
		load_map(&env.engine, &env);
		init_minimap(&env);

		/* gameloop */
		sdl_loop(&env);

		// display text end
		loop_intro(&env, iprovisoire, 0);

		/* free level */
		//free_map();
		lt_release(env.engine.minimap.surface);
		lt_release(env.engine.minimap.background);

		/*(env.level)++;*/
		iprovisoire++;
	}

	/* free and exit */
	doom_exit();
	return (0);
}
