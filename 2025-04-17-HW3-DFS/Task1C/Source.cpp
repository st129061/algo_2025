
#include <vector>
#include <iostream>

bool dfs( std::vector<std::vector<int>> tree )
{
    std::vector<int> stack;
    std::vector<int> stack_prev;
    std::vector<int> used(tree.size(), 0);

    stack.push_back(0);
    stack_prev.push_back(-1);
    used[0] = 1;

    while (!stack.empty())
    {
        int tmp = stack.back();
        int prev = stack_prev.back();

        stack.pop_back();
        stack_prev.pop_back();

        for (int i = 0; i < tree[tmp].size(); ++i)
        {
            if (!used[tree[tmp][i]])
            {
                used[tree[tmp][i]] = 1;
                stack_prev.push_back(tmp);
                stack.push_back(tree[tmp][i]);
            }
            else if (prev != tree[tmp][i])
            {
                used[tree[tmp][i]] = 2;
            }
        }
    }

    for (int i = 0; i < used.size(); ++i)
    {
        if (used[i] == 0 || used[i] == 2)
        {
            return false;
        }
    }

    return true;
}

int main( void )
{
    std::vector<std::vector<int>> tree;
    int n;

    std::cin >> n;

    tree.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp;

            std::cin >> tmp;
            if (tmp == 1)
            {
                tree[i].push_back(j);
            }
        }
    }

    std::cout << (dfs(tree) ? "YES" : "NO");

    return 0;
}