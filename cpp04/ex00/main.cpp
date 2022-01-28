/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:50:10 by tglory            #+#    #+#             */
/*   Updated: 2022/01/28 01:16:12 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat* wrongCat2 = new WrongCat();

	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << wrongCat2->getType() << " " << std::endl;

	std::cout << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound(); // without fonction override by child class
	wrongCat->makeSound(); // without virtual
	wrongCat2->makeSound(); // without virtual but type is not the inherits one
	wrongAnimal->makeSound(); // without fonction override by child class

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;
	delete wrongCat2;
	return 0;
}
