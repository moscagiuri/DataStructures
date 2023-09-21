#include <iostream>

#include "AddOnlyGraph.cpp"


using namespace std;


// Italian alias for updateAdjacencies
void aggiorna_adiacenti(AddOnlyGraph<int>& graph, const typename AddOnlyGraph<int>::Node& node) {
    int value = 0;
    for (auto adj : graph.adiacenti(node)) {
        for (auto a : graph.adiacenti(adj)) {
            value += graph.leggiArco(adj, a);
        }
        graph.scriviNodo(adj, value);
        value = 0;
    }
}

// Build a graph
template<class T>
AddOnlyGraph<T> buildGraph() {
    AddOnlyGraph<T> graph;

    // Add some nodes
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");
    graph.addNode("G");

    // Add some edges
    graph.addEdge("A", "B", 1);
    graph.addEdge("A", "C", 2);

    graph.addEdge("B", "G", 3);

    graph.addEdge("C", "B", 4);
    graph.addEdge("C", "D", 1);
    graph.addEdge("C", "E", 2);

    graph.addEdge("D", "F", 1);
    graph.addEdge("D", "B", 2);

    graph.print();

    return graph;

}

int main() {
    AddOnlyGraph<int> graph;

    // Add some nodes
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");


    // Add some edges
    graph.addEdge("A", "B", 2);
    graph.addEdge("A", "C", 1);
    graph.addEdge("B", "C", 4);
    graph.addEdge("B", "D", 1);
    graph.addEdge("B", "E", 2);
    graph.addEdge("C", "F", 3);

    // Print the graph
    cout << "Graph:" << endl;
    graph.print();

    // Print the edges and values
    cout << "B -> C: " << graph.readEdge("B", "C") << endl;
    cout << "B -> D: " << graph.readEdge("B", "D") << endl;
    cout << "B -> E: " << graph.readEdge("B", "E") << endl;
    cout << "C -> F: " << graph.readEdge("C", "F") << endl;

    // Print new line
    cout << endl;




    // Print B e C value before the update
    cout << "B value before update: " << graph.readNode("B") << endl;
    cout << "C value before update: " << graph.readNode("C") << endl;

    // Print new line
    cout << endl;

    // Update the graph
    cout << "Updating the graph..." << endl;
    aggiorna_adiacenti(graph, "A");

    // Print new line
    cout << endl;


    // Print the B value after the update
    cout << "B value after update: " << graph.readNode("B") << endl;
    cout << "C value after update: " << graph.readNode("C") << endl;

    return 0;
}
