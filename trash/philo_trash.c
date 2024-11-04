philos_routines :

// if (check_diner_status(current_philo) == DINER_IS_OVER)
		// 	return (NULL);

// usleep 50



static void	even_philo_is_eating(t_philo *philo)
{
	// philo_takes_left_fork(philo);
	// usleep(10);
	// philo_takes_right_fork(philo);
	even_philo_takes_forks(philo);
	philo_is_eating(philo);
	// philo_puts_left_fork(philo);
	// philo_puts_right_fork(philo);
	even_philo_puts_forks(philo);
}

static void odd_philo_is_eating(t_philo *philo)
{
	// philo_takes_right_fork(philo);
	// usleep(10);
	// philo_takes_left_fork(philo);
	odd_philo_takes_forks(philo);
	philo_is_eating(philo);
	// philo_puts_right_fork(philo);
	// philo_puts_left_fork(philo);
	odd_philo_puts_forks(philo);
}

//sleep tant que current - last_meal_time < time_to_eat


forks_usage.c :


// void	philo_puts_left_fork(t_philo *philo)
// {
// 	pthread_mutex_unlock(philo->left_fork);
// }

// void	philo_puts_right_fork(t_philo *philo)
// {
// 	pthread_mutex_unlock(philo->right_fork);
// }

// void	philo_takes_right_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->right_fork);
// 	philo_takes_the_microphone(philo);
// 	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
// 	philo_puts_back_the_microphone(philo);
// }

// void	philo_takes_left_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->left_fork);
// 	philo_takes_the_microphone(philo);
// 	philo_is_speaking(philo, PHILO_TAKES_A_FORK);
// 	philo_puts_back_the_microphone(philo);
// }
