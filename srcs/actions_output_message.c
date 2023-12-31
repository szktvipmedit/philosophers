/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_output_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:14:26 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/10/23 15:26:20 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	output_message_get_fork(t_philo_info *philo_info)
{
	pthread_mutex_lock(&philo_info->info->message_output_auth);
	if (check_is_someone_die(philo_info))
		printf("%zu %zu has taken a fork\n", get_curr_time()
			- philo_info->info->start_time, philo_info->id);
	pthread_mutex_unlock(&philo_info->info->message_output_auth);
}

void	output_message_eat(t_philo_info *philo_info)
{
	pthread_mutex_lock(&philo_info->info->message_output_auth);
	if (check_is_someone_die(philo_info))
		printf("%zu %zu is eating\n", get_curr_time()
			- philo_info->info->start_time, philo_info->id);
	pthread_mutex_unlock(&philo_info->info->message_output_auth);
}

void	output_message_sleep(t_philo_info *philo_info)
{
	pthread_mutex_lock(&philo_info->info->message_output_auth);
	if (check_is_someone_die(philo_info))
		printf("%zu %zu is sleeping\n", get_curr_time()
			- philo_info->info->start_time, philo_info->id);
	pthread_mutex_unlock(&philo_info->info->message_output_auth);
}

void	output_message_think(t_philo_info *philo_info)
{
	pthread_mutex_lock(&philo_info->info->message_output_auth);
	if (check_is_someone_die(philo_info))
		printf("%zu %zu is thinking\n", get_curr_time()
			- philo_info->info->start_time, philo_info->id);
	pthread_mutex_unlock(&philo_info->info->message_output_auth);
}

void	output_message_die(t_info *info)
{
	pthread_mutex_lock(&info->message_output_auth);
	pthread_mutex_lock(&info->report_die_to_observer);
	printf("%zu %d died\n", get_curr_time() - info->start_time,
		info->is_someone_die);
	pthread_mutex_unlock(&info->report_die_to_observer);
	pthread_mutex_unlock(&info->message_output_auth);
}
