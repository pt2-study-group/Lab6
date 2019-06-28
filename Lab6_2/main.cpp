//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																				//
// Author               : pt206																													//
// Day 				    : 04.06.2019																											//
// file name            : main.cpp																												//
//																																				//
// ---------------------------------------------------------------------------------------------------------------------------------------------//
// A																																			//
//              _____           _      _     _ _																								//
//             /  __ \         | |    | |   (_) |																								//
//             | /  \/ ___   __| | ___| |    _| |_ ___																							//
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )																							//
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/																							//
//              \____/\___/ \__,_|\___\_____/_|\__\___|																							//
//																																				//
//                                                  F i l e																						//
//																																				//
//	1. Реализовать алгоритм сортировки (алгоритм выбрать самостоятельно) в виде шаблонной функции.												//
//	Продемонстрировать работу шаблонной функции на массивах различных типов.																	//
//	2. Реализовать   класс   Rectangle   с   атрибутами,   хранящими   высоту   и   ширину,   и   поддерживающий								//
//	сравнение   по   площади.   Продемонстрировать   сортировку   массива   объектов   типа   Rectangle											//
//	шаблонной функцией, разработанной в предыдущем задании. 																					//
//	3. Реализовать   шаблонный   класс   DoubleBox   для   хранения   двух   атрибутов   разного   типа.   Тип									//
//	атрибутов   задать   параметрами   шаблона.   Реализовать   в   классе   конструктор   по   умолчанию,										//
//	инициализирующий конструктор, а также методы get и set.																						//
//	4. Задание   повышенной   сложности.   Реализовать   шаблонный   класс   Array   для   хранения   массива									//
//	произвольного типа и размера (без использования динамической памяти). Тип элементов и размер												//
//	массива задать параметрами шаблона. Реализовать в классе следующие конструкторы: 															//
//		конструктор по-умолчанию, без параметров; 																								//
//		конструктор, позволяющий инициализировать весь внутренний массив одинаковыми значениями, 												//
//		имеющий один параметр — инициализирующее значение;																						//
//		конструктор,  позволяющий инициализировать внутренний массив значениями из внешнего массива, 											//
//		имеющий два параметра — указатель на внешний массив и размер внешнего массива.															//
//	Реализовать в классе Array перегрузку оператора индексации operator[], 																		//
//	для того чтобы можно было применять его к экземплярам класса для выполнения обращения к элементам внутреннего массива.   					//
//	Проверить работоспособность оператора индексации для константных объектов, 																	//
//	а также работоспособность при использовании слева от оператора присваивания.																//
//																																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include "Triangle.h"
#include "ArrayList.h"

#define maxn 5

using namespace std;

template <typename T> void merge(T * a, int l, int r);
template <typename T> void swap(T & pa, T & pb);


template <typename T> void merge(T * a, int l, int r) {

    if (r == l) return;
    if (r - l == 1) { if (a[r] < a[l]) swap(a[r], a[l]); return; }
	
    int m = (r + l) / 2; 
	merge(a, l, m);
    merge(a, m + 1, r);
	
	T * buf =  new T[5];
	int cur = 0;
	int xl = l;
	int xr = m+1;
	while (r-l+1 != cur) {
		if (xl > m) 
			buf[cur++] = a[xr++];
        else if (xr > r) 
			buf[cur++] = a[xl++];
        else if (a[xl] > a[xr])	
			buf[cur++] = a[xr++];
        else 
			buf[cur++] = a[xl++];
	}
    for (int i = 0; i < cur; i++) { a[i + l] = buf[i]; }	
	delete[] buf;
}

int main(int argc, char **argv) {
	const int array_size = 5;
	Triangle * array = new Triangle[array_size];
	// 16	1	9	25	4
	array[0].setHeight(4);		array[0].setWeight(4);
	array[1].setHeight(1);		array[1].setWeight(1);
	array[2].setHeight(3);		array[2].setWeight(3);
	array[3].setHeight(5);		array[3].setWeight(5);
	array[4].setHeight(2);		array[4].setWeight(2);
	
	for (int i = 0; i < array_size; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	
	merge(array, 0, 4);



	//Отцветка массива после
	for (int i = 0; i < array_size; i++) { cout << array[i] << "\t"; } cout << endl;
	
	

	return 0;
}

template <typename T> void swap(T & pa, T & pb) {
	T temp = pa;
	pa = pb;
	pb = temp;
}