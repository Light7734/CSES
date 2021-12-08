#include <iostream>
#include <unordered_set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n_in = 0u;
    uint32_t n_unique = 0u;
    std::cin >> n_in;

    std::unordered_set<uint32_t> uniqueSet(static_cast<size_t>(n_in));
    
    for(uint32_t i = 0u; i < n_in; i++)
    {
        uint32_t in;
        std::cin >> in;

        if(uniqueSet.find(in) == uniqueSet.end())
        {
            uniqueSet.insert(in);
            n_unique++;
        }
    } 

    std::cout << n_unique;

#ifdef ENABLE_BREAK
	// flush
	std::cout << std::flush;
	
	// ignore
	std::cin.ignore();
	
	// pause
	std::cin.get();
#endif
}