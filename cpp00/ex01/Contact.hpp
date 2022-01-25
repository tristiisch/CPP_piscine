/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 04:26:38 by tglory            #+#    #+#             */
/*   Updated: 2022/01/25 19:26:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	public:
		Contact(void);
		~Contact(void);
		bool askContact(void);
		void displayContact(int index) const;
		void getContact(void) const;
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phone;
		std::string	secret;
};

#endif
