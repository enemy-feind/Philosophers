/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:23:01 by rkristi           #+#    #+#             */
/*   Updated: 2021/08/18 10:59:23 by rkristi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct s_phil
{
	int				n;
	long			life1;
	long			life2;
	long			life_d;

	int				meals;
	long			curse;
	long			eat;
	long			sleep;

	int				*ghost;	

	int				death;
	int				desert;

	long			nop;

	int				*c;

	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}				t_phil;
	// long			*nop;

typedef struct s_set
{
	long			nop;
	long			noes_nop;
	long			tdie;
	long			teat;
	long			tsleep;
	long			noes;

	t_phil			*p;
	pthread_mutex_t	*mtx;
	pthread_t		*tid;

	int				death;

	int				n;

	int				curtain;
}				t_set;
// nop - Number Of Philosophers
// tdie - Time to Die
// teat - Time to Eat
// tsleep - Time to Sleep
// noes - Number Of Eat Slots

void	start(t_set *u);
void	mutno(t_set *u);
void	cafedra(t_set *u);

// int		tik_tok(t_phil *f);
int		tik_tok(t_phil *f, int n);
void	food(t_phil *f);
void	sweats(t_set *u, int n);

void	for_prsn(t_set *u, t_phil *f);
void	prsn_start(t_phil *f);

void	alien_sleep(int n);

#endif