
#include <iostream>
#include <string>

/*
1
1

2
12
43

3
123
894
765

4
1)1  2  3  4
2)12 13 14 5
3)11 16 15 6
4)10 9  8  7

5

1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
void set_spiral( int ** place, int N, int level, int num, int x, int y )
{
    if (level > N / 2)
    {
        return;
    }
    
    for (int i = 0; i < N - level * 2; ++i)
    {
        place[y][x + i] = num++;
    }
    for (int i = 1; i < N - level * 2; ++i)
    {
        place[y + i][x + N - level * 2 - 1] = num++;
    }
    for (int i = 1; i < N - level * 2; ++i)
    {
        place[y + N - level * 2 - 1][x + N - level * 2 - 1 - i] = num++;
    }
    for (int i = 1; i < N - level * 2 - 1; ++i)
    {
        place[y + N - level * 2 - 1- i][x] = num++;
    }

    set_spiral(place, N, level + 1, num, x + 1, y + 1);
}

int main( void )
{
    int ** place = new int *[11];

    for (int i = 0; i < 11; ++i)
    {
        place[i] = new int[11];
        for (int j = 0; j < 11; ++j)
        {
            place[i][j] = 0;
        }
    }

    int N;
    std::cin >> N;

    set_spiral(place, N, 0, 1, 1, 1);

    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 1; j < N + 1; ++j)
        {
            std::cout << place[i][j] << "  ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 11; ++i)
    {
        delete[] place[i];
    }
    delete[] place;

    return 0;
}
