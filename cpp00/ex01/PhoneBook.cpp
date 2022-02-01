/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:36:15 by tglory            #+#    #+#             */
/*   Updated: 2022/02/01 16:07:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nb(0) {}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::start()
{
	std::string command;

	std::cout << "- Welcome in PhoneBook" << std::endl;
	this->help();
	do {
		std::cout << "> ";
		if (!(std::getline(std::cin, command)))
			break;
		if (!command.compare("ADD"))
		{
			if (!this->add())
				break ;
		}
		else if (!command.compare("SEARCH"))
		{
			if (!this->search())
				break ;
		}
		else if (!command.compare("EXIT"))
			break ;
		else
		{
			std::cout << "\e[0;31mWrong instruction. Please, retry.\e[0m" << std::endl;
			this->help();
		}
	} while (true);
	std::cout << "- See you later in PhoneBook" << std::endl;
}

void	PhoneBook::showContacts()
{
	std::cout << "\e[1;36m" << std::setfill(' ') << std::setw(10) << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "first name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < this->nb ; i++)
		this->contacts[i].displayContact(i + 1);
	std::cout << "\e[0m";
}

bool	PhoneBook::add()
{
	if (this->nb < 8)
	{
		if (this->contacts[this->nb].askContact() == false)
			return (false);
		this->nb++;
	}
	else if (this->nb < 0)
		return (false);
	else
		std::cout << "\e[31mSorry, you have already used every 8 contacts available. \e[5;92mUpgrade for only 50$/month.\e[0m" << std::endl;
	return (true);
}

bool	PhoneBook::search()
{
	std::string indexSelected;
	int indexDisplay = 0;

	if (this->nb > 0 && this->nb <= 8)
	{
		this->showContacts();
		do {
			std::cout << "Choose an <index> : ";
			if (!(std::getline(std::cin, indexSelected)))
				return (false);
		} while (indexSelected.find_first_not_of("12345678") != std::string::npos ||
					indexSelected.length() != 1);
		indexDisplay = std::stoi(indexSelected);
		if (indexDisplay > this->nb)
		{
			std::cout << "\e[0;31mSorry, index " << indexDisplay;
			std::cout << " doesn't exist yet. Creates it! Back to menu.\e[0m" << std::endl;
		}
		else
			this->contacts[indexDisplay - 1].getContact();
	}
	else
		std::cout << "\e[0;31mYour contact list is empty. Use <ADD> command to add one.\e[0m" << std::endl;
	return (true);
}

void	PhoneBook::help()
{
	std::cout << "\e[1;36m-- Commands:" << std::endl;
	std::cout << "     ADD: add a new friend" << std::endl;
	std::cout << "     SEARCH: search a friend" << std::endl;
	std::cout << "     EXIT: quit the program\e[0m" << std::endl;
}
