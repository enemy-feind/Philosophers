/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:51:51 by rkristi           #+#    #+#             */
/*   Updated: 2021/08/18 06:07:34 by rkristi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	tik_tok(t_phil *f, int n)
// int	tik_tok(t_phil *f)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	f->life2 = tm.tv_sec * 1000 + tm.tv_usec / 1000;
	f->life_d = f->life2 - f->life1;
	if (f->life_d > f->curse)
	{
		printf("\n№-%d 1 %zu 2 %zu D = %ld [№-%d %d]\n",
			f->n, f->life2, f->life1, f->life_d, f->n, n);
		printf("\n%zu №-%d died\n\n", f->life2, f->n);
		*f->ghost = 1;
		f->death = 1;
		return (-1);
	}
	return (1);
}

void	prsn_start(t_phil *f)
{
	struct timeval	tm;

	gettimeofday(&tm, NULL);
	f->life2 = tm.tv_sec * 1000 + tm.tv_usec / 1000;
	f->life1 = f->life2;
	f->life_d = f->life_d + (f->life2 - f->life1);
}

void	food(t_phil *f)
{
	if (f->meals != 0)
	{
		f->meals = f->meals - 1;
		if (f->meals == 0)
			f->desert = 1;
	}
}
			// printf ("~~~~~     №%d       MEALS = %d!!!\n", f->n, f->meals);

void	sweats(t_set *u, int n)
{
	if (u->p[n].desert == 1)
	{
		u->noes_nop = u->noes_nop - 1;
		u->p[n].desert = 0;
	}
}

void	alien_sleep(int n)
{
	struct timeval	t1;
	struct timeval	t2;

	gettimeofday(&t1, NULL);
	while (n)
	{
		usleep(50);
		gettimeofday(&t2, NULL);
		if (((t2.tv_sec - t1.tv_sec) * 1000 * 1000
				+ (t2.tv_usec - t1.tv_usec)) > n)
			break ;
	}
}
