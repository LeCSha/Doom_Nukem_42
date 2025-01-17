/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_rect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:19:50 by sgalasso          #+#    #+#             */
/*   Updated: 2019/05/04 18:11:27 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ui_draw_rect(SDL_Surface *surface, SDL_Rect rect, Uint32 color)
{
	t_edge		edge;

	edge.v1 = (t_vtx){rect.x, rect.y};
	edge.v2 = (t_vtx){rect.x + rect.w, rect.y};
	ui_draw_line(surface, edge, color);

	edge.v1 = (t_vtx){rect.x + rect.w, rect.y};
	edge.v2 = (t_vtx){rect.x + rect.w, rect.y + rect.h};
	ui_draw_line(surface, edge, color);

	edge.v1 = (t_vtx){rect.x + rect.w, rect.y + rect.h};
	edge.v2 = (t_vtx){rect.x, rect.y + rect.h};
	ui_draw_line(surface, edge, color);

	edge.v1 = (t_vtx){rect.x, rect.y + rect.h};
	edge.v2 = (t_vtx){rect.x, rect.y};
	ui_draw_line(surface, edge, color);
}

