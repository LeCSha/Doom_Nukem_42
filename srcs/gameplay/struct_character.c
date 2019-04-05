/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaille <abaille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 22:16:59 by abaille           #+#    #+#             */
/*   Updated: 2019/04/04 02:45:43 by abaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int     init_character(t_character *new)
{
    int i;

    i = -1;
    ft_bzero(&new->actions, sizeof(new));
    new->health = 200;
    new->shield = 200;
    new->max_health = 200;
    new->max_shield = 200;
    if (!(new->bullet = ui_img("bullet/", 0))
    || !(new->shot = malloc(sizeof(t_impact) * PLYR_NB_SHOT)))
        return (0);
    while (++i < PLYR_NB_SHOT)
        ft_bzero(&new->shot[i], sizeof(t_impact));
    return (1);
}