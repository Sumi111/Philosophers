/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:01:44 by sfathima          #+#    #+#             */
/*   Updated: 2022/07/04 13:25:41 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				n_ate;
	int				left_fork;
	int				right_fork;
	int				left_lock;
	int				right_lock;
	long long		t_lastmeal;
}	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				all_ate;
	int				die;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	pthread_t		*philo_thr;
	t_philo			*philo;
	long long		t_start;
}	t_data;

int		check_arg(int argc, char **argv);
int		another_check(t_data *data, int n);
int		get_argc(t_data *data, int argc, char **argv);

int		ft_isdigit(char c);
int		ft_atoi(char *str);
int		ft_error(char *str);

long	get_time(void);
void	ft_print(t_philo *ph, char *str);
void	ft_usleep(long t, t_data *data);
void	ft_free(t_data *data);

void	init_fork(t_data *data);
void	init_philo(t_data *data);
int		ft_init(t_data *data);

void	get_fork(t_philo *philo);
void	ft_eat(t_philo *ph);

void	one_philo(t_data *data);
void	ft_start(t_data *data);
void	*ft_routine(void *d);
void	*monitor_death(void *d);

#endif