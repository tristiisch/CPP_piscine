/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:07:16 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 01:19:57 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Karen.hpp"

int main(int argc, const char *argv[])
{
    Karen karen;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc < 2)
	{
		std::cout << C_RED << "Usage > ./karenFilter <DEBUG|INFO|WARNING|ERROR>" << C_RESET << std::endl;
		return (1);
	}
    int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if ((std::string)argv[1] == levels[i])
		{
            index = i;
			break ;
		}
	}
    switch (index)
	{
        case 0:
            karen.complain("DEBUG");
        case 1:
            karen.complain("INFO");
        case 2:
            karen.complain("WARNING");
        case 3:
            karen.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
	}
	return (0);
}
