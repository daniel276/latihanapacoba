// This program shows modification program to bring cout from void function to main function
// modified by Bagus

#include <iostream>
#include <cstdlib>
using namespace std;

// Function prototypes
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int, string &);

int main2()
{
    const int NUM_DONATIONS = 4;//15;
    string msgstr = "";
    // An array containing the donation amounts.
    int donations[NUM_DONATIONS] = {5, 100, 5, 25};//, 10, 19, 5, 25, 5, 5, 100, 20, 10, 15, 10};

    // An array of pointers to int.
    int *arrPtr[NUM_DONATIONS] = { nullptr, nullptr, nullptr, nullptr};//, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,nullptr, nullptr, nullptr, nullptr, nullptr };

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];
    //cout << donations << " " << donations[1] << "\n";
    //cout << arrPtr << " " << *arrPtr << " " << arrPtr[1] << " " << *arrPtr[1] << "\n";
    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, NUM_DONATIONS);
    //cout << arrPtr << " " << *arrPtr << " " << arrPtr[1] << " " << *arrPtr[1] << "\n";
    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS, msgstr);
    cout << msgstr << endl;
    
    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    return 0;
}

void arrSelectSort(int *arr[], int size)
{
    int startScan, minIndex; int *minElem;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for(int index = startScan + 1; index < size; index++)
            if (*(arr[index]) < *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}


void showArray(const int arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

void showArrPtr(int *arr[], int size, string &msgstr)
{
    int msg;
    //string msgstr = "";
    for (int count = 0; count < size; count++)
    {
        msg = *(arr[count]);
        msgstr += to_string(msg) + " ";
        
        //cout << *(arr[count]) << " ";
    }
    
}
