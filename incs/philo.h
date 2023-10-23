/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:23:36 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/10/23 16:54:45 by kousuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define INVALID_NUM_OF_ARG "Error : Invalid number of arguments\n"
# define INVALID_NUM_OF_ARG_CC 36
# define INVALID_VALUE_OF_ARG "Error : Invalid value of arguments\n"
# define INVALID_VALUE_OF_ARG_CC 36
# define INVALID_NUM_OF_PHILO "Error : num_of_philo must be \
less than or equal to INT_MAX\n"
# define INVALID_NUM_OF_PHILO_CC 59
# define FAILED_MUTEX_INIT "Error : Mutex initialization failed\n"
# define FAILED_MUTEX_INIT_CC 36
# define FAILED_PTHREAD_CREATE "Error : Pthread initialization failed\n"
# define FAILED_PTHREAD_CREATE_CC 38
# define FAILED_MALLOC "Error : malloc failed\n"
# define FAILED_MALLOC_CC 22

# define TRUE_ARG_CNT_DEFAULT 5
# define TRUE_ARG_CNT_OPTION 6
# define REFER_TO_ARRAY 3
# define MAX_NUM_FORKS_NEIGHBOR_HAS 2
# define DONT_HAVE -1
# define ARG_ERROR 1
# define MUTEX_ERROR 1
# define PTHREAD_ERROR 1
# define MALLOC_ERROR 1

struct	s_info;

typedef struct s_philo_info
{
	struct s_info	*info;
	pthread_t		th;
	size_t			id;
	size_t			eat_cnt;
	size_t			is_die;
	size_t			life;
	size_t			last_eat_time;

	int				fork1_id;
	int				fork2_id;
}					t_philo_info;

typedef struct s_info
{
	size_t			num_of_philo;
	size_t			num_of_each_philo_must_eat;
	int				is_someone_die;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				is_must_eat_option;
	size_t			is_all_thread_create;
	size_t			must_eat_philo_cnt;

	size_t			start_time;

	pthread_mutex_t	report_die_to_observer;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message_output_auth;
	t_philo_info	**philo_info;
}					t_info;

// libft_utils
size_t				ft_strlen(const char *s);
int					ft_isdigit(int i);
size_t				atos(char *str);
float				time_diff(struct timeval *start, struct timeval *end);
size_t				get_curr_time(void);
void				ft_usleep(size_t ms);

// read_args.c
int					not_admit_minus_or_char(int i, char **argv);
int					input_value_check(int argc, char **argv);
int					arg_error_check(int argc, char **argv);
int					read_input(t_info *info, int argc, char **argv);

// read_args_range.c
int					arg_range_check(char **argv, int i);
int					args_range_check(int argc, char **argv);

// init.c
int					create_forks(t_info *info);
void				store_info_arg_values(t_info *info, int argc, char **argv);
int					init_info_mutexes(t_info *info);
int					init_info(t_info *info, int argc, char **argv);

// init_philo_info.c
void				init_philo_info(t_info *info, t_philo_info *philo_info,
						int i);
int					create_philo_info(t_info *info);

// create_threads.c
int					create_thread_observer(t_info *info);
int					create_threads_philo(t_info *info);
int					create_threads(t_info *info);

// threads.c
void				observer_philo_survive(t_info *info);
void				observer_die_ditect(t_philo_info *philo_info);

// actions.c
void				forkid_init(t_philo_info *philo_info);
void				action_eat(t_philo_info *philo_info, int fork1_id,
						int fork2_id);
void				action_sleep(t_philo_info *philo_info);
void				action_think(t_philo_info *philo_info);
int					philo_life(t_philo_info *philo_info);

// actions_fork.c
void				get_fork1(t_philo_info *philo_info, int fork1_id);
void				get_fork2(t_philo_info *philo_info, int fork2_id);
void				take_fork(t_philo_info *philo_info, int fork1_id,
						int fork2_id);
void				put_fork(t_philo_info *philo_info, int fork1_id,
						int fork2_id);

// actions_output_message.c
void				output_message_get_fork(t_philo_info *philo_info);
void				output_message_eat(t_philo_info *philo_info);
void				output_message_sleep(t_philo_info *philo_info);
void				output_message_think(t_philo_info *philo_info);
void				output_message_die(t_info *info);

//main.c
void				free_philo_info(t_info *info);
void				failed_on_the_way_free_philo_info(t_info *info, int i);

//error.c
void				mutex_error(t_info *info);
#endif
