#pragma once
#include <iostream>

namespace Custom {

    template <class T>
    class Vector {
        // Member Variables
        int numSize;
        int numCapacity;
        T * array;

        // Private methods
        T * allocate(int size);
        void deallocate();
        T * fillArray(T* array, T fill, int size);
        T * copyArray(T* destination, T* source, int size);
        T * increaseCapacity();

    public:
        Vector();
        Vector(int numElements);
        Vector(int numElements, T fill);
        Vector(Vector& vector);
        ~Vector();

        void clear();
        T push_back(T item);

        int size() { return this->numSize; }
        int capacity() { return this->numCapacity; }
        bool empty() { return this->size() == 0; }
        T at(int index) { return this->array[index]; } // TODO: bounds checking

        friend std::ostream& operator<<(std::ostream& os, const Vector& rhs) {
            for(T * p = rhs.array; *p; p++) {
                os << *p;
                os << ',';
            }

            return os;
        }
    };

    template <class T>
    Vector<T>::Vector() {
        this->numSize = 0;
        this->numCapacity = 0;
        this->array = this->allocate(1);
    }

    template <class T>
    Vector<T>::Vector(int numElements) {
        this->numCapacity = numElements;
        this->numSize = this->numCapacity;
        this->array = new T[this->numCapacity];
    }

    template <class T>
    Vector<T>::Vector(int numElements, T fill) {
        this->numCapacity = numElements;
        this->numSize = this->numCapacity;
        this->array = new T[this->numCapacity];
        this->fillArray(this->array, fill, this->numSize);
    }

    template <class T>
    Vector<T>::Vector(Vector& vector) {
        this->numCapacity = vector.capacity();
        this->numSize = vector.size();
        this->array = this->copyArray(
            allocate(this->numCapacity),
            vector.array,
            this->numSize
            );

    }

    template <class T>
    Vector<T>::~Vector() {
        this->deallocate();
    }

    template <class T>
    void Vector<T>::clear() {
        this->fillArray(this->array, T(NULL), this->numSize);
        this->numSize = 0;
    }

    template <class T>
    T Vector<T>::push_back(T item) {
        if (this->numSize >= this->numCapacity)
            this->increaseCapacity();

        this->array[this->numSize] = item;
        this->numSize += 1;

        return item;
    }

    // private
    template <class T>
    T * Vector<T>::increaseCapacity() {
        int newCapacity = this->numCapacity * 2;

        T* newArray = this->allocate(newCapacity);
        this->copyArray(newArray, this->array, this->numSize);
        this->deallocate();
        this->array = newArray;

        this->numCapacity = newCapacity;
        return this->array;
    }

    template <class T>
    T * Vector<T>::copyArray(T* destination, T* source, int size) {
        for (int i = 0; i < size; i++) {
            destination[i] = source[i];
        }

        return destination;
    }

    template <class T>
    T * Vector<T>::allocate(int size) {
        // TODO: Error handling
        return new T[size];
    }

    template <class T>
    void Vector<T>::deallocate() {
        // TODO: Error handling
        delete[] this->array;
    }

    template <class T>
    T * Vector<T>::fillArray(T* array, T fill, int size) {
        for (int i = 0; i < size; i++) {
            array[i] = fill;
        }

        return array;
    }
}
