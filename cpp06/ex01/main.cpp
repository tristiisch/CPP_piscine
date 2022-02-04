# include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
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
	std::cout << "Address of serialize() :\t\t" << serialization << std::endl;

	Data *recovered = deserialize(serialization);
	std::cout << "Address after deserialize() :\t\t" << recovered << std::endl;
	std::cout << "Value after deserialize() :\t\t" << recovered->nbr << std::endl;

	delete ptr;
	return (0);
}
