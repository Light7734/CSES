#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef ENABLE_BREAK
	// flush the cout
	std::cout << std::endl;
	
	// pause (Windows only)
	system("pause");
#endif
}