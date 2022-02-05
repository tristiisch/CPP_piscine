/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:44:42 by tglory            #+#    #+#             */
/*   Updated: 2022/02/05 08:51:34 by tglory           ###   ########lyon.fr   */
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

# define RESET "\e[0m"
# define CYAN "\e[0;36m"

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\e[0;31measyfind::NotFoundException Value not found\e[0m");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator found = std::find(container.begin(), container.end(), number);
	if (found == container.end())
		throw NotFoundException();
	return (found);
}

#endif