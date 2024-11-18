/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:57:26 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:26:53 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

# define INT 1
# define DBL 2

# define WR_INPUT		"Input: ./miniRT [scene].rt"
# define FILE_ERROR		"File error. Check format / permissions"
# define MEMORY_FAIL	"Memory allocation did what!? It failed!"
# define WR_FORMAT		"Wrong object format"
# define WR_FORMAT_A	"Wrong ambient format"
# define WR_FORMAT_L	"Wrong light format"
# define WR_FORMAT_P	"Wrong plane format"
# define WR_FORMAT_C	"Wrong camera format"
# define WR_FORMAT_CO	"Wrong cone format"
# define WR_FORMAT_SP	"Wrong sphere format"
# define WR_FORMAT_CY	"Wrong cylinder format"
# define WR_FORMAT_CU	"Wrong cube format"
# define WR_FORMAT_OP	"Wrong shape option format"
# define WR_FORMAT_CNT	"Missing or duplicate elements"
# define WR_FORMAT_VECT	"Wrong vector format"
# define WR_FORMAT_DBL	"Wrong double format"

void		rt_error(char *err_mssg, t_data *data);
void		check_file_ext(t_data *data);
char		is_whitespace(char c);
char		check_empty_line(char *line);

t_line		*rt_lastnode(t_line *lst);
t_line		*rt_lstnew(t_data *data, char *line);
void		rt_lstadd_back(t_line **lst, t_line *node);

char		check_object(t_line *node);
void		populate_node(t_line *node, char **configs, t_data *data);
void		populate_list(t_data *data, char *line);
int			process_file(t_data *data);

int			array_len(char **array);
int			is_double(char *nbr);
int			is_int(char *nbr);
t_vect		get_vect(char *vect, int type, t_data *data);
int			is_normalised(t_vect *vect, t_data *data);
double		rt_atod(char *nbr, t_data *data);
int			skip_whitespaces(t_line *node, int i);

t_matrix	axis_rotation(t_vect orientation);
t_matrix	orientation_matrix(t_vect axis, double angle);

void		parse_ambient(t_line *node, char **configs, t_data *data);
void		parse_light(t_line *node, char **configs, t_data *data);
void		parse_sphere(t_line *node, char **configs, t_data *data);
void		parse_plane(t_line *node, char **configs, t_data *data);
void		parse_camera(t_line *node, char **configs, t_data *data);
void		parse_cylinder(t_line *node, char **configs, t_data *data);
void		parse_cone(t_line *node, char **configs, t_data *data);
void		parse_cube(t_line *node, char **configs, t_data *data);

int			validate_list(t_data *data);

void		populate_scene(t_data *data);
void		populate_light(t_line *line, t_data *data);
void		populate_ambient(t_line *line, t_data *data);
void		populate_camera(t_line *line, t_data *data);
void		populate_sphere(t_line *line, t_data *data);
void		populate_plane(t_line *line, t_data *data);
void		populate_cylinder(t_line *line, t_data *data);
void		populate_cone(t_line *line, t_data *data);
void		populate_cube(t_line *line, t_data *data);

void		parse_options(t_line *node, char **configs, t_data *data);
void		parse_scale(t_line *node, char *scale, t_data *data);
void		parse_rot(t_line *node, char *rot, t_data *data);
void		parse_mat(t_line *node, char *mat, t_data *data);
void		default_options(t_line *node);

char		**rt_split(char *str);

#endif