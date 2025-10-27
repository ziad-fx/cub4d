/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:59:54 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/27 11:27:06 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex_cub_bonus.h"

int	valid_map(t_data *data)
{
	int	index;
	int	player_der;

	player_der = 0;
	index = 0;
	while (index < data->map_lines)
	{
		if (valid_chars(data->maps[index], &player_der, 1) != 0)
			return (ft_error("invalid character"), 1);
		index++;
	}
	if (player_der != 1)
		return (ft_error("player less or greater than one"), 1);
	if (valid_dor(data) != 0)
		return (ft_error("door position invalid"), 1);
	if (map_closed(data) != 0)
		return (1);
	return (0);
}

int	pars_map(char *line, t_data *data)
{
	int		type;
	char	*path;

	if (!line || !data)
		return (1);
	if (pars_line_helper(line, &type, &path) != 0)
		return (1);
	free(path);
	if (map_start(data, type))
		return (1);
	if (type == 8)
	{
		data->map_start = 1;
		if (init_map(data))
			return (1);
		data->maps[data->map_index] = ft_strdup(line);
		if (!data->maps[data->map_index])
			return (1);
		data->map_index++;
		if (data->map_index == data->map_lines)
			data->maps[data->map_index] = NULL;
	}
	return (0);
}

int	pars_line(char *line, t_data *data)
{
	char	*path;
	char	*temp;
	int		type;

	if (!line || !data)
		return (1);
	if (pars_line_helper(line, &type, &path) != 0)
		return (1);
	temp = path;
	path = ft_strtrim(path, " ");
	free(temp);
	if (!path)
		return (1);
	if ((type >= 2 && type <= 5) || type == 9)
	{
		if (is_valid_extension(path, ".xpm") != 0)
			return (ft_error("invalid texture"), free(path), 1);
	}
	if (type == 8)
		data->map_lines++;
	if (store_data(type, data, path) != 0)
		return (free(path), 1);
	free(path);
	return (0);
}

int	open_read(t_data *data, char *file_name, int flag)
{
	int		fd;
	char	*line;

	if (!data || !file_name)
		return (1);
	if (is_valid_extension(file_name, ".cub") != 0)
		return (ft_error("File map does not exist!"), 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (write(2, "open faild \n", 13), 1);
	line = get_next_line(fd);
	while (line)
	{
		if (start_parsing(line, data, fd, flag) != 0)
		{
			free(line);
			close(fd);
			return (1);
		}
		(1) && (free(line), line = get_next_line(fd));
	}
	close(fd);
	if (valid_file(data) == 1)
		return (ft_error("texture does not found"), 1);
	return (0);
}

int	parsing_part(t_data *data, char *file_name)
{
	int	i;

	i = 1;
	init_data(data);
	while (i < 3)
	{
		if (open_read(data, file_name, i) != 0)
		{
			print_error();
			return (1);
		}
		i++;
	}
	if (valid_map(data) != 0)
	{
		print_error();
		return (1);
	}
	return (0);
}
