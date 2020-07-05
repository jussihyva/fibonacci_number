/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 07:02:52 by ubuntu            #+#    #+#             */
/*   Updated: 2020/05/26 01:07:32 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIB_H
# define FIB_H
# include "libft.h"
# include "ft_printf.h"

typedef enum	e_cal_type
{
	e_fib_recursive = 1,
	e_fib_recursive_memory = 2,
	e_fib_iterative = 3,
	e_fib_iterative_2 = 4,
	e_fib_iterative_memory = 5,
	e_fib_iterative_save_prev = 6
}				t_cal_type;

unsigned long long			*create_array(size_t fib_nbr);
int							fib_iterative(size_t fib_nbr);
int							fib_iterative_mem(size_t fib_nbr);

#endif
