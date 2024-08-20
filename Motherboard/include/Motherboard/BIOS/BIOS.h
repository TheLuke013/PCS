#ifndef BIOS_H
#define BIOS_H

#include <iostream>
#include <Windows.h>

#include <CPU/CPU.h>
#include <GPU/GPU.h>
#include <RAM/RAM.h>
#include <Storage/Storage.h>

#include <Motherboard/Core.h>

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
