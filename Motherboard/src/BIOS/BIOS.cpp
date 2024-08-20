#include <Motherboard/BIOS/BIOS.h>

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
		}
	}

	bool BIOS::PerformPOST()
	{
		std::cout << "Checking the components operation..." << std::endl;

		//CPU
		if (!cpu->StartCPU())
			return false;

		//GPU

		//RAM

		//Storage

		return true;
	}

	void BIOS::LoadBootloader()
	{
		Sleep(1000);
		system("cls");
		Beep(2000, 300);
	}
}