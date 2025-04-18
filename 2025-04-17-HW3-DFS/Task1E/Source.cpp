
#include <vector>
#include <iostream>

void dfs( std::vector<std::vector<int>> tree )
{
    std::vector<int> stack;
    std::vector<int> used(tree.size(), 0);
    std::vector<int> connectivity_component;
    std::vector<int> connectivity_component_size;
    int ans = 1;

    connectivity_component.reserve(tree.size());

    for (int i = 0; i < tree.size(); ++i)
    {
        if (!!used[i])
        {
            continue;
        }
        int component_size = connectivity_component.size();

        stack.push_back(i);
        connectivity_component.push_back(i);
        used[i] = ans;

        while (!stack.empty())
        {
            int tmp = stack.back();
            stack.pop_back();

            for (int i = 0; i < tree[tmp].size(); ++i)
            {
                if (!used[tree[tmp][i]])
                {
                    used[tree[tmp][i]] = ans;
                    stack.push_back(tree[tmp][i]);
                    connectivity_component.push_back(tree[tmp][i]);
                }
            }
        }
        
        connectivity_component_size.push_back(connectivity_component.size() - component_size);
        ans += 1;
    }

    std::cout << ans - 1 << "\n";
    int prev_size = 0;
    for (int i = 0; i < connectivity_component_size.size(); ++i)
    {
        std::cout << connectivity_component_size[i] << "\n";
        for (int j = 0; j < connectivity_component_size[i]; ++j)
        {
            std::cout << connectivity_component[prev_size + j] + 1 << " ";
        }
        prev_size += connectivity_component_size[i];
        std::cout << "\n";
    }
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

    dfs(tree);

    return 0;
}