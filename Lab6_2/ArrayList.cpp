#include "ArrayList.h"
#include <cstdlib>

template <typename T>
ArrayList<T>::ArrayList(int (*compare)(T* val1, T* val2)) {
    values = new void*[DEFAULT_CAPACITY + RESERVED];
    values[0] = new unsigned long long(0);
    values[1] = new unsigned long long(DEFAULT_CAPACITY);
    ArrayList::compare = compare;
}

template <typename T>
ArrayList<T>::ArrayList(unsigned long long capacity, int (*compare)(T* val1, T* val2)) {
    values = new void*[capacity + RESERVED];
    values[0] = new unsigned long long(0);
    values[1] = new unsigned long long(capacity);
    ArrayList::compare = compare;
}

template <typename T>
void ArrayList<T>::add(T* val) {

    if (isFull())
        expand(EXPAND_DELTA);

    if (compare == nullptr) {
        values[getSize() + RESERVED] = val;
        setSize(getSize() + 1);
        return;
    }

    if (getSize() == 0) {
        values[RESERVED] = val;
        setSize(1);
        return;
    }

    T* iterValue;
    for (unsigned long long i = 0; i < getSize(); i++) {
        iterValue = get(i);

        if (compare(iterValue, val) == 1) {
            addBefore(i, val);
            return;
        }
    }

    addAfter(getSize()-1, val);
}

template <typename T>
void ArrayList<T>::addAfter(unsigned int index, T* val) {
    if (isFull())
        expand(EXPAND_DELTA);

    if (getSize() == 0) {
        add(val);
        return;
    }

    for (int i = getSize() - 1; i > signed(index); i--) {
        values[i + RESERVED + 1] = values[i + RESERVED];
    }

    values[index + RESERVED + 1] = val;
    setSize(getSize() + 1);
}

template <typename T>
void ArrayList<T>::addBefore(unsigned int index, T* val) {
    if (isFull())
        expand(EXPAND_DELTA);

    if (getSize() == 0) {
        add(val);
        return;
    }

    for (int i = getSize() - 1; i >= signed(index); i--) {
        values[i + RESERVED + 1] = values[i + RESERVED];
    }

    values[index + RESERVED] = val;
    setSize(getSize() + 1);
}

template <typename T>
int ArrayList<T>::set(unsigned int index, T* val) {
    if (index >= getSize())
        return -1;

    values[index + RESERVED] = val;
    return 0;
}

template <typename T>
int ArrayList<T>::swap(unsigned int firstIndex, unsigned int secondIndex) {
    if (firstIndex >= getSize() || secondIndex >= getSize())
        return -1;

    void* tmp = values[firstIndex + RESERVED];

    values[firstIndex + RESERVED] = values[secondIndex + RESERVED];
    values[secondIndex + RESERVED] = tmp;
    return 0;
}

template <typename T>
T* ArrayList<T>::remove(unsigned int index) {
    unsigned long long size = getSize();

    if (index >= size)
        return nullptr;

    unsigned int realIndex = index + RESERVED;
    void* elem = values[realIndex];

    for (unsigned int i = realIndex; i < size + RESERVED; i++)
        values[i] = values[i+1];

    setSize(size - 1);

    return reinterpret_cast<T*>(elem);
}

template <typename T>
T* ArrayList<T>::remove(T* element) {
    int index = indexOf(element);

    if (index == -1)
        return nullptr;

    return remove(index);
}

template <typename T>
int ArrayList<T>::indexOf(T* element) {
    if (compare == nullptr) {
        unsigned long long size = getSize();

        if (size == 0 || element == nullptr)
            return -1;

        for (int i = 0; i < size; i++) {
            if (get(i) == element)
                return i;
        }

        return -1;
    }

    if (isEmpty())
        return -1;

    int left = 0;
    int right = getSize() - 1;


    while (left <= right) {
        int middle = (left + right) / 2;
        int result = (*compare)(get(middle), element);

        if (result == 0)
            return middle;
        else if (result == 1)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

template <typename T>
T* ArrayList<T>::get(unsigned int index) {
    return reinterpret_cast<T*>(values[index + RESERVED]);
}

template <typename T>
bool ArrayList<T>::isFull() {
    if (getSize() >= getCapacity())
        return true;

    return false;
}

template <typename T>
void ArrayList<T>::expand(unsigned int delta) {
    unsigned long long newCapacity = getCapacity() * delta;

    void* reallocated = realloc(*values, sizeof(void*) * (newCapacity + RESERVED));

    free(*values);
    *values = reallocated;

    setCapacity(newCapacity);
}

template <typename T>
bool ArrayList<T>::contains(void* val) {
    for (unsigned int i = RESERVED - 1; i < getSize(); i++) {
        if (values[i] == val)
            return true;
    }

    return false;
}

template <typename T>
bool ArrayList<T>::isEmpty() {
    return getSize() == 0;
}

template <typename T>
void ArrayList<T>::clear() {
    for (int i = getSize()-1; i >= 0; i--) {
        remove(i);
    }
}

template <typename T>
void ArrayList<T>::clearWithDelete() {
    for (int i = getSize()-1; i >= 0; i--) {
        delete remove(i);
    }
}

template <typename T>
unsigned long long ArrayList<T>::getSize() {
    return *reinterpret_cast<unsigned long long*>(values[0]);
}

template <typename T>
void ArrayList<T>::setSize(unsigned long long size) {
    if (values[0] != nullptr) {
        delete reinterpret_cast<unsigned long long*>(values[0]);
    }

    values[0] = new unsigned long long(size);
}

template <typename T>
unsigned long long ArrayList<T>::getCapacity() {
    return *reinterpret_cast<unsigned long long*>(values[1]);
}

template <typename T>
void ArrayList<T>::setCapacity(unsigned long long capacity) {
    if (values[1] != nullptr) {
        delete reinterpret_cast<unsigned long long*>(values[1]);
    }

    ArrayList::values[1] = new unsigned long long(capacity);
}
