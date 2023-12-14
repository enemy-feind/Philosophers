/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkristi <rkristi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:01:56 by rkristi           #+#    #+#             */
/*   Updated: 2021/08/18 10:17:47 by rkristi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	numb(char *arg)
{
	while (*arg)
	{
		if ((*arg < '0') || (*arg > '9'))
			return (-1);
		arg++;
	}
	return (1);
}

int	ph_atoi(char *arg)
{
	int		n;

	n = 0;
	while (*arg)
	{
		n = (n * 10) + (*arg - 48);
		arg++;
	}
	return (n);
}

void	setup(char **argv, t_set *u, int argc)
{
	int		n;

	n = 0;
	u->nop = ph_atoi(argv[1]);
	u->tdie = ph_atoi(argv[2]);
	u->teat = ph_atoi(argv[3]);
	u->tsleep = ph_atoi(argv[4]);
	if (argc == 6)
		u->noes = ph_atoi(argv[5]);
	else
		u->noes = -1;
	u->noes_nop = u->nop;
	u->death = 0;
	u->curtain = 1;
}
	// if (u->nop < 2)
	// {
	// 	write(1, "Need more people, for valid experiment.\n", 40);
	// 	exit (-1);
	// }

int	arg_val(int argc, char **argv, t_set *u)
{
	int		i;

	i = 1;
	if ((argc < 5) || (argc > 6))
	{
		write (1, "Wrong number of arguments.\n", 26);
		return (-1);
	}
	while (argv[i])
	{
		if (numb(argv[i]) != 1)
		{
			write(1, "Try valid arguments next time.\n", 31);
			return (-1);
		}
		i++;
	}
	setup(argv, u, argc);
	return (1);
}

int	main(int argc, char **argv)
{
	t_set	u;

	if (arg_val(argc, argv, &u) != 1)
		return (-1);
	start(&u);
	return (0);
}
