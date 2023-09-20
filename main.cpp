#include <iostream>
#include <list>
#include <map>

#include "AddOnlyGraph.cpp"


using namespace std;


int main() {
    AddOnlyGraph<int> graph;
    // Verify that the graph is empty
    cout << "The graph is empty: " << boolalpha << graph.empty() << endl;

    // Add some nodes
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");

    // Add some edges
    graph.addEdge("A", "B", 1);


    // Verify that the graph is empty
    cout << "The graph is empty: " << boolalpha << graph.empty() << endl;

    // Print the graph
    graph.print();


    return 0;
}
