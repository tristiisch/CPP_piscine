/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:59:01 by tglory            #+#    #+#             */
/*   Updated: 2022/01/24 18:05:10 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int main(int argc, char const *argv[])
{
	std::string filename, s1, s2;
	std::ifstream src;
	std::ofstream dest;

	if (argc < 4)
	{
		std::cout << "Usage : <filename> <s1> <s2>." << std::endl;
		return (1);
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	src.open(argv[1], std::ios::binary);
	if (!src.is_open())
	{
		std::cout << "Can't open file '" << argv[1] << "'." << std::endl;
		return (1);
	}
	
	std::string destName = argv[1];
	destName.append(".replace");

	dest.open(destName.c_str(), std::ios::binary);
	if (!dest.is_open())
	{
		std::cout << "Can't open file '" << destName << "'." << std::endl;
		return (1);
	}
	dest << src.rdbuf();

	dest.close();
	src.close();
	return (0);
}
