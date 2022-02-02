/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:10 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 18:08:08 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *matt = new Bureaucrat("Matt");
	Bureaucrat *jacky;
	Form *form = new Form("Book", 50, 75);

	std::cout << *matt << std::endl;
	std::cout << *form << std::endl;
	matt->signForm(*form);

	jacky = new Bureaucrat("Jacky", 150);
	std::cout << *jacky << std::endl;
	std::cout << *form << std::endl;
	jacky->signForm(*form);

	std::cout << *form << std::endl;
	jacky->signForm(*form);

	delete jacky;
	delete form;
	return 0;
}
