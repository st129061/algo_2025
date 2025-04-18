
#include <iostream>
#include <string>


void money_counting( int active, int N, int M, int money[16], int use[16], int save_use[16], int &save_min )
{
    if (N == 0)
    {
        int min = 0;
        for (int i = 0; i < M; ++i)
        {
            min += use[i];
        }

        if (min < save_min || save_min == -1)
        {
            save_min = min;
            for (int i = 0; i < M; ++i)
            {
                save_use[i] = use[i];
            }
        }
        return;
    }

    if (N < 0 || active >= M)
    {
        return;
    }

    
    // not include active
    use[active] = 0;
    money_counting(active + 1, N, M, money, use, save_use, save_min);
    
    // include 1 active
    use[active] = 1;
    money_counting(active + 1, N - money[active], M, money, use, save_use, save_min);

    // incude 2 active
    use[active] = 2;
    money_counting(active + 1, N - 2 * money[active], M, money, use, save_use, save_min);
    
    use[active] = 0;
}

int main( void )
{
    int money[16] = { 0 };
    int save_min = -1;
    int use[16] = { 0 };
    int save_use[16] = { 0 };

    int N, M;
    std::cin >> N >> M;

    int sum = 0;
    for (int i = 0; i < M; ++i)
    {
        std::cin >> money[i];
        sum += money[i];
    }

    if (sum * 2 < N)
    {
        std::cout << "-1";
        return 0;
    }

    money_counting(0, N, M, money, use, save_use, save_min);

    if (save_min == -1)
    {
        std::cout << "0";
    }
    else
    {
        std::cout << save_min << "\n";
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < save_use[i]; ++j)
            {
                std::cout << money[i] << " ";
            }
        }
    }

    return 0;
}
