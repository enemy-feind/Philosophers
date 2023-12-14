/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:52:01 by rkristi           #+#    #+#             */
/*   Updated: 2021/08/18 10:25:49 by rkristi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mutno(t_set *u)
{
	int	n;
	int	st;

	n = 0;
	u->mtx = malloc(sizeof(pthread_mutex_t) * u->nop);
	if (!u->mtx)
	{
		write(1, "Fail to create a MUTEX.\n", 24);
		return ;
	}
	while (n < u->nop)
	{
		st = pthread_mutex_init(&u->mtx[n], NULL);
		if (st != 0)
		{
			write(1, "Fail to create a MUTEX.\n", 24);
			return ;
		}
		n++;
	}
	printf ("forks = %d\n", n);
}

void	sets(t_set *u, int n)
{
	u->p[n].curse = u->tdie;
	u->p[n].eat = u->teat;
	u->p[n].sleep = u->tsleep;
	u->p[n].meals = u->noes;
	u->p[n].death = u->death;
	u->p[n].life1 = 0;
}

void	cafedra(t_set *u)
{
	int	n;

	n = 0;
	u->p = malloc(sizeof(t_phil) * u->nop);
	if (!u->p)
	{
		write(1, "Fail to create a CAFEDRA.\n", 24);
		exit (-1);
	}
	while (n < u->nop)
	{
		u->p[n].n = n + 1;
		sets(u, n);
		u->p[n].ghost = &u->death;
		u->p[n].c = &u->curtain;
		u->p[n].left = &u->mtx[n];
		if (n == 0)
			u->p[n].right = &u->mtx[u->nop - 1];
		else
			u->p[n].right = &u->mtx[n - 1];
		if (u->p[n].left == u->p[n].right)
			u->p[n].right = NULL;
		n++;
	}
}
		// printf("ph = %ld     n =  %d\n", u->nop, n);
		// u->p[n].right = &u->mtx[n];
		// if (n + 1 == u->nop)
		// 	u->p[n].left = &u->mtx[0];
		// else
		// 	u->p[n].left = &u->mtx[n + 1];
// u->tdie = ph_atoi(argv[2]);
// u->teat = ph_atoi(argv[3]);
// u->tsleep = ph_atoi(argv[4]);
// u->noes = ph_atoi(argv[5]);
