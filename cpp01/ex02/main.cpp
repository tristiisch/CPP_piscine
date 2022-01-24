/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:02:28 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 15:11:41 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
	// Init vars
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	// Print adress
	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	// Print values
	std::cout << str << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return 0;
}
