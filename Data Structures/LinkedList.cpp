#include <iostream>

using namespace std;
template<class T> class Node {
protected:
    Node<T>* nextNode;
    T data;

public:
    Node() {
        nextNode = 0;
        data = 0;
    }

    Node(Node& node){
    this->data = node.getData();
    this->nextNode = new Node(node.next());
    }

    Node(T data) {
        this->data = data;
        //nextNode = 0;
    }

    Node<T>& operator=(Node<T>& passedInNode) {
        this->data = passedInNode.data;
        this->nextNode = passedInNode.nextNode;

        return passedInNode;
    }
    ~Node() {
        delete nextNode;
        nextNode = 0;
    }
    Node<T>& next() {
      return *nextNode;
    }

    T& getData() {
        return this->data;
    }
    void setData(T data) {
        this.data = data;
    }

};

template<class T> class LinkedList {
protected:
    Node<T>* firstNode;
    Node<T>* lastNode;
    int amount;
public:
    LinkedList(){
        clear();
    }
    ~LinkedList(){
        delete firstNode;
        delete lastNode;
        firstNode = 0;
        lastNode = 0;
    }
    void clear() {
        firstNode = 0;
        lastNode = 0;
        amount = 0;
    }
    virtual void add(T data){
        Node<T> temp(data);
        if(amount == 0) {
            firstNode = new Node<T>(temp);
        }
        else {
            lastNode->next() = temp;
            *lastNode = temp;
        }
        amount++;
    }

    virtual void add(int position, T data) {
        Node<T>* afterNode;
        Node<T>*beforeNode;
        Node<T>* addedNode= new Node<T>(data);
        beforeNode = getNodeAt(position-1);
        afterNode = new Node<T>(beforeNode->next());
        beforeNode->next() = new Node<T>(addedNode);
        addedNode->next() = afterNode;
        amount++;
        delete afterNode;
        delete beforeNode;
    }

    virtual bool remove(int position) {
        if(position <= amount && amount != 0 ) {
            Node<T> temp = new Node<T>();
            temp = getNodeAt(position-1);
            temp.next() = temp.next().next();
            return true;
        }
        return false;
    }
    virtual void replace(int position, T data) {
        getNodeAt(position).setData(data);
    }

    Node<T>* getNodeAt(int position) {
        Node<T> currentNode = *firstNode;
        if(position <= amount && amount != 0){
            for (int count = 1; count < position; count++) {
                currentNode = currentNode.next();
            }
            return &currentNode;
        }

        return &currentNode;
    }

    int getLength() {
        return amount;
    }

};

int main() {
    LinkedList<int> list;
    list.add(4);
    list.add(8);
    list.add(9);

    int count = 1;
    while (list.getLength() + 1 != count) {
        cout << list.getNodeAt(count)->getData() << endl;
    }

    return 0;
}

