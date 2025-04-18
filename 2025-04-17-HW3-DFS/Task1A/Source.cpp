
#include <vector>
#include <iostream>

int dfs( std::vector<std::vector<int>> tree, int find )
{
    std::vector<int> stack;
    std::vector<int> used(tree.size(), 0);
    int ans = 0;

    stack.push_back(find);
    used[find] = 1;

    while (!stack.empty())
    {
        int tmp;

        tmp = stack.back();
        stack.pop_back();

        for (int i = 0; i < tree[tmp].size(); ++i)
        {
            if (!used[tree[tmp][i]])
            {
                ans += 1;
                used[tree[tmp][i]] = 1;
                stack.push_back(tree[tmp][i]);
            }
        }
    }

    return ans;
}

int main( void )
{
    std::vector<std::vector<int>> tree;
    int n, find;

    std::cin >> n >> find;

    find -= 1;
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

    std::cout << dfs(tree, find);

    return 0;
}