/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:37:22 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 18:41:01 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T &x, T &y)
{
	T temp;
	
	temp = x;
	x = y;
	y = temp;
}

template<typename T>
T const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template<typename T>
T const &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

#endif