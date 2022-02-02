/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 02:48:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "targetNoName", 25, 5)  {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)  {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &instance)
{
	*this = instance;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &instance)
{
	this->target = instance.getTarget();
	this->isSigne = instance.isSigned();
	this->requireLvlToSigned = instance.getRequireLvlToSigned();
	this->requireLvlToExecute = instance.getRequireLvlToExecute();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::cout << target << " was forgiven by Zaphod Beeblebrox." << std::endl;
}
