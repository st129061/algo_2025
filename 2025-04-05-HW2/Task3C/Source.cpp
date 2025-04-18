
#include <iostream>
#include <string>

void chain( int n, int k, int mass[7], int index = 0 )
{
    if (index >= n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << mass[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = 1; i <= k; ++i)
    {
        mass[index] = i;
        chain(n, k, mass, index + 1);
    }
}

int main( void )
{
    int mass[7] = { 0 };

    int n, k;
    std::cin >> n >> k;

    chain(n, k, mass);

    return 0;
}
