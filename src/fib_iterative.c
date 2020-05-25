/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib_iterative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:06:02 by ubuntu            #+#    #+#             */
/*   Updated: 2020/05/26 01:08:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fib.h"

int			fib_iterative(size_t fib_nbr)
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

int			fib_iterative_mem(size_t fib_nbr)
{
	unsigned long long				fib_result;
	unsigned long long				*res_array;
	size_t							nbr;

	res_array = create_array(fib_nbr);
	nbr = -1;
	fib_result = 0;
	while (++nbr <= fib_nbr)
	{
		if (nbr > 1)
			fib_result += res_array[nbr - 2];
		else if (nbr == 1)
			fib_result += 1;
		else
			fib_result = 0;
		res_array[nbr] = fib_result;
	}
	return (fib_result);
}
