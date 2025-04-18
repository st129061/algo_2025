
#include <iostream>
#include <string>

char get_max_num( std::string s, int index )
{
    if (s.size() == index)
    {
        return 0;
    }

    return std::max(s[index], get_max_num(s, index + 1));
}

int main( void )
{
    std::string in;
    std::cin >> in;
    std::cout << (get_max_num(in, 0));

    return 0;
}
