#pragma once
#include "adjNode.h"
#include "graphEdge.h"

namespace za
{
    class DiaGraph
    {
        // insert new nodes into adjacency list from given graph
        za::adjNode *getAdjListNode(int value, int weight, za::adjNode *head);

        int N; // number of nodes in the graph
    public:
        za::adjNode **head; // adjacency list as array of pointers
        // Constructor
        DiaGraph(graphEdge edges[], int n, int N);
        // Destructor
        ~DiaGraph();
    };
}