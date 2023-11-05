#include<stdio.h>
void main(){
   int a[20], n, i, key, CON = 0, num = 0;
   printf("Enter the no of elements:");
   scanf("%d",&n);
   for(i = 0 ; i < n ; i++ ){
      printf("Enter the element: ");
      scanf("%d",&a[i]);
   }
   printf("\nEnter the key: ");
   /*Element to be Search */
   scanf("%d",&key);
   for(i = 0 ; i < n ; i++ ){
      if(a[i] == key){
      	 num ++;
         if(num == 1){
              CON = 1;
      	      printf("The element %d found at %d ",key,i+1);
         }
         else{
             printf("and %d ",i+1);
         }
   	  }
   }
   
   if(CON == 0)
         printf("The element not found");
 }
