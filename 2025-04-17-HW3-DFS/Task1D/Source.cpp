
#include <vector>
#include <iostream>

bool dfs( std::vector<std::vector<int>> tree )
{
    std::vector<int> stack;
    std::vector<int> stack_num_table(tree.size(), 0);
    std::vector<int> used(tree.size(), 0);

    for (int i = 0; i < tree.size(); ++i)
    {
        if (used[i] == 1)
        {
            continue;
        }
        stack.push_back(i);
        stack_num_table[i] = 1;
        used[i] = 1;

        while (!stack.empty())
        {
            int tmp = stack.back();
            int tmp_table = stack_num_table[tmp];

            stack.pop_back();

            for (int i = 0; i < tree[tmp].size(); ++i)
            {
                if (!used[tree[tmp][i]])
                {
                    used[tree[tmp][i]] = 1;
                    stack_num_table[tree[tmp][i]] = 3 - tmp_table;
                    stack.push_back(tree[tmp][i]);
                }
                else if (stack_num_table[tree[tmp][i]] == tmp_table)
                {
                    used[tree[tmp][i]] = 2;
                }
            }
        }

        for (int i = 0; i < used.size(); ++i)
        {
            if (used[i] == 2)
            {
                return false;
            }
        }
    }

    return true;
}

int main( void )
{
    std::vector<std::vector<int>> tree;
    int n, m;

    std::cin >> n >> m;

    tree.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;

        std::cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }

    std::cout << (dfs(tree) ? "YES" : "NO");

    return 0;
}