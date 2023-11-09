#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = newTerm;
    newTerm->prev = newTerm;
    return newTerm;
}

// Function to insert a term into a polynomial as a circular doubly linked list
void insertTerm(Term* header, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    Term* current = header->prev;
    newTerm->next = header;
    newTerm->prev = current;
    current->next = newTerm;
    header->prev = newTerm;
}

// Function to multiply two polynomials
Term* multiplyPolynomials(Term* poly1, Term* poly2) {
    Term* result = createTerm(0, 0); // Initialize result as a single term polynomial (0x^0)

    Term* current1 = poly1->next;
    while (current1 != poly1) {
        Term* current2 = poly2->next;
        while (current2 != poly2) {
            int coefficient = current1->coefficient * current2->coefficient;
            int exponent = current1->exponent + current2->exponent;
            insertTerm(result, coefficient, exponent);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(Term* header) {
    Term* current = header->next;
    while (current != header) {
        printf("%dx^%d", current->coefficient, current->exponent);
        if (current->next != header) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Term* polynomial1 = createTerm(0, 0); // Initialize header node
    Term* polynomial2 = createTerm(0, 0); // Initialize header node

    // Insert terms into the first polynomial
    insertTerm(polynomial1, 5, 3);
    insertTerm(polynomial1, -2, 2);
    insertTerm(polynomial1, 7, 1);

    // Insert terms into the second polynomial
    insertTerm(polynomial2, 3, 4);
    insertTerm(polynomial2, 2, 2);
    insertTerm(polynomial2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);
    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    Term* result = multiplyPolynomials(polynomial1, polynomial2);

    printf("Product of Polynomials: ");
    displayPolynomial(result);

    // Free allocated memory
    Term* current = polynomial1->next;
    while (current != polynomial1) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(polynomial1);

    current = polynomial2->next;
    while (current != polynomial2) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(polynomial2);

    current = result->next;
    while (current != result) {
        Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(result);

    return 0;
}
