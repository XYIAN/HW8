/* TITLE Queue.h
 * ABSTRACT: 
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/9/19
 */
 
#include <iostream>
using namespace std;

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
