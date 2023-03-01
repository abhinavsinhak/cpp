    //implementing the doubly linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* pre;
  struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
struct node* createNode(int d){
 struct node* temp = (struct node*)malloc(sizeof(struct node));
 temp->data = d;
 temp->pre = NULL;
 temp->next = NULL;
  return temp;
}

void insertAtHead(int d){
  struct node* curr = createNode(d);
 if(head==NULL){
  struct node* temp = createNode(d);
  head = temp;
  tail = temp;
  return;
 }

 curr->next = head;
 head->pre = curr;
 head = curr;
}
void insertAtTail(int d){
  struct node* curr = createNode(d);
 if(tail==NULL){
  struct node* temp = createNode(d);
  head = temp;
  tail = temp;
  return;
 }

 tail->next = curr;
 curr->pre = tail;
 tail = curr;

}
void insertAtPos(int pos,int d){
   int cnt =1;
  struct node* temp = head;
 struct node* newNode = createNode(d);
 if(pos==1){
  insertAtHead(d);
 }


 while(cnt<pos-1){
  temp = temp->next;
  cnt++;
 }
 if(temp->next ==NULL){
  insertAtTail(d);
  return;
 }

 newNode->next = temp->next;
 temp->next = newNode;
 newNode->pre = temp;
}
void delete(int pos){
  int cnt = 1;
 struct node* curr = head;
 if(pos==1){
  struct node* temp = head;
   head = temp->next;
   temp->pre = NULL;
   temp->next = NULL;
   free(temp);
   return;
 }

 while(cnt <pos){
  curr = curr->next;
  cnt++;
 }
 if(curr->next ==NULL){
  curr->pre->next = NULL;
  tail = curr->pre;
  curr->pre = NULL;
  free(curr);
  return;

 }
 curr->pre->next = curr->next;
 curr->next->pre = curr->pre;
 curr->pre = NULL;
 curr->next = NULL;
 free(curr);
}
void print(){
 struct node* temp = head;
 while(temp!=NULL){
  printf("%d ",temp->data);
  temp= temp->next;
 }
}
void reverse(){
 struct node* before = NULL;
 struct node* curr = head;
 struct node* ahead = NULL;
 while(curr !=NULL){
  ahead = curr->next;
  curr->next = before;
  curr->pre  = ahead;
  before = curr;
  curr = ahead;
 }
 head = before;
 tail = ahead;
}
void print_rev(){
 struct node* temp = tail;
 while(temp !=NULL){
  printf("%d ",temp->data);
  temp = temp->pre;
 }
}
void main(){
 clrscr();
 insertAtHead(10);
 insertAtHead(9);
 insertAtTail(11);
 insertAtPos(2,4);

 print();
 printf("\n");
 delete(2);
 print();
 printf("\n");
 reverse();
 print();
 printf("\n");
 print_rev();
 getch();
}