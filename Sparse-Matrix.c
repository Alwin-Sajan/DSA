/* Sparse Matrix */

#include<stdio.h>

int Create_Sparse(int a[][25], int r, int c , int b[][3]){
  int i , j , k;
  k = 1 ;
  b[0][0] = r;
  b[0][1] = c;
  for( i = 0 ; i < r ; i++ ){
    for( j = 0 ; j < c ; j++ ){
        if( a[i][j] != 0){
        b[k][0] = i;
        b[k][1] = j;
        b[k][2] = a[i][j];
        k++;
      }
    }
  }
  b[0][2] = k-1;
}

void Print_sparse(int b[][3]){
  int i , c = b[0][2];
  for ( i = 0 ; i <= c ; i++ ){
    printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
  }
}
 
void Tranpose_Sparse(int a[][25], int r, int c , int T[][3]){
  int i , j , k;
  k = 1 ;
  T[0][0] = r;
  T[0][1] = c;
  for( i = 0 ; i < r ; i++ ){
    for( j = 0 ; j < c ; j++ ){
      if( a[i][j] != 0){
        T[k][0] = j;
        T[k][1] = i;
        T[k][2] = a[i][j];
        k++;
      }
    }
  }
  T[0][2] = k-1;
}

/* Main Function */ 
void main(){
  int a[25][25] , i , j , r, c ,b[25][3],T[25][3];
  printf("Enter the no of rows: ");
  scanf("%d",&r);
  printf("Enter the no of column: ");
  scanf("%d",&c);
  for(i = 0 ; i < r ; i++ ){
    for( j = 0 ; j < c ; j++ ){
      printf("Enter the element : ");
      scanf("%d",&a[i][j]);
    }
  }
  //print matrix original
  printf("\nThe Matrix is \n");
  for(i = 0 ; i < r ; i++ ){
    for( j = 0 ; j < c ; j++){
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
  Create_Sparse( a , r, c , b);
  printf("\nSparse form - list of 3 Triplet is \n\n");
  Print_sparse(b);

  /* To display the traspose of Matrix */
  Tranpose_Sparse(a , r, c , T);
  printf("\nTranspose of Matrix\n");
  Print_sparse(T);
}