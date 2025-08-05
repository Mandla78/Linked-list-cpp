#include <iostream>

using namespace std;
class Node{
   public:
       int value;
       Node *nextNode;
};

// print list of node
void printList(Node *n){
   while(n != NULL){
      cout<<n->value<<endl;
      n = n->nextNode;
   }
}

// add a new node at the first
void addNewNodeAtTheFront(Node** newHeadNode, int newValue){
      // 1. prepare a new node
      Node *newNode = new Node();
      newNode->value = newValue;
      //2. put it in the current head
      newNode->nextNode = *newHeadNode;
      // 3. move head of the list to the newnNode
      *newHeadNode = newNode;
}

// add a new node to the last
void addNewNodeToTheLast(Node ** newTailNode, int newValue){
 // 1. prepare a new node
     Node* newNode = new Node();
     newNode->value = newValue;
     newNode->nextNode = NULL;
 // 2. if linked list is empty, newNode will be a headNode
  if(*newTailNode == NULL){
    *newTailNode = newNode;
    return;
  }
 // 3. find the last node
   Node* newLastNode = *newTailNode;
   while(newLastNode ->nextNode != NULL){
      newLastNode= newLastNode->nextNode;
   }
 // 4. insert newNode after last node(at the node)
 newLastNode->nextNode =newNode ;
}

// add new node
void addNewNode( Node *previosNode, int newValue){
   // 1. check if previos node is NULL
    if(previosNode == NULL){
         cout<<"previos node cannot be NULL";
         return;
    }
   // 2. prepare a newNode
   Node *newNode = new Node();
   newNode->value = newValue;
   // 3. Insert newNode after previos
   newNode->nextNode = previosNode->nextNode;
   previosNode->nextNode = newNode;
}


int main()
{
     Node* headNode = new Node();
     Node* secondNode = new Node();
     Node* thirdNode = new Node();

     headNode->value = 1;
     headNode->nextNode = secondNode;
     secondNode->value = 2;
     secondNode->nextNode = thirdNode;
     thirdNode->value = 3;
     thirdNode->nextNode = NULL;

    // addNewNodeAtTheFront(&headNode, 0);
     addNewNodeAtTheFront(&headNode, 100);

    addNewNode(headNode, 10000);
    addNewNode(headNode, 20000);
     addNewNodeToTheLast(&headNode,400);
     printList(headNode);

    return 0;
}
