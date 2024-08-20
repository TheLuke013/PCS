#ifndef CPU_H
#define CPU_H

#include <CPU/Core.h>

namespace CPU
{
	class CPU_API CPU
	{
	public:
		CPU();
		~CPU();

		bool StartCPU();
		void ShowInfo();
	};
}

#endif