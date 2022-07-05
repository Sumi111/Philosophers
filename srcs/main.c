/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:03:44 by sfathima          #+#    #+#             */
/*   Updated: 2022/06/30 13:29:49 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	another_check(t_data *data, int n)
{
	if (data->n_philo < 1 || data->n_philo > 200)
		return (ft_error("Too many philosophers!"));
	if (data->t_die <= 0 || data->t_eat <= 0 || data->t_sleep <= 0)
		return (ft_error("Time must be quntitative!!"));
	if (n == 6 && data->n_eat < 1)
		return (ft_error("Check number of meals!"));
	return (0);
}

int	get_argc(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = -1;
	if (argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	if (another_check(data, argc) != 0)
		return (-42);
	if (ft_init(data) != 0)
		return (-42);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments!"));
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			return (ft_error("Can't pass negative arguments!"));
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_error("Arguments must be numerics!"));
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_arg(argc, argv) != 0)
		return (-1);
	if (get_argc(&data, argc, argv) != 0)
		return (-1);
	if (data.n_philo == 1)
		one_philo(&data);
	else
		ft_start(&data);
	ft_free(&data);
	return (0);
}
