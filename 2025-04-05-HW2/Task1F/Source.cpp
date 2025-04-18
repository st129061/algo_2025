                                    
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
    
    std::cout << s[index];

    my_print(s, index + 1);

    if (s[index] == '(')
    {
        std::cout << ')';
    }
    else
    {
        std::cout << s[index];
    }
}

int main( void )
{
    std::string in;
    std::cin >> in;

    my_print(in, 0);

    return 0;
}
