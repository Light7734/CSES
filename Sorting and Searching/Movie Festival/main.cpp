// https://www.cses.fi/problemset/task/1629

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    uint32_t n;
    std::cin >> n;

    std::vector<std::pair<uint32_t, uint32_t>> movies;
    movies.resize(n);


    for(uint32_t i = 0; i < n; i++)
    {
        uint32_t start, end;
        std::cin >> start >> end;
        movies[i] = {start, end};
    }

    std::sort(movies.begin(), movies.end(), [](const std::pair<uint32_t,uint32_t>& left, const std::pair<uint32_t,uint32_t>& right)
    {
            return left.second == right.second ? left.first < right.first : left.second < right.second;
    });

    uint32_t totalWatched = 0u;
    uint32_t watchingUntil = 0u;
    for(uint32_t i = 0; i < n; i++)
    {
        if(movies[i].first >= watchingUntil)
        {
            totalWatched++;
            watchingUntil = movies[i].second;
        }
    }

    std::cout << totalWatched;
}
