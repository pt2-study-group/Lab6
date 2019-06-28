#ifndef ARRAYLIST_H
#define ARRAYLIST_H

static const unsigned long long RESERVED = 2;
static const unsigned long long DEFAULT_CAPACITY = 10;
static const unsigned long long EXPAND_DELTA = 2;

template <typename T>
class ArrayList {

public:
    ArrayList<T>(int (*compare)(T* val1, T* val2));
    ArrayList<T>(unsigned long long capcity, int (*compare)(T* val1, T* val2));

    T* get(unsigned int index);
    T* remove(unsigned int index);
    T* remove(T* element);
    int indexOf(T* element);

    void add(T* val);
    void addAfter(unsigned int index, T* val);
    void addBefore(unsigned int index, T* val);
    int set(unsigned int index, T* val);
    int swap(unsigned int firstIndex, unsigned int secondIndex);

    bool contains(void* val);
    bool isEmpty();

    unsigned long long getSize();
    unsigned long long getCapacity();

    void expand(unsigned int delta);

    void clear();
    void clearWithDelete();

private:
    bool isFull();

    void setSize(unsigned long long size);
    void setCapacity(unsigned long long capacity);

    int (*compare)(T* val1, T* val2);

    void** values;
};


#endif // ARRAYLIST_H
