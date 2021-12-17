#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int32_t numChild, maxWeight;
    std::vector<int32_t> childsWeight;
    std::cin >> numChild >> maxWeight;
    childsWeight.resize(numChild);
 
    for(int32_t i = 0; i < numChild; i++)
        std::cin >> childsWeight[i];
    
    std::sort(childsWeight.begin(), childsWeight.end());
 
    int32_t numGondola = 0u;
	int32_t* reverse_i = &childsWeight[0];
	int32_t* i = &childsWeight[numChild - 1];
 
    for(; i >= reverse_i; i--)
    {
        const int32_t childWeight = *i;
 
        if(i > reverse_i)
        {
            const int32_t otherChildWeight = *reverse_i;
            if(otherChildWeight + childWeight <= maxWeight)
                reverse_i++;
        }
 
        numGondola++;
    }
 
    std::cout << numGondola;
 
    return 0;
}
