/*Circle Queue */

#include<stdio.h>
int F = -1 , R = -1 ;
int a[10] ;

void main(){
  int item , op = 0 , MAXS;
  printf("Enter the size of Queue : ");
  scanf("%d",&MAXS);
  while(op != 4){
    printf("\nMenu Of Circle Queue\n--------------------- \n1) Enqueue \n2) Dequeue \n3) Display the queue \n4) Exit the program\n");
    printf("Enter the your choice : ");
    scanf("%d",&op);
    switch(op){

    /* Enqueue */
      case 1:
        if(F == ((R+1) % MAXS)){
          printf("The Queue is full \n");
        }
        else if((F == -1)&&(R == -1)){
          R = 0;
          printf("Enter the element : ");
          scanf("%d",&item);
          a[R] = item;
          F = 0;
        }
        else{
          R = (R + 1) % MAXS ;
          printf("Enter the element : ");
          scanf("%d",&item);
          a[R] = item;
}
          break;
      
    /* Dequeue */
      case 2:
        if((F == -1)&&(R == -1)){
          printf("The Queue is Empty \n");
        }
        else if(F == R){
          item = a[F];
          F = -1;
          R = -1;
          printf("The deleted element is %d \n",item);
        }
        else{
          item = a[F];
          F = (F + 1) % MAXS ;
          printf("The deleted element is %d \n",item);
        }
        break;

    /* display queue */
      case 3 :
        if((F == -1)&&(R == -1)){
          printf("The Queue is Empty \n");
        }
        else if(F == R){
          printf("The Queue is : ");
          printf("%d \n",a[F]);
        }
        else{
          int i = F;
          printf("The Queue is : ");
          while(i != R){
            printf("%d ",a[i]);
            i = ( i + 1 ) % MAXS;
          }
          printf("%d\n",a[i]);
          i = ( i + 1 ) % MAXS;
        }
        break;

    case 4:
      break;

    default:
      printf(" ! ! Invalid choice ! ! \n");
      break;

    }
  }
}
