/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:50:32 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 18:06:12 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

# define HIGHEST_RANK 1
# define LOWEST_RANK 150

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &instance);
		Bureaucrat &operator=(Bureaucrat const &instance);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void signForm(Form &form);

	private:
		const std::string name;
		const int grade;
};

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &instance);

#endif
