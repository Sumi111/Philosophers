/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:07:55 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 13:11:58 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_error(char *str)
{
	printf("ERROR: %s\nTry again!!\n", str);
	return (-42);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while ((str[i] >= '9' && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-42);
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (n > 2147483647)
		return (-42);
	return (n);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long t, t_data *data)
{
	long long	n;
	long long	m;

	n = get_time();
	while (data->die != 1 && data->all_ate < data->n_philo)
	{
		m = get_time();
		if (m - n >= t)
			break ;
		usleep(100);
	}
}
