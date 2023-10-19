#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
typedef struct Term Term;
struct Term {
    int coefficient;
    int exponent;
    Term* next;
};

// Function to create a new term node
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);
    newTerm->next = *poly;
    *poly = newTerm;
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    // Append any remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, -2, 1);
    insertTerm(&poly1, 5, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, -1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(sum);

    // Free memory
    while (poly1 != NULL) {
        Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }

    while (poly2 != NULL) {
        Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }

    while (sum != NULL) {
        Term* temp = sum;
        sum = sum->next;
        free(temp);
    }

    return 0;
}
