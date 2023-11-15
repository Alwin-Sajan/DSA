#include<stdio.h>
 int bubbleSort(int a[], int n){
 int temp;
 for(int i = 0 ; i < n-1 ; i++ ){
   for( int j = 0 ; j < n-1-i ; j++ ){
     if(a[j] > a[j+1]){
       temp = a[j];
         a[j] = a[j+1];
         a[j+1] = temp;
     }
   }
 }
}
void main(){
 int i , a[30], n , j , b[30] ;
 printf("Enter the no of elements: ");
 scanf("%d",&n);
 for(i = 0 ; i < n ; i++){
   printf("Enter the element: ");
   scanf("%d",&a[i]);
 }
 bubbleSort(a,n);
 printf("\nThe sorted array\n");
 for(i = 0 ; i < n ; i++ ){
   printf("%d ",a[i]);
 }
}