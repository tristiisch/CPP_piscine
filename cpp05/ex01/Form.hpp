/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:56:21 by tglory            #+#    #+#             */
/*   Updated: 2022/01/31 23:14:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int requireLvlToSigned, int requireLvlToExecute);
		Form(Form const &instance);
		Form &operator=(Form const &instance);
		~Form();

		std::string getName() const;
		bool isSigned() const;
		int getRequireLvlToSigned() const;
		int getRequireLvlToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mForm::FormAlreadySigned > The form is already signed\e[0m");
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
		bool isSigne;
		int requireLvlToSigned;
		int requireLvlToExecute;

};

std::ostream &operator<<(std::ostream &outputFile, Form const &instance);

#endif
