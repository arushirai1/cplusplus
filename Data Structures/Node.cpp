template<class T> class Node {
protected:
    Node<T>* nextNode;
    T data;

public:
    Node();
    Node(T data);
    Node(Node& node);
    Node& operator =(Node& passedInNode);
    ~Node();
    Node& next();
    T& getData();
    void setData(T data);
};
Node::Node() {
    nextNode = 0;
    data = 0;
}

Node::Node(T data) {
    this.data = new T(data);
    nextNode = NULL;
}

Node::Node(Node& node){
    this.data = node.getData();
}

Node& Node::operator=(Node& passedInNode) {
    this.data = passedInNode.data;
    this.nextNode = passedInNode.nextNode;

    return passedInNode;
}
~Node::Node() {
    delete nextNode;
    nextNode = 0;
}
Node& Node::next() {
  return *nextNode;
}

T& Node::getData() {
    return this.data;
}
void Node::setData(T data) {
    this.data = data;
}


