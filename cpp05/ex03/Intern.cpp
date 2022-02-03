/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:25:04 by tglory            #+#    #+#             */
/*   Updated: 2022/02/03 03:08:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &instance)
{
	*this = instance;
}

Intern &Intern::operator=(Intern const &instance)
{
	(void)instance;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
	int index = -1;
	std::string formNames[] = {"presidential pardon", "robotomy request", "shruberry creation"};
	int formSize = sizeof(formNames) / sizeof(formNames[0]);

	for (int i = 0; i < formSize; ++i)
	{
		if (formNames[i] == formName)
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			throw Intern::UnknownForm();
	}
}
