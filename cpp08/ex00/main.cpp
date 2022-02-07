/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:44:35 by tglory            #+#    #+#             */
/*   Updated: 2022/02/07 00:02:32 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

static void vectorTest(int size)
{
	std::vector<int> intVector;

	std::cout << "Vector Test :" << std::endl;
	std::srand(time(0));
	for (int i = 0; i < size; i++)
		intVector.push_back(std::rand() % (size));

	try
	{
		printResult(intVector, 5);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void dequeTest(int size)
{
	std::deque<int> intDeque;

	std::cout << "Deque Test :" << std::endl;
	std::srand(time(0));
	for (int i = 0; i < size; ++i)
		intDeque.push_front(std::rand() % (size));

	try
	{
		printResult(intDeque, 8);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void listTest(int size)
{
	std::list<int> intList;

	std::cout << "List Test :" << std::endl;
	std::srand(time(0));
	for (int i = 0; i < size; i++)
		intList.push_front(std::rand() % (size));
	intList.sort();

	try
	{
		printResult(intList, 3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void setTest(int size)
{
	std::set<int> intSet;

	std::cout << "Set Test :" << std::endl;
	std::srand(time(NULL));
	for (int i = 0; i < size; i++)
		intSet.insert(std::rand() % (size));

	try
	{
		printResult(intSet, 2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	int size = 10;

	vectorTest(size);
	dequeTest(size);
	listTest(size);
	setTest(size);
}
