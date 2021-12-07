#pragma once
#include "adjNode.h"
#include "graphEdge.h"

class DiaGraph
{
    // insert new nodes into adjacency list from given graph
    adjNode *getAdjListNode(int value, int weight, adjNode *head);

    int N; // number of nodes in the graph
public:
    adjNode **head; // adjacency list as array of pointers
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N);
    // Destructor
    ~DiaGraph();
};
