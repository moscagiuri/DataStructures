//
// Created by Gianpiero on 20/09/2023.
//

#include <list>
#include <map>
#include <string>
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

    void writeNode(const Node& node, T value) override {
        nodesList.push_back(node);
        nodes.insert({node, value});
    }

    void addEdge(const Node& from, const Node& to, int weight) override {
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) {
            edges.insert({make_pair(from, to), weight});

            if (adjacencies.find(from) == adjacencies.end()) {
                adjacencies.insert({from, list<Node>()});
            } else {
                adjacencies[from].push_back(to);
            }
        }
    }

    T readEdge(const Node& from, const Node& to) const override {
        return edges.at(make_pair(from, to));
    }

    // Italian alias for addNode
    void aggiungiNodo(const Node& node) {
        addNode(node);
    }

    // Print the graph
    void print() {
        for (auto node : nodesList) {
            cout << node << " -> ";
            for (auto adj : adjacencies[node]) {
                cout << adj << " ";
            }
            cout << endl;
        }
    }



private:
    typedef pair<Node, Node> edge;
    list<Node> nodesList;
    map<Node, T> nodes; // int is the value of the node
    map<edge, T> edges; // int is the value of the edge
    map<Node, list<Node>> adjacencies;
};
