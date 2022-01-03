#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n, m;
    std::set<std::pair<uint32_t, uint32_t>> tickets;

    std::cin >> n >> m;

    for(uint32_t i = 0u; i < n; i++)
    {
        uint32_t ticket;
        std::cin >> ticket;
        tickets.insert({ticket, i});
    }

    for(uint32_t i = 0u; i < m; i++)
    {
         uint32_t price;
         std::cin >> price;

         auto it = tickets.lower_bound({price + 1, 0});
         if(it == tickets.begin())
             std::cout << -1 << '\n';
         else
         {
             it--;
             std::cout << (*it).first << '\n';
             tickets.erase(it);
         }
    }
}
