#include <iostream>
#include <stdexcept>

template <class T>
class mystack {
    T * values;
    int mysize;
    public:
        mystack(int size) {values = new T [size]; mysize = 0;};
        int size() {return mysize;};
        T popit();
        void pushit(T);
        bool isEmpty() {if (mysize == 0) return true; else return false;};
};

template <class T>
T mystack<T>::popit() {
    if (isEmpty())
        throw std::underflow_error("Empty stack");
    mysize -= 1;
    return values[mysize];
}

template <class T>
void mystack<T>::pushit(T item) {
    values[mysize] = item;
    mysize += 1;
}

int main(int argc, char *argv[])
{
    mystack<int> stackint(10);
    stackint.pushit(3);
    stackint.pushit(7);
    stackint.pushit(2);
    stackint.pushit(9);
    std::cout << stackint.popit() << std::endl;
    std::cout << stackint.popit() << std::endl;
    std::cout << stackint.popit() << std::endl;
    std::cout << stackint.popit() << std::endl;
    std::cout << stackint.popit() << std::endl;
    return 0;
}
