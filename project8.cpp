#include <iostream>
#include <climits>
using namespace std;

#include "project8.h"

template <typename T>
List2<T>::List2()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}
template <typename T>
List2<T>::List2(List2* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 int pos = 1;
 doubleNode<T>* start = lst->FindPosition(pos);

 while (pos < lst->length)
 {
  Insert(start->item,pos);
  start = start->next;
  pos++;
 }  
}
template <typename T>
List2<T>::~List2()
{
}
template <typename T>
doubleNode<T>* List2<T>::FindPosition(int pos)
{
 doubleNode<T>* cur = head;
 int i = 0;
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename T>
void List2<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for the previous and next nodes
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void List2<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}


template <typename T>
void List2<T>::DeleteItemH()
{
if(head -> next == NULL)
	{
	head = NULL;
	length =0;
	tail=NULL;
        }
else
{
 doubleNode<T>* temp = head;
 head=head -> next;
 delete temp;
 length --;
}
}
template <typename T>
void List2<T>::DeleteItemT()
{
	doubleNode<T> *pre = head;
	doubleNode<T> * temp = head;
	while ( temp->next != NULL)
		{
		pre = temp;
		temp=temp->next;
		}

    if (length >1)
        {
        tail=pre;
        delete temp;
        tail-> next = NULL;
        }
        else 
        {
            delete temp;
            head=NULL;
            tail=NULL;
        }
    length--;
}


 
 template <typename T>
 void List2<T>::Delete(int pos)
{
if (head!=NULL)
{
  if (pos==1)
  {
   DeleteItemH();	
  }
  else if (pos == length)
  {
  DeleteItemT();
  }
  else
  {

  	doubleNode<T>* temp = head;
  for (int i=1; i < pos;i++)
   {
    temp = temp -> next;
   }
   doubleNode<T>* nodie= temp-> next;
   temp -> next = nodie -> next;
   delete nodie;
   length -- ;
  }
}
}
template <typename T>
int List2<T>::DeleteAll(T item)
{
int temp;
temp = length;

  for(int i = length;i>0;i--)
  {
  
	Delete(i);
  }
  return temp;
  }
  
  
/*  
void List2::PrintForward()
{
 doubleNode * temp = head;
 for (int i=1;i<=length;i++)
  {
  cout << temp -> item <<endl;
  temp = temp -> next;
  }
}
*/
template <typename T>
void List2<T>::PrintBackwards()
{

 doubleNode<T> * temp = tail->prev;
 for(int i=length;i>0;i--)
 {
 cout << temp -> item << endl;
 temp = temp -> prev;
 }
}
