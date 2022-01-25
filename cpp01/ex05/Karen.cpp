/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:11:32 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 19:40:44 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen::complain(std::string level) 
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Karen::*f[4]) () = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			break ;
		}
	}
}

void Karen::debug(void)
{
	std::cout << C_CYAN << "DEBUG > ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << C_RESET << std::endl;
}

void Karen::info(void)
{
	std::cout << C_GREEN << "INFO > ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! " \
	"If you did, I wouldn’t be asking for more!";
	std::cout << C_RESET << std::endl;
}

void Karen::warning(void)
{
	std::cout << C_YELLOW << "WARNING > ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just " \
	"started working here last month.";
	std::cout << C_RESET << std::endl;
}

void Karen::error(void)
{
	std::cout << C_RED << "ERROR > ";
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << C_RESET << std::endl;
}
