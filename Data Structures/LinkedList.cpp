#include "Node.cpp"

using namespace std;
template<class T> class LinkedList {
protected:
    Node* firstNode;
    Node* lastNode;
    int amount;
public:
    LinkedList();
    ~LinkedList();
    virtual void add(T data);
    virtual void add(int position, T data);
    virtual bool remove(int position);
    virtual void replace(int position, T data);
    Node* getNodeAt(int position);
    void clear();
    int getLength();
    //T[] toArray();
}

LinkedList::LinkedList(){
    clear();
}
~LinkedList::LinkedList(){
    delete firstNode;
    delete lastNode;
    firstNode = 0;
    lastNode = 0;
}
void clear() {
    firstNode = NULL;
    lastNode = NULL;
    amount = 0;
}
virtual void LinkedList::add(T data){
    Node<T> temp = new Node<T>(data);
    if(amount == 0) {
        *firstNode = new Node<T>(temp);
    }
    else {
        lastNode->next() = temp;
        *lastNode = temp;
    }
    amount++;
}

virtual void LinkedList::add(int position, T data) {
    Node<T> afterNode;
    Node<T> beforeNode;
    Node<T> addedNode(data);
    beforeNode = getNodeAt(position-1);
    afterNode = beforeNode.next();
    beforeNode.next() = addedNode;
    addedNode.next() = afterNode;
    amount++;
}

virtual bool LinkedList::remove(int position) {
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

Node* Node::getNodeAt(int position) {
    Node currentNode = *firstNode;
    if(position <= amount && amount != 0){
        for (int count = 1; count < position; count++) {
            currentNode = currentNode.next();
        }
        return currentNode;
    }

    return NULL;
}

int getLength() {
    return amount;
}
