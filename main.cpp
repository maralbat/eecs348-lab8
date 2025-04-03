#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void read_matrices_from_file(const std::string &filename, Matrix &A, Matrix &B) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Error opening file: " + filename);
    }

    std::size_t N;
    file >> N;

    std::vector<std::vector<int>> matrixA(N, std::vector<int>(N));
    std::vector<std::vector<int>> matrixB(N, std::vector<int>(N));

    //read first matrix
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            file >> matrixA[i][j];
        }
    }

    //read second matrix
    for (std::size_t i = 0; i < N; i++) {
        for (std::size_t j = 0; j < N; j++) {
            file >> matrixB[i][j];
        }
    }

    A = Matrix(matrixA);
    B = Matrix(matrixB);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::string filename = argv[1];
    Matrix A(0), B(0);

    try {
        read_matrices_from_file(filename, A, B);
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    //print matrices
    std::cout << "Matrix A:\n";
    A.print_matrix();
    std::cout << "\nMatrix B:\n";
    B.print_matrix();

    //addition
    std::cout << "\nA + B:\n";
    Matrix sumMatrix = A + B;
    sumMatrix.print_matrix();

    //multiplication
    std::cout << "\nA * B:\n";
    Matrix productMatrix = A * B;
    productMatrix.print_matrix();

    //diagonal sums
    std::cout << "\nSum of main diagonal (A): " << A.sum_diagonal_major() << '\n';
    std::cout << "Sum of secondary diagonal (A): " << A.sum_diagonal_minor() << '\n';

    //swap rows
    std::cout << "\nSwapping row 0 and row 1 in A:\n";
    A.swap_rows(0, 1);
    A.print_matrix();

    //swap columns
    std::cout << "\nSwapping column 0 and column 1 in A:\n";
    A.swap_cols(0, 1);
    A.print_matrix();

    //modify a value
    std::cout << "\nUpdating A[2][2] to 99:\n";
    A.set_value(2, 2, 99);
    A.print_matrix();

    return 0;
}

