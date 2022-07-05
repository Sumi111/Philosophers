/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:10:42 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 13:11:49 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return ;
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i;
		data->philo[i].n_ate = 0;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->n_philo;
		data->philo[i].left_lock = 0;
		data->philo[i].right_lock = 0;
		data->philo[i].t_lastmeal = get_time();
		i++;
	}
}

int	ft_init(t_data *data)
{
	data->all_ate = 0;
	data->die = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (data->philo == NULL)
		return (-42);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (data->forks == NULL)
		return (-42);
	data->philo_thr = malloc(sizeof(pthread_t) * data->n_philo);
	if (data->philo_thr == NULL)
		return (-42);
	init_philo(data);
	init_fork(data);
	return (0);
}
