/* Victoria Todd, Jayson Morgado, Shaun Shahan
 * TA: Lauren Olson
 *  09/19/19
 * CISC220lab3.cpp
 */

#include "hanningWindow.hpp";
#include <iostream>;

using namespace std;


	hanningWindow::hanningWindow(int w, int x[],int s, int y[]){
		windowSize = w;
		arr = x;
		size = s;
		filteredArr = y;



		//Constructor

	}
//Problem 1.
// returns the weighted average of the window of array

int hanningWindow::hanningWindow1(int arr[],int len, int window){

		int weight = 0;//this will be used to divide the summ
		int cap = window/2 +1;
		for(int i = 1; i <= cap; i++){
			if(i == cap){
				weight = weight + i;
				break;
			}//for
			weight = weight + 2 * i;//this for loops finds what to divide sum by
		}//for
		int sum = 0;
		int multiplier = 1;
		int index = 0;
		//adds the values in the window
		while(multiplier <= cap){
			if(multiplier == cap){
				sum = multiplier * arr[index] + sum;
			}
			else{//if
				sum =  (multiplier * arr[0 + index] + multiplier * arr[window - (1 +index)]) + sum;
			}//else
			multiplier++;
			index++;
		}//while
		int avg = sum / weight;

		return avg;
}

//Problem 2.
// calls method from above and create a new filtered array

void hanningWindow::hanningWindowNew(){
	for(int i = 0; i < size; i++)
	{
		cout<<arr[0]<<endl;
		if(i < windowSize/2 || size - i <= windowSize/2)//this knows where to place the 0s of the array
			filteredArr[i] = 0;
		if(i > size - windowSize/2)
			break;
		filteredArr[i + windowSize/2] = hanningWindow1(&arr[i], size, windowSize);//sets the element in the array to the approriate value
	}

	//for(int i = 0; i < size; i++){
	//	cout << filteredArr[i];//prints the array
	//}
	//cout <<endl;
}

//Problem 3.
// printing out a graph of either original or filtered array, takes input parameter bool
//if boolean value is true, print graph of filtered array and if false
//print graph of original array

bool hanningWindow::windowGraph(bool x){
	int high;
	int low;

	if (x ==true)
	{
		high = highNum (filteredArr);
		low = lowNum (filteredArr);
	}
	if ( x == false)
	{
		high = highNum (&arr[0]);
		low = lowNum (arr);
	}

	int rows = high - low;

	//cout << high << endl;
	//cout << low << endl;

	for(int c = high; c>low-1; c--){ // specifies row
		cout<<c<<":";
		for(int r = 0; r < size; r++){ // specifies column
			if (x) {
				if(filteredArr[r] == c){ // prints star when the index number for the element matches the row number.
					cout << "*"; //
				}
				else
					cout << " "; //prints spaces when the element number doesn't match the row number.
			} else {
				if (arr[r] == c) {
					cout << "*";
				}
				else
					cout << " "; //prints spaces when the element number doesn't match the row number.
			}


		}
		cout <<endl;
	}

	return true;
};

//Helper function to determine the highest number in array

int hanningWindow::highNum(int *arr)
{
	int high = arr[0];
	for ( int i = 0; i < size;i ++ )
	{
		if (arr[i] > high)
			high = arr[i];

	}return high;
}


//Helper function to determine lowest number in array

int hanningWindow::lowNum(int *arr)
{
	int low = arr[0];
	for ( int i = 0; i < size;i ++ )
	{
		if (arr[i] < low)
			low = arr[i];

	}return low;
}
// Problem 4.
//determines if window size is odd, if its not, subtract 1.

void hanningWindow::modifiedWindowSize(int x)
{
	if (x %2 == 0)
	{
		x -= 1;
	}
windowSize = x;

hanningWindowNew();
}

//Problem 5.
// If boolean value is true, print filtered array,
//if false, print original array

void hanningWindow::printArray(bool x)
{
int *array;

if (x == true)
{
	array = filteredArr;
}
else
{
	array = arr;

}

for (int i = 0; i < size +1; i++)
{
	cout<< array[i] << endl;
}
}


//Getters

int hanningWindow::getWindowSize() {
	return windowSize;
}

int* hanningWindow::getArr() {
	return arr;
}

int hanningWindow::getSize() {
	return size;
}

int* hanningWindow::getFilteredArr() {
	return filteredArr;
}
