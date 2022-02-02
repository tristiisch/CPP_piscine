/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:56:21 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:25:44 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name, std::string target, int requireLvlToSigned, int requireLvlToExecute);
		AForm(AForm const &instance);
		AForm &operator=(AForm const &instance);
		virtual ~AForm();

		std::string getName() const;
		std::string getTarget() const;
		bool isSigned() const;
		int getRequireLvlToSigned() const;
		int getRequireLvlToExecute() const;
		void canExecute(Bureaucrat const &executor) const;
		void canSigne(Bureaucrat const &executor) const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mForm::FormAlreadySigned > The form is already signed\e[0m");
				}
		};
		class NoSignatureException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mForm::FormNotSigned > Unable to perform an action on it.\e[0m");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mForm::GradeTooLowException > Grade too low\e[0m");
				}
		};
	private:
		std::string name;
		std::string target;
		bool isSigne;
		int requireLvlToSigned;
		int requireLvlToExecute;

};

std::ostream &operator<<(std::ostream &outputFile, AForm const &instance);

#endif
