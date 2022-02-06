/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:01:28 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 15:08:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T array[], int const len, void f(T const &param))
{
	int i = 0;
	while (i < len)
		f(array[i++]);
}

template<typename T>
void display(T const &value)
{
	std::cout << value << " ";
}

template<typename T>
void displayString(T const &value)
{
	std::cout << value;
}

#endif