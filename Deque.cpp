#include <iostream>

using namespace std;

//declaração do nó usuado no no deque, stack e queue
template<typename T>
class Node {
private:
    T item;
public:
    Node* next;
    Node* back;
    Node() {
        next = nullptr;
        back = nullptr;
    }
    Node(T item_) {
        item = item_;
        next = nullptr;
        back = nullptr;
    }
    T& get_item() {
        return item;
    }
};

template<typename T>
class ListNavigator {
private:
    Node<T>* current;
    Node<T>* endNode;
public:
    ListNavigator(Node<T>* start, Node<T>* end) {
        current = start;
        endNode = end;
    }
    bool hasNext() {
        return current != endNode;
    }
    T& getCurrent() {
        return current->get_item();
    }
    void next() {
        if (current != endNode) {
            current = current->next;
        }
    }
};

//declarando o QueueNavigator com base no ListNavigator  
template<typename T>
using QueueNavigator = ListNavigator<T>;

//declarando o StackNavigator com base no ListNavigator
template<typename T>
using StackNavigator = ListNavigator<T>;

template<typename T>
class Deque {
private:
    Node<T>* first;
    Node<T>* last;
public:
    Deque() {
        first = new Node<T>();
        last = new Node<T>();
        first->next = last;
        last->back = first;
    }
    Node<T>* getFirst() {
        //retorna o ponteiro que aponta para o Nó sentinela na frente da lista
        return first;
    }
    Node<T>* getLast() {
        //retorna o ponteiro que aponta para o Nó sentinela do final da lista
        return last;
    }
    void setFront(T item) {
        //adiciona um novo Nó posicionado na frente da lista 
        //ponteiro next do sentinela inicial passa a apontar pra esse novo Nó adicionado 
        //e no novo Nó o next aponta para o antigo Nó na posição 1 e o back para o sentinela inicial
        Node<T>* aux = new Node<T>(item);
        aux->next = first->next;
        first->next->back = aux;
        first->next = aux;
        aux->back = first;
    }
    void setBack(T item) {
        //adiciona um novo Nó posicionado no final da lista 
        //ponteiro back do sentinela final passa a apontar pra esse novo Nó adicionado no fim da fila 
        //e no novo Nó o back aponta para o antigo Nó no fim da lista e o next para o sentinela final
        Node<T>* aux = new Node<T>(item);
        aux->back = last->back;
        last->back->next = aux;
        aux->next = last;
        last->back = aux;
    }
    void removeFront() {
        //verifica se a lista ta vazia, se não tiver
        //remove o Nó posicionado na frente da lista 
        //ponteiro next do Nó sentinela inicial passa a apontar pro Nó que estava na posição 2
        //e nesse Nó, o back que antes apontava pro Nó na posição 1 passa apontar pro sentinela inicial
        //e remove o Nó que estava na posição 1 da memória
        if(empty()) {
            return;
        }
        Node<T>* aux = first->next;
        first->next = aux->next;
        aux->next->back = first;
        delete aux;
    }
    void removeBack() {
        //verifica se a lista ta vazia, se não tiver
        //remove o Nó posicionado na ultima posição da lista 
        //ponteiro back do Nó sentinela final passa a apontar pro Nó que estava na penúltima posição
        //e nesse Nó, o next que antes apontava pro Nó na última posição passa apontar pro sentinela final
        //e remove o Nó que estava na última posição da memória
        if(empty()) {
            return;
        }
	    Node<T>* aux = last->back;
	    last->back = aux->back;
	    aux->back->next = last;
	    delete aux;
    }
    T& getItemFront() {
        //retorna o dado amarzenado no Nó na posição 1
        return first->next->get_item();
    }
    ListNavigator<T> getListNavigator() {
        //retorna o Navigator
        return ListNavigator<T>(first->next, last);
    }
};

template<typename T>
class Queue {
private:
    //A fila implementa um deque, mas apenas chama as funções necessárias para manter o funcionamento da fila (FIFO)
    Deque<T> deque;
    int length;
public:
    Queue() {
        length = 0;
    }
    void enqueue(T item) {
        //adiciona um Nó à fila (adiciona à última posição)
        deque.setBack(item);
        length++;
    }
    void dequeue() {
        //verifica se a fila está vazia, se não estiver
        //remove o Nó da fila (remove o Nó na primeira posição)
        if (!empty()) {
            deque.removeFront();
            length--;
        }
    }
    T& front() {
        //retorna o dado salvo no Nó na primeira posição da fila
        return deque.getItemFront();
    }
    bool empty() {
        //verifica se a lista está vazia
        return length == 0;
    }
    int size() {
        //retorna o tamanho da fila
        return length;
    }
    QueueNavigator<T> getQueueNavigator() {
        //implementa uma QueueNavigator com base no ListNavigator
        return QueueNavigator<T>(deque.getFirst()->next, deque.getLast());
    }
};

template<typename T>
class Stack {
private:
    //A pilha implementa um deque, mas apenas chama as funções necessárias para manter o funcionamento da pilha (FILO)
    Deque<T> deque;
    int length;
public:
    Stack() {
        length = 0;
    }
    void push(T item) {
        //adiciona um Nó à pilha (adiciona à primeira posição)
        deque.setFront(item);
        length++;
    }
    void pop() {
        //verifica se a fila está vazia, se não estiver
        //remove o Nó da pilha (remove o Nó na primeira posição)
        if (!empty()) {
            deque.removeFront();
            length--;
        }
    }
    T& top() {
        //retorna o dado salvo no Nó no topo da pilha
        return deque.getItemFront();
    }
    bool empty() {
        //verifica se a lista está vazia
        return length == 0;
    }
    int size() {
        //retorna o tamanho da fila
        return length;
    }
    StackNavigator<T> getStackNavigator() {
        //implementa uma StackNavigator com base no ListNavigator
        return StackNavigator<T>(deque.getFirst()->next, deque.getLast());
    }
};

class Command {
public:
    char action;
    int id;
    Command() {
        action = '-';
        id = 0;
    }
    Command(char action_, int id_) {
        action = action_;
        id = id_;
    }
};

bool existsInFep(Queue<Command>& fep, int id) {
    QueueNavigator<Command> navigator = fep.getQueueNavigator();
    while (navigator.hasNext()) {
        Command command = navigator.getCurrent();
        if (command.action == 'E' && command.id == id) {
            return true;
        }
        navigator.next();
    }
    return false;
}

void processBiggy(Queue<Command>& commands, Queue<Command>& fep, Queue<int>& cancel, Queue<int>& desc) {
    while (!commands.empty()) {
        Command command = commands.front();
        commands.dequeue();

        if (command.action == 'E') {
            fep.enqueue(command);
        } else if (command.action == 'C') {
            if (existsInFep(fep, command.id)) {
                fep.enqueue(command);
            } else {
                cancel.enqueue(command.id);
            }
        } else if (command.action == 'A') {
            if (existsInFep(fep, command.id)) {
                fep.enqueue(command);
            } else {
                desc.enqueue(command.id);
            }
        } else if (command.action == '-') {
            fep.enqueue(command);
            break;
        }
    }
}

void removeFromPep(int id, char action, Stack<int>& pep, Stack<int>& aux, Queue<int>& cancel, Queue<int>& desc) {
    while (!pep.empty() && pep.top() != id) {
        aux.push(pep.top());
        pep.pop();
    }
    if (!pep.empty()) {
        pep.pop();
        if (action == 'C') {
            cancel.enqueue(id);
        } else {
            desc.enqueue(id);
        }
    }
    while (!aux.empty()) {
        pep.push(aux.top());
        aux.pop();
    }
}

void processBang(Queue<Command>& fep, Stack<int>& pep, Stack<int>& aux, Queue<int>& cancel, Queue<int>& desc) {
    while (!fep.empty()) {
        Command command = fep.front();
        fep.dequeue();
        if (command.action == 'E') {
            pep.push(command.id);
        } else if (command.action == 'C' || command.action == 'A') {
            removeFromPep(command.id, command.action, pep, aux, cancel, desc);
        } else if (command.action == '-') {
            break;
        }
    }
}

void printCommandQueue(const char* name, Queue<Command>& queue) {
    cout << name << " = [";
    QueueNavigator<Command> navigator = queue.getQueueNavigator();
    bool first = true;
    while (navigator.hasNext()) {
        if (!first) {
            cout << ", ";
        }
        Command command = navigator.getCurrent();
        cout << "(" << command.action << ", " << command.id << ")";
        first = false;
        navigator.next();
    }
    if (first) {
        cout << " ";
    }
    cout << "]\n";
}

void printIntQueue(const char* name, Queue<int>& queue) {
    cout << name << " = [";
    QueueNavigator<int> navigator = queue.getQueueNavigator();
    bool first = true;
    while (navigator.hasNext()) {
        if (!first) {
            cout << ", ";
        }
        cout << navigator.getCurrent();
        first = false;
        navigator.next();
    }
    if (first) {
        cout << " ";
    }
    cout << "]\n";
}

void printStack(const char* name, Stack<int>& stack) {
    cout << name << " = [";
    StackNavigator<int> navigator = stack.getStackNavigator();
    bool first = true;
    while (navigator.hasNext()) {
        if (!first) {
            cout << ", ";
        }
        cout << navigator.getCurrent();
        first = false;
        navigator.next();
    }
    if (first) {
        cout << " ";
    }
    cout << "]\n";
}

int main() {
    Queue<Command> commands;
    Queue<Command> fep;

    Queue<int> cancel;
    Queue<int> desc;

    Stack<int> pep;
    Stack<int> aux;

    char action;
    int id;

    while (cin >> action >> id) {
        commands.enqueue(Command(action, id));
        if (action == '-') {
            break;
        }
    }
    processBiggy(commands, fep, cancel, desc);

    cout << "Biggy:\n";
    printCommandQueue("FEP", fep);
    printIntQueue("CANCEL", cancel);
    printIntQueue("DESC", desc);

    processBang(fep, pep, aux, cancel, desc);

    cout << "\nBang:\n";
    printCommandQueue("FEP", fep);
    printStack("PEP", pep);
    printStack("AUX", aux);
    printIntQueue("CANCEL", cancel);
    printIntQueue("DESC", desc);

    return 0;
}