/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:23:49 by fmadura           #+#    #+#             */
/*   Updated: 2019/01/09 13:02:17 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void        character_set(t_character *new)
{
    new->health = 100;
    new->shield = 0;
    new->max_weapons = 3;
    new->max_objects = 3;
    new->max_health = 200;
    new->max_shield = 200;
    new->sprite = NULL;
    point_set(&new->pos, 0, 0);
    point_set(&new->plane, 0, 0);
    point_set(&new->dir, 0, 0);
}

t_character *character_new(void)
{
    t_character *new;

    if ((new = (t_character *)(malloc(sizeof(t_character)))) == NULL)
        return (NULL);
    ft_bzero(new, sizeof(t_character));
    character_set(new);
    return (new);
}