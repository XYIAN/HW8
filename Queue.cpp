/* TITLE Queue.cpp
 * ABSTRACT: 
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/9/19
 */
 
 // --------------------------------------------update 2.2------------------------------------------
#include "Queue.h"
#include <iostream>
using namespace std;

/*
const int QUEUE_CAPACITY = 10;
typedef int QueueElement;


class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
    void ascending(); 
    void descending(); 
    void bubble_sort(int values[], int size);
    void swap(int &x, int &y); 
    
    

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration
*/

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // queue isn't full
    { 
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
    }
}


//--- Definition of display()
void Queue::display() const
{
    //cout << "Array regular display    : ";
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of front()
QueueElement Queue::front() const
{
    if ( !empty() ) 
    {
        return (myArray[myFront]);
    }
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if ( !empty() )
    {
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}
void Queue::swap(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}



//999999999999999999999999999999999999999999999999999

void Queue::ascending()
{
    cout << "Array in ascending order : " ; 
    for(int i = myFront; i != (myBack - 1)%QUEUE_CAPACITY; i = (i + 1)%QUEUE_CAPACITY )
    {
         
        int minIndex = i;
        
        for(int j = (i + 1)%QUEUE_CAPACITY; j != (myBack)%QUEUE_CAPACITY ; j = (j + 1)%QUEUE_CAPACITY)
        {
            
            if(myArray[j] < myArray[minIndex])
            
                minIndex = j;
        }
        
        swap(myArray[minIndex], myArray[i]);
    }
    
}

void Queue::descending()
{
    cout << "Array in descending order: " ; 
    for(int i = myFront; i != (myBack -1)%QUEUE_CAPACITY; i = (i + 1)%QUEUE_CAPACITY )
    {
         
        int minIndex = i;
        
        for(int j = (i + 1)%QUEUE_CAPACITY; j != (myBack )%QUEUE_CAPACITY ; j = (j + 1)%QUEUE_CAPACITY)
        {
            
            if(myArray[j] > myArray[minIndex])
            
                minIndex = j;
        }
        
        swap(myArray[minIndex], myArray[i]);
    }
    
}

/*
int main()
{
    Queue q1, q2;

    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(50);
    cout << endl<< "Starting array(1)--------: ";
    q2.display(); 
    //cout << endl; 
    
    q2.ascending();
    q2.display(); 
    
    //q2.dequeue();
    //cout <<"Dequeued(x1): ";
    //q2.display();
    
    q2.descending();
    q2.display();
    
    
    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    q1.enqueue(400);
    q1.enqueue(500);
    q1.enqueue(600);
    //cout << endl<<"Starting array(2):";
    //q1.display(); 
    
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    //cout <<endl<< "Dequeue(x3): ";
    //q1.display(); 
    q1.enqueue(700);
    q1.enqueue(800);
    q1.enqueue(900);
    q1.enqueue(500);
    q1.enqueue(700);
    cout << endl<<"Starting array(2)--------: ";
    q1.display(); 
    
    //cout<< endl; 
    q1.descending();
    q1.display(); 
    //cout << endl;
    
    q1.ascending();
    q1.display(); 
    cout << endl; 

  


    return 0;
}
*/

