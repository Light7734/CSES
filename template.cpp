#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef ENABLE_BREAK
	// flush
	std::cout << std::flush;
	
	// ignore
	std::cin.ignore();
	
	// pause
	std::cin.get();
#endif
}