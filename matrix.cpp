#include "matrix.hpp"
#include <iostream>
#include <iomanip> //for formatted output

//constructor for an empty NxN matrix
Matrix::Matrix(std::size_t N) : data(N, std::vector<int>(N, 0)), size(N) {}

//constructor that initializes from a given 2D vector
Matrix::Matrix(std::vector<std::vector<int>> nums) : data(nums), size(nums.size()) {}

//overloaded addition operator
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (size != rhs.size) throw std::invalid_argument("Matrix sizes do not match!");
    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

//overloaded multiplication operator
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (size != rhs.size) throw std::invalid_argument("Matrix sizes do not match!");
    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            for (std::size_t k = 0; k < size; k++) {
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;
}

//set a value in the matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds!");
    data[i][j] = n;
}

//get a value from the matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= size || j >= size) throw std::out_of_range("Index out of bounds!");
    return data[i][j];
}

//get the matrix size
int Matrix::get_size() const {
    return size;
}

//sum of the main diagonal elements
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += data[i][i];
    }
    return sum;
}

//sum of the secondary diagonal elements
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += data[i][size - i - 1];
    }
    return sum;
}

//swap two rows
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size) throw std::out_of_range("Row index out of bounds!");
    std::swap(data[r1], data[r2]);
}

//swap two columns
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size) throw std::out_of_range("Column index out of bounds!");
    for (std::size_t i = 0; i < size; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
}

//print the matrix
void Matrix::print_matrix() const {
    for (const auto &row : data) {
        for (int num : row) {
            std::cout << std::setw(4) << num; //align output
        }
        std::cout << '\n';
    }
}
