#ifndef RAM_H
#define RAM_H

#include "Core.h"

namespace RAM
{
	class RAM_API RAM
	{
	public:
		RAM();
		~RAM();

		bool StartRAM();
		void ShowInfo();
	};
}

#endif
