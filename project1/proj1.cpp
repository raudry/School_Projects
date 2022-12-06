/*
	Beverly Raudry
	CSCI 3110-001
	Project #1
	Due: 09/06/19
	Description: This program reads in values, creates an array, then expands it. 
*/

#include <iostream>
#include <fstream>
using namespace std;

//Function Prototypes
int* allocateArray(int *arrPtr, int *size, double);
double calcAvg(int* arrPtr, int);

int main()
{
	//Variable Definitions
	int count = 0;
	int num, size;
	double perVal, avg;
	ifstream myin;
	ofstream myout;

	//Pointers
	int *arrPtr;
	arrPtr = NULL;

	//Read in file.
	myin.open("nums.txt");

	//Write to file
	myout.open("out.txt");

	//Read in first two lines
	myin >> size;
	myin >> perVal;

	//Validate input
	if ((size < 100) || (size > 350) || !(size % 50 == 0))
	{
		cout << "Error" << endl;
		return 0;
	}
	
	else
	{
		//Call the function to dynamically allocate
		//an array with the number of elements specified
		arrPtr = allocateArray(arrPtr, &size, perVal);

		//-Print to file and screen:
		cout << size << endl;
		myout << size << endl;

		//Read the remaining integers from input 
		while (myin >> num)
		{
			//myin >> num;
			arrPtr[count] = num;

            //When you reach the last number then write out to file and screen
			if (count + 1 == size)
			{
		        //-Call calcAvg
	            avg = calcAvg(arrPtr, size);

				cout << size << " " << avg << endl;
				myout << size << " " << avg << endl;
		        
			    //Call allocateArray to expand
			    arrPtr = allocateArray(arrPtr, &size, perVal);
			}
			count++;
		}
        
	    avg = calcAvg(arrPtr, count);
        cout << size << " " << count << " " << avg << endl;
        myout << size << " " << count << " " << avg << endl;
	}	
	
	//Close files
	myin.close();
	myout.close();

    //Deallocate Array
    delete[] arrPtr;

	return 0;
}

//Function dynamically allocates an array
//When necessary, copies elements from old array to the new
int* allocateArray(int *arrPtr, int *numPtr, double percent)
{	
	if (arrPtr == NULL)
	{
		arrPtr = new int[*numPtr];
	}

	else
	{
        //Local variable with new incremented size
		int newSize =((int) (*numPtr * percent));

        //Allocated space for new array with new size
		int* newArr = new int [*numPtr + newSize];
		
		//Copy values to new array
		for (int x = 0; x < *numPtr; x++)
		{
			newArr[x] = arrPtr[x];
		}

		//Deallocate array
		delete[] arrPtr;
        
        //Update size
        *numPtr = *numPtr + newSize;

	    return newArr;
	}
}

//Function accepts dynamic array and the number of values that have been read into it
//It returns the calculated average (as a double)
double calcAvg(int* arrPtr, int size)
{
	float sum = 0;
	
	for (int x = 0; x < size; x++)
	{
		sum += arrPtr[x];
	}
	return sum / size;
}
