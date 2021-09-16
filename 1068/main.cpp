#include <iostream>

int main()
{
	uint64_t input;
	std::cin >> input;

	while (input != 1)
	{
		std::cout << input << ' ';
		input = (input % 2u) ? input * 3u + 1u : input / 2u;
	}

	std::cout << 1;

#ifdef ENABLE_BREAK
	// flush the cout
	std::cout << std::endl;
	
	// pause (Windows only)
	system("pause");
#endif
}