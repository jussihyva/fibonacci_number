/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 06:51:06 by ubuntu            #+#    #+#             */
/*   Updated: 2020/05/26 01:18:39 by ubuntu           ###   ########.fr       */
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

static int	fib_rec_save_prev(size_t fib_nbr, unsigned long long nbr_1,
											unsigned long long nbr_2, size_t c)
{
	unsigned long long				fib_result;

	if (fib_nbr == 1 || fib_nbr == 2)
		return (1);
	else if (c < fib_nbr)
	{
		if (c == 1)
			nbr_1 = 0;
		else if (c == 2)
			nbr_1 = 1;
		fib_result = fib_rec_save_prev(fib_nbr, nbr_2 + nbr_1, nbr_1, c + 1);
	}
	else
		fib_result = nbr_2 + nbr_1;
	return (fib_result);
}

static int	fib_rec_mem(size_t fib_nbr)
{
	unsigned long long				fib_result;
	static unsigned long long		*res_array = NULL;
	static size_t					array_size = 0;

	if (array_size <= fib_nbr)
	{
		if (res_array)
			free(res_array);
		res_array = create_array(fib_nbr);
		array_size = fib_nbr;
	}
	if (res_array[fib_nbr])
		fib_result = res_array[fib_nbr];
	else
	{
		if (fib_nbr > 1)
			fib_result = fib_rec_mem(fib_nbr - 1) + fib_rec_mem(fib_nbr - 2);
		else if (fib_nbr == 1)
			fib_result = 1;
		else
			fib_result = 0;
		res_array[fib_nbr] = fib_result;
	}
	return (fib_result);
}

int			main(int argc, char **argv)
{
	unsigned long long		fib_result;
	size_t					nbr;
	size_t					fib_nbr;
	int						(*function_array[6])(size_t);

	function_array[1] = fib_rec;
	function_array[2] = fib_rec_mem;
	function_array[3] = fib_iterative;
	function_array[4] = fib_iterative_2;
	function_array[5] = fib_iterative_mem;
	if (argc == 3)
	{
		fib_nbr = ft_atoi(argv[1]);
		nbr = -1;
		while (++nbr <= fib_nbr)
		{
			if (ft_atoi(argv[2]) == e_fib_iterative_save_prev)
				fib_result = fib_rec_save_prev(nbr, 0, 0, 0);
			else
				fib_result = function_array[ft_atoi(argv[2])](nbr);
			ft_printf("%zu: %llu\n", nbr, fib_result);
		}
	}
	return (0);
}
