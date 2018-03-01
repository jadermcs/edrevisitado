#include <iostream>
#include <stdexcept>

template <class T>
class myqueue {
    T * values;
    int qtail, qhead, qsize;
    public:
        myqueue(int size) {
            values = new T [size];
            qtail = qhead = 0;
            qsize = size;
        };
        int size() {
            if (isEmpty())
                return 0;
            else if (qhead > qtail)
                return (qhead+1) - (qtail+1) + 1;
            else return (qtail+1) - (qhead+1) + 1;
        };
        T popit();
        void pushit(T);
        void pos() {std::cout << qhead << "---" << qtail << std::endl;};
        bool isEmpty() {if (qhead == qtail) return true; else return false;};
};

template <class T>
T myqueue<T>::popit() {
    if (isEmpty())
        throw std::underflow_error("Empty queue.");
    T res = values[qhead];
    qhead = (qhead+1) % qsize;
    return res;
}

template <class T>
void myqueue<T>::pushit(T item) {
    int mys = size();
    if ((qtail+1) % qsize == qhead)
        throw std::overflow_error("Full queue.");
    values[qtail] = item;
    qtail = (qtail+1) % qsize;
}

int main(int argc, char *argv[])
{
    myqueue<int> queueint(5);
    queueint.pushit(3);
    queueint.pushit(7);
    queueint.pos();
    std::cout << queueint.popit() << std::endl;
    std::cout << queueint.popit() << std::endl;
    queueint.pos();
    queueint.pushit(9);
    queueint.pushit(1);
    queueint.pushit(7);
    queueint.pushit(2);
    queueint.pos();
    std::cout << queueint.popit() << std::endl;
    std::cout << queueint.popit() << std::endl;
    std::cout << queueint.popit() << std::endl;
    queueint.pos();
    queueint.pushit(3);
    queueint.pushit(7);
    queueint.pushit(2);
    queueint.pos();
    return 0;
}
