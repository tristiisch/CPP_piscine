/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:57:40 by tglory            #+#    #+#             */
/*   Updated: 2022/02/06 15:04:01 by tglory           ###   ########lyon.fr   */
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

	std::cout << "Address of ptr :\t\t\t" << ptr << std::endl;
	std::cout << "Value in struct :\t\t\t" << ptr->nbr << std::endl;

	uintptr_t serialization = serialize(ptr);
	std::cout << "Serialize() result:\t\t\t" << serialization << std::endl;

	Data *recovered = deserialize(serialization);
	std::cout << "Address after deserialize() :\t\t" << recovered << std::endl;
	std::cout << "Value after deserialize() :\t\t" << recovered->nbr << std::endl;

	delete ptr;
	return (0);
}
