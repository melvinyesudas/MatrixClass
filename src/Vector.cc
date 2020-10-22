/*
 * Vector.cc
 *
 * Author: Melvin Yesudas
 * Email:  melvinyesudas@gmail.com
 *
 * Created on: October 20, 2020
 *
 */

#include "Vector.hh"

void MyVector::push_back(int value) {
    if (count == size) {
        int* temp = new int[scale * size];
        for (unsigned i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        size *= scale;
        delete[] arr;
        arr = temp;
    }
    arr[count] = value;
    count++;
}

int MyVector::Size() { return count; }

void MyVector::printVec() {
    std::cout << std::endl;
    for (unsigned i = 0; i < count; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

int MyVector::operator()(int index) { return arr[index]; }
