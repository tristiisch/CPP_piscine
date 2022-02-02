/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:59:05 by tglory            #+#    #+#             */
/*   Updated: 2022/02/02 16:32:05 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void mandatoryTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void unequipTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* instanceIce;
	instanceIce = src->createMateria("ice");
	me->equip(instanceIce);

	AMateria* instanceCure;
	instanceCure = src->createMateria("cure");
	me->equip(instanceCure);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	delete instanceIce;

	me->unequip(1);
	delete instanceCure;

	delete bob;
	delete me;
	delete src;
}

void unequipCustomTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* instanceIce;
	instanceIce = src->createMateria("ice");
	me->equip(instanceIce);

	AMateria* instanceCure;
	instanceCure = src->createMateria("cure");
	me->equip(instanceCure);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unEquipSafe(0);
	me->unEquipSafe(1);

	delete bob;
	delete me;
	delete src;
}

void notRegisterTest()
{
	MateriaSource* src = new MateriaSource();

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void equipSameInstanceTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void useOutOfRangeTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(4, *bob);

	delete bob;
	delete me;
	delete src;
}

void learnSameClassTest()
{
	MateriaSource* src = new MateriaSource();

	src->learnMateria(new Cure());

	AMateria* tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;

	delete src;
}

int main()
{
	std::cout << "#####################{mandatoryTest}#####################" << std::endl;
	mandatoryTest();
	std::cout << std::endl << "#####################{unequipTest}#####################" << std::endl;
	unequipTest();
	std::cout << std::endl << "#####################{unequipCustomTest}#####################" << std::endl;
	unequipCustomTest();
	std::cout << std::endl << "#####################{notRegisterTest}#####################" << std::endl;
	notRegisterTest();
	std::cout << std::endl << "#####################{equipSameInstanceTest}#####################" << std::endl;
	equipSameInstanceTest();
	std::cout << std::endl << "#####################{useOutOfRangeTest}#####################" << std::endl;
	useOutOfRangeTest();
	std::cout << std::endl << "#####################{learnSameClassTest}#####################" << std::endl;
	learnSameClassTest();
}
