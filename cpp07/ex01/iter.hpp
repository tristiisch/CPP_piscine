/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:01:28 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 19:03:51 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T array[], int const len, void f(T &param))
{
	int i = 0;
	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

template<typename T>
void function(T &param)
{
	if ((param >= 65 && param <= 90) || (param >= 97 && param <= 122))
		param -= 32;
}

#endif