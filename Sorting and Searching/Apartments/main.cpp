#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // variables
    uint32_t applicants, apartments, maxDiff;
    std::vector<uint32_t> desiredSizes, apartmentsSize;
    std::cin >> applicants >> apartments >> maxDiff;
    desiredSizes.reserve(applicants);
    apartmentsSize.reserve(apartments);

    // applicants' desired apartment size
    for(uint32_t i = 0; i < applicants; i++)
    {
        uint32_t temp;
        std::cin >> temp;
        desiredSizes.push_back(temp); 
    }

    // appartments' size
    for(uint32_t i = 0; i < apartments; i++)
    {
        uint32_t temp;
        std::cin >> temp;
        apartmentsSize.push_back(temp);
    }

    // sort vectors
    std::sort(desiredSizes.begin(), desiredSizes.end());
    std::sort(apartmentsSize.begin(), apartmentsSize.end());
    uint32_t apartmentIndex = 0u;
    uint32_t validCount = 0u;

    for(uint32_t i = 0; i < applicants && apartmentIndex < apartments; i++)
    {
        const int32_t desiredMin = desiredSizes[i] - maxDiff;
        const int32_t desiredMax = desiredSizes[i] + maxDiff;
        const int32_t apartmentSize = apartmentsSize[apartmentIndex];

        // valid - assign appartment
        if(apartmentSize >= desiredMin && apartmentSize <= desiredMax)
        {
             validCount++;
             apartmentIndex++;
             continue;
        }
        
        // too big - move to the next applicant
        if(apartmentSize > desiredMax)
        {
            continue;
        }

        // too small - move to the next apartment
        if(apartmentSize < desiredMin)
        {
            apartmentIndex++;
            i--;
            continue;
        }

    }
    
    std::cout << validCount;

#ifdef ENABLE_BREAK
	// flush
	std::cout << std::flush;
	
	// ignore
	std::cin.ignore();
	
	// pause
	std::cin.get();
#endif
}
