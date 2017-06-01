// Nauka - agregat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "agr.h"
#include <exception>
#include <iostream>
#include <initializer_list>

int main()
{
	try
	{
		Agr<int> agr{ 1,2,3,4,5 };
		Wsk<int> wsk{ agr };
		agr.print();
		std::cout << *wsk << "\n";
		++wsk;
		*wsk = 8;
		std::cout << *wsk << "\n";
		agr.print();
	}
	catch (const std::exception &message)
	{
		std::cerr << "Exception occured: " << message.what() << "\n";
	}
    return 0;
}