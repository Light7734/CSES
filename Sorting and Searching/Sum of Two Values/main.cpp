// https://www.cses.fi/problemset/task/1640

#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

int main()
{
	// Don't flush w/ cout
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Input
	uint32_t n, x;
	std::vector<std::pair<uint32_t, uint32_t>> entries;

	std::cin >> n >> x;
	entries.resize(n);

	for (uint32_t i = 0; i < n; i++)
	{
		uint32_t val;
		std::cin >> val;

		entries[i] = { val, i + 1 };
	}

	// Sort
	std::sort(entries.begin(), entries.end(), [](const auto& lhs, const auto& rhs) {
		return lhs.first < rhs.first;
	});

	// Find the end position of search
	auto it = std::upper_bound(entries.begin(), entries.end(), x - entries.begin()->first, [](const auto& lhs, const auto& rhs) {
		return lhs < rhs.first;
	});

	if (it == entries.end())
		it--;

	for (uint32_t i = 0; i < n; i++)
	{
		uint32_t a = entries[i].first;
		uint32_t b = 0u;
		if (a > std::ceil(x / 2.0f))
			break;

		for (auto rev_it = it; rev_it != entries.begin() && rev_it->second != entries[i].second; rev_it--)
		{
			b = rev_it->first;
			if (a + b == x)
			{
				std::cout << entries[i].second << ' ' << rev_it->second;
				return 0;
			}
			else if (b > x - a)
			{
				it = rev_it;
			}
			else if (a + b < x)
				break;
		}
	}

	std::cout << "IMPOSSIBLE";
	return 0;
}
