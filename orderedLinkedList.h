#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedList.h"

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the list,
        // otherwise the value false is returned.
        void insert(const Type& newItem);
        //Function to insert newItem in the list.
        //Postcondition: first points to the new list, newItem
        // is inserted at the proper place in the list, and
        // count is incremented by 1.
        void insertCheck (const Type& newItem);
        //inserts newItem, but first checks if it is already in th elist
        void insertFirst(const Type& newItem);
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the beginning of the list, last points to the
        // last node in the list, and count is incremented by 1.
        void insertLast(const Type& newItem);
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the end of the list, last points to the
        // last node in the list, and count is incremented by 1.
        void deleteNode(const Type& deleteItem);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing deleteItem is

};

template <class Type>
void orderedLinkedList<Type>::insertCheck(const Type& newItem)
{
    bool alreadyInList = search(newItem);

    if(alreadyInList)
    {
        cout<<"This is already in the list. We are not allowing duplicates.";
    }
    else
    {
        nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;

    bool found;

    newNode = new nodeType<Type>;
    newNode->info=newItem;
    newNode->link= NULL;

    if(this->first==NULL)     //case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        while(current != NULL && !found)
        {
            if(current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current  = current->link;
            }
        }
        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
                this->last = newNode;
                this->count++;
        }
    }




    }//end else
}//end insert



template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;
    current =this->first;

    while (current!=NULL&&!found)
    {
         if(current->info>=searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    if (found)
        found = (current->info==searchItem);
    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;

    bool found;

    newNode = new nodeType<Type>;
    newNode->info=newItem;
    newNode->link= NULL;

    if(this->first==NULL)     //case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        while(current != NULL && !found)
        {
            if(current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current  = current->link;
            }
        }
        if (current == this->first)
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL)
                this->last = newNode;
                this->count++;
        }
    }//end else
}//end insert


template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

//    nodeType<Type> *last = back();
//    nodeType<Type> *first = front();
 //   int counter = getCounter();

    if(this->first==NULL)
        cout<<"Error. Cannot delete from an empty list."<<endl;
    else
    {
        current = this->first;
        found = false;
        while(current!=NULL && !found)//search the list
        {
            if(current->info>=deleteItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if (current == NULL)
        {
            cout<<"The item to be deleted is not in the list."<<endl;
        }
        else
        {
            if (current->info == deleteItem)
            {
                if (this->first == current)
                {
                    this->first = this->first->link;
                    if (this->first==NULL)
                    {
                        this->last = NULL;
                    }
                    delete current;
                }
                else
                {
                    trailCurrent->link=current->link;
                        if (current == this->last)
                        {
                            this->last = trailCurrent;
                        }
                }   delete current;

                this->count--;
            }
            else
                cout<<"The item to be deleted is not in the list."<<endl;
        }
        }//end deleteNode
    }
}

/*template <class Type>
Type orderedLinkedList<Type>::getFirst() const
{
    return *first;
}

template <class Type>
Type orderedLinkedList<Type>::getLast() const
{
    return *last;
}*/
#endif // ORDEREDLINKEDLIST_H
