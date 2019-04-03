/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:33:40 by sgalasso          #+#    #+#             */
/*   Updated: 2019/04/03 21:28:57 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void        export_map(t_env *env)
{

	int		xmin = WIN_W;	// translation
	int		ymin = WIN_H;	// translation

	char	*path;
	int		fd;
	int		nb_wobj = 0;
	int		nb_cons = 0;
	int		nb_ntty = 0;
	int		nb_spec = 0;

	printf("%s\n", env->map_name);

	t_sct	*sct;
	t_vtx	*vtx;
	sct = env->sct_start;
	while (sct)
	{
		vtx = sct->vtx_start;
		while (vtx)
		{
			if (vtx->pos.x < xmin)
				xmin = vtx->pos.x;
			if (vtx->pos.y < ymin)
				ymin = vtx->pos.y;
			vtx = vtx->next;
		}
		sct = sct->next;
	}

	t_object    *obj = env->objects;
	while (obj)
	{
		if (obj->category == WALL_OBJ)
			nb_wobj++;
		else if (obj->category == CONSUMABLE)
			nb_cons++;
		else if (obj->category == ENTITY)
			nb_ntty++;
		else if (obj->category == SPECIAL)
			nb_spec++;
		obj = obj->next;
	}

	if (!(path = ft_strjoin("maps/", env->map_name)))
		ui_error_exit_sdl("Editor: Error while opening file", env->data);

	if ((fd = open(path, O_CREAT | O_TRUNC | O_WRONLY,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		ui_error_exit_sdl("Editor: Error while opening file", env->data);
	free(path);	

	ft_putendl_fd("# map name", fd);
	ft_putendl_fd(env->map_name, fd);

	dprintf(fd, "# nb vertex:\n%d\n", env->nb_vtx);
	dprintf(fd, "# vertex: x y\n");
	sct = env->sct_start;
	while (sct)
	{
		vtx = sct->vtx_start;
		while (vtx)
		{
			dprintf(fd, "vertex %d %d\n",
			(int)((vtx->pos.x - xmin) * env->zoom_coef),
			(int)((vtx->pos.y - ymin) * env->zoom_coef));
			vtx = vtx->next;
		}
		sct = sct->next;	
	}

	ft_putendl_fd("# nb sectors:", fd);
	ft_putnbr_fd(env->nb_sct, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("# sector: ceil floor n-vertex n-neighbors", fd);
	sct = env->sct_start;
	while (sct)
	{
		dprintf(fd, "sector /**/ /**/");
		dprintf(fd, "/**/\n");
		sct = sct->next;	
	}

	ft_putendl_fd("# nb wall objects:", fd);
	ft_putnbr_fd(nb_wobj, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("# wall_object: x y sector ref", fd);
	obj = env->objects;
	while (obj)
	{
		if (obj->category == WALL_OBJ)
			dprintf(fd, "wall_object %d %d /**/ /**/\n",
			(int)((obj->pos.x - xmin) * env->zoom_coef),
			(int)((obj->pos.y - ymin) * env->zoom_coef));
		obj = obj->next;	
	}

	ft_putendl_fd("# nb consumables:", fd);
	ft_putnbr_fd(nb_cons, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("# consumable: x y sector ref is_wpn", fd);
	obj = env->objects;
	while (obj)
	{
		if (obj->category == CONSUMABLE)
			dprintf(fd, "consumable %d %d /**/ /**/ /**/\n",
			(int)((obj->pos.x - xmin) * env->zoom_coef),
			(int)((obj->pos.y - ymin) * env->zoom_coef));
		obj = obj->next;	
	}
	
	ft_putendl_fd("# nb entities:", fd);
	ft_putnbr_fd(nb_ntty, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("# entity: x y sector ref", fd);	
	obj = env->objects;
	while (obj)
	{
		if (obj->category == ENTITY)
			dprintf(fd, "entity %d %d /**/ /**/\n",
			(int)((obj->pos.x - xmin) * env->zoom_coef),
			(int)((obj->pos.y - ymin) * env->zoom_coef));
		obj = obj->next;	
	}

	ft_putendl_fd("# nb specials:", fd);
	ft_putnbr_fd(nb_spec, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("# special: x y ref", fd);
	obj = env->objects;
	while (obj)
	{
		if (obj->category == SPECIAL)
			dprintf(fd, "special %d %d /**/\n",
			(int)((obj->pos.x - xmin) * env->zoom_coef),
			(int)((obj->pos.y - ymin) * env->zoom_coef));
		obj = obj->next;	
	}

	if (close(fd) == -1)
		ui_error_exit_sdl("Editor: Error while closing file", env->data);
}
