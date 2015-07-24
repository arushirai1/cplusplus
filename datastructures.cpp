using namespace std;

template<typename T>
class Node {
public:
    Node();
    Node(T data);
    void operator = (T data);
    Node& operator = (Node passedInNode);
    ~Node();
    Node& next();
private:
    Node* nextNode;
    T data;
};
Node::Node() {

}

Node::Node(T data) {
    this.data = data;
}

void Node::operator=(T data) {
    this.data = data;

}
Node& Node::next() {
  return nextNode;
}
template <class T>
class Stack{
public:
    Stack();
    ~Stack();
    void push(T& data);
    T pop();
private:
    int amount;
    T* top;
};
