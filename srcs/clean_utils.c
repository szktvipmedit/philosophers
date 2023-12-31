
#include "../incs/philo.h"

void    mutex_destroy(pthread_mutex_t *ptr)
{
    if(pthread_mutex_destroy(ptr) != 0)
        pthread_mutex_unlock(ptr);
}

void	failed_on_the_way_free_philo_info(t_info *info, int i)
{
	--i;
	while (i >= 0)
	{
		free(info->philo_info[i]);
		i--;
	}
	free(info->philo_info[i]);
}

void	failed_on_the_way_mutex_forks_destroy(t_info *info, int i)
{
	--i;
	while (i >= 0)
	{
		mutex_destroy(&info->mutex_forks[i]);
		i--;
	}
	free(info->mutex_forks);
	free(info->forks);
}

void	failed_on_the_way_each_philo_info_mutex_destroy(t_info *info, int i,
		int is_eat_cnt)
{
	if (is_eat_cnt)
		mutex_destroy(&info->philo_info[i]->mutex_last_eat_time);
	--i;
	while (i >= 0)
	{
		mutex_destroy(&info->philo_info[i]->mutex_last_eat_time);
		mutex_destroy(&info->philo_info[i]->mutex_eat_cnt);
		i--;
	}
}
