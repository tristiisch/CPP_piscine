/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:36:15 by tglory            #+#    #+#             */
/*   Updated: 2022/01/21 16:54:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook(void)
{
	this->nb = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::start()
{
	std::string		command;

	std::cout << "- Welcome in PhoneBook" << std::endl;
	this->help();
	do {
		std::cout << "> ";
		if (!(std::cin >> command))
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
	std::cout << std::setfill(' ') << std::setw(10) << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "first name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	for (int iter = 0; iter < this->nb ; iter++)
		this->contacts[iter].displayContact(iter + 1);
}

bool	PhoneBook::add()
{
	if (this->nb >= 0 && this->nb < 8)
	{
		if (this->contacts[this->nb].askContact() == false)
			return (false);
		this->nb++;
	}
	else
		std::cout << "\e[31mSorry, you have already used every 8 contacts available. \e[5;92mUpgrade for only 50$/month.\e[0m" << std::endl;
	return (true);
}

bool	PhoneBook::search()
{
	std::string		index_selected;
	int				index_to_display = 0;

	if (this->nb > 0 && this->nb <= 8)
	{
		this->showContacts();
		do {
			std::cout << "Choose an <index> : ";
			if (!(std::cin >> index_selected))
				return (false);
		} while (index_selected.find_first_not_of("12345678") != std::string::npos ||
					index_selected.length() != 1);
		index_to_display = std::stoi(index_selected);
		if (index_to_display > this->nb)
		{
			std::cout << "\e[0;31mSorry, index " << index_to_display;
			std::cout << " doesn't exist yet. Create it! Back to menu.\e[0m" << std::endl;
		}
		else
			this->contacts[index_to_display - 1].getContact();
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
	std::cout << "     EXIT: bye bye!\e[0m" << std::endl;
}