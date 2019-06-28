#include <iostream>

using namespace std;

template <typename T1, typename T2> class DoubleBox {
private:
    T1 data1;
    T2 data2;
public:
    DoubleBox(): data1(0), data2(0){};
    DoubleBox(T1 value1, T2 value2):data1(value1), data2(value2) {};
    T1 get1();
    T2 get2();
    void set(T1 value1, T2 value2);
};

template <typename T1, typename T2> void DoubleBox<T1, T2>::set(T1 value1, T2 value2) {
    data1 = value1;
    data2 = value2;
}


template <typename T1, typename T2> T1 DoubleBox<T1, T2>::get1()  {
    return data1;
}

template <typename T1, typename T2> T2 DoubleBox<T1, T2>::get2()  {
    return data2;
}


int main(int argc, char **argv)
{
    DoubleBox<int, double> a(1, 2.3456);
    cout << a.get1() << endl; cout << a.get2() << endl;
	
    a.set(7, 8.910);
    cout << a.get1() << endl; cout << a.get2() << endl;
	return 0;
}