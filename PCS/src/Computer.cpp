#include "Computer.h"

#include <iostream>
#include <string>
#include <Windows.h>

namespace Computer
{
	Computer::Computer()
		: motherboard(nullptr)
	{
		Standby();
	}

	Computer::~Computer()
	{

	}

	void Computer::Boot()
	{
		motherboard = new Motherboard::Motherboard();
	}

	void Computer::Shutdown()
	{
		isOn = false;
	}

	void Computer::Standby()
	{
		while (isOn)
		{
			//verifica se a placa mãe esta presente
			if (!canInitialize)
			{
				if (CheckMotherboard())
				{
					canInitialize = true;
					system("cls");
					std::cout << "Motherboard detected" << std::endl;
					Boot();
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
