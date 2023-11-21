#include<stdio.h>
int F = -1 , R = -1 , MAXS;
int DQ[10] ,item ;

void Insert_Rear(){
  if(((F == 0 )&&(R == (MAXS - 1)))||(F == R+1)){
    printf("The DQueue is full\n");
  }
  else if((F == -1)&&(R == -1)){
    F = 0;
    R = 0;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[R] = item;
  }
  else if( R == MAXS - 1 ){
    R = 0 ;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[R] = item;
  }
  else{
    R++;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[R] = item;
  }
}

void Insert_Front(){
  if(((F == 0 )&&(R == (MAXS - 1)))||(F == R+1)){
    printf("The DQueue is full \n");
  }
  else if((F == -1)&&(R == -1)){
    F = 0;
    R = 0;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[F] = item;
  }
  else if( F == 0){
    F = MAXS - 1;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[F] = item;
  }
  else{
    F -= 1;
    printf("Enter the element : ");
    scanf("%d",&item);
    DQ[F] = item;
  }
}

void Delete_Front(){
  if((F == -1)&&(R == -1)){
    printf("The DQueue is Empty \n");
  }
  else if(F == R){
    item = DQ[F];
    F = -1;
    R = -1;
    printf("The deleted element is %d \n",item);
  }
  else if(F == (MAXS - 1)){
    printf("The DQueue is : ");
    printf("%d \n",DQ[F]);
    F = 0;
  }
  else{
    item = DQ[F];
    printf("The deleted element is %d \n",item);
    F = F+1;
  }
}


void Delete_Rear(){
  if((F == -1)&&(R == -1)){
    printf("The DQueue is Empty \n");
  }
  else if(F == R){
    item = DQ[R];
    F = -1;
    R = -1;
    printf("The deleted element is %d \n",item);
  }
  else if(R == 0){
    printf("The DQueue is : ");
    printf("%d \n",DQ[R]);
    R = MAXS-1;
  }
  else{
    item = DQ[R];
    printf("The deleted element is %d \n",item);
    R = R - 1;
  }
}

void Display(){
  int i =F;
  printf("Element in a DQueue are : ");
  while(i!= R){
    printf("%d ",DQ[i] );
    i = (i+1) % MAXS ;
  }
  printf("%d ",DQ[i] );
}

void main(){
  int item , op = 0 ;
  printf("Enter the size of Double-End Queue : ");
  scanf("%d",&MAXS);
  while(op != 6){
    printf("\nMenu Of Double-End Queue\n--------------------- \n1) Insertion from front \n2) Insertion from Rear \n3) Deletion from Front \n4) Deletion from Rear \n5) Display the queue \n6) Exit the program \n");
    printf("Enter the your choice : ");
    scanf("%d",&op);
    switch(op){
    
      /* Insertion from Front*/
      case 1:
        Insert_Front();
        break;
      
      /* Insertion from Rear */
      case 2:
        Insert_Rear();
        break;
      
      /*Deletion from front*/
      case 3:
        Delete_Front();
        break;
      
      /*Delete from Rear*/
      case 4:
        Delete_Rear();
        break;
      
      /* display queue */
      case 5 :
        Display();
        break;
      
      case 6:
        break;
    
      default:
        printf(" ! ! Invalid choice ! ! \n");
        break;
      
    }
  }
}
