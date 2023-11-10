#include<stdio.h>

void main(){
  int item , op = 0 , MAXS , a[10] ,  F = -1 , R = -1 ;
  printf("Enter the size of Queue : ");
  scanf("%d",&MAXS);
  while(op != 4){
    printf("\nM   E   N   U \n1) Enqueue \n2) Dequeue \n3) Display the queue \n4) Exit the program\n");
    printf("Enter the your choice : ");
    scanf("%d",&op);
    switch(op){
    case 1:
      if(R == MAXS-1){
        printf("The Queue is full \n");
}
      else{
        printf("Enter the element : ");
        scanf("%d",&item);
        if((F == -1)&&(R == -1)){
          R = R +1;
          a[R] = item;
          F = F + 1;
        }
        else{
          R = R + 1 ;
          a[R] = item;
        }
      }
      break;

    case 2:
      if((F == -1)&&(R == -1)){
        printf("The Queue is Empty \n");
      }
      else{
        if(F == R){
          item = a[F];
          F = -1;
          R = -1;
        }
        else{
          item = a[F];
          F = F + 1 ;
        }
      printf("The deleted element is %d \n",item);
     }
     break;

case 3 :
printf("The Queue is : ");
for(int i = F ; i <= R ; i++){
printf("%d ",a[i]);
}
printf("\n");
break;

case 4:
break;

default:
printf(" ! ! Invalid choice ! ! \n");
break;

}
}
}