#pragma once
#ifndef AGR_H
#define AGR_H

#include <initializer_list>
#include <iostream>

template <class>
class Wsk;

template <class typ>
class Agr
{
	int len;
	typ *list{ nullptr };
public:
	Agr() :len(0) {}
	Agr(const std::initializer_list<typ> &l)
		:len(l.size())
	{
		list = new typ[len];
		int i(0);
		for (auto el : l)
		{
			list[i] = el;
			++i;
		}
	}
	typ& operator[](const int &index)
	{
		if (index >= len || index < 0)
			throw std::runtime_error("Index out of range");
		return list[index];
	}
	void print()
	{
		std::cout << "Printing content:\n";
		for (int i = 0;i < len;++i)
		{
			std::cout << list[i] << " ";
		}
		std::cout << "\n";
	}
	~Agr()
	{
		if (len < 2)
			delete list;
		else
			delete[]list;
	}
	template <class>
	friend class Wsk;
};



template <class typ>
class Wsk
{
	typ* wsk;
	int len, pos;
public:
	Wsk() = delete;
	explicit Wsk(Agr<typ> &agr);
	Wsk& operator++();
	Wsk& operator--();
	typ& operator*();
	Wsk& operator+(const int &x);
	Wsk& operator-(const int &x);
	friend std::ostream& operator<<(std::ostream&out, Wsk &wsk);
	Wsk& end();
	Wsk& beg();
	template<class>
	friend class Agr;
};

template <class typ>
Wsk<typ>::Wsk(Agr<typ> &agr)
	:len(agr.len), wsk(agr.list), pos(0)
{
	if (!agr.list)
		throw std::runtime_error("Agr is empty");
}

template <class typ>
Wsk<typ>& Wsk<typ>::operator++()
{
	if (pos >= len)
		throw std::runtime_error("cannot increase wsk");
	++pos;
	++wsk;
	return *this;
}

template <class typ>
Wsk<typ>& Wsk<typ>::operator--()
{
	if (!pos)
		throw std::runtime_error("Positon cannot be lower than 0");
	--pos;
	--wsk;
	return *this;
}

template <class typ>
typ& Wsk<typ>::operator*()
{
	return *wsk;
}

template <class typ>
Wsk<typ>& Wsk<typ>::operator+(const int &x)
{
	if (pos + x >= len)
		throw std::runtime_error("Position out of range");
	for (int i = 0;i < x;++i)
	{
		++pos;
		++wsk;
	}
	return &this;
}

template <class typ>
Wsk<typ>& Wsk<typ>::operator-(const int &x)
{
	if (pos + x <= 0)
		throw std::runtime_error("Position out of range");
	for (int i = 0;i < x;++i)
	{
		--pos;
		--wsk;
	}
	return *this;
}

template <class typ>
std::ostream& operator<<(std::ostream&out, Wsk<typ> &wsk)
{
	return out << *wsk;
}

template <class typ>
Wsk<typ>& Wsk<typ>::end()
{
	while (pos < len - 1)
	{
		++pos;
		++wsk;
	}
	return *this;
}

template <class typ>
Wsk<typ>& Wsk<typ>::beg()
{
	while (pos > 0)
	{
		--pos;
		--wsk;
	}
	return *this;
}

#endif // !AGR_H