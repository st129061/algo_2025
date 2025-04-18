
#include <iostream>
#include <string>

/*
123456
012345
*/
void my_print( std::string s, int index )
{
    if (index >= s.size())
    {
        return;
    }
    if (s.size() == (index + 1) * 2)
    {
        std::cout << s[index] << s[s.size() - index - 1];
    }
    else if (s.size() == index * 2 + 1)
    {
        std::cout << s[index];
    }
    else
    {
        std::cout << s[index] << "(";
        my_print(s, index + 1);
        std::cout << ")" << s[s.size() - index - 1];
    }
}

int main( void )
{
    std::string in;
    std::cin >> in;

    my_print(in, 0);

    return 0;
}
