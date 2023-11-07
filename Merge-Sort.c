#include <stdio.h>

void merge(int a[],int i1,int i2,int j1,int j2){
  int temp[50];
  int i,j,k;
  i=i1; j=j1; k=0;
  while(i<=i2 && j<=j2){
    if(a[i]<a[j])
      temp[k++]=a[i++];
    else
      temp[k++]=a[j++];
  }
  while(i<=i2)
    temp[k++]=a[i++];
  while(j<=j2)
    temp[k++]=a[j++];
  for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];
}


void mergeSort(int a[],int i,int j){
  int mid;
  if(i<j){
    mid =(i+j)/2;
    mergeSort(a,i,mid);
    mergeSort(a,mid+1,j);
    merge(a,i,mid,mid+1,j);
  }
}


void main(){
  int n,a[50],i,j;
  printf("Enter no of elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter the element: ");
    scanf("%d",&a[i]);
  }

  printf("Unsorted array is : ");
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }

  mergeSort(a,0,n-1);
  printf("\nSorted array is : ");
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
}