/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:51:23 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:17:01 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("nameless"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(Bureaucrat const &instance)
{
	*this = instance;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &instance)
{
	this->name = instance.getName();
	this->grade = instance.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade; 
}

void Bureaucrat::upGrade()
{
	if (this->grade <= HIGHEST_RANK)
		throw Bureaucrat::GradeTooHighException();
	--this->grade;
}

void Bureaucrat::downGrade()
{
	if (this->grade >= LOWEST_RANK)
		throw Bureaucrat::GradeTooLowException();
	++this->grade;
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signs form " << form.getName() << "." << std::endl;
	} catch (Form::FormAlreadySigned &e) {
		std::cout << this->name << " cannot signs form " << form.getName() << " because the form is already signed." << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << this->name << " cannot signs form " << form.getName() << " because his grade is too low." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &instance)
{
	outputFile << instance.getName() << " is lvl " << instance.getGrade() << ".";
	return outputFile;
}
