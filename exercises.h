//
// Created by Gianpiero on 21/09/2023.
//

#ifndef EXERCISES_H
#define EXERCISES_H


#include <iostream>
#include <list>

#include "AddOnlyGraph.cpp"

#include "exercises.h"
#include "MyList.h"

using namespace std;

/*
 * EXAM 2 - 2022-02-14 - Exercise Lab
 * Implement a function raggiungibili(Graph G, Node N, int k)
 * that returns a list of nodes reachable from N with a path of length at most k.
 */

// Build a graph

AddOnlyGraph<int> buildGraph_Exam_2_2022_02_14() {
    AddOnlyGraph<int> graph;

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

// Implement a function raggiungibili(Graph G, Node N, int k) by Antonio Sedicina
template <class T>
MyList<typename AddOnlyGraph<T>::Nodo> raggiungibili_Sedicina (AddOnlyGraph<T> &G, typename AddOnlyGraph<T>::Nodo &N, int k) {
    MyList<typename AddOnlyGraph<T>::Nodo> lista;
    visita(G, N, k, lista, 0);
    return lista;
}
{
//MyList<AddOnlyGraph<T>::Nodo> lista;
list<string> lista;
visita(G, N, k, lista, 0);
return lista;
}

template <class T>
void visita(AddOnlyGraph<T> &G, typename AddOnlyGraph<T>::Nodo &N, int num_passi_max, MyList<string> &lista, int num_passi_fatti) {
    if(num_passi_fatti <= num_passi_max) {
        if(num_passi_fatti > 0) // EVITO DI INSERIRE IL NODO DI PARTENZA
            //verificare se il nodo è già nella lista prima di inserirlo
            lista.inserisci(N, lista.begin());
        MyList<typename AddOnlyGraph<T>::Nodo> ad = G.adiacenti(N);
        MyList<typename AddOnlyGraph<T>::Nodo>::position pos = ad.primoLista();
        while(!lista.fineLista(pos)) {
            typename AddOnlyGraph<T>::Nodo adiacente = ad.leggi(pos);
            if(!G.leggiMarcatura(adiacente)) {
                G.marcaNodo(adiacente, true);
                visita(G, adiacente, num_passi_max, lista, num_passi_fatti+1);
            }
            pos = lista.succLista(pos);
        }
    }
}



template <class T>
list<string> raggiungibili_Exam_2_2022_02_14(AddOnlyGraph<T> graph, const typename AddOnlyGraph<T>::Node& node, int k) {
    // Result list
   list<string> result;

    // Base case
    if (k == 0) {
        result.push_back(node);
        return result;
    }

    // Recursive case

    // Get adjacencies of the node
    list<string> adjacencies = graph.adiacenti(node);

    // For each adjacency
    for (const auto& adj : adjacencies) {
        // Get the list of nodes reachable from the adjacency with a path of length k-1
        list<string> reachable = raggiungibili_Exam_2_2022_02_14(graph, adj, k-1);

        // Append the list to the result
        result.insert(result.end(), reachable.begin(), reachable.end());
    }

    return result;

}


// --> Exam X - 202X-XX-XX
/*
 * EXAM X - 202X-XX-XX - Exercise Lab
 * Implement a function aggiorna_adiacenti(Graph G, Node N)
 * that updates the value of each node adjacent to N with the sum of the values of the nodes adjacent to the adjacent node.
 */

// Graph for Exam X - 202X-XX-XX
// Build a graph
template<class T>
AddOnlyGraph<T> buildGraph_Exam_X_202X_XX_XX() {
    AddOnlyGraph<T> graph;

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

    return graph;

}


// Implement a function aggiorna_adiacenti(Graph G, Node N)
template <class T>
list<T> aggiorna_adiacenti_Exam_X_202X_XX_XX(AddOnlyGraph<int>& graph, const typename AddOnlyGraph<int>::Node& node) {
    int value = 0;
    for (const auto& adj : graph.adiacenti(node)) {
        for (const auto& a : graph.adiacenti(adj)) {
            value += graph.leggiArco(adj, a);
        }
        graph.scriviNodo(adj, value);
        value = 0;
    }
}
// <-- End Exam X - 202X-XX-XX


#endif //EXERCISES_H