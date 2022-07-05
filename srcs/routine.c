/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:17:51 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 14:32:13 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print(t_philo *ph, char *str)
{
	t_data	*data;

	pthread_mutex_lock(&ph->data->print_lock);
	data = ph->data;
	if (data->die != 1 && data->all_ate <= data->n_philo)
		printf("%lld Philo:%d %s\n", get_time() - data->t_start,
			ph->id + 1, str);
	pthread_mutex_unlock(&ph->data->print_lock);
}

void	ft_eat(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	get_fork(ph);
	ft_print(ph, "is eating");
	pthread_mutex_lock(&ph->data->print_lock);
	ph->t_lastmeal = get_time();
	if (data->n_eat != 0)
	{
		ph->n_ate++;
		if (ph->n_ate == data->n_eat)
			data->all_ate++;
	}
	pthread_mutex_unlock(&ph->data->print_lock);
	usleep((ph->data->t_eat * 980));
	ph->left_lock = 0;
	ph->right_lock = 0;
	pthread_mutex_unlock(&(data->forks[ph->right_fork]));
	pthread_mutex_unlock(&(data->forks[ph->left_fork]));
}

void	ft_sleep(t_philo *ph)
{
	ft_print(ph, "is sleeping");
	ft_usleep(ph->data->t_sleep, ph->data);
	ft_print(ph, "is thinking");
}

void	*ft_routine(void *d)
{
	t_philo	*ph;

	ph = (t_philo *)d;
	while (1)
	{
		if (ph->n_ate == ph->data->n_eat)
			return (0);
		ft_eat(ph);
		ft_sleep(ph);
		if (ph->data->die == 1)
			break ;
	}
	return (0);
}
