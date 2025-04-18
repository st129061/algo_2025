                          
#include <iostream>
#include <string>

/*
123456
012345
*/
int get_count_connect( int * connect_mass[2], int size, int delete_message )
{
    int res = 1;

    for (int i = 0; i < size; ++i)
    {
        if (connect_mass[1][i] == delete_message)
        {
            res += get_count_connect(connect_mass, size, connect_mass[0][i]);
        }
    }

    return res;
}

int main( void )
{
    int size;
    std::cin >> size;

    int * message[2] = { new int[size], new int[size] };

    for (int i = 0; i < size; ++i)
    {
        std::cin >> message[0][i] >> message[1][i];
    }

    int delete_msg;
    std::cin >> delete_msg;
    std::cout << get_count_connect(message, size, delete_msg);

    delete[] message[0];
    delete[] message[1];

    return 0;
}
