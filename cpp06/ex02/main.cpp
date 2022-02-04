/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:24:49 by tglory            #+#    #+#             */
/*   Updated: 2022/02/04 18:25:17 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	Base *baseClass;
	int random;

	std::srand(time(NULL));
	random = rand() % 3;
	switch (random)
	{
		case 0:
			baseClass = new A();
			std::cout << "class A generated" << std::endl;
			break;
		case 1:
			baseClass = new B();
			std::cout << "class B generated" << std::endl;
			break;
		case 2:
		default:
			baseClass = new C();
			std::cout << "class C generated" << std::endl;
			break;
	}
	return baseClass;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A identify with pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B identify with pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C identify with pointer" << std::endl;
}

void identify(Base& ref)
{
	try 
	{
		(void) dynamic_cast<A&>(ref);
		std::cout << "A identify with ref" << std::endl;
	} catch (std::exception &e) {
		// std::cout << e.what() << " Not A" << std::endl;
	}
	try 
	{
		(void) dynamic_cast<B&>(ref);
		std::cout << "B identify with ref" << std::endl;
	} catch (std::exception &e) {
		// std::cout << e.what() << " Not B" << std::endl;
	}
	try 
	{
		(void) dynamic_cast<C&>(ref);
		std::cout << "C identify with ref" << std::endl;
	} catch (std::exception &e) {
		// std::cout << e.what() << " Not C" << std::endl;
	}
}

int main(void)
{
	Base *classRandom = generate();
	Base &classRef = *classRandom;

	identify(classRandom);
	identify(classRef);

	delete classRandom;
}
