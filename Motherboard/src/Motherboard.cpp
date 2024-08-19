#include "Motherboard.h"

#include <Windows.h>
#include <iostream>

namespace Motherboard
{
	Motherboard::Motherboard()
	{
		while (componentsDetected != MAX_COMPONENTS)
		{
			system("cls");
			CheckHardwares();

			if (componentsDetected != MAX_COMPONENTS)
			{
				Sleep(3000);
				componentsDetected = 0;
			}
		}

		Sleep(1000);
		system("cls");
		std::cout << "Initializing..." << std::endl;
		Beep(2000, 300);
	}

	Motherboard::~Motherboard()
	{
	}

	void Motherboard::CheckHardwares()
	{
		//CPU
		if (CheckDll("CPU.dll"))
		{
			componentsDetected++;
			std::cout << "CPU detected" << std::endl;

		}
		else
		{
			std::cout << "CPU not detected!" << std::endl;
		}

		//GPU
		if (CheckDll("GPU.dll"))
		{
			componentsDetected++;
			std::cout << "GPU detected" << std::endl;
		}
		else
		{
			std::cout << "GPU not detected!" << std::endl;
		}

		//RAM
		if (CheckDll("RAM.dll"))
		{
			componentsDetected++;
			std::cout << "RAM detected" << std::endl;
		}
		else
		{
			std::cout << "RAM not detected!" << std::endl;
		}

		//Storage
		if (CheckDll("Storage.dll"))
		{
			componentsDetected++;
			std::cout << "Storage detected" << std::endl;
		}
		else
		{
			std::cout << "Storage not detected!" << std::endl;
		}

		std::cout << componentsDetected << std::endl;
	}

	bool Motherboard::CheckDll(const char* dllName)
	{
		HMODULE hDll = LoadLibraryA(dllName);
		if (hDll)
		{
			FreeLibrary(hDll);
			return true;
		}
		return false;
	}
}