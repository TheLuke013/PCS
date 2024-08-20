#ifndef COMPUTER_H
#define COMPUTER_H

#include <Motherboard/Motherboard.h>

namespace Computer
{
	class Computer
	{
	public:
		Computer();
		~Computer();

	private:
		bool CheckMotherboard();

		bool canInitialize = false;

		Motherboard::Motherboard* motherboard;

	};
}

#endif
