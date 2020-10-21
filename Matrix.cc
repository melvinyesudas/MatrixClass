/*
 * Matrix.cc
 *
 * Author: Melvin Yesudas
 * Email:  melvinyesudas@gmail.com
 *
 * Created on: October 20, 2020
 *
 */

#include "Matrix.hh"

void Matrix::printMat(Mats &output) {
    std::cout << std::endl;
    for (int n = 0; n < output.raws; n++) {
        for (int m = 0; m < output.cols; m++) {
            std::cout << output.vec[n][m] << ", ";
        }
        std::cout << std::endl;
    }
}

void Matrix::setMat(Mats &output) {
    for (int i = 0; i < output.raws; i++) {
        std::vector<int> v1;
        for (int j = 0; j < output.cols; j++) {
            int num;
            std::cin >> num;
            v1.push_back(num);
        }
        output.vec.push_back(v1);
    }
}

Mats operator+(const Mats &mat1, const Mats &mat2) {
    if ((mat1.cols != mat2.cols) || (mat1.raws != mat2.raws)) {
        std::cout << "Matrix addition not possible" << std::endl;
        return {};
    }
    Mats output;
    std::vector<std::vector<int> > vec(mat1.raws, std::vector<int>(mat2.cols));
    for (unsigned i = 0; i < mat1.raws; i++) {
        for (unsigned j = 0; j < mat1.cols; j++) {
            vec[i][j] = mat1.vec[i][j] + mat2.vec[i][j];
        }
    }
    output.cols = mat2.cols;
    output.raws = mat1.raws;
    output.vec = vec;
    return output;
}

Mats operator*(const Mats &mat1, const Mats &mat2) {
    if (mat1.cols != mat2.raws) {
        std::cout << "Matrix multiplication not possible" << std::endl;
        return {};
    }
    Mats output;
    std::vector<std::vector<int> > vec(mat1.raws, std::vector<int>(mat2.cols));
    for (unsigned i = 0; i < mat1.raws; i++) {
        for (unsigned j = 0; j < mat2.cols; j++) {
            for (unsigned k = 0; k < mat2.raws; k++) {
                vec[i][j] += mat1.vec[i][k] * mat2.vec[k][j];
            }
        }
    }
    output.cols = mat2.cols;
    output.raws = mat1.raws;
    output.vec = vec;
    return output;
}

MyVector operator*(const Mats &mat, MyVector &v) {
    MyVector res;
    for (unsigned i = 0; i < mat.raws; i++) {
        int sum = 0;
        for (unsigned j = 0; j < mat.cols; j++) {
            sum += mat.vec[i][j] * v(j);
        }
        res.push_back(sum);
    }
    return res;
}

template <class scalar>
Mats operator*(const Mats &mat, const scalar &value) {
    Mats output;
    std::vector<std::vector<int> > vec(mat.raws, std::vector<int>(mat.cols));
    for (unsigned i = 0; i < mat.raws; i++) {
        for (unsigned j = 0; j < mat.cols; j++) {
            vec[i][j] = mat.vec[i][j] * value;
        }
    }
    output.cols = mat.cols;
    output.raws = mat.raws;
    output.vec = vec;
    return output;
}

// int main() {
//     Mats _Mat1, _Mat2;
//     std::shared_ptr<Matrix> obj;
//     freopen("test.txt", "r", stdin);
//     std::cin >> _Mat1.raws >> _Mat1.cols >> _Mat2.raws >> _Mat2.cols;

//     obj->setMat(_Mat1);

//     obj->printMat(_Mat1);
//     std::cout << std::endl;
//     obj->setMat(_Mat2);
//     obj->printMat(_Mat2);
//     Mats res_ = _Mat1 + _Mat2;
//     Mats sc = _Mat1 * 2;
//     Mats m = _Mat1 * _Mat2;
//     obj->printMat(sc);
//     obj->printMat(res_);

//     obj->printMat(m);
//     MyVector v, r;
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(3);
//     r = _Mat1 * v;
//     r.printVec();
//     return 0;
// }
