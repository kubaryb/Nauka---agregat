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
	explicit Wsk(Agr<typ> &agr)
		:len(agr.len),wsk(agr.list),pos(0)
	{
		if (!agr.list)
			throw std::runtime_error("Agr is empty");
	}
	Wsk& operator++()
	{
		if (pos >= len)
			throw std::runtime_error("cannot increase wsk");
		++pos;
		++wsk;
		return *this;
	}
	typ& operator*()
	{
		return *wsk;
	}
	friend std::ostream& operator<<(std::ostream&out, Wsk &wsk)
	{
		return out << *wsk;
	}
	template<class>
	friend class Agr;
};

#endif // !AGR_H