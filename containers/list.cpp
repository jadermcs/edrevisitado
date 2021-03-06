#include <iostream>
#include <exception>
#include <string>

template <class T>
class mylist {
    struct Node {
        T value;
        Node * next;
    };
    Node * head;
    int sizelist;
    public:
        mylist () {head = NULL; size = 0;}
        void pushit(T);
        T popit();
        int size() {return sizelist;}
};

template <class T>
void mylist<T>::pushit(T val){
    Node * n = new Node();
    n->value = val;
    n->next = head;
    head = n;
    sizelist++;
}

template <class T>
T mylist<T>::popit(){
    T val = head->value;
    head = head->next;
    sizelist--;
    return val;
}

int main(int argc, char *argv[])
{
    mylist<std::string> liststring;
    for (int i = 0; i < 1000; ++i) {
        liststring.pushit("jader");
        liststring.pushit("martins");
    }
    for (int i = 0; i < 1000; ++i) {
        std::cout << liststring.popit() << std::endl;
        std::cout << liststring.popit() << std::endl;
    }
    return 0;
}
