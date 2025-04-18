
#include <iostream>
#include <string>

int nod( int a, int b )
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        a = tmp;
    }
    if (a % b == 0)
    {
        return b;
    }

    return nod(b, a % b);
}

int main( void )
{
    int a, b;
    std::cin >> a >> b;

    std::cout << nod(a, b);

    return 0;
}
