/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:20:09 by ubuntu            #+#    #+#             */
/*   Updated: 2020/05/25 23:21:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fib.h"

unsigned long long			*create_array(size_t fib_nbr)
{
	unsigned long long		*res_array;

	res_array = (unsigned long long *)ft_memalloc(sizeof(*res_array) *
																(fib_nbr + 1));
	return (res_array);
}
