/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:10 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:44:41 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void defaultTest(Bureaucrat *bureaucrat, AForm *form)
{
	std::cout << *form << std::endl;
	try
	{
		while (bureaucrat->getGrade() > form->getRequireLvlToSigned())
		{
			bureaucrat->upGrade();
		}
		while (bureaucrat->getGrade() > form->getRequireLvlToExecute())
		{
			bureaucrat->upGrade();
		}
		bureaucrat->signForm(*form);
		bureaucrat->execute(*form);
	} catch (std::exception &e) {
		std::cout << "Unable to execute form : " << e.what() << std::endl;
	}
	delete form;
}

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("Jacky");
	AForm *form;

	form = new RobotomyRequestForm("Elon");
	defaultTest(bureaucrat, form);

	form = new ShrubberyCreationForm("Foo");
	defaultTest(bureaucrat, form);

	form = new PresidentialPardonForm("Bar");
	defaultTest(bureaucrat, form);

	delete bureaucrat;
	return 0;
}
