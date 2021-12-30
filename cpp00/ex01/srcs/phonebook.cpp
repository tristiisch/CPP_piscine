/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:44:03 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:43:42 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to My Awesome PhoneBook" << std::endl;
	std::cout << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl;
	std::cout << "Closing My Awesome PhoneBook" << std::endl;
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
}

bool PhoneBook::executeCommand(void)
{
	bool returnValue;

	returnValue = this->command->execute();
	if (!returnValue)
		return (returnValue);
	returnValue = this->command->print();
	return (returnValue);
}


Command	*PhoneBook::resolveCommand(std::string str) const
{
	std::string add("ADD");
	std::string search("SEARCH");
	std::string exit("EXIT");

	if (!add.compare(str))
	{
		return (new Add());
	}
	if (!search.compare(str))
		return (new Search());
	if (!exit.compare(str))
		return (new Exit());
/*	switch (str2int(str))
	{
		case str2int("ADD"):
			return (Cmd::ADD);
			break;
		case str2int("SEARCH"):
			return (Cmd::SEARCH);
			break;
		case str2int("EXIT"):
			return (Cmd::EXIT);
			break;
		default:
			break;
	}*/
/*	for (int i = Cmd::ADD; i <= Cmd::EXIT; i++)
	{
		Cmd foo = static_cast<Cmd>(i);

	}*/
	return NULL;
}


Command	*PhoneBook::askCommand()
{
	std::string input;
	Command *cmd;

	while (true)
	{
		std::cout << "Choose a command" << std::endl;
		std::cout << "ADD, SEARCH or EXIT" << std::endl;
		std::cin >> input;
		
		cmd = resolveCommand(input);
		if (cmd)
		{
			if (!cmd->getName().compare("EXIT"))
				break ;
			std::cout << "Choosing '" << cmd->getName() << "' ..." << std::endl;
			this->command = cmd;
			return (cmd);
		}
		std::cout << std::endl;
	}
	return (NULL);
}

Command *PhoneBook::getCommand() const
{
	return (this->command);

}

Contact PhoneBook::getContact() const
{
	return (this->contact);
}

bool PhoneBook::addContact(Contact contact)
{
	this->contact = contact;
	return (true);
}
