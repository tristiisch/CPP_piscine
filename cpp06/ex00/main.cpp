/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:38:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/03 21:26:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void print(char c)
{
	int i = c;
	float f = c;
	double d = c;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "First arguement is require" << std::endl;
		return 1;
	}
	Convert convert(argv[1]);

	convert.print();
	return 0;
}
