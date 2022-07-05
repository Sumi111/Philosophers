/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:13:58 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 14:09:44 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	one_philo(t_data *data)
{
	long	t;

	data->t_start = get_time();
	usleep(data->t_die * 1000);
	t = get_time() - data->t_start;
	printf("%ld Philo:%d died\n", t, 1);
	return ;
}

void	ft_start(t_data *data)
{
	int	i;

	i = 0;
	data->t_start = get_time();
	while (i < data->n_philo)
	{
		data->philo[i].t_lastmeal = data->t_start;
		pthread_create(&data->philo_thr[i], NULL,
			&ft_routine, (void *)&data->philo[i]);
		usleep(100);
		i++;
	}
	monitor_death(data);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philo_thr[i], NULL);
		i++;
	}
}
