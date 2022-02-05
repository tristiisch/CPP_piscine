
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	public:
		Array() : array(NULL), _size(0) {}
		Array(unsigned int size) : array(new T[size]), _size(size)
		{
			if (size < 0)
				throw OutOfRangeException();
		}
		Array(Array const &instance)
		{
			unsigned int i = 0;
			this->_size = instance._size;
			this->array = new T[_size];
			while (i < _size)
			{
				this->array[i] = instance.array[i];
				i++;
			}
			return ;
		}
		Array &operator=(Array const &instance)
		{
			if (this->_size != 0 && this->_size != instance._size)
				delete [] array;
			this->_size = instance._size;
			this->array = new T[_size];
			unsigned int i = 0;
			while (i < this->_size)
			{
				this->array[i] = instance.array[i];
				++i;
			}
			return (*this);
		}
		~Array()
		{
			delete [] array;
		}
		T &operator[](unsigned int i)
		{
			if (i < 0 || i >= _size)
				throw OutOfRangeException();
			return (this->array[i]);
		}
		int size()
		{
			return (_size);
		}
		class OutOfRangeException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("\e[0;31mArray::OutOfRangeException > This index is out of range\e[0m");
			}
		};
	private:
		T *array;
		unsigned int _size;
};

#endif