#include<stdio.h>

void display(int top , int Stack[]){
  for(int i = top ; i >= 0 ; i-- ){
    printf("%d ",Stack[i]);
  }
}

void main(){
  int op = 1 , data, ndata , top = -1 , MAXSIZE = 30 , Stack[30] , i;
  while(op != 0){
      printf("\n\nM   E   N   U\n1. Push an element. \n2. Pop an element. \n3. Peek the stack \n4. Display the stack \n5. Exit the program.\nEnter your choice ( 1 / 2 / 3 / 4 / 5 ) : ");
      scanf("%d",&op);
      
      switch(op){
      
        case 1:
        
          if( top != MAXSIZE){
            top = top + 1;
            printf("Enter the element to be pushed : ");
            scanf("%d",&ndata);
            Stack[top] = ndata;
            display(top , Stack);
          }
          else
            printf("Could not insert data ,Stack is full"); 
          break;
        
        case 2:
        
          if(top != -1){
            data = Stack[top] ;
            top = top - 1 ;
            printf("The deleted element is : %d \n",data);
            display(top, Stack);
            }
          else{
            printf("Could not perform deletion , Stack is empty !!");
          }
          break;
        
        case 3:
          if(top != -1){
            data = Stack[top];
            printf("The top most element is : %d\n",data);
          }
          else{
            printf("The stack is empty !! ");
          }
          break;
        
        case 4:
          if(top != -1){
            display(top, Stack);
          }
          else{
            printf("The stack is empty !! ");
          }
          break;
        
        case 5:
          op = 0;
          break;
        
        default:
          printf(" ! ! Invalid choice ! ! \n");
          break;
      
    }
  }
}
