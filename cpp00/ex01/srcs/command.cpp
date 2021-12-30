/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:04:54 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:05:30 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook *Command::getPhoneBook() const
{
	return (this->phonebook);
}

void Command::setPhoneBook(PhoneBook *phoneBook)
{
	this->phonebook = phoneBook;
}
