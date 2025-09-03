#include <stdio.h>
#include <stdlib.h>

/* Node for polynomial term */
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

/* Create node or exit on memory error */
struct Node* createNode(int coeff, int pow) {
    struct Node* n = (struct Node*)malloc(sizeof *n);
    if (!n) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->coeff = coeff;
    n->pow = pow;
    n->next = NULL;
    return n;
}

/* Insert term into list sorted by descending power.
   Combines like terms and removes node if coefficient becomes zero. */
void insertTerm(struct Node** poly, int coeff, int pow) {
    if (coeff == 0) return; /* nothing to insert */

    struct Node* cur = *poly;
    struct Node* prev = NULL;

    /* find insertion point (descending powers) */
    while (cur != NULL && cur->pow > pow) {
        prev = cur;
        cur = cur->next;
    }

    /* if same power, combine */
    if (cur != NULL && cur->pow == pow) {
        cur->coeff += coeff;
        if (cur->coeff == 0) { /* remove node if coeff becomes 0 */
            if (prev == NULL) *poly = cur->next;
            else prev->next = cur->next;
            free(cur);
        }
        return;
    }

    /* otherwise create new node and insert */
    struct Node* newNode = createNode(coeff, pow);
    if (prev == NULL) { /* insert at head */
        newNode->next = *poly;
        *poly = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

/* Add two polynomials (returns new list) */
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* res = NULL;
    while (p1 != NULL || p2 != NULL) {
        if (p1 == NULL) {
            insertTerm(&res, p2->coeff, p2->pow);
            p2 = p2->next;
        } else if (p2 == NULL) {
            insertTerm(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow > p2->pow) {
            insertTerm(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(&res, p2->coeff, p2->pow);
            p2 = p2->next;
        } else { /* equal powers */
            insertTerm(&res, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return res;
}

/* Subtract p2 from p1 (returns new list) */
struct Node* subPoly(struct Node* p1, struct Node* p2) {
    struct Node* res = NULL;
    while (p1 != NULL || p2 != NULL) {
        if (p1 == NULL) {
            insertTerm(&res, -p2->coeff, p2->pow);
            p2 = p2->next;
        } else if (p2 == NULL) {
            insertTerm(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow > p2->pow) {
            insertTerm(&res, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insertTerm(&res, -p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            insertTerm(&res, p1->coeff - p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return res;
}

/* Nicely display polynomial:
   - skips zero coeffs
   - prints "x" instead of "x^1"
   - prints constants for pow 0
   - handles + / - spacing */
void displayPoly(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    int first = 1;
    while (poly != NULL) {
        int c = poly->coeff;
        int p = poly->pow;
        if (c != 0) {
            if (!first) {
                /* middle terms: show sign with spaces */
                if (c > 0) printf(" + ");
                else printf(" - ");
            } else {
                /* first term: print leading '-' if negative */
                if (c < 0) printf("-");
            }

            int ac = (c < 0) ? -c : c; /* absolute coeff */

            /* omit printing "1" (or -1) for non-constant terms */
            if (!(ac == 1 && p != 0)) printf("%d", ac);

            if (p > 1) printf("x^%d", p);
            else if (p == 1) printf("x");
            /* if p == 0 -> constant, already printed */

            first = 0;
        }
        poly = poly->next;
    }
    if (first) /* all terms were zero */
        printf("0");
    printf("\n");
}

/* Free list */
void freePoly(struct Node* poly) {
    while (poly) {
        struct Node* t = poly;
        poly = poly->next;
        free(t);
    }
}

/* Example usage */
int main(void) {
    struct Node *P1 = NULL, *P2 = NULL, *sum = NULL, *diff = NULL;

    /* P1 = 19x^4 - 8x^3 + 9x^2 + 5 */
    insertTerm(&P1, 19, 4);
    insertTerm(&P1, -8, 3);
    insertTerm(&P1, 9, 2);
    insertTerm(&P1, 5, 0);

    /* P2 = 9x^5 + 3x^3 + 9x^2 + 3x - 15 */
    insertTerm(&P2, 9, 5);
    insertTerm(&P2, 3, 3);
    insertTerm(&P2, 9, 2);
    insertTerm(&P2, 3, 1);
    insertTerm(&P2, -15, 0);

    printf("P1 = ");
    displayPoly(P1);

    printf("P2 = ");
    displayPoly(P2);

    sum = addPoly(P1, P2);
    printf("P1 + P2 = ");
    displayPoly(sum);

    diff = subPoly(P1, P2);
    printf("P1 - P2 = ");
    displayPoly(diff);

    freePoly(P1);
    freePoly(P2);
    freePoly(sum);
    freePoly(diff);

    return 0;
}
