//
// Created by Gianpiero on 20/09/2023.
//

#include <list>
#include <map>
#include <iostream>

#include "Graph.cpp"

using namespace std;

template<class T>
class AddOnlyGraph : public Graph <T> {
public:
    typedef string Node;

    AddOnlyGraph() = default;

    bool empty() const override {
        return nodes.empty() && nodesList.empty();
    }

    void addNode(const Node& node) override {
        nodesList.push_back(node);
        nodes.insert({node, 0});
    }

    T readNode(const Node& node) const override {
        return nodes.at(node);
    }

    void writeNode(const Node& node, T value) override {
        nodes[node] = value;
    }

    void addEdge(const Node& from, const Node& to, int weight) override {
          edges.insert({make_pair(from, to), weight});
          adjacencies[from].push_back(to);
    }

    T readEdge(const Node& from, const Node& to) const override {
        return edges.at(make_pair(from, to));
    }


    // Get adjacencies of a node
    list<Node> getAdjacencies(const Node& node) const {
        return adjacencies.at(node);
    }

    // Italian alias for addNode
    void aggiungiNodo(const Node& node) {
        addNode(node);
    }

    list<Node> adiacenti (const Node& node) const {
        return getAdjacencies(node);
    }

    void scriviNodo(const Node& node, T value) {
        writeNode(node, value);
    }

    T leggiNodo(const Node& node) const {
        return readNode(node);
    }

    T leggiArco(const Node& from, const Node& to) const {
        return readEdge(from, to);
    }


    // Print the graph
    void print() {
        for (const auto& node : nodesList) {
            if (!adjacencies[node].empty()) {
                cout << node << " -> ";
            for (const auto& adj : adjacencies[node]) {
                cout << adj << " ";
            }
            cout << endl;
            }
        }
        // Print new line
        cout << endl;
    }



private:
    typedef pair<Node, Node> edge;
    list<Node> nodesList;
    map<Node, T> nodes; // T is the value of the node
    map<edge, T> edges; // T is the value of the edge
    map<Node, list<Node>> adjacencies;
};
