/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:38:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 03:34:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

void test(std::string str)
{
	Converter *convert;

	convert = new Converter(str.c_str());
	convert->print();
	delete convert;
	std::cout << std::endl;
}

int main(void)
{
	test("A");
	test("!");
	test("0");
	test("42");
	test("-42");

	// test("nan");
	// test("42.0f");

	// test("-inff");
	// test("+inff");
	// test("nanf");

	// test("-inf");
	// test("+inf");
	// test("nan");
	return 0;
}


