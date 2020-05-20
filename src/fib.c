/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 06:51:06 by ubuntu            #+#    #+#             */
/*   Updated: 2020/05/20 09:09:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fib.h"

static int	fib_rec(size_t fib_nbr)
{
	unsigned long long		fib_result;

	if (fib_nbr > 1)
		fib_result = fib_rec(fib_nbr - 1) + fib_rec(fib_nbr - 2);
	else if (fib_nbr == 1)
		fib_result = 1;
	else
		fib_result = 0;
	return (fib_result);
}

static int	fib_iterative(size_t fib_nbr)
{
	unsigned long long		fib_result;
	size_t					nbr;
	size_t					next_nbr_2;
	size_t					nbr_2;

	fib_result = 0;
	nbr_2 = 0;
	nbr = -1;
	while (++nbr <= fib_nbr)
	{
		next_nbr_2 = fib_result;
		if (nbr > 1)
			fib_result += nbr_2;
		else if (nbr == 1)
			fib_result += 1;
		else
			fib_result = 0;
		nbr_2 = next_nbr_2;
	}
	return (fib_result);
}

static int	fib_iterative_mem(size_t fib_nbr, unsigned long long *fib_result_array)
{
	unsigned long long		fib_result;
	size_t					nbr;

	nbr = -1;
	fib_result = 0;
	while (++nbr <= fib_nbr)
	{
		if (nbr > 1)
			fib_result += fib_result_array[nbr - 2];
		else if (nbr == 1)
			fib_result += 1;
		else
			fib_result = 0;
		fib_result_array[nbr] = fib_result;
	}
	return (fib_result);
}

static int	fib_rec_mem(size_t fib_nbr, unsigned long long *fib_result_array)
{
	unsigned long long				fib_result;

	if (fib_result_array[fib_nbr])
		fib_result = fib_result_array[fib_nbr];
	else
	{
		if (fib_nbr > 1)
			fib_result = fib_rec_mem(fib_nbr - 1, fib_result_array) +
									fib_rec_mem(fib_nbr - 2, fib_result_array);
		else if (fib_nbr == 1)
			fib_result = 1;
		else
			fib_result = 0;
		if (fib_nbr && fib_result_array[fib_nbr - 1] > fib_result)
			fib_result = 0;
		fib_result_array[fib_nbr] = fib_result;
	}
	return (fib_result);
}

int			main(int argc, char **argv)
{
	unsigned long long		fib_result;
	unsigned long long		*fib_result_array;
	size_t					nbr;
	size_t					fib_nbr;

	fib_result = 0;
	if (argc == 3)
	{
		fib_nbr = ft_atoi(argv[1]);
		fib_result_array =
				(unsigned long long *)ft_memalloc(sizeof(*fib_result_array) *
																(fib_nbr + 1));
		nbr = -1;
		while (++nbr <= fib_nbr)
		{
			if (ft_atoi(argv[2]) == 1)
				fib_result = fib_rec(nbr);
			if (ft_atoi(argv[2]) == 2)
				fib_result = fib_rec_mem(nbr, fib_result_array);
			if (ft_atoi(argv[2]) == 3)
				fib_result = fib_iterative(nbr);
			if (ft_atoi(argv[2]) == 4)
				fib_result = fib_iterative_mem(nbr, fib_result_array);
			ft_printf("%zu: %llu\n", nbr, fib_result);
		}
	}
	return (0);
}
