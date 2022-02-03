/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:26:02 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 03:28:18 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 25, 5)  {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->canExecute(executor);

	std::ofstream	outfile;
	std::string		fileName(this->getTarget() + "_shrubbery");
	std::string		content;

	outfile.open(fileName.c_str());
	if (outfile.fail())
		throw ShrubberyCreationForm::CantWriteFile();
	outfile << "        _-_" << std::endl;
	outfile << "     /~~   ~~\\" << std::endl;
	outfile << "  /~~         ~~\\" << std::endl;
	outfile << " {               }" << std::endl;
	outfile << "  \\  _-     -_  /" << std::endl;
	outfile << "       \\\\ //   " << std::endl;
	outfile << "        | |     " << std::endl;
	outfile << "        | |     " << std::endl;
	outfile << "       // \\\\" << std::endl;
	outfile.close();
	std::cout << fileName << " file created." << std::endl;
}
