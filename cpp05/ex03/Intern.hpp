/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:23:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/03 03:08:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &instance);
		Intern &operator=(Intern const &instance);
		~Intern();
		AForm* makeForm(std::string formName, std::string target) const;

		class UnknownForm : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mIntern::UnknownForm > Unable to find a valid form\e[0m");
				}
		};
};

#endif