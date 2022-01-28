/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:29:23 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 02:14:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>
#include <limits>


std::string getRandomChars(size_t length)
{
	// static std::string *cache;

	// if (cache)
		// return (*cache);
	size_t outSize = (rand() % (length - 10)) + 10;
	std::string out(outSize, 'x');
	for (size_t i = 0; i < outSize; ++i)
	{
		int randomChar = rand() % (26 + 26 + 10);
		if (randomChar < 26)
			out[i] = 'a' + randomChar;
		else if (randomChar < 26 + 26)
			out[i] = 'A' + randomChar - 26;
		else
			out[i] = '0' + randomChar - 26 - 26;
		// std::cout << i << std::endl;
	}
	// cache = &out;
	return (out);
}

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = getRandomChars(100000);
		// this->ideas[i] = getRandomChars(std::numeric_limits<int>::max());
		// std::cout << this->ideas[i] << std::endl;
	}
}

Brain::Brain(Brain const& instance)
{
	*this = instance;
}

Brain::~Brain(void) {}

void Brain::operator=(Brain const &instance)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = instance.ideas[i];
}

