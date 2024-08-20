#include <Motherboard/BIOS.h>

#include <CPU/CPU.h>
#include <GPU/GPU.h>
#include <RAM/RAM.h>
#include <Storage/Storage.h>

namespace Motherboard
{
	BIOS::BIOS()
		: cpu(nullptr), gpu(nullptr), ram(nullptr), storage(nullptr)
	{
	}

	BIOS::~BIOS()
	{
	}

	void BIOS::InitializeSystem()
	{
		std::cout << "Initializing system..." << std::endl;
		if (PerformPOST())
		{
			std::cout << "System initialized successfully" << std::endl;
			LoadBootloader();
		}
		else
		{
			std::cout << "System initialization failed" << std::endl;
			Sleep(5000);
		}
	}

	bool BIOS::PerformPOST()
	{
		std::cout << "Checking the components operation..." << std::endl;

		//CPU
		if (!cpu->StartCPU())
			return false;

		//GPU
		if (!gpu->StartGPU())
			return false;

		//RAM
		if (!ram->StartRAM())
			return false;

		//Storage
		if (!storage->StartStorage())
			return false;

		return true;
	}

	void BIOS::LoadBootloader()
	{
		Sleep(1000);
		system("cls");
		Beep(2000, 300);
	}
}