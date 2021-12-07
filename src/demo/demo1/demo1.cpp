#include "trasversal.h"
#include <iostream>

int main(int argc, char const *argv[])
{

    std::map<char, std::vector<char>> myGraph;
    myGraph['a'] = {'b', 'c'};
    myGraph['b'] = {'d'};
    myGraph['c'] = {'e'};
    myGraph['d'] = {'f'};
    myGraph['e'] = {};
    myGraph['f'] = {};
    std::vector<std::pair<char, char>> edg = {{'i', 'j'}, {'k', 'i'}, {'m', 'k'}, {'k', 'l'}, {'o', 'n'}};
    // bfs_for(myGraph, 'a');
    // std::cout << "\nRec\n";
    // bfs_rec(myGraph, 'a');
    // bfs_rec(myGraph, 'a');
    // bfs_for(myGraph, 'a');
    /*
        if (has_path_avoid_cycle_un_direct_graphmyGraph, 'e', 'b'))
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }
    */
    std::map<char, std::vector<char>> myGraph2 = unDirectGraphFromEdge(edg);

    for (auto &[key, val] : myGraph2)
    {
        std::cout << key << ":";
        for (auto &v : val)
        {
            std::cout << "[" << v << "]";
        }
        std::cout << "\n";
    }
    std::set<char> vis;
    if (has_path_avoid_cycle_un_direct_graph(myGraph2, 'o', 'j', vis))
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "connect[" << count_connect(myGraph2) << "]\n";

    std::map<char, std::vector<char>> myGraph3;
    myGraph3['0'] = {'8', '1', '5'};
    myGraph3['1'] = {'0'};
    myGraph3['5'] = {'0', '8'};
    myGraph3['8'] = {'0', '5'};
    myGraph3['2'] = {'3', '4'};
    myGraph3['3'] = {'2', '4'};
    myGraph3['4'] = {'3', '2'};
    std::cout << "large[" << largestCom(myGraph3) << "]\n";

    std::vector<std::pair<char, char>> edg2 = {{'w', 'x'}, {'x', 'y'}, {'z', 'y'}, {'z', 'v'}, {'w', 'v'}};
    std::cout << "short path[" << short_path(edg2, 'w', 'z') << "]\n";
    std::vector<std::vector<char>> grid1 = {
        {'w', 'l', 'w', 'w', 'w'},
        {'w', 'l', 'w', 'w', 'w'},
        {'w', 'w', 'w', 'l', 'w'},
        {'w', 'w', 'l', 'l', 'w'},
        {'l', 'w', 'w', 'l', 'l'},
        {'l', 'l', 'w', 'w', 'w'}};
    std::cout << "islands[" << count_island(grid1) << "]\n";
    /* code */
    return 0;
}
