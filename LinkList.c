#include<stdio.h>
#include<stdlib.h>

struct node *temp ;
struct node *ptr ;
struct node *ptr2;
struct node *Head = NULL;
int item ;

struct node{
int data;
struct node *next;
};


void create_node(){
temp = (struct node*) malloc(sizeof(struct node));
printf("Enter the data : ");
scanf("%d",&item);
temp->data = item ;
temp->next = NULL;
}

/* Insertion */

void insert_At_Head(){
if(Head == NULL){
create_node();
Head = temp;
}
else{
create_node();
temp->next = Head;
Head = temp;
}
}
void insert_At_Tail(){
if(Head == NULL){
create_node();
Head = temp;
}
else{
create_node();
ptr = Head;
while(ptr->next != NULL){
ptr = ptr->next;
}
ptr->next = temp;
}
}

void insert_At_Pos(){
int pos;
printf("Enter the position : ");
scanf("%d",&pos);
if(Head == NULL){
create_node();
Head = temp;
}
else if(pos == 1 )
insert_At_Head();

else{
ptr = Head;
create_node();
int i = 1;
while(i<pos){
ptr = ptr->next;
i++;
}
temp->next = ptr->next;
ptr->next = temp;
}
}

/* Delection */

void Del_Head(){
if(Head == NULL){
printf("List is Empty ");
}
else{
ptr = Head;
Head = Head->next;
printf("The deleted element is %d",ptr->data);
free(ptr);
}
}

void Del_Tail(){
if(Head == NULL){
printf("List is Empty ");
}
else{
ptr = Head;
while((ptr->next)->next != NULL){
ptr = ptr->next;
}
ptr2 = ptr->next;
ptr->next =NULL;
printf("The deleted element is %d",ptr2->data);
free(ptr2);
}
}

void Del_Pos(){
int pos;
printf("Enter the position : ");
scanf("%d",&pos);
if(Head == NULL){
printf("List is Empty ");
}
else if(pos == 1){
Del_Head();
}
else{
ptr = Head;
int i = 1;
while(i<pos-1){
ptr = ptr->next;
i++;
}
temp = ptr->next;
ptr->next = temp->next;
printf("The deleted element is %d",temp->data);
free(temp);
}
}

void Display(){
printf("The List is : ");
ptr = Head;
while(ptr->next != NULL){
printf("%d ",ptr->data);
ptr = ptr->next;
}printf("%d ",ptr->data);
}

void main(){
int op = 0;
do{
printf("\nMenu Of Link-List\n1) Insertion at head \n2) Insertion at tail ");
printf("\n3) Insertion at specific position \n4) Deletion at head \n5) Deletion at tail \n6) Deletion at specific position \n7) Display the List \n8) Exit the program\n");

printf("Enter the choice : ");
scanf("%d",&op);

switch(op){

case 1:
insert_At_Head();
break;

case 2:
insert_At_Tail();
break;

case 3:
insert_At_Pos();
break;

case 4:
Del_Head();
break;

case 5:
Del_Tail();
break;

case 6:
Del_Pos();
break;

case 7:
Display();
break;

case 8:
break;

default:
printf("!! Invalid choice !!\n");
break;

}
}
while(op != 8);
}