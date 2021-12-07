#pragma once
#include "adjNode.h"
#include <iostream>

namespace za
{
    // print all adjacent vertices of given vertex
    void display_AdjList(za::adjNode *ptr, int i)
    {
        while (ptr != nullptr)
        {
            std::cout << "(" << i << ", " << ptr->val
                      << ", " << ptr->cost << ") ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
}
