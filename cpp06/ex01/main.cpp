/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:57:40 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 20:52:32 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

static uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data *ptr = new Data();
	ptr->nbr = 42;
	ptr->str = "Foo Bar";

	std::cout << "Address of ptr :\t\t\t" << ptr << std::endl;
	std::cout << "Int in struct :\t\t\t\t" << ptr->nbr << std::endl;
	std::cout << "String in struct :\t\t\t" << ptr->str << std::endl;
	std::cout << std::endl;

	uintptr_t serialization = serialize(ptr);
	std::cout << "Serialize() result:\t\t\t" << serialization << std::endl;
	std::cout << std::endl;

	Data *recovered = deserialize(serialization);
	std::cout << "Address after deserialize() :\t\t" << recovered << std::endl;
	std::cout << "Int after deserialize() :\t\t" << recovered->nbr << std::endl;
	std::cout << "String after deserialize() :\t\t" << recovered->str << std::endl;

	delete ptr;
	return (0);
}
