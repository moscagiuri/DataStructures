//
// Created by Gianpiero on 20/09/2023.
//

#include <string>

using namespace std;

template<class T>
class Graph {
public:
    typedef string Node;

    Graph() = default;

    virtual bool empty() const = 0;
    virtual void addNode(const Node& node) = 0;
    virtual T readNode(const Node& node) const = 0;
    virtual void writeNode(const Node&, int)  = 0;
    virtual void addEdge(const Node& from, const Node& to, int weight) = 0;

    virtual T readEdge(const Node& from, const Node& to) const = 0;
};
