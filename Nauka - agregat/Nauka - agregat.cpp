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
		Agr<int> agr{ 1,1,3,32,24,5,2,23,4,23 };
		Wsk<int> wsk{ agr };
		std::cout << *wsk.beg() << " " << *wsk.end() << "\n";
	}
	catch (const std::exception &message)
	{
		std::cerr << "Exception occured: " << message.what() << "\n";
	}
    return 0;
}