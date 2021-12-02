#include <iostream>
#include "linkedList.h"
//#include "linkedListIterator.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
#include "linkedList.h"
#include <string>
#include <stack>
#include <list>
using namespace std;

template <class Type>
void deleteSmallest(linkedListType<Type> &myList)
{
    nodeType<Type> *current;
    current=myList.first->link;
    nodeType<Type> *smallest = myList.first;

    while (current!=NULL)
    {
        cout<<endl<<"checking.. current value is "<<current->info;
        if (current->info < smallest->info)
            smallest = current;
        current=current->link;
    }

    cout<<endl<<"The smallest value found was "<<smallest->info;
    myList.deleteNode(smallest->info);
    cout<<endl<<"Deleted the smallest. List is now: "<<endl;
    myList.print();

}



template <class Type>
int occuranceCounter(unorderedLinkedList<Type> &list, Type &occur)
{
    nodeType<Type> *current;
    current=list.first;
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

//a function to receive a linked list, and reverse it
template <class Type>
void reverseList(unorderedLinkedList<Type> &myList)
{
    //declare a variable to traverse the linked list
    Type current;
    //declare a stack to hold the elements of our linked list
    stack<Type> myStack;
    //traverse through the linked list, deleting each node
    //after we have pushed its value onto the stack
    while(!myList.isEmptyList())
    {
        //we will save the first node's value into current
        current = myList.front();
        //push the value onto the stack
        myStack.push(current);
        //delete the node from the linked list
        myList.deleteNode(myList.front());
    }//end while

    //after copying the linked list to the stack,
    //we must reverse it and copy it back onto our linked list
    //store each value of the stack into the linked list, deleting as we go
    while(!myStack.empty())
    {
        //store the top value of our stack
      current = myStack.top();
      //insert that value at the end of our linked list
      myList.insertLast(current);
      //delete the value from the stack
      myStack.pop();
    }//end while

}//end reverseList

//a function to test if a word is in the language of a^n b^a*2
template<class Type>
bool moreBs(unorderedLinkedList<Type> &myList)
{
    //a bool to hold true or false
    bool isInLanguage;
    //two lists, one to hold the a's and one to hold the b's
    unorderedLinkedList<char> listA;
    unorderedLinkedList<char> listB;

//a nodeType to traverse the main list
     nodeType<Type> *current;
     //this nodeType will start at the beginnning of the main list
     current=myList.first;

     //first check if the first letter is a
     if(current->info=='a')
     {
         //if it s, then add it to listA
        nodeType<Type> *newNode; //pointer to create the new node
        newNode = new nodeType<Type>; //create the new node
        newNode->info = 'a'; //store the new item in the node
         listA.first=newNode;
         listA.last=newNode;
         //go on to the next character
         current=current->link;
     }
     //if the first letter is  not a, then the list has already failed the test
     else if(current->info!='a')
     {
         return false;
     }

    //next we add as amany a's as are in the main list to listA
    while(current->info=='a'&&current!=NULL)
    {
        nodeType<Type> *newNode; //pointer to create the new node
        newNode = new nodeType<Type>; //create the new node
        newNode->info = 'a'; //store the new item in the node
        listA.insertFirst('a');
        listA.first=newNode;
        current=current->link;
    }

    //when we have no more a's, the next should be our first b and should be added to our listB
    if(current->info=='b')
     {
        nodeType<Type> *newNode; //pointer to create the new node
        newNode = new nodeType<Type>; //create the new node
        newNode->info = 'b'; //store the new item in the node
         listB.first=newNode;
         listB.last=newNode;
        //go onto the next letter
         current=current->link;
     }
     //if the next is not b then the list failed the test
     else if(current->info!='b')
     {
         return false;
     }

     //for every b on hte main list, we need a b on the listB
    while(current->info=='b'&&current!=NULL)
    {
        nodeType<Type> *newNode; //pointer to create the new node
        newNode = new nodeType<Type>; //create the new node
        newNode->info = 'b'; //store the new item in the node
        listB.insertFirst('b');
        listB.first=newNode;
        current=current->link;
    }

    //next we create nodeTypes to traverse our new lists
    nodeType<Type> *currentA;
    currentA=listA.first;

    nodeType<Type> *currentB;
    currentB=listB.first;

    //we will go through the lists. for every one a, we need 2 b's
    while(currentA!=NULL&&currentB!=NULL)
    {
        currentA->link;
        currentB->link->link;
        //if one list ends before the other, the list failed the test
        if(currentA==NULL&&currentB!=NULL)
        {
            return false;
        }
        else if (currentB==NULL&&currentA!=NULL)
        {
            return false;
        }
    }
//if we made it this far, our list passed the test and is in the language
    return true;
}

int main()
{

    unorderedLinkedList<char> list1;        //Line 5
    char num;                                    //Line 6

    cout << "Line 7: Enter letters ending "
         << "with z." << endl;               //Line 7
    cin >> num;                                 //Line 8

    while (num != 'z')                         //Line 9
    {                                           //Line 10
        list1.insertLast(num);                  //Line 11
        cin >> num;                             //Line 12
    }                                           //Line 13

    cout << endl;

    bool inLang = moreBs(list1);
    if(inLang)
        cout<<endl<<"The string is in.";
    else
        cout<<endl<<"the string is not in.";

    cout<<endl<<endl<<"Let's check the minimum value in the list.";
    int minimum = list1.min();
    cout<<endl<<"minimum is "<<minimum<<endl;

    cout<<endl<<"Let's delete the smallest value.";
    deleteSmallest(list1);

      unorderedLinkedList<int> mergetest;        //Line 5
    int entry;                                    //Line 6

    cout << "We are going to check some things. New list. Enter numbers ending "
         << "with -999." << endl;               //Line 7
    cin >> entry;                                 //Line 8

    while (entry != -999)                         //Line 9
    {                                           //Line 10
        mergetest.insertLast(entry);                  //Line 11
        cin >> entry;                             //Line 12
    }                                           //Line 13

    cout << endl;

    cout<<endl<<"ok lets see here..";
    nodeType<int>*middle;
    nodeType<int>*current;

    middle = mergetest.first;
    current=mergetest.first->link;

    while(current!=NULL)
    {
        middle=middle->link;
        current=current->link;
        if(current!=NULL)
            current=current->link;
    }
    cout<<endl<<"ok  the middle is "<<middle->info<<endl;
/*
    cout<<"Ok lets reverse it.";
    reverseList(list1)  ;                            //Line 14;

    cout << "Line 15: list1: ";                 //Line 15
    list1.print();                              //Line 16*/
    cout << endl;

    int occurance;
    cout<<"What should we search for? ";
    cin>>  occurance;
/*    int numberOfOccurance =  occuranceCounter(list1, occurance) ;                          //Line 17;
    cout<<endl<<"We have "<<numberOfOccurance<<" occurances of "<<occurance<<".";

    /*
    int minimum = list1.min();
    cout<<endl<<"the minimum value is "<<minimum<<endl<<endl;

    /*list2 = list1; 								//Line 18

    cout << "Line 19: list2: ";                 //Line 19
    list2.print();                              //Line 20
    cout << endl;                               //Line 21

    cout << "Line 22: Enter the number to be "
         << "deleted: ";                        //Line 22
    cin >> num;                                 //Line 23
    cout << endl;                               //Line 24

    list2.deleteNode(num);                      //Line 25

    cout << "Line 26: After deleting "
         << num << ", list2: " << endl;         //Line 26
    list2.print();                              //Line 27
    cout << endl;                               //Line 28

    cout << "Testing iterator for list1: "		//Line 29
		 << endl;                          		//Line 30
	for (linkedListIterator<int> i = list1.begin(); i != list1.end(); ++i) { //Line 31
		cout << *i << " ";						//Line 32
	}											//Line 33

	cout << endl;								//Line 34*/


    unorderedLinkedList<int> sharedList;        //Line 5
    int number;                                    //Line 6

    cout << endl<<endl<<"We are going to share a list. \nEnter numbers ending "
         << "with -999." << endl;               //Line 7
    cin >> number;                                 //Line 8

    while (number != -999)                         //Line 9
    {                                           //Line 10
        sharedList.insertLast(number);                  //Line 11
        cin >> number;                             //Line 12
    }                                           //Line 13

    cout << endl;
	unorderedLinkedList<int> firstList, secondList;
	sharedList.shareList(sharedList, firstList, secondList);

	unorderedLinkedList<int> subList;
	unorderedLinkedList<int>myList;
	int myListEntry;                                    //Line 6

    cout << endl<<endl<<"We are going to share a list from a position. \nEnter numbers ending "
         << "with -999." << endl;               //Line 7
    cin >> myListEntry;                                 //Line 8

    while (myListEntry != -999)                         //Line 9
    {                                           //Line 10
        myList.insertLast(myListEntry);                  //Line 11
        cin >> myListEntry;                             //Line 12
    }

    myList.divideAt(subList, 4);
    cout<<endl<<"let's check out two lists: myList, and subList.";
    cout<<endl<<"myList: ";
    myList.print();
    cout<<endl<<"subList: ";
    subList.print();
	//unorderedLinkedList<int> circleList;

    /*int number;

    cout << "Line 7: Enter numbers ending "
         << "with -999." << endl;               //Line 7
    cin >> number;                                 //Line 8

    while (number != -999)                         //Line 9
    {                                           //Line 10
        circleList.insertCircle(number);                  //Line 11
        cin >> number;                             //Line 12
    }                                 //Line 8

    cout<<"end";
*/
/*
int num;
unorderedLinkedList<int> unorderedList;
orderedLinkedList<int> orderedList;
    cout<<"Line 7: Enter numbers ending with -999."<<endl;
    cin>>num;

    while(num!= -999)
    {
       unorderedList.insertLast(num);

        orderedList.insertCheck(num);
        //linkedList.insertFirst(num)
        cin>>num;
    }

    cout <<endl;
   // unorderedList.linkedInsertionSort();
    cout<<endl<<"unordered list: ";
    unorderedList.print();
    cout<<endl<<"ordered list: ";
    orderedList.print();

    //cout<<"Unordered List: ";
    //unorderedList.print();
    //cout<<endl<<endl<<"Okay, lets share the list.";
    //unorderedList.shareList(listA, listB);

    //cout<<endl<<"list a: ";
    //listA.print();

    //cout<<endl<<"List b: ";
    //listB.print();
   //cout<<endl<<"Ordered List :";
   //orderedList.print();
    /*int searching;
    cout<<endl<<"What should we search for?"<<endl;
    cin>>searching;
    //cin>>searching;
    int occurance = unorderedList.occurance(searching);
    cout<<endl<<"The value "<<searching<<" occurred "<<occurance<<" times.";*/


    /*cout<<"We will delete the smallest."<<endl;
    unorderedList.deleteSmallest();
    cout<<"Here is the list now: "<<endl;
    unorderedList.print();
    cout<<"We are finished.";*/
   // cout<<endl<<"We will now do a test."<<endl;

    //unorderedList.testingPastpapers();

    unorderedLinkedList<int> checking;
    int listValue;
    cout<<endl<<"Enter your list values, ending with -999."<<endl;
    cin>>listValue;
    int size = 0;
    while(listValue!= -999)
    {
        checking.insertLast(listValue);
        size++;
        cin>>listValue;
    }
    nodeType<int> p;
    nodeType<int> q;

    cout<<checking.first->link->link->info;
    //cout<<p->info;
    return 0;
}
