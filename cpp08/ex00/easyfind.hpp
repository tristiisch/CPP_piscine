/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:44:42 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 22:17:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <list>
# include <set>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\e[0;31measyfind::NotFoundException > Value not found\e[0m");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

template<typename T>
void printResult(T container, int tryToFind)
{
	typename T::iterator itTmp;

	itTmp = container.begin();
	while (itTmp != container.end())
		std::cout << *itTmp++ << " ";
	std::cout << std::endl;
	std::cout << "try easyFind " << tryToFind << " : ";
	try
	{
		itTmp = easyfind(container, tryToFind);
		std::cout << "found " << *itTmp << " - ";
		std::cout << "at index " << std::distance(container.begin(), itTmp) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

#endif