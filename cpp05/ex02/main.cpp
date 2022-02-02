/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:10 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 18:44:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

static void defaultTest(Bureaucrat *bureaucrat, AForm *form)
{
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->signForm(*form);
		bureaucrat->execute(*form);
	} catch (std::exception &e) {
		std::cout << "Unable to execute form : " << e.what() << std::endl;
	}
	delete form;
}

static void executeWithoutSigned(Bureaucrat *bureaucrat, AForm *form)
{
	std::cout << *form << std::endl;
	try
	{
		bureaucrat->execute(*form);
	} catch (std::exception &e) {
		std::cout << "Unable to execute form : " << e.what() << std::endl;
	}
	delete form;
}

static void testBureaucrat(Bureaucrat *bureaucrat, void (*f)(Bureaucrat *, AForm *))
{
	AForm *form;

	form = new RobotomyRequestForm("Elon");
	f(bureaucrat, form);

	form = new ShrubberyCreationForm("Foo");
	f(bureaucrat, form);

	form = new PresidentialPardonForm("Bar");
	f(bureaucrat, form);

	delete bureaucrat;
}


int main()
{
	Bureaucrat *bureaucrat;

	bureaucrat = new Bureaucrat("Jacky", 1);
	testBureaucrat(bureaucrat, defaultTest);

	bureaucrat = new Bureaucrat("Jason", 1);
	testBureaucrat(bureaucrat, executeWithoutSigned);

	bureaucrat = new Bureaucrat("Joe", 150);
	testBureaucrat(bureaucrat, defaultTest);

	return 0;
}
