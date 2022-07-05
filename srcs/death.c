/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:19:33 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 14:27:08 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_kill(t_data *d, int i)
{
	long	t;

	pthread_mutex_lock(&d->print_lock);
	t = get_time() - d->t_start;
	d->die = 1;
	printf ("%ld Philo: %d died\n", t, d->philo[i].id + 1);
	pthread_mutex_unlock(&d->print_lock);
}

void	ft_free(t_data *data)
{
	free(data->forks);
	free(data->philo_thr);
	free(data->philo);
}

void	check_death(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n_philo)
	{
		pthread_mutex_lock(&d->print_lock);
		if (d->n_eat == d->philo[i].n_ate)
		{
			pthread_mutex_unlock(&d->print_lock);
			return ;
		}
		else if (get_time() - d->philo[i].t_lastmeal >= d->t_die)
		{
			pthread_mutex_unlock(&d->print_lock);
			ft_kill(d, i);
			return ;
		}
		else
			pthread_mutex_unlock(&d->print_lock);
	}
}

void	*monitor_death(void *d)
{
	t_data	*data;

	data = (t_data *)d;
	while (data->die != 1)
	{
		pthread_mutex_lock(&data->print_lock);
		if (data->all_ate == data->n_philo)
		{
			pthread_mutex_unlock(&data->print_lock);
			return (0);
		}
		else
			pthread_mutex_unlock(&data->print_lock);
		check_death(data);
	}
	return (0);
}
