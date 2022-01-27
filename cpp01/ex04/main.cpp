/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:59:01 by tglory            #+#    #+#             */
/*   Updated: 2022/01/27 18:36:36 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <sstream>

/**
 * @brief Copy src into dest with replace all occurrence of s1 by s2
 */
void ft_replace(std::ifstream &src, std::ofstream &dest, std::string s1, std::string s2)
{
	size_t indexOccurrence;
	std::string str;
	std::ostringstream fileContentStream;

	fileContentStream << src.rdbuf();
	str = fileContentStream.str();
	do {
		indexOccurrence = str.find(s1);
		if (indexOccurrence == std::string::npos)
			break ;
		str.erase(indexOccurrence, s1.length());
		str.insert(indexOccurrence, s2);
	} while (true);
	dest << str;
}

int ft_check_args(int argc, char const *argv[])
{
	if (argc < 4)
	{
		std::cout << "Usage : <filename> <s1> <s2>." << std::endl;
		return (1);
	}
	if (!std::string(argv[2]).size())
	{
		std::cout << "Argument <s1>, the n°2 is empty." << std::endl;
		return (2);
	}
	if (!std::string(argv[3]).size())
	{
		std::cout << "Argument <s2>, the n°3 is empty." << std::endl;
		return (3);
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	std::string s1;
	std::string s2;
	std::string fileName;
	std::string destName;
	std::ifstream src;
	std::ofstream dest;
	int ret;

	if ((ret = ft_check_args(argc, argv)) != 0)
		return (ret);
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	src.open(fileName);
	if (src.fail())
	{
		std::cout << "Can't open file '" << fileName << "'." << std::endl;
		return (4);
	}
	destName = fileName + ".replace";
	dest.open(destName);
	if (dest.fail())
	{
		src.close();
		std::cout << "Can't create or open file '" << destName << "'." << std::endl;
		return (5);
	}
	ft_replace(src, dest, s1, s2);
	src.close();
	dest.close();
	return (0);
}
