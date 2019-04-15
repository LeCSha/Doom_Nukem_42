/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <fmadura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:39:10 by fmadura           #+#    #+#             */
/*   Updated: 2019/04/14 16:08:10 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	print_line(t_parseline *line)
{
	t_token	*iter;

	iter = NULL;
	iter = line->first;
	while (iter)
	{
		printf("[%u: %d]", iter->pos, iter->value);
		iter = iter->next;
	}
	printf("\n");
}

void	print_file(t_parsefile *file)
{
	t_parseline	*line;

	line = NULL;
	line = file->first;
	while (line)
	{
		print_line(line);
		line = line->next;
	}
}

int		free_file(t_parsefile *file)
{
	t_parseline	*line;
	t_token		*iter;

	while (file->first)
	{
		line = file->first;
		while (line->first)
		{
			iter = line->first;
			line->first = iter->next;
			free(iter);
			iter = NULL;
		}
		file->first = line->next;
		free(line);
		line = NULL;
	}
	return (1);
}