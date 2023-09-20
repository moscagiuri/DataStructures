//
// Created by Gianpiero on 20/09/2023.
//

#include <list>
#include <map>
#include <string>

using namespace std;

template<class T>
class AddOnlyGraph {
public:
    typedef string Node;

    AddOnlyGraph() = default;

    bool empty() const;

    void insNode(const Node &);

    void insEdge(const Node &, const Node &, int);

    list<Node> adjacent(const Node &) const;

    T readNode(const Node &) const;

    void writeNode(const T &, const Node &);

    int readEdge(const Node &, const Node &) const;

    void writeEdge(const Node &, const Node &, int);

    void markNode(const Node &, bool);

    bool isMarked(const Node &) const;

    // Italian aliases
    typedef Node Nodo;

    bool vuoto() const { return empty(); }

    void insNodo(const Nodo &n) { insNode(n); }

    void insArco(const Nodo &n1, const Nodo &n2, int peso) { insEdge(n1, n2, peso); }

    list<Nodo> adiacenti(const Nodo &n) const { return adjacent(n); }

    T leggiNodo(const Nodo &n) const { return readNode(n); }

    void scriviNodo(const T &val, const Nodo &n) { writeNode(val, n); }

    int leggiArco(const Nodo &n1, const Nodo &n2) const { return readEdge(n1, n2); }

    void scriviArco(const Nodo &n1, const Nodo &n2, int peso) { writeEdge(n1, n2, peso); }

    void marcaNodo(const Nodo &n, bool status) { markNode(n, status); }

    bool marcato(const Nodo &n) const { return isMarked(n); }

private:
    using edge = pair<Node, Node>;

    list<Node> nodes;
    map<Node, int> nodesMap;
    list<edge> edges;
    map<edge, int> edgesMap;
    map<Node, bool> marked;
};


template<class T>
void AddOnlyGraph<T>::insEdge(const AddOnlyGraph::Nodo &n1, const AddOnlyGraph::Nodo &n2, int weight) {
    edges.emplace_back(n1, n2);
    edgesMap[make_pair(n1, n2)] = weight;
}

template<class T>
bool AddOnlyGraph<T>::empty() const {
    return nodes.empty();
}

template<class T>
void AddOnlyGraph<T>::insNode(const Node &n) {
    nodes.push_back(n);
}

template<class T>
list<typename AddOnlyGraph<T>::Nodo> AddOnlyGraph<T>::adjacent(const AddOnlyGraph::Node &n) const {
    list<Node> adjacentNodes;

    for (const auto &edge: edges) {
        if (edge.first == n) {
            adjacentNodes.push_back(edge.second);
        }
    }
    return adjacentNodes;
}

template<class T>
T AddOnlyGraph<T>::readNode(const AddOnlyGraph::Node &) const {
    return T();
}

template<class T>
void AddOnlyGraph<T>::writeNode(const T &, const AddOnlyGraph::Node &) {

}

template<class T>
int AddOnlyGraph<T>::readEdge(const AddOnlyGraph::Node &n1, const AddOnlyGraph::Node &n2) const {
    return edgesMap.at(make_pair(n1, n2));
}

template<class T>
void AddOnlyGraph<T>::writeEdge(const AddOnlyGraph::Node &, const AddOnlyGraph::Node &, int) {

}


template<class T>
void AddOnlyGraph<T>::markNode(const Node &n, bool status) {
    marked[n] = status;
}

template<class T>
bool AddOnlyGraph<T>::isMarked(const AddOnlyGraph::Node &n) const {
    return marked.at(n);
}