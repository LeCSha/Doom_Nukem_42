/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:36:44 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/08 19:39:25 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

SDL_Surface	*make_surface(int width, int height)
{
	SDL_Surface	*surface;

	if (!(surface = lt_push(SDL_CreateRGBSurface(0, width, height,
			32, 0xff000000, 0xff0000, 0xff00, 0xff), srf_del)))
		doom_error_exit("Doom_nukem error on make_surface");
	return (surface);
}
