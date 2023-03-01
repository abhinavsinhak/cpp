      /// implementing circular linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;

};
struct node* tail = NULL;
struct node* createNode(int d){
 struct node* newNode = (struct node*)malloc(sizeof(struct node));
 newNode->data = d;
 newNode->next = NULL;
 return newNode;
};
void insertnode(int element,int d){
  struct node* curr =tail;
 struct node* temp = createNode(d);
  if(tail==NULL){
    struct node* temp =createNode(d);
    tail = temp;
    temp->next = temp;
    return;
  }

  while(curr->data !=element){
   curr = curr->next;
  }

  temp->next = curr->next;
  curr->next = temp;
};
void print(){
  struct node* temp = tail;
 if(tail==NULL){
  printf("list is empty\n");
  return;
 }

 do{
  printf("%d ",tail->data);
  tail = tail->next;
 }while(tail !=temp);
};
void main(){
 clrscr();
  insertnode(1,4);
  insertnode(4,5);
  insertnode(4,8);
  print();
 getch();
}