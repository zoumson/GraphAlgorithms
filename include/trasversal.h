#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <set>

void dfs_for(std::map<char, std::vector<char>> graph, char start);
void bfs_for(std::map<char, std::vector<char>> graph, char start);
void dfs_rec(std::map<char, std::vector<char>> graph, char start);
void bfs_rec(std::map<char, std::vector<char>> graph, char start);
bool has_path(std::map<char, std::vector<char>> graph, char src, char dest);
std::map<char, std::vector<char>> unDirectGraphFromEdge(std::vector<std::pair<char, char>> edg);
bool has_path_avoid_cycle_un_direct_graph(std::map<char, std::vector<char>> graph, char src, char dest, std::set<char> vis);

bool explore(std::map<char, std::vector<char>> graph, char start, std::set<char> &vis);
int exploreSize(std::map<char, std::vector<char>> graph, char start, std::set<char> &vis);
int largestCom(std::map<char, std::vector<char>> graph);
int count_connect(std::map<char, std::vector<char>> graph);
int bfs_dist(std::map<char, std::vector<char>> graph, char src, char dst);
int short_path(std::vector<std::pair<char, char>> edg, char src, char dst);
bool island(std::vector<std::vector<char>> grid, int r, int c, std::set<std::pair<int, int>> &vis);
int count_island(std::vector<std::vector<char>> grid);
