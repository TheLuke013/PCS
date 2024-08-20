#include "Computer.h"

#include <iostream>
#include <string>
#include <Windows.h>

namespace Computer
{
	Computer::Computer()
		: motherboard(nullptr)
	{
		while (!canInitialize)
		{
			//verifica se a placa mãe esta presente
			if (!canInitialize)
			{
				if (CheckMotherboard())
				{
					canInitialize = true;
					system("cls");
					std::cout << "Motherboard detected" << std::endl;

					motherboard = new Motherboard::Motherboard();
				}
				else
				{
					system("cls");
					std::cout << "Motherboard not detected!" << std::endl;
					Sleep(3000);
				}
			}
		}
	}

	Computer::~Computer()
	{

	}

	//checa a presença da placa mãe
	bool Computer::CheckMotherboard()
	{
		HMODULE hDll = LoadLibraryA("Motherboard.dll");
		if (hDll)
		{
			FreeLibrary(hDll);
			return true;
		}
		return false;
	}
}
