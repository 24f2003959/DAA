#include <iostream>
#include "Graph.h"

int main() {
    Graph<int> graph(6);

    graph + 1;
    graph + 2;
    graph + 3;
    graph + 4;
    graph + 5;

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    std::cout << "Original graph:\n";
    std::cout << graph;

    std::cout << "\nRemoving vertex 3:\n";
    graph - 3;
    std::cout << graph;

    return 0;
}
