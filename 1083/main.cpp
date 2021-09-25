#include <iostream>

#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	// get n
    uint32_t n;
    std::cin >> n;

	// create bitset
    std::vector<bool> bitset(n);

	// fill the bitset with values
	for (uint32_t i; i < n - 1; i++)
	{
		uint32_t in;
		std::cin >> in;

		bitset[in - 1] = true;
	}

	// find the missing value's index
	uint32_t index = std::find(bitset.begin(), bitset.end(), false) - bitset.begin();
	std::cout << index + 1;

#ifdef ENABLE_BREAK
	// flush the cout
	std::cout << std::endl;
	
	// pause (Windows only)
	system("pause");
#endif
}