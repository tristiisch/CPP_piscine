/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 20:51:37 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Jacky");
	Form *form = new Form("Book", 50, 50);

	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;

	bureaucrat->signForm(*form);

	try
	{
		while (bureaucrat->getGrade() > HIGHEST_RANK)
		{
			bureaucrat->upGrade();
		}
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;
	bureaucrat->signForm(*form);
	std::cout << *form << std::endl;
	delete bureaucrat;
	delete form;
	return 0;
}
