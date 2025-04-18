
#include <iostream>

bool get_from( int start, int end )
{
    if (start == end)
    {
        return true;
    }
    if (start >= end)
    {
        return false;
    }

    return get_from(start + 3, end) || get_from(start + 5, end);
}

int main( void )
{
    int N;
    std::cin >> N;
    std::cout << (get_from(1, N) ? "YES" : "NO");

    return 0;
}
