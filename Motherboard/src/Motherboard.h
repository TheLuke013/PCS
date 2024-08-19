#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "Core.h"

#define MAX_COMPONENTS 4

namespace Motherboard
{
	class MOTHERBOARD_API Motherboard
	{
	public:
		Motherboard();
		~Motherboard();

	private:
		void CheckHardwares();
		bool CheckDll(const char* dllName);

		int componentsDetected = 0;
	};
}

#endif
