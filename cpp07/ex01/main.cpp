/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:31:44 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 11:37:30 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

int main(void)
{
	int size;

	int ints[] = {42, 69, 74, 87, 199};
	size = sizeof(ints) / sizeof(*ints);
	iter(ints, size, display);
	std::cout << std::endl << std::endl;

	float floats[] = {42.8f, 74.0f, 199.9f, 87.5f, 69.1f};
	size = sizeof(floats) / sizeof(*floats);
	iter(floats, size, display);
	std::cout << std::endl << std::endl;

	double doubles[] = {42.88, 74.66, 199.99, 87.55, 69.11};
	size = sizeof(doubles) / sizeof(*doubles);
	iter(doubles, size, display);
	std::cout << std::endl << std::endl;

	bool bools[] = {false, true};
	size = sizeof(bools) / sizeof(*bools);
	iter(bools, size, display);
	std::cout << std::endl << std::endl;

	char string[] = "You should give me outstanding !!!";
	size = sizeof(string) / sizeof(*string);
	iter(string, size, displayString);
	std::cout << std::endl << std::endl;

	std::string strings[] = {"Hello", "world", "template"};
	size = sizeof(strings) / sizeof(*strings);
	iter(strings, size, display);
	std::cout << std::endl;

	return (0);
}
