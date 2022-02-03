/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:25:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:41:39 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &instance);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &instance);
		~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const &executor) const;
	
		class CantWriteFile : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("\e[0;31mForm::ShrubberyCreationForm > Unable to write to file\e[0m");
				}
		};
};

#endif
