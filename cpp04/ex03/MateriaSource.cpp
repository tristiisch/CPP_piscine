#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->initMateriaStorage();
}

MateriaSource::MateriaSource(MateriaSource const &instance)
{
	this->initMateriaStorage();
	*this = instance;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &instance)
{
	for (int i = 0; i < MAX_MATERIA; ++i)
	{
		if (instance.materias[i])
			this->materias[i] = instance.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIA; ++i)
	{
		if (this->materias[i])
		{
			if (DEBUG)
				std::cout << "[DEBUG] Materia " << this->materias[i]->getType() << ", unregister & destroyed from MateriaSource." << std::endl;
			delete this->materias[i];
		}
	}
}

void MateriaSource::initMateriaStorage()
{
	for (int i = 0; i < MAX_MATERIA; ++i)
		this->materias[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < MAX_MATERIA; ++i)
	{
		if (!this->materias[i])
		{
			this->materias[i] = materia;
			if (DEBUG)
			{
				std::cout << "[DEBUG] Materia " << materia->getType() << " is register." << std::endl;
			}
			return;
		}
		else if (this->materias[i] == materia)
		{
			std::cout << "This instance of materia " << materia->getType() << " is already learned." << std::endl;
			return;
		}
		else if (this->materias[i]->getType() == materia->getType())
		{
			std::cout << "Materia " << materia->getType() << " is already learned." << std::endl;
			return;
		}
	}
	std::cout << "The space limit of " << MAX_MATERIA << " for MateriaSource has been reached. ";
	std::cout << materia->getType() << " couldn't be added." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	AMateria *materia;
	for (int i = 0; i < MAX_MATERIA; ++i)
	{
		materia = this->materias[i];
		if (materia && materia->getType() == type)
			return (materia->clone());
	}
	std::cout << "Materia " << type << " unknown." << std::endl;
	return (NULL);
}
