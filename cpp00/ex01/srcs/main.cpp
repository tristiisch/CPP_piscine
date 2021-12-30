/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:33:22 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:03:01 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook phonebook;
	Command *command;

	command = phonebook.askCommand();
	if (!command)
		return (0);
	command->execute();
	return (0);
}
