#include<stdio.h>

int Partion(int a[] , int l , int r ){
  int pivot=a[l];
  int i=l,j=r,t;
  while(i<=j){
    while(a[i]<=pivot &&i<=r)
    {
      i++;
    }
    while(a[j]>pivot)
    {
      j--;
    }
    if(i<j)
    {
      t=a[j];
      a[j]=a[i];
      a[i]=t;
    }
    t=a[j];
    a[j]=a[l];
    a[l]=t;
    return j;
  }
}

int QuickSort(int a[], int L , int R){
  int q ;
  if(L < R){
    q = Partion(a , L , R );
    QuickSort(a , L , q-1 );
    QuickSort(a , q+1 , R );
  }
}

void main(){
  int a[25] , n , i , Left , Right ;
  printf("Enter the no of elements: ");
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    printf("Enter the Element: ");
    scanf("%d",&a[i]);
  }
  Left = 0 ;
  Right = n-1 ;

  QuickSort(a, Left, Right);
  printf("The Sort array is ");
  for(i = 0 ; i < n ; i++ ){
    printf("%d ",a[i]);
  }
}