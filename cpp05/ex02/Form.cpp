/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:48:17 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 23:24:23 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("nameless"), isSigne(false), requireLvlToSigned(LOWEST_RANK), requireLvlToExecute(LOWEST_RANK)  {}

Form::Form(std::string name) : name(name), isSigne(false), requireLvlToSigned(LOWEST_RANK), requireLvlToExecute(LOWEST_RANK)  {}

Form::Form(std::string name, int requireLvlToSigned, int requireLvlToExecute) : name(name), isSigne(false), requireLvlToSigned(requireLvlToSigned), requireLvlToExecute(requireLvlToExecute) {}

Form::Form(Form const &instance)
{
	*this = instance;
}

Form &Form::operator=(Form const &instance)
{
	this->name = instance.getName();
	this->isSigne = instance.isSigned();
	this->requireLvlToSigned = instance.getRequireLvlToSigned();
	this->requireLvlToExecute = instance.getRequireLvlToExecute();
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
	outputFile << "signed. The minimum lvl to signed is " << instance.getRequireLvlToSigned() << " and the minimum lvl to execute is " << instance.getRequireLvlToExecute() << ".";
	return outputFile;
}
