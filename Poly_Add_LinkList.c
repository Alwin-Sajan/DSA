#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};
typedef struct Node Node;
void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
   
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
   
    Node* current = *poly;
   
    while (current->next != NULL) {
        current = current->next;
    }
   
    current->next = temp;
}
void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
   
    Node* current = poly;
   
    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
   
    printf("\n");
}
Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;
   
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
   
    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
   
    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
   
    return result;
}

void main(){
int n1 , n2 , n3 , i , j , k ;
// for X1
printf("\nEnter the number of terms for X1: ");
scanf("%d",&n1);
Node* poly1 = NULL;
int coeff , expo;
    while(n1 != 0){
    printf("Enter the coeff of x%d : ",n1-1);
    scanf("%d",&coeff);
insert(&poly1, coeff , n1-1);
n1--;
    }

printf("\nEnter the number of terms for X2: ");
scanf("%d",&n2);
Node* poly2 = NULL;
while(n2 != 0){
    printf("Enter the coeff of x%d : ",n2-1);
    scanf("%d",&coeff);
insert(&poly2, coeff , n2-1);
n2--;
    }

printf("\nFirst polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);
    Node* result = add(poly1, poly2);
    printf("\nSum of polynomials is : ");
    print(result);

}
