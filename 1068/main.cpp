#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	uint64_t input;
	std::cin >> input;

	while (input != 1)
	{
		std::cout << input << ' ';
		input = (input % 2u) ? input * 3u + 1u : input / 2u;
	}

	std::cout << 1;
}