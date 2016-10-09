//
//  test.cpp
//  sortingpointer
//
//  Created by Ida Bagus Kerthyayana Manuaba on 9/10/16.
//  Copyright © 2016 introprogram. All rights reserved.
//
/*
 The application should accept minimum a single argument, a string. The application should then output an alphabetized list of all the letters used in the string ignoring duplicate letters. All letters should be output as capitals. The application should then prompt for another string and do the same thing with the newly entered string. It should continue to prompt until an empty string is entered, at which point it should exit.

*/

#include<iostream>
using namespace std;

void assignedAddress(char *[], char []);
void sortingData(char *[], char []);
void showResultWONumber(char *[], char []);
void showResultWithNumber(char *[], char []);
void displayInput(char *[], char []);


int main()
{
    const int SIZE = 100;
    char inputarray[SIZE];
    char *inputptr[SIZE];
    
    //do looping to prompt for another string and do the same thing with the newly entered string
    do
    {
        cout << "Please input the word(s) - max 100 characters: ";
        //accept minimum a single argument, a string
        cin.getline(inputarray,SIZE);
        
        //assigned array address to pointer
        assignedAddress(inputptr,inputarray);
        
        //check if the input is not empty
        if (strcmp(inputarray, "") != 0)
        {
            
            displayInput(inputptr,inputarray);
            
            //output an alphabetized list of all the letters used in the string ignoring duplicate letters
            //sorting the input data (comparing the characters)
            sortingData(inputptr,inputarray);
            
            //shows sorting result without number, ignoring the duplicate
            showResultWONumber(inputptr,inputarray);
            
            //shows sorting result without number, ignoring the duplicate
            showResultWithNumber(inputptr,inputarray);
            
        }
    } while (strcmp(inputarray, "") != 0);
    
    exit(0);
    
    return 0;
}

void assignedAddress(char *ptr[], char arr[])
{
    for (int count = 0; count < strlen(arr); count++ )
    {
        ptr[count]=&arr[count];
    }
}

void sortingData (char *ptr[], char arr[])
{
    int startScan, minIndex; char *minElem;
    for (startScan = 0; startScan < strlen(arr)-1; startScan++)
    {
        minIndex = startScan;
        minElem = ptr[startScan];
        for (int index = startScan+1; index < strlen(arr); index++ )
        {
            if (*(ptr[index]) < *minElem)
            {
                minElem = ptr[index];
                minIndex = index;
            }
        }
        ptr[minIndex] = ptr[startScan];
        ptr[startScan] = minElem;
    }
}

void showResultWONumber(char *ptr[], char arr[])
{
    cout << "in order you have : ";
    for (int count = 0; count < strlen(arr); count++)
    {
        if (isspace(*(ptr[count])) == 0)
        {
            //All letters should be output as capitals
            cout << char(toupper(*(ptr[count]))) << " ";
            
        }
    }
    cout << endl;
}

void showResultWithNumber(char *ptr[], char arr[])
{
    char temp = '\0';
    int tot = 1;
    
    cout << "So you have (with number) : ";
    for (int count = 0; count < strlen(arr); count++)
    {
        
        if (isspace(*(ptr[count])) == 0)
        {
            if ((*(ptr[count]) != temp) && (temp == '\0'))
            {
                //All letters should be output as capitals
                cout << char(toupper(*(ptr[count])));
                temp = *(ptr[count]);
                tot = 1;
            }
            else if (*(ptr[count]) != temp)
            {
                cout << "(" << tot << ") ";
                //All letters should be output as capitals
                cout << char(toupper(*(ptr[count])));
                temp = *(ptr[count]);
                tot = 1;
            }
            else if (*(ptr[count]) == temp)
            {
                tot++;
                temp = *(ptr[count]);
            }
            
            if (count == strlen(arr)-1)
            {
                cout << "(" << tot << ") ";
            }
        }
    }
    cout << endl;
}

void displayInput(char *ptr[], char arr[])
{
    cout << "Your input is : ";
    for (int count = 0; count < strlen(arr); count++)
        cout << *ptr[count] << " ";
    cout << "(" << strlen(arr) << " character(s)) including space";
    cout << endl;
}
