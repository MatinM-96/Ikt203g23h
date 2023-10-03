#include <iostream>
using namespace std;



template <typename T>

//sort the array based on the selection sort, find the minmum elemnet, and place it into the sorted array 
T* SelectionSort(T array[], T sizeOFarray)
{
    //staring with the first element in the array
    int i  = 0;
    //placeholder for the second element int the array
    while (i<sizeOFarray-1) //this loops through each element
    {
        int minIndex  = i; //consier the first element as minimum value 
        int j = i+1;    //starting from the second element 
        //this loop search for the smallest element
        while (j<sizeOFarray)
        {
            if (array[i]>array[j]) //if the first element in the array is greater than the second elemenet in the array
            {
                minIndex  = j;  // the minimum variable become to the second element in the array
            }
            j++;
        }
        T temp = array[i]; //store the current element into the temp variable
         
         if(minIndex != i)
         {
            array[i] = array[minIndex]; //overwrite the value of the index i buy the value of the index min
            array[minIndex] = temp; //overwrite the value of the index mini with te temp
         }    
        i++;
    }

    // The worst-case time complexity of insertion sort is O(n^2).
    // The best-case time complexity is O(n), if the array is already sorted. 


    return array;
};



template <typename I>
I* InsertionSort(I array[], I sizeOfTheArray) //sorting the array by the insertion method, assuming the first elemenet is sorted 
{
    for (int current = 1; current<sizeOfTheArray; current++) //we assum that the first elenet is sorted, and we start with the second element.
    { 
        I temp = array[current]; //The current elemenet, this variable will holde the value of the current index
       int previous  = current - 1 ; //get the previous index 

    // Check if the the previous in grater or equl to zero and if the previous elemnet is 
    // greater than the current elemnet 
       while(previous>= 0 && array[previous]> temp) 
       {
            array[previous+1] = array[previous]; //ransfer the value from the previous index to the next index
            previous--; //Decrement the privious to get the element before the previous
       }
        array[previous+1] = temp; //update the current index with the value key a

       // The worst-case time complexity of insertion sort is O(n^2).
        // The best-case time complexity is O(n), if the array is already sorted.


    }
    return array;
};


template <typename B> 
// Sort an array using the Bubble Sort algorithm.
B* BubbleSortAlgorithm(B array[], int size)
{
    for(int i = 0; i < size-1; i++)    
    {
        bool flag = false; // Use bool for a more descriptive type 

        // inner loop goes up to size-1-i
        for (int j = 0; j < size-1-i; j++) 
        {
            // Compare current element with the next element
            if(array[j] > array[j+1]) 
            {
                // Swapping the elements
                B temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; 
                flag = true; 
            }
        }

        // If no elements were swapped by the inner loop, then the array is already sorted.
        // The worst-case time complexity of Bubble Sort is O(n^2). The best-case time complexity is O(n) when the array is already sorted.
        if(!flag)
            break; 
    }

    return array; 
}


template<typename M>

M* mergeSortAlgorithm(M array[], int size)
{
    int lenght = size;
    if(lenght <=1)
        return 0; 
    
    int middel = lenght/2; 

    M lowerBound[middel]; 
    M upperBownd[size-middel]; 
    int j = 0; 


    //this loop goiing throught each element, and it wil divide each array into the sub arrays.
    for(int i = 0; i < size; i++)
    {
        if(i<middel)
        {
            lowerBound[i] = array[i]; //assigning value to the lowerbownd array  
        }
        else
        {
            upperBownd[j] = array[i]; //assning value to the raight side of the array   
            j++; 
    
        }
            
    }
    
    cout<<"the left side of the array: ";
    cout<<endl;
    cout<<endl;

    for(int i = 0; i<middel; i++)
    {
        cout<<lowerBound[i]<<endl;
         
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"the right side of the array: " ;
    cout<<endl; 
    cout<<endl;

    
    for(int i = 0; i<middel; i++)
    {
       
        cout<<upperBownd[i]<<endl; 
    }


    mergeSortAlgorithm(lowerBound, middel);            //we call the merge sort algorithm recursive, to devide the reminder  
    mergeSortAlgorithm(upperBownd, middel);

    return array;
}






void Display(int *array, int size)   //display the elemenet within of the array 
{
    cout<<"sorted list: "<<endl;
    for (int i = 0; i <size; i++)
    {
        cout<<array[i]<<endl;

    }
}

int main()
{
    int myNumbers[5] = {15, 2, 30, 0, 25};
    int *array;

    //array= SelectionSort(myNumbers, 5);
    array = mergeSortAlgorithm(myNumbers, 5);

    Display(array, 5);



    return 0;
}




