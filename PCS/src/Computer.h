#ifndef COMPUTER_H
#define COMPUTER_H

#include "Motherboard.h"

namespace Computer
{
	class Computer
	{
	public:
		Computer();
		~Computer();

		void Boot();
		void Shutdown();

	private:
		void Standby();
		bool CheckMotherboard();

		bool isOn = true;
		bool canInitialize = false;

		Motherboard::Motherboard* motherboard;

	};
}

#endif
