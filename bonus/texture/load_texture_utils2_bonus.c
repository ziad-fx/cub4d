/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_utils2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:21:17 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/26 17:50:46 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex_cub.h"

static int	load_texture_no(t_player *player)
{
	player->data->no_texture = mlx_xpm_file_to_image(player->mlx->mlx,
			player->data->no_path, &player->data->tex_with,
			&player->data->tex_height);
	if (!player->data->no_texture)
		return (1);
	player->data->no_address = mlx_get_data_addr(player->data->no_texture,
			&player->data->tex_bpp, &player->data->tex_line_len,
			&player->data->tex_endian);
	if (!player->data->no_texture || !player->data->no_address)
		return (1);
	return (0);
}

static int	load_texture_so(t_player *player)
{
	player->data->so_texture = mlx_xpm_file_to_image(player->mlx->mlx,
			player->data->so_path, &player->data->tex_with,
			&player->data->tex_height);
	if (!player->data->so_texture)
		return (1);
	player->data->so_address = mlx_get_data_addr(player->data->so_texture,
			&player->data->tex_bpp, &player->data->tex_line_len,
			&player->data->tex_endian);
	if (!player->data->so_texture || !player->data->so_address)
		return (1);
	return (0);
}

static int	load_texture_we(t_player *player)
{
	player->data->we_texture = mlx_xpm_file_to_image(player->mlx->mlx,
			player->data->we_path, &player->data->tex_with,
			&player->data->tex_height);
	if (!player->data->we_texture)
		return (1);
	player->data->we_address = mlx_get_data_addr(player->data->we_texture,
			&player->data->tex_bpp, &player->data->tex_line_len,
			&player->data->tex_endian);
	if (!player->data->we_texture || !player->data->we_address)
		return (1);
	return (0);
}

static int	load_texture_ea(t_player *player)
{
	player->data->ea_texture = mlx_xpm_file_to_image(player->mlx->mlx,
			player->data->ea_path, &player->data->tex_with,
			&player->data->tex_height);
	if (!player->data->ea_texture)
		return (1);
	player->data->ea_address = mlx_get_data_addr(player->data->ea_texture,
			&player->data->tex_bpp, &player->data->tex_line_len,
			&player->data->tex_endian);
	if (!player->data->ea_texture || !player->data->ea_address)
		return (1);
	return (0);
}

int	load_texture(t_player *player)
{
	free_text(player);
	if (load_texture_no(player) == 1)
		exit_all(player, 1);
	if (load_texture_so(player) == 1)
		exit_all(player, 1);
	if (load_texture_we(player) == 1)
		exit_all(player, 1);
	if (load_texture_ea(player) == 1)
		exit_all(player, 1);
	if (load_door(player) == 1)
		exit_all(player, 1);
	if (load_text_animation(player) == 1)
		exit_all(player, 1);
	return (0);
}
