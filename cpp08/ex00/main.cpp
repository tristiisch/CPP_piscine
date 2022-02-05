/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:44:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/05 08:50:55 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


static void vectorTest(void)
{
	std::vector<int> intVector;

	for (int i = 0; i < 10; i++)
		intVector.push_back((i * 10) + i);
		
	std::cout << "intVector: " << std::endl;
	std::vector<int>::iterator arrayIterator = intVector.begin();
	while (arrayIterator != intVector.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	std::cout << CYAN << "easy find 11" << RESET << std::endl;
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 11);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYAN << "easy find 1111" << RESET << std::endl;
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void dequeTest(void)
{
	std::deque<int> intDeque;

	for (int i = 0; i < 10; i++)
		intDeque.push_front(i * i);
		
	std::cout << "intDeque: " << std::endl;
	std::deque<int>::iterator arrayIterator = intDeque.begin();
	while (arrayIterator != intDeque.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	std::cout << CYAN << "easy find 25" << RESET << std::endl;
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, 25);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYAN << "easy find 1111" << RESET << std::endl;
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void listTest(void)
{
	std::list<int> intList;

	for (int i = 0; i < 10; i++)
		intList.push_front(std::rand());
	intList.push_front(22);
	intList.sort();
	std::cout << "intList: " << std::endl;
	std::list<int>::iterator arrayIterator = intList.begin();
	while (arrayIterator != intList.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	std::cout << CYAN << "easy find 22" << RESET << std::endl;
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 22);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYAN << "easy find 1111" << RESET << std::endl;
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void setTest(void)
{
	std::set<int> intSet;

	for (int i = 0; i < 10; i++)
		intSet.insert(i);
	std::cout << "intSet: " << std::endl;
	std::set<int>::iterator arrayIterator = intSet.begin();
	while (arrayIterator != intSet.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	std::cout << CYAN << "easy find 9" << RESET << std::endl;
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 9);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << CYAN << "easy find 1111" << RESET << std::endl;
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	std::cout << CYAN << "\n-----Vector Test-----\n" << RESET << std::endl;
	vectorTest();
	std::cout << CYAN << "\n-----Deque Test-----\n" << RESET << std::endl;
	dequeTest();
	std::cout << CYAN << "\n-----List Test-----\n" << RESET << std::endl;
	listTest();
	std::cout << CYAN << "\n-----Set Test-----\n" << RESET << std::endl;
	setTest();
}