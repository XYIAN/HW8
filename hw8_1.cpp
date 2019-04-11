/* TITLE hw8_1.cpp
 * ABSTRACT: this program will take an input txt file from the user 
 * if the file contains size and intergers the program will then 
 * be able to sort the intergers in either ascending or descending order 
 * which BOTH MUST be followed with a display function to display properly
 * Author: Kyle Dilbeck 
 * ID: 1996
 * Date: 4/9/19
 */

#include <iostream>
#include <fstream>

using namespace std;


// Function prototypes
int ARRAY_SIZE = 10; 
void readNumbers(ifstream &inFile, int numbers[], int size);
void insertion_sort (int values[], int size);
void quick_sort(int x[], int first, int last);
int partition(int list[], int low, int high);
void swap(int &x, int &y);
void display(int x, int fill[]);


int main()
{
    // File stream object
    ifstream inFile;
   
    // Array to hold the numbers
    int numbers[ARRAY_SIZE];

    // Open the input file.
    string input; 
    cout << "Please enter file name with .txt : "; 
    cin >> input; 
    inFile.open(input);
    cout << endl << "    Kyle's hw8_1--> "; 
    

    // Test for errors.
    if (!inFile)
    {
        cout << "Error opening the file.\n";
        return 0;
    }
    int nums;
    inFile >> nums;
    // Read the numbers into the array.
    readNumbers(inFile, numbers, nums);
    /*
    cout << "===== First 10 Numbers from Input File =====\n";
    for (int i=0; i < nums; i++)
        cout << numbers[i] << " ";
    cout << endl << endl;
    */
    
    // Close the file.
    inFile.close();
    /*
    cout << "DEBUG print " << input << " ."<< endl;
    for( int i= 0 ; i < nums ; i++ )
    {
        cout << " " << numbers[i]; 
    }
    */
    
    //cout << "Start the sorting..." << endl;
    
    //cout << endl; 
    
    quick_sort(numbers, 0, nums-1);
    
    /*
    cout << "\n===== Sorted Numbers I =====\n";
    for (int i=0; i < nums; i++)
        cout << numbers[i] << " ";
    cout << endl;
    
    
    cout << " display sorted with '-' " << endl; 
    */
    display(nums, numbers); 
   
    return 0;
}

// ********************************************************
// The readNumbers function reads numbers from inFile and *
// stores them in the numbers array.                      *
// ********************************************************
void readNumbers(ifstream &inFile, int numbers[], int size)
{
    
   for (int i = 0; i < size; i++)
      inFile >> numbers[i];
}


/*
// Sort an array of integer values in ascending order.
void insertion_sort (int values[], int size) 
{
    // Develop the insertion sort.
    //

    for(int i = 0; i < size - 1; i++)
    {
        //set temp value
        int temp ;
        temp = values[i+1]; 
        
        
        //check sorted 
        for(int j = i ; j >=  0 ; j--)
        {
            //swaping 
            if(values[j] > temp)
            {
                swap(values[j], values[j+1]);
            }
            else
            {
                values[j+1] = temp; 
                break; 
            }
                
               
            
        }
    }
}
*/

void quick_sort(int list[], int left, int right)
{
    if (left < right)
    {
        int s = partition(list, left, right);
        quick_sort(list, left, s - 1);
        quick_sort(list, s + 1, right);
    }
}


int partition(int list[], int left, int right)
{
    int pivot = list[left];
    int i = left;
    int j = right + 1;
  
    while (i < j)
    {
        do
        {
            i++;
        } while (list[i] < pivot);

        do
        {
            j--;
        } while (list[j] > pivot);

        swap(list[i], list[j]);
    }
    // undo the last swap which happened at i >= j
    swap(list[i], list[j]);
    
    // swap the pivot and list[j] to finish the partitioning.
    swap(list[left], list[j]);
    
    return j;
}


void swap(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}



void display(int x, int fill[])
{
    int i = 0; 
    
    while(i < x)
    {
        int j = i+1; 
        int prev = fill[i]; 
        while(j < x && fill[j] == prev+1)
        {
            prev = fill[j]; 
            //cout << "-";  
            j++;
            
        }
        if((j-1-i) > 0)
        {
            cout << fill[i] << "-" << fill[j-1] << " "; 
            i = j ; 
            
        }
        else 
        {
            cout << fill[i] << " ";
            i++;
        }
        
    }
  
    cout << endl << endl ; 
    
}
