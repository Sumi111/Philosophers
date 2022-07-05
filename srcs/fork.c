/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:28:10 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 13:07:20 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	odd_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->die != 1)
	{
		pthread_mutex_unlock(&philo->data->print_lock);
		if (!pthread_mutex_lock(&philo->data->forks[philo->left_fork]))
		{
			philo->right_lock = 1;
			ft_print(philo, "has taken a fork");
		}
		if (philo->right_lock == 1
			&& !pthread_mutex_lock(&philo->data->forks[philo->right_fork]))
		{
			philo->left_lock = 1;
			ft_print(philo, "has taken a fork");
		}
	}
}

void	even_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->die != 1)
	{
		pthread_mutex_unlock(&philo->data->print_lock);
		if (!pthread_mutex_lock(&philo->data->forks[philo->right_fork]))
		{
			philo->left_lock = 1;
			ft_print(philo, "has taken a fork");
		}
		if (philo->left_lock == 1
			&& !pthread_mutex_lock(&philo->data->forks[philo->left_fork]))
		{
			philo->right_lock = 1;
			ft_print(philo, "has taken a fork");
		}
	}
}

void	get_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		odd_philo(philo);
	else
		even_philo(philo);
}
