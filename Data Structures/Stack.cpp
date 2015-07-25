#include "Node.cpp"
#include "LinkedList.cpp"

template <class T>
class Stack:: public class LinkedList{
public:
    Stack();
    ~Stack();
    void push(T& data);
    T pop();
};

Stack::Stack() : LinkedList() { }
~Stack() {}

void Stack::push(T& data) {
    add(data);
}

T Stack::pop() {
    T temp = lastNode->getData();
    *lastNode = getNodeAt(amount-1);
    return temp;
}
