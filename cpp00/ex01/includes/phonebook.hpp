/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:38:21 by tglory            #+#    #+#             */
/*   Updated: 2021/12/30 01:42:41 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
// #include "cmd.h"

class Contact
{
    public:

    std::string  getFirstName();
    void         setFirstName();

    private:

    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
};

class Command
{
    public:

    // Command(void);
    // ~Command(void);

    bool execute();
    bool print();
    std::string getName() const;
    class PhoneBook *getPhoneBook() const;
    void setPhoneBook(class PhoneBook *phoneBook);
    
    private:

    class PhoneBook *phonebook;
    std::string name;
};

class PhoneBook
{
    public:

    PhoneBook(void);
    ~PhoneBook(void);

    bool executeCommand();
    Command *askCommand();
    Command *getCommand() const;
    Contact getContact() const;
    bool addContact(Contact contact);

    protected:

    class Command *command;
    Contact contact;

    private:
    
    class Command *resolveCommand(std::string str) const;

};


#endif
