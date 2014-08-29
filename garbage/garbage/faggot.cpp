#include <iostream>
using namespace std;

struct listNode
{
 char name;
 listNode *nextNode;
};

typedef listNode *listNodePtr;
listNode* addNodeToEnd(listNode *front,char nName);
listNode* deleteNode(listNode *front,char name);
void printList(listNode *front);

int main()
{
 listNode* front = NULL;
 front = addNodeToEnd(front,'l');
 front = addNodeToEnd(front,'i');
 front = addNodeToEnd(front,'s');
 front = addNodeToEnd(front,'t');
 front = addNodeToEnd(front,' ');
 front = addNodeToEnd(front,'o');
 front = addNodeToEnd(front,'f');
 front = addNodeToEnd(front,' ');
 front = addNodeToEnd(front,'n');
 front = addNodeToEnd(front,'o');
 front = addNodeToEnd(front,'d');
 front = addNodeToEnd(front,'e');
 front = addNodeToEnd(front,'s');
 
 cout << "List at point 1:" << endl;
 printList(front);
 
 front = deleteNode(front,'s');
 front = deleteNode(front,' ');
 front = deleteNode(front,' ');
 front = addNodeToEnd(front,'z');
 front = deleteNode(front,'n');
 front = deleteNode(front,'s');
 front = deleteNode(front,'o');
 front = addNodeToEnd(front,'!');
 
 cout << endl << "List at point 2:" << endl;
 printList(front);
 
 return 0;
}

listNode* addNodeToEnd(listNode *front,char nName)
{
 listNode* temp = front;
 listNode* temp2 = NULL;
 if(temp==NULL)
 {/*if the list is empty create new node and set its next to NULL*/
  temp = new listNode;
  temp->name = nName;
  temp->nextNode = NULL;
  return temp;
 } else { /*list is not empty, add to end*/
     while(temp->nextNode!=NULL)
     {/*while temp's nextNode is not NULL, iterate through list nodes*/
/**** 8A. Student to fill in line of code for answer ****/
    temp = temp->nextNode;
     }
     /*temp now points to the end of the list. Create new node and add after temp*/
     temp2 = new listNode;
     temp2->name = nName;
/**** 8B. Student to fill in line of code for answer ****/
    temp2->nextNode = NULL;
     temp->nextNode = temp2;
     return front;
 }
}
listNode* deleteNode(listNode *front,char name)
{
 listNode* temp = front;
 listNode* temp2 = NULL;
 
 if(temp==NULL)
 {/*empty, no nodes to delete*/
  return front;
 }
 if(temp->name==name)
 {/*if the first node is to be deleted, move the front to the next and delete*/
  front = temp->nextNode;
  delete temp;
  return front;
 }
 temp2 = temp->nextNode;
/**** 8C. Student to fill in line of code for answer ****/
while(temp2 != NULL && temp2->name != name)
 {/*loop until either temp2 finds name or temp2 hits NULL*/
  temp = temp2;
  temp2 = temp->nextNode;
/**** 8D. Student to fill in line of code for answer ****/
 }
 /*either the node is found or we hit the end*/
 if(temp2->name==name)
 {/*if temp2 is pointing to the correct node correct temp's pointer and delete temp2*/
/**** 8E. Student to fill in line of code for answer ****/
temp->nextNode = temp2->nextNode;
  delete temp2;
 }
 return front;
}
void printList(listNode *front)
{
 listNode* temp = front;
 cout << "The node list contains:";
 while(temp!=NULL)
 {/*print until the end*/
  cout << temp->name << " ";
  temp = temp->nextNode;
 }
}