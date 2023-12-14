/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 06:49:40 by rkristi           #+#    #+#             */
/*   Updated: 2021/08/18 11:00:34 by rkristi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	physiology(t_phil *f)
{
	printf("%zu №-%d has taken a R fork\n", f->life2, f->n);
	printf("%zu №-%d is eating\n", f->life2, f->n);
	food(f);
	f->life1 = f->life2;
	f->life_d = 0;
	alien_sleep(f->eat * 1000);
	pthread_mutex_unlock(f->left);
	pthread_mutex_unlock(f->right);
	if (tik_tok(f, 4) < 0)
		return ;
	printf("%zu №-%d is sleeping\n", f->life2, f->n);
	alien_sleep(f->sleep * 1000);
	if (tik_tok(f, 5) < 0)
		return ;
}

void	person(t_phil *f)
{
	while (*f->c == 1)
		;
	prsn_start(f);
	if ((f->n % 2) == 0)
		usleep(100);
	while (f->death == 0)
	{
		if (tik_tok(f, 1) < 0)
			return ;
		if (pthread_mutex_lock(f->left) == 0)
		{
			if (tik_tok(f, 2) < 0)
				return ;
			printf("%zu №-%d has taken a L fork\n", f->life2, f->n);
		}
		if ((!f->right) || (pthread_mutex_lock(f->right) != 0))
		{
			pthread_mutex_unlock(f->left);
			printf("%zu №-%d has dropped a L fork\n", f->life2, f->n);
		}
		else
			physiology(f);
		printf("%zu №-%d is thinking\n", f->life2, f->n);
	}
}

void	carousel(t_set *u)
{
	int				n;
	int				st;

	st = 0;
	n = 0;
	u->tid = malloc(sizeof(pthread_t) * u->nop);
	if (!u->tid)
		return ;
	while (n < u->nop)
	{
		u->n = n;
		st = pthread_create(&u->tid[n], NULL, (void *)person, &u->p[n]);
		if (st != 0)
		{
			write(1, "Fail to create a THREAD.\n", 25);
			return ;
		}
		n++;
	}
}

void	start(t_set *u)
{
	int				n;

	mutno(u);
	cafedra(u);
	carousel(u);
	n = 0;
	u->curtain = 0;
	while ((u->death == 0) && (u->noes_nop != 0))
	{
		sweats(u, n);
		n++;
		if (n == u->nop)
			n = 0;
	}
	if (u->noes_nop == 0)
		write(1, "\nDinner is over. Everyone is fed.\n\n", 35);
}
	// int				st;
	// pthread_t		*tid;
	// tid = malloc(sizeof(pthread_t) * u->nop);
	// if (!tid)
	// 	return ;
	// n = 0;
	// while (n < u->nop)
	// {
	// 	u->n = n;
	// 	st = pthread_create(&tid[n], NULL, (void *)person, &u->p[n]);
	// 	if (st != 0)
	// 	{
	// 		write(1, "Fail to create a THREAD.\n", 25);
	// 		return ;
	// 	}
	// 	n++;
	// }
