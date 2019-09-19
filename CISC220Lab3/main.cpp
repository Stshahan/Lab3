/* Victoria Todd, Jayson Morgado, Shaun Shahan
 * TA: Lauren Olson
 *  09/19/19
 * CISC220lab3.cpp
 */

#include "hanningWindow.hpp";
#include <iostream>
using namespace std;

int main () {

	int array1 [5] = {9,3,12,5,25};
	int array2 [5] = {8,14,9,17,6};

	hanningWindow win(3,array1, 5, array2);

	win.hanningWindowNew();
	win.printArray(false);
	cout<< "********************************************************"<<endl;
	win.printArray(true);
	cout<< "********************************************************"<<endl;
	win.windowGraph(false);
	cout<< "********************************************************"<<endl;
	win.windowGraph (true);
	cout<< "********************************************************"<<endl;
	win.modifiedWindowSize(5);
	win.printArray(false);
	cout<< "********************************************************"<<endl;
	win.printArray(true);
	cout<< "********************************************************"<<endl;
	win.windowGraph(false);
	cout<< "********************************************************"<<endl;
	win.windowGraph (true);
	cout<< "********************************************************"<<endl;

}


