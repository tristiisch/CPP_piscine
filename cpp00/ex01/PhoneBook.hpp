/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 04:26:38 by tglory            #+#    #+#             */
/*   Updated: 2022/02/05 08:19:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void start();
		void help();
		void showContacts();
		bool add();
		bool search();
	private:
		Contact contacts[8];
		int nb;
};

#endif
