#include "Node.cpp"

using namespace std;
//abstract class/interface
template<class T> class LinkedListInterface {
protected:
    int amount;
public:
    virtual void add(T data)=0;
    virtual void add(int position, T data)=0;
    virtual bool remove(int position)=0;
    virtual void replace(int position, T data)=0;
    void clear()=0;
    T getData()=0;
    int getLength()=0;
    T[] toArray()=0;
}
