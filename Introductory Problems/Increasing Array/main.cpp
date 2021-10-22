/* https://www.cses.fi/problemset/task/1094 */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t count = 0u;
    uint64_t in = 0u;
    uint64_t in_prev = 0u;
    uint64_t steps = 0u;

    std::cin >> count;
    for(uint32_t i = 0u; i < count; i++)
    {
        std::cin >> in;
        
        if(in < in_prev)
            steps += in_prev - in;
        else
            in_prev = in;
    }

    std::cout << steps;

#ifdef ENABLE_BREAK
	// flush
	std::cout << std::flush;
	
	// ignore
	std::cin.ignore();
	
	// pause
	std::cin.get();
#endif
}