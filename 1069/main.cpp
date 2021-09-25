#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string dna;
    std::cin >> dna;

    char cc = dna[0];
    uint32_t repetition = 0;
    uint32_t high_rep = 0u;

    for(const auto c : dna)
    {
        if(c == cc)
            repetition++;
        else
        {
            cc = c;
            high_rep = repetition > high_rep ? repetition : high_rep; 
            repetition = 1;
        }
    }

    high_rep = repetition > high_rep ? repetition : high_rep; 
    std::cout << high_rep;

#ifdef ENABLE_BREAK
	// flush the cout
	std::cout << std::endl;

	// pause (Windows only)
	system("pause > nul");
#endif
}