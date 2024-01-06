#include <iostream>
#pragma comment(lib, "../Debug/OS12_LIB.lib")
#include "../OS12_LIB/OS12_LIB.h"

void main()
{
	try
	{
		OS12LIB h1 = OS12::Init();
		OS12LIB h2 = OS12::Init();

		std::cout << "SP02::Adder::Add(h1, 2, 3) = " << OS12::Adder::Add(h1, 2, 3) << "\n";
		std::cout << "SP02::Adder::Add(h2, 2, 3) = " << OS12::Adder::Add(h2, 2, 3) << "\n";

		std::cout << "SP02::Adder::Sub(h1, 2, 3) = " << OS12::Adder::Sub(h1, 2, 3) << "\n";
		std::cout << "SP02::Adder::Sub(h2, 2, 3) = " << OS12::Adder::Sub(h2, 2, 3) << "\n";

		std::cout << "SP02::Multiplier::Mul(h1, 2, 3) = " << OS12::Multiplier::Mul(h1, 2, 3) << "\n";
		std::cout << "SP02::Multiplier::Mul(h2, 2, 3) = " << OS12::Multiplier::Mul(h2, 2, 3) << "\n";

		std::cout << "SP02::Multiplier::Div(h1, 2, 3) = " << OS12::Multiplier::Div(h1, 2, 3) << "\n";
		std::cout << "SP02::Multiplier::Div(h2, 2, 3) = " << OS12::Multiplier::Div(h2, 2, 3) << "\n";

		OS12::Dispose(h1);
		OS12::Dispose(h2);
	}
	catch (int e) {
		std::cout << "SP02: error = " << e << "\n";
	}
}