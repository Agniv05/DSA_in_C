#include <stdio.h>

struct Node{
  int data;
  struct node* left;
  struct node* right;
 };

struct node* createNode(int data){
  struct node *n;  //creating a node pointer
  n=(struct node *)malloc(sizeof(struct node));    // allocating memory in heap  
  n->data=data;   // setting data
  n->left=NULL;   //setting left and right children to null
  n->right=NULL;
  return n;    // returning created node
}

int main(){
  /*struct node *p;
  p=(struct node *)malloc(sizeof(struct node));   //root node
  p->data=2;
  p->left=NULL;
  p->right=NULL;
  struct node *p1;
  p1=(struct node *)malloc(sizeof(struct node));   
  p1->data=7;
  p1->left=NULL;
  p1->right=NULL;  
  struct node *p2;
  p2=(struct node *)malloc(sizeof(struct node));   
  p2->data=14
  p2->left=NULL;
  p2->right=NULL;
  p->left=p1;
  p->right=p2;   //p is root node with two child nodes p1 and p2*/

  //constructing root node
  struct node *p=createNode(2);
  struct node *p1=createNode(7);    // left node
  struct node *p2=createNode(14);   // right node
  p->left=p1;  //linked left child to root node
  p->right=p2; //linked right child to root node
  return 0;
}
