#include <iostream>
using namespace std;
#include "Queue.h"

int main()
{
    Queue q1, q2 , q3;

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
    
    
   cout << endl<<"Starting array(3)--------: ";
   for(int i = 0 ; i < 9 ; i++)
   {
       q3.enqueue(500 + i);
   }
   q3.display();
   
   q3.descending(); 
   q3.display(); 
   
   
   
    
    

  


    return 0;
}

