/* Victoria Todd, Jayson Morgado, Shaun Shahan
 * TA: Lauren Olson
 *  09/19/19
 * CISC220lab3.cpp
 */

#ifndef HANNINGWINDOW_HPP_
#define HANNINGWINDOW_HPP_

class hanningWindow {
private:
	int windowSize;
	int *arr;
	int size;
	int *filteredArr;

public:
	hanningWindow(int w, int *x,int s, int *y);

int hanningWindow1(int arr[],int len, int window);
void hanningWindowNew();
bool windowGraph(bool x);
int highNum(int *arr);
int lowNum(int *arr);
void modifiedWindowSize(int x);
void printArray(bool x);

int getWindowSize();
int* getArr();
int getSize();
int* getFilteredArr();
};

#endif /* HANNINGWINDOW_HPP_ */
