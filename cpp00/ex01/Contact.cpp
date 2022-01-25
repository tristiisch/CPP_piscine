/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:37:43 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 19:27:44 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

bool Contact::askContact(void)
{
	std::cout << "\e[1;35mWhat is the <first name> ?\e[0m ";
	if (!(std::cin >> this->firstName))
		return (false);
	std::cout << "\e[1;35mWhat is the <last name> ?\e[0m ";
	if (!(std::cin >> this->lastName))
		return (false);
	std::cout << "\e[1;35mWhat is the <nickname> ?\e[0m ";
	if (!(std::cin >> this->nickName))
		return (false);
	std::cout << "\e[1;35mWhat is the <phone number> ?\e[0m ";
	if (!(std::cin >> this->phone))
		return (false);
	std::cout << "\e[1;35mWhat is the <darkest secret> ?\e[0m ";
	if (!(std::cin >> this->secret))
		return (false);
	std::cout << "\e[0;32m" + this->firstName + " " + this->lastName + " has been added to PhoneBook\e[0m" << std::endl;
	return (true);
}

void Contact::displayContact(int index) const
{
	std::cout << std::setfill(' ') << std::setw(10) << index << "|";
	if (this->firstName.length() > 10)
		std::cout << this->firstName.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->firstName;
	std::cout << "|";
	if (this->lastName.length() > 10)
		std::cout << this->lastName.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->lastName;
	std::cout << "|";
	if (this->nickName.length() > 10)
		std::cout << this->nickName.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->nickName;
	std::cout << "|" << std::endl;
}

void Contact::getContact(void) const
{
	std::cout << "Contact's infos :" << std::endl;
	std::cout << "  First name : " << this->firstName << std::endl;
	std::cout << "  Last name : " << this->lastName << std::endl;
	std::cout << "  Nickname : " << this->nickName << std::endl;
	std::cout << "  Phone number : " << this->phone << std::endl;
	std::cout << "  Darkest secret : " << this->secret << std::endl;
}
