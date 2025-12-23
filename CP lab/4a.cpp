#include <iostream>
#include <vector>

class SparseMatrix {
private:
    std::vector<std::vector<int>> sparseArray;

public:
    // Constructor with size initialization
    SparseMatrix(int sizeX, int sizeY) : sparseArray(sizeX, std::vector<int>(sizeY, 0)) {}

    // Constructor for converting a regular matrix to a sparse matrix
    SparseMatrix(const std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] != 0) {
                    sparseArray.push_back({i, j, matrix[i][j]});
                }
            }
        }
    }

    // Function to display the sparse matrix
    void display() const {
        std::cout << "Sparse Matrix:\n";
        for (const auto& element : sparseArray) {
            std::cout << element[0] << "\t" << element[1] << "\t" << element[2] << "\n";
        }
    }

    // Function to add two sparse matrices
    SparseMatrix add(const SparseMatrix& other) const {
        int sizeX = std::max(sparseArray.back()[0] + 1, other.sparseArray.back()[0] + 1);
        int sizeY = std::max(sparseArray.back()[1] + 1, other.sparseArray.back()[1] + 1);
        SparseMatrix result(sizeX, sizeY);

        int i = 0, j = 0;

        while (i < sparseArray.size() && j < other.sparseArray.size()) {
            if (sparseArray[i][0] < other.sparseArray[j][0] ||
                (sparseArray[i][0] == other.sparseArray[j][0] && sparseArray[i][1] < other.sparseArray[j][1])) {
                result.sparseArray.push_back(sparseArray[i]);
                ++i;
            } else if (sparseArray[i][0] > other.sparseArray[j][0] ||
                       (sparseArray[i][0] == other.sparseArray[j][0] && sparseArray[i][1] > other.sparseArray[j][1])) {
                result.sparseArray.push_back(other.sparseArray[j]);
                ++j;
            } else {
                result.sparseArray.push_back({sparseArray[i][0], sparseArray[i][1], sparseArray[i][2] + other.sparseArray[j][2]});
                ++i;
                ++j;
            }
        }

        while (i < sparseArray.size()) {
            result.sparseArray.push_back(sparseArray[i]);
            ++i;
        }

        while (j < other.sparseArray.size()) {
            result.sparseArray.push_back(other.sparseArray[j]);
            ++j;
        }

        return result;
    }

    // Function to transpose the sparse matrix
    SparseMatrix transpose() const {
        int sizeX = sparseArray.back()[1] + 1;
        int sizeY = sparseArray.back()[0] + 1;
        SparseMatrix result(sizeX, sizeY);

        for (const auto& element : sparseArray) {
            result.sparseArray.push_back({element[1], element[0], element[2]});
        }
        return result;
    }
};

int main() {
    // Example matrices
    std::vector<std::vector<int>> matrix1 = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    std::vector<std::vector<int>> matrix2 = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    SparseMatrix sparseMatrix1(matrix1);
    SparseMatrix sparseMatrix2(matrix2);

    // Display original sparse matrices
    sparseMatrix1.display();
    std::cout << "\n";
    sparseMatrix2.display();
    std::cout << "\n";

    // Add sparse matrices
    SparseMatrix sumMatrix = sparseMatrix1.add(sparseMatrix2);
    std::cout << "Sum of sparse matrices:\n";
    sumMatrix.display();
    std::cout << "\n";

    // Transpose sparse matrix
    SparseMatrix transposedMatrix = sparseMatrix1.transpose();
    std::cout << "Transpose of sparse matrix:\n";
    transposedMatrix.display();

    return 0;
}
