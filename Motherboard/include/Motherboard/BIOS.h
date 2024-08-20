#ifndef BIOS_H
#define BIOS_H

#include <iostream>
#include <Windows.h>

#include <Motherboard/Core.h>

namespace CPU
{
	class CPU;
}

namespace GPU
{
	class GPU;
}

namespace RAM
{
	class RAM;
}

namespace Storage
{
	class Storage;
}

namespace Motherboard
{
	class MOTHERBOARD_API BIOS
	{
	public:
		BIOS();
		~BIOS();

		void InitializeSystem();
		bool PerformPOST();
		void LoadBootloader();

	private:
		bool systemInitalized = false;

		CPU::CPU* cpu;
		GPU::GPU* gpu;
		RAM::RAM* ram;
		Storage::Storage* storage;

	};
}

#endif
