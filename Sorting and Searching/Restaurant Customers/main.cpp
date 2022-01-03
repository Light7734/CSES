#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n;
    std::vector<std::pair<uint32_t, bool>> customers;

    std::cin >> n;
    customers.reserve(n * 2);
    
    for(uint32_t i = 0; i < n; i++)
    {
        uint32_t arrival, leaving;
        std::cin >> arrival;
        std::cin >> leaving;
        
        customers.push_back({arrival, true});
        customers.push_back({leaving, false});
    }
    std::sort(customers.begin(), customers.end());

    int32_t tempCount = 0u;
    int32_t maxCount = 0u;
    int32_t currentHour = 0u;
    int32_t currentCount = 0u;
    for(uint32_t i = 0; i < n * 2; i++)
    {
        auto customer = customers[i];

        if(currentHour != customer.first)
        {
            currentHour = customer.first;

            currentCount += tempCount;
            tempCount = 0u;
            
            maxCount = maxCount < currentCount ? currentCount : maxCount;
        }

        tempCount += customer.second ? +1 : -1;
    }

    currentCount += tempCount;
    maxCount = maxCount < currentCount ? currentCount : maxCount;

    std::cout << maxCount;
}
