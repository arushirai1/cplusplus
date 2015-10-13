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
    this.data = node.getData();
    this.nextNode = node.next();
    }

    Node(T data) {
        this.data = new T(data);
        //nextNode = 0;
    }

    Node<T>& operator=(Node<T>& passedInNode) {
        this.data = passedInNode.data;
        this.nextNode = passedInNode.nextNode;

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
        return this.data;
    }
    void setData(T data) {
        this.data = data;
    }

};

