
#include <vector>
#include <iostream>

bool dfs( std::vector<std::vector<int>> tree, int k )
{
    std::vector<int> stack;
    std::vector<int> used(tree.size(), 0);

    stack.push_back(k);
    used[k] = 1;

    while (!stack.empty())
    {
        int tmp;

        tmp = stack.back();
        stack.pop_back();

        for (int i = 0; i < tree[tmp].size(); ++i)
        {
            if (!used[tree[tmp][i]])
            {
                used[tree[tmp][i]] = 1;
                stack.push_back(tree[tmp][i]);
            }
        }
    }

    for (int i = 0; i < used.size(); ++i)
    {
        if (used[i] == 0)
        {
            return false;
        }
    }

    return true;
}

int main( void )
{
    std::vector<std::vector<int>> tree;
    int n, k;

    std::cin >> n >> k;

    k -= 1;
    tree.resize(n);
    do
    {
        int x, y;

        std::cin >> x;
        if (x == 0)
        {
            break;
        }
        else
        {
            std::cin >> y;
            tree[x - 1].push_back(y - 1);
        }
    } while (true);

    std::cout << (dfs(tree, k) ? "Yes" : "No");

    return 0;
}