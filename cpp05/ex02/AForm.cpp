/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:48:17 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 01:59:40 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("nameless"), isSigne(false), requireLvlToSigned(LOWEST_RANK), requireLvlToExecute(LOWEST_RANK)  {}

AForm::AForm(std::string name, std::string target, int requireLvlToSigned, int requireLvlToExecute) : name(name),
	target(target), isSigne(false), requireLvlToSigned(requireLvlToSigned), requireLvlToExecute(requireLvlToExecute) {}

AForm::AForm(AForm const &instance)
{
	this->target = instance.getName();
	*this = instance;
}

AForm &AForm::operator=(AForm const &instance)
{
	this->name = instance.getName();
	this->target = instance.getName();
	this->isSigne = instance.isSigned();
	this->requireLvlToSigned = instance.getRequireLvlToSigned();
	this->requireLvlToExecute = instance.getRequireLvlToExecute();
	return *this;
}

AForm::~AForm() {}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (this->isSigned())
		throw AForm::FormAlreadySigned();
	if (this->requireLvlToSigned < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->isSigne = true;
}

void AForm::canExecute(Bureaucrat const &bureaucrat) const
{
	if (!this->isSigned())
		throw AForm::NoSignatureException();
	if (this->requireLvlToExecute < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}

void AForm::canSigne(Bureaucrat const &bureaucrat) const
{
	if (this->requireLvlToSigned < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return this->name;
}

std::string AForm::getTarget() const
{
	return this->target;
}

int AForm::getRequireLvlToExecute() const
{
	return this->requireLvlToExecute;
}

int AForm::getRequireLvlToSigned() const
{
	return this->requireLvlToSigned;
}

bool AForm::isSigned() const
{
	return this->isSigne;
}

std::ostream &operator<<(std::ostream &outputFile, AForm const &instance)
{
	outputFile << "Form " << instance.getName() << " is ";
	if (!instance.isSigned())
		outputFile << "not ";
	outputFile	<< "signed. Minimum lvl to signed > " << instance.getRequireLvlToSigned()
				<< " & minimum lvl to execute > " << instance.getRequireLvlToExecute() << ".";
	return outputFile;
}
