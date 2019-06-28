#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

class Triangle {
	friend ostream& operator<<(ostream& outputStream, const Triangle & o) {
		return outputStream << (o.weight * o.height); 
	}
	
	private:
		int weight;
		int height;
	public:
		Triangle () : weight(0), height(0) {};
		Triangle (int xSize, int ySize);
		Triangle& operator = (Triangle& right) {
			if (this == &right) {
				return *this;
			}
			weight = right.weight;
			height = right.height;
		
			return *this;
		}
		void setHeight (int value) {
			height = value;
		}
		void setWeight (int value) {
			weight = value;
		}
		friend const bool operator > (Triangle r1, Triangle r2);
		friend const bool operator < (Triangle r1, Triangle r2);
		friend const bool operator ==(Triangle& left, Triangle& right);
};