/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:38:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/27 00:48:07 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex_cub.h"

void	ft_error(char *s)
{
	write (2, s, ft_strlen(s));
	write(2, "\n", 1);
}

int	destroy(t_player *player)
{
	exit_all(player, 0, NULL);
	return (0);
}

void	mlx_action(t_player *player)
{
	mlx_hook(player->mlx->win_mlx, 2, 1L << 0, event_listener, player);
	mlx_hook(player->mlx->win_mlx, 3, 1L << 1, event_realise, player);
	mlx_hook(player->mlx->win_mlx, 17, 0L, destroy, player);
	mlx_loop_hook(player->mlx->mlx, render, player);
}

int	start(t_data *data)
{
	t_pixel		pixel;
	t_player	player;
	t_mlx		new_mlx;

	player.data = data;
	player.pixel = &pixel;
	set_zero(&player);
	find_player_position(&player);
	new_mlx.mlx = mlx_init();
	if (new_mlx.mlx == NULL)
		exit_all(&player, 1, "MLX inital failed");
	new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!new_mlx.win_mlx)
		exit_all(&player, 1, "Window failed");
	player.mlx = &new_mlx;
	load_texture(&player);
	draw_map(&pixel, &new_mlx, &player);
	mlx_action(&player);
	mlx_loop(new_mlx.mlx);
	return (0);
}
