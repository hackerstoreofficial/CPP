#include <iostream>
#include <iomanip>

const int MAX_DEGREE_X = 3; // Maximum degree of x
const int MAX_DEGREE_Y = 2; // Maximum degree of y

class Polynomial {
private:
    int poly[MAX_DEGREE_X + 1][MAX_DEGREE_Y + 1];

public:
    Polynomial() {
        // Initialize the polynomial array with zeros
        for (int i = 0; i <= MAX_DEGREE_X; ++i) {
            for (int j = 0; j <= MAX_DEGREE_Y; ++j) {
                poly[i][j] = 0;
            }
        }
    }

    // Function to set the coefficient of a term
    void setCoefficient(int degreeX, int degreeY, int coefficient) {
        poly[degreeX][degreeY] = coefficient;
    }

    // Function to add two polynomials
    Polynomial addPolynomials(const Polynomial& other) const {
        Polynomial result;

        for (int i = 0; i <= MAX_DEGREE_X; ++i) {
            for (int j = 0; j <= MAX_DEGREE_Y; ++j) {
                result.poly[i][j] = poly[i][j] + other.poly[i][j];
            }
        }

        return result;
    }

    // Function to display the polynomial
    void display() const {
        std::cout << "Polynomial:\n";

        for (int i = MAX_DEGREE_X; i >= 0; --i) {
            for (int j = 0; j <= MAX_DEGREE_Y; ++j) {
                if (poly[i][j] != 0) {
                    std::cout << poly[i][j] << "x^" << i << "y^" << j;
                    if (i + j > 0) {
                        std::cout << " + ";
                    }
                }
            }
        }

        std::cout << std::endl;
    }
};

int main() {
    Polynomial poly1, poly2, result;

    // Set coefficients for the first polynomial
    poly1.setCoefficient(2, 1, 3);
    poly1.setCoefficient(1, 2, 5);
    poly1.setCoefficient(0, 0, 1);

    // Set coefficients for the second polynomial
    poly2.setCoefficient(2, 1, 2);
    poly2.setCoefficient(1, 2, 4);
    poly2.setCoefficient(0, 0, -1);

    // Display the first polynomial
    poly1.display();

    // Display the second polynomial
    poly2.display();

    // Add the polynomials
    result = poly1.addPolynomials(poly2);

    // Display the result
    result.display();

    return 0;
}
