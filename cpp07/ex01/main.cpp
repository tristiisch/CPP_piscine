# include "iter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ex01.out <argument>" << std::endl;
		return (0);
	}
	char *str = av[1];
	int i = 0;

	while (str[i])
		i++;

	std::cout << "**Array before iter() called with template function:" << std::endl;
	std::cout << str << std::endl;
	iter(str, i, function);

	std::cout << "** Content in the Array after iter():" << std::endl;
	std::cout << str << std::endl;
	std::cout << "** tab of int before iter():" << std::endl;

	int tab[4] = {70, 71, 72, 73};

	i = 0;
	while (i < 4)
	{
		std::cout << tab[i] << std::endl;
		i++;
	}
	iter(tab, 4, function);
	std::cout << "** tab Content after iter():" << std::endl;
	i = 0;
	while (i < 4)
	{
		std::cout << tab[i] << std::endl;
		i++;
	}
	return (0);
}
