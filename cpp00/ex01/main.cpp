/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 04:26:32 by tglory            #+#    #+#             */
/*   Updated: 2021/12/31 05:02:06 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

void				showSeveralsContacts(Contact contacts[8], int nb)
{
	std::cout << std::setfill(' ') << std::setw(10) << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "first name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	for(int iter = 0; iter < nb ; iter++)
		contacts[iter].displayContact(iter + 1);
}

int					main( void )
{
	std::string		instruct;
	std::string		index_selected;
	Contact			contacts[8];
	bool			exit_phoneBook = true;
	int				nb = 0;
	int				ret = 0;
	int				index_to_display = 0;

	// MENU LOOP
	std::cout << "- Welcome in PhoneBook" << std::endl;
	do {
		std::cout << "\e[1;36m-- Commands:" << std::endl;
		std::cout << "     ADD: add a new friend" << std::endl;
		std::cout << "     SEARCH: search a friend" << std::endl;
		std::cout << "     EXIT: bye bye!\e[0m" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, instruct);
		// ADD COMMAND
		if (!instruct.compare("ADD"))
		{
			if (nb >= 0 && nb < 8)
			{
				contacts[nb].askContact();
				nb++;
			}
			else
				std::cout << "Sorry, you have already used every 8 contacts available. Upgrade for only 50$/month." << std::endl;
		}
		// SEARCH COMMAND
		else if (!instruct.compare("SEARCH"))
		{
			if (nb > 0 && nb <= 8)
			{
				showSeveralsContacts(contacts, nb);
				do {
					std::cout << "Choose an <index> > ";
					std::getline(std::cin, index_selected);
				} while (index_selected.find_first_not_of("12345678") != std::string::npos ||
						 index_selected.length() != 1);
				index_to_display = std::stoi(index_selected);
				if (index_to_display > nb)
				{
					std::cout << "\e[0;31Sorry, index " << index_to_display;
					std::cout << " doesn't exist yet. Create it! Back to menu.\e[0m" << std::endl;
				}
				else
					contacts[index_to_display - 1].getContact();
			}
			else
				std::cout << "\e[0;31mYour contact list is empty. Use <ADD> command to add one.\e[0m" << std::endl;
		}
		// EXIT COMMAND
		else if (!instruct.compare("EXIT"))
			exit_phoneBook = false;
		else
			std::cout << "\e[0;31mWrong instruction. Please, retry.\e[0m" << std::endl;
	} while (exit_phoneBook == true);
	std::cout << "- See you later in PhoneBook" << std::endl;
	return (0);
}