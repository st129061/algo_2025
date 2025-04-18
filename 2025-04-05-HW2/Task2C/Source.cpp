
#include <iostream>
#include <string>

/*

3
1 2 3
1 0 0
1 1 0
0 1 1
1 1 1

1 2 3 4
0 0 0 0
1 0 0 0
1 1 0 0
0 1 1 0
1 0 1 0
0 0 1 1
1 1 1 1

0 1 2 3 4 5
0 0 0 0 0 0
1 1 0 0 0 0
0 1 1 0 0 0
1 0 1 0 0 0
0 0 1 1 0 0
1 1 1 1 0 0
1 0 1 1 0 0
0 0 0 1 1 0

*/

void occupy_space( int place[10], int occup_place );

void free_space( int place[10], int free_place )
{
    if (place[free_place] == 0)
    {
        return;
    }

    if (free_place == 1)
    {
        std::cout << "-1" << " ";
        place[1] = 0;
        return;
    }

    occupy_space(place, free_place - 1);
    for (int i = free_place - 2; i > 0; --i)
    {
        free_space(place, i);
    }

    std::cout << "-" << free_place << " ";
    place[free_place] = 0;
}

void occupy_space( int place[10], int occup_place )
{
    if (place[occup_place] == 1)
    {
        return;
    }
    
    if (occup_place == 1)
    {
        std::cout << "1" << " ";
        place[1] = 1;
        return;
    }

    occupy_space(place, occup_place - 1);
    for (int i = occup_place - 2; i > 0; --i)
    {
        free_space(place, i);
    }
    std::cout << occup_place << " ";
    place[occup_place] = 1;
}

int main( void )
{
    int place[11];

    for (int i = 0; i < 11; ++i)
    {
        place[i] = 0;
    }

    int N;
    std::cin >> N;

    for (int i = N; i > 0; --i)
    {
        occupy_space(place, i);
    }

    return 0;
}
