/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:16 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:19:40 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "targetNoName", 25, 5)  {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 25, 5)  {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &instance)
{
	*this = instance;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &instance)
{
	this->target = instance.getTarget();
	this->isSigne = instance.isSigned();
	this->requireLvlToSigned = instance.getRequireLvlToSigned();
	this->requireLvlToExecute = instance.getRequireLvlToExecute();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::srand(time(0));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized." << std::endl;
	else
		std::cout << "The robotization operation has failed on " <<  this->target << "." << std::endl;
}
