/* ************************************************************************** */
/*                    */
/*              :::      ::::::::   */
/*   Contact.cpp            :+:      :+:    :+:   */
/*                 +:+ +:+  +:+     */
/*   By: tglory <tglory@student.42lyon.fr>   +#+  +:+       +#+        */
/*             +#+#+#+#+#+   +#+    */
/*   Created: 2021/12/31 04:25:34 by tglory     #+#    #+#      */
/*   Updated: 2021/12/31 04:44:31 by tglory    ###   ########lyon.fr   */
/*                    */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::askContact(void)
{
	std::cout << "\e[1;35mWhat is the <first name> ?\e[0m ";
	std::getline (std::cin, this->first_name);
	std::cout << "\e[1;35mWhat is the <last name> ?\e[0m ";
	std::getline (std::cin, this->last_name);
	std::cout << "\e[1;35mWhat is the <nickname> ?\e[0m ";
	std::getline (std::cin, this->nickname);
	std::cout << "\e[1;35mWhat is the <phone number> ?\e[0m ";
	std::getline (std::cin, this->phone);
	std::cout << "\e[1;35mWhat is the <darkest secret> ?\e[0m ";
	std::getline (std::cin, this->secret);
	std::cout << "\e[0;32m" + this->first_name + " " + this->last_name + " has been added to PhoneBook\e[0m" << std::endl;
	return;
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
	return;
}

void Contact::getContact(void) const
{
	std::cout << "Contact's infos :" << std::endl;
	std::cout << "  First name : " << this->first_name << std::endl;
	std::cout << "  Last name : " << this->last_name << std::endl;
	std::cout << "  Nickname : " << this->nickname << std::endl;
	std::cout << "  Phone number : " << this->phone << std::endl;
	std::cout << "  Darkest secret : " << this->secret << std::endl;
	return;
}
