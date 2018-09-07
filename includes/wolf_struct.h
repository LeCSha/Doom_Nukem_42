/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:54:38 by fmadura           #+#    #+#             */
/*   Updated: 2018/09/07 15:32:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_STRUCT_H
# define WOLF_STRUCT_H

typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_env	t_env;
typedef struct s_point	t_point;
typedef struct s_thr	t_thr;
typedef struct s_thw	t_thw;
typedef struct s_line	t_line;
typedef struct s_ray	t_ray;

struct					s_img
{
	void		*iptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			w;
	int			h;
};

struct					s_mlx
{
	void		*mptr;
	void		*wptr;
	void		*iptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
};

struct					s_point
{
	double		x;
	double		y;
};

struct					s_thr
{
	pthread_t	th;
	t_env		*env;
	int			nbr;
};

struct					s_thw
{
	t_thr		t1;	
	t_thr		t2;	
	t_thr		t3;	
	t_thr		t4;
	t_thr		t5;
	t_thr		t6;
	t_thr		t7;
	t_thr		t8;
};

struct					s_ray
{
	t_img		*text;
	t_point		map;
	t_point		delta;
	t_point		step;
	t_point		raydir;	
	t_point		wall;
	t_point		side;
	double		wdist;
	int			sidew;
	int			lineh;
	int			sdraw;
	int			edraw;
};

struct					s_line
{
	t_img		*text;
	t_point		map;
	t_point		delta;
	t_point		step;
	t_point		raydir;	
	t_point		wall;
	t_point		side;
	double		wdist;
	int			sidew;
	int			lineh;
	int			sdraw;
	int			edraw;
};

struct					s_env
{
	t_mlx		mlx;
	t_thw		thw;
	t_point		pos;
	t_point		dir;
	t_point		plane;
	t_point		old;
	double		is_updn;
	double		cam;
	double		ang;
	double		pang;
	int			**w_map;
	t_img		*portal;
	t_img		*blackportal;
	t_point		pos_portal;
	t_img		*wall;
	t_img		*walls[10];
	t_img		*floor;
	t_img		*sky;
	t_img		*gun;
	int			width;
	int			height;
	int			outportal;
	int			inportal;
};

#endif
