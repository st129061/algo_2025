
#include <iostream>
#include <string>

int get_nums( std::string s, int index )
{
    if (s.size() == index)
    {
        return 0;
    }

    return (s[index] >= '0' && s[index] <= '9') + get_nums(s, index + 1);
}

int main( void )
{
    std::string in;
    std::cin >> in;
    std::cout << (get_nums(in, 0));

    return 0;
}
