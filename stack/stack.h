#include <iostream>
#include "../vector/vector.h"

namespace Custom {

    template <class T>
    class Stack: public Vector<T> {
    private:
        // Don't expose non-stack interface
        using Vector<T>::push_back;
        using Vector<T>::at;

    public:
        Stack();
        Stack(Stack& Vector);
        T push(T);
        T pop();
        T peek();
    };

    template <class T>
    Stack<T>::Stack() : Vector<T>() { }

    template <class T>
    Stack<T>::Stack(Stack& stack) : Vector<T>(stack.array, stack.numSize, stack.numCapacity) {}

    template <class T>
    T Stack<T>::push(T item) {
        Vector<T>::push_back(item);

        return item;
    }

    template<class T>
    T Stack<T>::peek() {
        return Vector<T>::at(this->numSize - 1);
    }

    template<class T>
    T Stack<T>::pop() {
        T item = this->peek();
        this->numSize -= 1;

        return item;
    }
}