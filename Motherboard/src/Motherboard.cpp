#include <Motherboard/Motherboard.h>

#include <Windows.h>
#include <iostream>

#include <CPU/CPU.h>

namespace Motherboard
{
	Motherboard::Motherboard()
	{
		//detecta os componentes do pc
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

		//inicializa a BIOS
		BIOS bios;
		bios.InitializeSystem();
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

		std::cout << componentsDetected << " components detected\n\n";
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