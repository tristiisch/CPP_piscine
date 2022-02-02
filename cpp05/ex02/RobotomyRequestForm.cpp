/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:16 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:28:21 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 25, 5)  {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);
	std::srand(time(0));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "The robotization operation has failed on " <<  this->getTarget() << "." << std::endl;
}
