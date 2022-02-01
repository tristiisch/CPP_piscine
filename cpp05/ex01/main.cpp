/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 23:25:15 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Jacky");
	Form *form = new Form("Book", 50, 75);

	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;
	bureaucrat->signForm(*form);

	try
	{
		while (bureaucrat->getGrade() > form->getRequireLvlToSigned())
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
	bureaucrat->signForm(*form);

	delete bureaucrat;
	delete form;
	return 0;
}
