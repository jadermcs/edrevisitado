#include <iostream>
#include <stdexcept>
#include <exception>

template <class T>
class mystack {
    T * values;
    int mysize, stacksize;
    public:
        mystack(int size) {
            values = new T [size];
            mysize = 0;
            stacksize = size;
        };
        int size() {return mysize;};
        T popit();
        void pushit(T);
        bool isEmpty() {if (mysize == 0) return true; else return false;};
};

template <class T>
T mystack<T>::popit() {
    if (isEmpty())
        throw std::underflow_error("Empty stack.");
    mysize -= 1;
    return values[mysize];
}

template <class T>
void mystack<T>::pushit(T item) {
    if (mysize+1 > stacksize)
        throw std::overflow_error("Full stack.");
    values[mysize] = item;
    mysize += 1;
}

int main(int argc, char *argv[])
{
    mystack<char> stackchar(5);
    for (char i = 'a'; i < 'f'; ++i) {
        stackchar.pushit(i);
    }
    for (int i = 0; i < 7; ++i) {
        try {
            std::cout << stackchar.popit() << std::endl;
        }catch(std::exception& e) {
            std::cout << "[error] " << e.what() << std::endl;
        }
    }
    for (char i = 'a'; i < 'g'; ++i) {
        try {
            stackchar.pushit(i);
        }catch(std::exception& e) {
            std::cout << "[error] " << e.what() << std::endl;
        }
    }
    return 0;
}
