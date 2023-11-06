/* Polynomial Addition */

#include<stdio.h>
struct Poly{
  int coeff;
  int expo;
}X1[10] , X2[20] , X3[10];

/* I created this program with no function other than than main function */


void main(){
  int n1, n2, n3 , i ,j ,k ;

  //first Element
  printf("\nEnter the number of terms for X1: ");
  scanf("%d",&n1);
  for( i = 0 ; i < n1+1 ; i++ ){
    printf("Enter the coeff of x%d : ",n1-i);
    scanf("%d",&X1[i].coeff);
    X1[i].expo = n1-i;
  }
  i = 0;
  printf("X1 is : ");
  printf("%dx^%d ",X1[i].coeff,X1[i].expo);
  for( i = 1 ; i < n1+1 ; i++ ){
    printf("+ %dx^%d ",X1[i].coeff,X1[i].expo);
  }

  //Second Element
  printf("\n\nEnter the number of terms for X2: ");
  scanf("%d",&n2);
  for( i = 0 ; i < n2+1 ; i++ ){
    printf("Enter the coeff of x%d : ",n2-i);
    scanf("%d",&X2[i].coeff);
    X2[i].expo = n2-i;
  }
  i = 0;
  printf("X2 is : ");
  printf("%dx^%d ",X2[i].coeff,X2[i].expo);
  for( i = 1 ; i < n2+1 ; i++ ){
    printf("+ %dx^%d ",X2[i].coeff,X2[i].expo);
  }

  //Addition
  printf("\n\nAddition of X1 and X2 is \n");
  i = 0  , j = 0  , k = 0;
  while(n1>=i && n2>=i){

    if (X1[i].expo == X2[j].expo){
      X3[k].coeff = X1[i].coeff + X2[j].coeff;
      X3[k].expo = X2[j].expo;
      i++;
      j++;
      k++;
    }
    else if (X1[i].expo > X2[j].expo){
      X3[k].coeff = X1[i].coeff;
      X3[k].expo = X1[i].expo;
      k++;
      i++;
    }
    else{
      X3[k].coeff = X2[j].coeff;
      X3[k].expo = X2[j].expo;
      j++;
      k++;
    }
  }
  int Last = n1-i ;
  while(Last>0){
    X3[k].coeff = X1[i].coeff;
    X3[k].expo = X1[i].expo;
    k++;
    i++;
    Last--;
  }
  Last = n2-j ;
  while(Last>0){
    X3[k].coeff = X2[j].coeff;
    X3[k].expo = X2[j].expo;
    j++;
    k++;
    Last--;
  }

  //Display Addition answer
  i = 0 ;
  Printf("X1 + X2 = ");
  printf("%dx^%d ",X3[i].coeff,X3[i].expo);
  for( i = 1 ; i < k ; i++ ){
    printf("+ %dx^%d ",X3[i].coeff,X3[i].expo);
  }
}