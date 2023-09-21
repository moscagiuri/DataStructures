//
// Created by Gianpiero on 21/09/2023.
//

#ifndef DATASTRUCTURES_MYLIST_H
#define DATASTRUCTURES_MYLIST_H

template <class T>
class MyList {
private:
    struct Cella {
        T element;
        Cella* next;
        Cella* prev;
    };
    Cella* primo;


public:
    typedef Cella* position;

    MyList();
    bool vuota() const;
    T leggi(position) const;
    void scrivi(const T &, position);
    position primoLista() const;
    position begin() const;
    position successivo(position) const;
    position precedente(position) const;
    bool fineLista(position) const;
    void rimuovi(position);
    void inserisci(const T &, position);


};

template <class T>
MyList<T>::MyList() {
    primo = new Cella;
}

template <class T>
bool MyList<T>::vuota() const {
    return primo->next == nullptr;
}

template <class T>
T MyList<T>::leggi(position p) const {
    return p->element;
}

template <class T>
void MyList<T>::scrivi(const T &a, position p) {
    p->element = a;
}

template <class T>
typename MyList<T>::position MyList<T>::primoLista() const {
    return primo;
}

template <class T>
typename MyList<T>::position MyList<T>::begin() const {
    return primo->next;
}

template <class T>
typename MyList<T>::position MyList<T>::successivo(position p) const {
    return p->next;
}

template <class T>
typename MyList<T>::position MyList<T>::precedente(position p) const {
    return p->prev;
}

template <class T>
bool MyList<T>::fineLista(position p) const {
    return p == nullptr;
}

template <class T>
void MyList<T>::rimuovi(position p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

template <class T>
void MyList<T>::inserisci(const T &a, position p) {
    Cella* nuovo = new Cella;
    nuovo->element = a;
    nuovo->next = p;
    nuovo->prev = p->prev;
    p->prev->next = nuovo;
    p->prev = nuovo;
}


#endif //DATASTRUCTURES_MYLIST_H
