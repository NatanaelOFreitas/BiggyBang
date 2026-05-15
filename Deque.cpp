#include <iostream>

template<typename T>
class Node{
private:
    T item;
public:
    Node* next;
    Node* back;

    Node(){
        next = nullptr;
        back = nullptr;
    }

    Node(T item_){
        item = item_;
        next = nullptr;
        back = nullptr;
    }

    T& get_item();
};

template<typename T>
T& Node<T>::get_item(){
    return item;
}


template<typename T>
class Deque{
private:
    Node<T>* first;
    Node<T>* last;
public:
    Deque(){
        first = new Node<T>();
        last = new Node<T>();
        first->next = last;
        last->back = first;
    }

    Node<T>* getFirst();
    Node<T>* getLast();
    void setFront(T item);
    void setBack(T item);
    void removeFront();
    T& getItemFront();
};

template <typename T>
Node<T>* Deque<T>::getFirst(){
    return first;
}

template <typename T>
Node<T>* Deque<T>::getLast(){
    return last;
}

template<typename T>
void Deque<T>::setFront(T item){
    Node<T>* aux = new Node<T>(item);
    aux->next = first->next;
    first->next->back = aux;
    first->next = aux;
    aux->back = first;
}

template <typename T>
void Deque<T>::setBack(T item){
    Node<T>* aux = new Node<T>(item);
    aux->back = last->back;
    last->back->next = aux;
    aux->next = last;
    last->back = aux;
}

template<typename T>
void Deque<T>::removeFront(){
    Node<T>* aux = first->next;
    first->next = aux->next;
    aux->next->back = first;
    delete aux;
}

template<typename T>
T& Deque<T>::getItemFront(){
    return first->next->get_item();
}