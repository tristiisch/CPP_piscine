/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:04:50 by tglory            #+#    #+#             */
/*   Updated: 2022/02/03 21:26:28 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : raw("42") {}

Convert::Convert(std::string name) : raw(name) {}

Convert::Convert(Convert const &instance) : raw(instance.getRaw())
{
	*this = instance;
}

Convert &Convert::operator=(Convert const &instance)
{
	(void)instance;
	return *this;
}

Convert::~Convert() {}

std::string Convert::getRaw() const
{
	return (this->raw);
}

void Convert::print() const
{
	char c = '*';
	int i = c;
	float f = c;
	double d = c;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}
