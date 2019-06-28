#include <stdio.h>
#include "Triangle.h"

using namespace std;

Triangle::Triangle (int xSize, int ySize) {
	weight = xSize;
	height = ySize;
}

const bool operator > (Triangle r1, Triangle r2) {
    return (r1.height * r1.weight) > (r2.height * r2.weight);
}

const bool operator < (Triangle r1, Triangle r2) {
    return (r1.height * r1.weight) < (r1.height * r2.weight);
}

const bool operator==(Triangle& left, Triangle& right) {
    return (left.height * left.weight) == (right.height * right.weight);
}
