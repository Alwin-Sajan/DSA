#include<stdio.h>
  
int InsertionSort(int a[] , int n){
  int j , i , key ;
  for(i = 1 ; i < n ; i++ )
  {
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }
}

void main(){
  int a[25] , n , i;
  printf("Enter the no of elements: ");
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    printf("Enter the Element: ");
    scanf("%d",&a[i]);
  }
  InsertionSort(a,n);
  printf("The Sort array is ");
  for(i = 0 ; i < n ; i++ ){
    printf("%d ",a[i]);
  }
}