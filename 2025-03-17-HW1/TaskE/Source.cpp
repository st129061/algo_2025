#include <iostream>

int main(int argc, char* argv[])
{
	long long n = 0;
	long long nums[2] = {0, 0};

	std::cin >> n >> nums[0] >> nums[1];

	n += 1;

	long long * track[2] = {new long long[n] { 0 }, new long long[n] { 0 }};

	for (long long k = 0; k < 2; ++k)
	{
		long long tmp = nums[k];

		for (long long i = (long long)log2(tmp) + 1; i >= 0; --i)
		{
			track[k][i] = tmp;
			tmp = tmp % 2 == 0 ? tmp / 2 : (tmp - 1) / 2;
		}
	}

	long long ind = 0;
	bool end = false;

	for (long long i = n - 1; i >= 0 && !end; --i)
	{
		for (long long j = n - 1; j >= 0 && !end; --j)
		{
			if (track[0][i] == track[1][j] && track[1][j] != 0)
			{
				ind = i;
				end = true;
			}
		}
	}

	std::cout << track[0][ind];

	return EXIT_SUCCESS;
}
