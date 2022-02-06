/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:48:17 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 16:07:46 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("nameless"), isSigne(false), requireLvlToSigned(LOWEST_RANK), requireLvlToExecute(LOWEST_RANK)  {}

Form::Form(std::string name) : name(name), isSigne(false), requireLvlToSigned(LOWEST_RANK), requireLvlToExecute(LOWEST_RANK)  {}

Form::Form(std::string name, int requireLvlToSigned, int requireLvlToExecute) : name(name), isSigne(false), requireLvlToSigned(requireLvlToSigned), requireLvlToExecute(requireLvlToExecute)
{
	if (this->requireLvlToSigned <= HIGHEST_RANK)
		throw Form::GradeTooHighException();
	if (this->requireLvlToSigned > LOWEST_RANK)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &instance) : name(name)
{
	this->isSigne = instance.isSigned();
	this->requireLvlToSigned = instance.getRequireLvlToSigned();
	this->requireLvlToExecute = instance.getRequireLvlToExecute();
	*this = instance;
}

Form &Form::operator=(Form const &instance)
{
	(void)instance;
	return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (this->isSigned())
		throw Form::FormAlreadySigned();
	if (requireLvlToSigned < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->isSigne = true;
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getRequireLvlToExecute() const
{
	return this->requireLvlToExecute;
}

int Form::getRequireLvlToSigned() const
{
	return this->requireLvlToSigned;
}

bool Form::isSigned() const
{
	return this->isSigne;
}

std::ostream &operator<<(std::ostream &outputFile, Form const &instance)
{
	outputFile << "Form " << instance.getName() << " is ";
	if (!instance.isSigned())
		outputFile << "not ";
	outputFile	<< "signed. Minimum lvl to signed : " << instance.getRequireLvlToSigned()
				<< " & minimum lvl to execute : " << instance.getRequireLvlToExecute() << ".";
	return outputFile;
}
