/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 04:26:38 by tglory            #+#    #+#             */
/*   Updated: 2022/01/21 18:00:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	Contact contacts[8];
	int nb;
	void start();
	void help();
	void showContacts();
	bool add();
	bool search();
};

#endif
