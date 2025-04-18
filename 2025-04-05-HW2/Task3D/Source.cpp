
#include <iostream>
#include <string>

void my_print( int mass[1000], int N, int index = 0 )
{
    if (index >= N)
    {
        return;
    }
    my_print(mass, N, index + 1);
    std::cout << mass[index] << " ";
}

int main( void )
{
    int mass[1000] = { 0 };

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> mass[i];
    }

    my_print(mass, N);

    return 0;
}
