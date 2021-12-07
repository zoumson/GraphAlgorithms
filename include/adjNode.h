
#pragma once
// stores adjacency list items
namespace za
{
    struct adjNode
    {
        int val, cost;
        adjNode *next;
    };
}