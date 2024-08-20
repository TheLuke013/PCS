#ifndef GPU_H
#define GPU_H

#include "Core.h"

namespace GPU
{
	class GPU_API GPU
	{
	public:
		GPU();
		~GPU();

		bool StartGPU();
		void ShowInfo();
	};
}

#endif
