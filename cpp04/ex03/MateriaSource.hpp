#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &instance);
		MateriaSource &operator=(MateriaSource const &instance);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *materias[MAX_MATERIA];

		void initMateriaStorage();
};

#endif
