/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:29:23 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 16:26:53 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

static std::string getRandomChars(size_t length)
{
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
	}
	return (out);
}

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = getRandomChars(1000);
		//std::cout << this->ideas[i] << std::endl;
	}
	std::cout << "Bain created." << std::endl;
}

Brain::Brain(Brain const& instance)
{
	*this = instance;
}

Brain::~Brain(void)
{
	std::cout << "Bain destroyed." << std::endl;
}

void Brain::operator=(Brain const &instance)
{
	for(int i = 0; i < 100; i++)
		this->ideas[i] = instance.ideas[i];
}

