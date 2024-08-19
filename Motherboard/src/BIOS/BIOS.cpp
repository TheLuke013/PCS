#include "BIOS.h"

namespace Motherboard
{
	BIOS::BIOS()
	{
	}

	BIOS::~BIOS()
	{
	}

	void BIOS::InitializeSystem()
	{
	}

	bool BIOS::PerformPOST()
	{
		system("cls");
		std::cout << "Checking the components operation..." << std::endl;
		return false;
	}

	void BIOS::LoadBootloader()
	{
		Sleep(1000);
		system("cls");
		Beep(2000, 300);
	}
}