/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:37:43 by tglory            #+#    #+#             */
/*   Updated: 2022/01/20 17:38:42 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(void) { return; }

Contact::~Contact(void) { return; }

bool Contact::askContact(void)
{
	std::cout << "\e[1;35mWhat is the <first name> ?\e[0m ";
	if (!(std::cin >> this->first_name))
		return (false);
	std::cout << "\e[1;35mWhat is the <last name> ?\e[0m ";
	if (!(std::cin >> this->last_name))
		return (false);
	std::cout << "\e[1;35mWhat is the <nickname> ?\e[0m ";
	if (!(std::cin >> this->nickname))
		return (false);
	std::cout << "\e[1;35mWhat is the <phone number> ?\e[0m ";
	if (!(std::cin >> this->phone))
		return (false);
	std::cout << "\e[1;35mWhat is the <darkest secret> ?\e[0m ";
	if (!(std::cin >> this->secret))
		return (false);
	std::cout << "\e[0;32m" + this->first_name + " " + this->last_name + " has been added to PhoneBook\e[0m" << std::endl;
	return (true);
}

void Contact::displayContact(int index) const
{
	std::cout << std::setfill(' ') << std::setw(10) << index << "|";
	if (this->first_name.length() > 10)
		std::cout << this->first_name.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->first_name;
	std::cout << "|";
	if (this->last_name.length() > 10)
		std::cout << this->last_name.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->last_name;
	std::cout << "|";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << this->nickname;
	std::cout << "|" << std::endl;
}

void Contact::getContact(void) const
{
	std::cout << "Contact's infos :" << std::endl;
	std::cout << "  First name : " << this->first_name << std::endl;
	std::cout << "  Last name : " << this->last_name << std::endl;
	std::cout << "  Nickname : " << this->nickname << std::endl;
	std::cout << "  Phone number : " << this->phone << std::endl;
	std::cout << "  Darkest secret : " << this->secret << std::endl;
}
