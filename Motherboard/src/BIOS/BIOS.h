#ifndef BIOS_H
#define BIOS_H

#include "../Core.h"

#include <iostream>
#include <Windows.h>

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

	};
}

#endif
