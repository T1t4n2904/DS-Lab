#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add any remaining terms from both polynomials
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
    while (poly != NULL) {
        printf("%dX^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Term* polynomial1 = NULL;
    Term* polynomial2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&polynomial1, 5, 3);
    insertTerm(&polynomial1, -2, 2);
    insertTerm(&polynomial1, 7, 1);

    // Insert terms into the second polynomial
    insertTerm(&polynomial2, 3, 4);
    insertTerm(&polynomial2, 2, 2);
    insertTerm(&polynomial2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);
    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    Term* result = addPolynomials(polynomial1, polynomial2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    // Free allocated memory
    while (polynomial1 != NULL) {
        Term* temp = polynomial1;
        polynomial1 = polynomial1->next;
        free(temp);
    }

    while (polynomial2 != NULL) {
        Term* temp = polynomial2;
        polynomial2 = polynomial2->next;
        free(temp);
    }

    while (result != NULL) {
        Term* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
