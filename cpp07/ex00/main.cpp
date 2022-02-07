/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:45:13 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 10:31:04 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int i1 = 2;
	int i2 = 3;
	std::cout << "int1 = " << i1 << std::endl;
	std::cout << "int2 = " << i2 << std::endl;
	::swap(i1, i2);
	std::cout << "int1 = " << i1 << std::endl;
	std::cout << "int2 = " << i2 << std::endl;
	std::cout << "min = " << ::min(i1, i2) << std::endl;
	std::cout << "max = " << ::max(i1, i2) << std::endl;
	std::cout << std::endl;

	std::string s1 = "chaine1";
	std::string s2 = "chaine2";
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "min = " << ::min(s1, s2) << std::endl;
	std::cout << "max = " << ::max(s1, s2) << std::endl;
	return 0;
}
