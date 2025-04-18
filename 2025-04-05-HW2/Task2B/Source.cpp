
#include <iostream>
#include <string>

/*
123456
012345
*/
int free_space( int place[12][12], int x, int y )
{
    int res = 0;

    if (place[x][y] == 0)
    {
        res += 1;

        place[x][y] = 1;
        res += free_space(place, x + 1, y);
        res += free_space(place, x, y + 1);
        res += free_space(place, x - 1, y);
        res += free_space(place, x, y - 1);
    }

    return res;
}

int main( void )
{
    int place[12][12];

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            place[i][j] = 1;
        }
    }
    
    int size;
    std::cin >> size;

    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            char tmp;
            std::cin >> tmp;
            if (tmp == '.')
            {
                place[i][j] = 0;
            }
        }
    }
    
    int x, y;
    std::cin >> x >> y;

    std::cout << free_space(place, x, y);

    return 0;
}
