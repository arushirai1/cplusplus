#include "LinkedList.cpp"

using namespace std;
int main() {
    LinkedList<int> list = new LinkedList<int>();
    list.add(4);
    list.add(8);
    list.add(9);

    int count = 1;
    while (list.getLength + 1 != count) {
        cout << list.getNodeAt(count).getData() << endl;
    }
}
