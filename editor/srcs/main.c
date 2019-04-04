/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:13:14 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/01 15:44:33 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int				main(void)
{
	t_data		data;
	t_env		env;

	ui_init_sdl(&data);
	init_env(&env, &data);
	ui_gameloop(&handle_events, &editor, &env);
	return (0);
}
