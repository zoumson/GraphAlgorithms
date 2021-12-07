#include "trasversal.h"

void dfs_for(std::map<char, std::vector<char>> graph, char start)
{

    std::cout << "DFS\n";
    std::stack<char> s;
    s.push(start);
    char current;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        std::cout << current << std::endl;
        for (auto &c : graph[current])
        {
            s.push(c);
        }
    }
}
void bfs_for(std::map<char, std::vector<char>> graph, char start)
{

    std::cout << "BFS\n";
    std::queue<char> s;
    s.push(start);
    char current;
    while (!s.empty())
    {
        current = s.front();
        s.pop();
        std::cout << current << std::endl;
        for (auto &c : graph[current])
        {
            s.push(c);
        }
    }
}
void dfs_rec(std::map<char, std::vector<char>> graph, char start)
{

    std::cout << start << std::endl;
    for (auto &n : graph[start])
    {
        dfs_rec(graph, n);
    }
}
void bfs_rec(std::map<char, std::vector<char>> graph, char start)
{
    std::cout << start << std::endl;
    for (auto &n : graph[start])
    {
        std::cout << n << std::endl;
        bfs_rec(graph, n);
    }
}

bool has_path(std::map<char, std::vector<char>> graph, char src, char dest)
{
    std::stack<char> s;
    s.push(src);
    char current;
    while (!s.empty())
    {
        current = s.top();
        if (current == dest)
        {
            return true;
        }
        s.pop();
        for (auto &c : graph[current])
        {
            s.push(c);
        }
    }
    return false;
}

std::map<char, std::vector<char>> unDirectGraphFromEdge(std::vector<std::pair<char, char>> edg)
{
    std::map<char, std::vector<char>> graf;
    for (auto &ed : edg)
    {
        graf[ed.first].push_back(ed.second);
        graf[ed.second].push_back(ed.first);
    }
    return graf;
}

bool has_path_avoid_cycle_un_direct_graph(std::map<char, std::vector<char>> graph, char src, char dst, std::set<char> vis)
{

    if (src == dst)
    {
        return true;
    }
    if (vis.find(src) != vis.end())
    {
        return false;
    }
    vis.insert(src);

    for (auto &n : graph[src])
    {
        if (has_path_avoid_cycle_un_direct_graph(graph, n, dst, vis))
        {
            return true;
        }
    }
    return false;
}

static void dfs_rec(std::map<char, std::vector<char>> graph, char start, std::set<char> vis)
{

    std::cout << start << std::endl;
    for (auto &n : graph[start])
    {
        dfs_rec(graph, n);
    }
}

bool explore(std::map<char, std::vector<char>> graph, char start, std::set<char> &vis)
{
    if (vis.find(start) != vis.end())
    {
        return false;
    }
    vis.insert(start);

    for (auto &n : graph[start])
    {
        explore(graph, n, vis);
    }
    return true;
}

int count_connect(std::map<char, std::vector<char>> graph)
{
    std::set<char> vis;
    int cc = 0;
    for (auto &[k, v] : graph)
    {

        if (explore(graph, k, vis) == true)
        {
            cc++;
        }
    }
    return cc;
}

int exploreSize(std::map<char, std::vector<char>> graph, char start, std::set<char> &vis)
{
    if (vis.find(start) != vis.end())
    {
        return 0;
    }
    vis.insert(start);
    int m = 1;
    for (auto &n : graph[start])
    {
        m += exploreSize(graph, n, vis);
    }
    return m;
}

int largestCom(std::map<char, std::vector<char>> graph)
{
    std::set<char> vis;
    int cc = 0;
    for (auto &[k, v] : graph)
    {
        int tmp = exploreSize(graph, k, vis);
        if (tmp > cc)
        {
            cc = tmp;
        }
    }
    return cc;
}

int bfs_dist(std::map<char, std::vector<char>> graph, char src, char dst)
{
    std::queue<std::pair<char, int>> s;
    s.push({src, 0});
    std::set<char> vis;
    vis.insert(src);
    std::pair<char, int> current;
    while (!s.empty())
    {
        current = s.front();
        s.pop();

        if (current.first == dst)
        {
            return current.second;
        }

        for (auto &n : graph[current.first])
        {
            if (vis.find(n) == vis.end())
            {
                s.push({n, current.second + 1});
                vis.insert(n);
            }
        }
    }

    return -1;
}

int short_path(std::vector<std::pair<char, char>> edg, char src, char dst)
{
    std::map<char, std::vector<char>> g = unDirectGraphFromEdge(edg);
    return bfs_dist(g, src, dst);
}

bool island(std::vector<std::vector<char>> grid, int r, int c, std::set<std::pair<int, int>> &vis)
{
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
    {
        return false;
    }
    if (grid[r][c] == 'w')
    {
        return false;
    }
    if (vis.find({r, c}) != vis.end())
    {
        return false;
    }
    vis.insert({r, c});
    island(grid, r + 1, c, vis);
    island(grid, r - 1, c, vis);
    island(grid, r, c + 1, vis);
    island(grid, r, c - 1, vis);
    return true;
}
int count_island(std::vector<std::vector<char>> grid)
{
    int cc = 0;
    std::set<std::pair<int, int>> vis;
    // if (island(grid, 0, 1, vis))
    //++cc;

    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (island(grid, r, c, vis))
            {
                ++cc;
            }
        }
    }

    return cc;
}