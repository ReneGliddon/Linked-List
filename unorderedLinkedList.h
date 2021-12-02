#ifndef UNORDERED_LINKED_LIST_H
#define UNORDERED_LINKED_LIST_H

#include "linkedlist.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
	public:
		bool search(const Type& searchItem) const;
		void insertFirst(const Type& newItem);
		void insertLast(const Type& newItem);
		void deleteNode(const Type& deleteItem);
		void shareList(const unorderedLinkedList<Type> &orig, unorderedLinkedList<Type> &listA, unorderedLinkedList<Type> &listB);
        void testingPastpapers();
        int occurance(Type & occur);
//        nodeType<Type> searching*;
        void shareList(unorderedLinkedList<Type> & listA, unorderedLinkedList<Type> & listB);
        void linkedInsertionSort();
        void insertCircle(Type & newItem);
        //void printCircle();
        void divideAt(unorderedLinkedList<Type>&subList, int pos);



};

template<class Type>
void unorderedLinkedList<Type>::divideAt(unorderedLinkedList<Type> &subList, int pos)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *temp;

    trailCurrent=this->first;
    if(this->first->link!=NULL)
        current=this->first->link;
    //iterate through the list to the position for division
    for (int i = 1; i<pos;i++)
    {
        if(current->link!=NULL)
        {
             trailCurrent=trailCurrent->link;
            current=current->link;
        }

    }

    //first of the new list
    if(current!=NULL)
    {
        subList.first = new nodeType<Type>;
		subList.first->info = current->info;
		subList.first->link = NULL;
		subList.last = subList.first;
		temp =current;
		current = current->link;
		//trailCurrent=subList.first;
		deleteNode(temp->info);

    }


		while (current != NULL)
        {
            nodeType<Type> *newNode; //pointer to create the new node
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			subList.last->link = newNode;
			subList.last = newNode;
			temp = current;
			current = current->link;
			deleteNode(temp->info);
		}

}

template <class Type>
void unorderedLinkedList<Type>::insertCircle(Type & newItem)
{
    nodeType<Type> *adjPtr;
    nodeType<Type> *newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
   if(this->first==NULL)//first node in list
   {
       cout<<"our first node";
       this->first=newNode;
       this->last=newNode;
       this->first->link=newNode;
       this->last->link=newNode;

   }
   else //list is not empty
   {
       cout<<"entering another node!";
       newNode->link = this->first; //insert newNode before first
       this->first = newNode; //make first point to the actual first node
        cout<<endl<<"first is now "<<this->first->info;
        adjPtr = newNode;//let adjPtr point to the firs tnode as requested
        this->count++; //increment count
        this->last->link=newNode;
   }
//   print();


    cout<<endl<<"Let's check if the last node points to the first."<<endl;

   cout<<"our first node is: "<<this->first->info<<". ";
   cout<<" Our our last node is: "<<this->last->info;
   cout<<". Last points to "<<this->last->link->info<<endl<<endl;

}

template <class Type>
void unorderedLinkedList<Type>::linkedInsertionSort()
{
    nodeType<Type> *lastInOrder;
    nodeType<Type> *firstOutOfOrder;
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    lastInOrder = this->first;
    if (this->first == NULL)
        cerr << "Cannot sort an empty list." << endl;
    else if (this->first->link == NULL)
        cout << "The list is of length 1. "<< "It is already in order." << endl;
    else
    while (lastInOrder->link != NULL)
    {
        firstOutOfOrder = lastInOrder->link;
        if (firstOutOfOrder->info < this->first->info)
        {
            lastInOrder->link = firstOutOfOrder->link;
            firstOutOfOrder->link = this->first;
            this->first = firstOutOfOrder;
        }
        else
        {
            trailCurrent = this->first;
            current = this->first->link;
            while (current->info < firstOutOfOrder->info)
            {
                trailCurrent = current;
                current = current->link;
            }
            if (current != firstOutOfOrder)
            {
                lastInOrder->link = firstOutOfOrder->link;
                firstOutOfOrder->link = current;
                trailCurrent->link = firstOutOfOrder;
            }
            else
                lastInOrder = lastInOrder->link;
        }
        cout<<endl;
        this->print();
        cout<<endl;
    } //end while
} //end linkedInsertionSort

template <class Type>
void unorderedLinkedList<Type>::shareList(unorderedLinkedList<Type> & listA, unorderedLinkedList<Type> & listB)
{
    //create the node for traversing the original list
    nodeType<Type> *current;
    current = new nodeType<Type>;
    //set it to the front of the original list
    current = this->first;

    //create the nodes for traversing list a and b
    nodeType<Type> *currentA;
    nodeType<Type> *currentB;

    //set the front of each list (a and b)
    listA.first = current;
    listA.last=current;
    currentA=listA.last;

    current = current->link;

    //currentB = current;
    listB.first=current;
    listB.last=current;
    currentB=listB.last;

    current=current->link;

    //set the rest of the nodes in the list
    while(current!=NULL)
    {
        listA.insertLast(current->info);
        current=current->link;

        listB.insertLast(current->info);
        current=current->link;
        /*currentA->link=current;
        currentA=currentA->link;
        listA.back()=currentA;
        cout<<endl<<"List A: "<<listA.back();

        current=current->link;

        currentB->link=current;
        currentB=currentB->link;
        listB.back()=currentB;
        cout<<endl<<"List B: "<<listB.back();

        current=current->link;
*/



    }
}

template <class Type>
int unorderedLinkedList<Type>::occurance(Type & occur)
{
    nodeType<Type> *current;
    current=this->first;
    int num = 0;

    while (current!=NULL)
    {
        cout<<endl<<"searching.. current value is "<<current->info;
        if (current->info == occur)
            num++;
        current=current->link;
    }
    return num;
}

template <class Type>
void unorderedLinkedList<Type>::testingPastpapers()
{
        nodeType<Type> *p;
        nodeType<Type> *q;
        p = this->first;
        q= this->first->link->link;

        while (q!=NULL)
        {
            p=p->link;
            cout<<endl<<q->info<<", ";
            q=p->link->link;

        }
}


template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
	nodeType<Type> *current;
	bool found = false;

	current = this->first;

	while (current != NULL && !found) {
		if (current->info == searchItem)
			found = true;
		else
			current = current->link;
	}

	return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = this->first;
	this->first = newNode;
	this->count++;

	if (this->last == NULL)
		this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;

	if (this->first == NULL) {
		this->first = newNode;
	} else {
		this->last->link = newNode;
	}

	this->last = newNode;
	this->count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent;
	bool found;

	if (this->first == NULL)
		cout << "Cannot delete from an empty list."
			 << endl;
	else {
		if (this->first->info == deleteItem) {
			current = this->first;
			this->first = this->first->link;
			this->count--;

			if (this->first == NULL)
				this->last == NULL;

			delete current;
		} else {
			found = false;
			trailCurrent = this->first;
			current = this->first->link;

			while (current != NULL && !found) {
				if (current->info != deleteItem) {
					trailCurrent = current;
					current = current->link;
				} else
					found = true;
			}

			if (found) {
				trailCurrent->link = current->link;
				this->count--;

				if (this->last == current)
					this->last = trailCurrent;
				delete current;
			} else {
				cout << "The item to be deleted is not in teh list"
					 << endl;
			}
		}
	}
}

template <class Type>
void unorderedLinkedList<Type>::shareList(const unorderedLinkedList<Type> &orig, unorderedLinkedList<Type> &listA,
		unorderedLinkedList<Type> &listB)
{
	unorderedLinkedList<Type> temp;
	int index = 0;
	Type tempItem;
	temp = orig;

	while (!temp.isEmptyList()) {
		tempItem = temp.front();
		if (index % 2 == 0) {
			listA.insertLast(tempItem);
		} else {
			listB.insertLast(tempItem);
		}
		temp.deleteNode(tempItem);
		++index;
	}
	cout << "listA: ";
	listA.print();
	cout << "listB: ";
	listB.print();
}

#endif

