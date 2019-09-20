//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/19/19
// CISC220 Lab 3/===========================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include string.h;
using namespace std;
#include "Box.hpp"


class MathQuiz {
private:
		int subject;  // number we're testing on today.
		int nbrCorrect;	// total number of correct answers
		int totalNbrTested; // total number of test questions

public:
		MathQuiz(int x) {   // constructor
			subject=x;
			nbrCorrect=0;
			totalNbrTested=0;
			}  //Constructor

	int getNbrCorrect() const {
		return nbrCorrect;
	}

	void setNbrCorrect(int nbrCorrect) {
		this->nbrCorrect = nbrCorrect;
	}

	int getSubject() const {
		return subject;
	}

	void setSubject(int subject) {
		this->subject = subject;
	}

	int getTotalNbrTested() const {
		return totalNbrTested;
	}

	void setTotalNbrTested(int totalNbrTested) {
		this->totalNbrTested = totalNbrTested;
	}

	void testQuestion(MathQuiz q){
		srand(time(NULL)); // calls random number generator
		int answer = 0;
		int x= rand()%13; //generates a random number between 1 and 13;
			cout << x << " x " << this->getSubject() << " =" << endl; // prints the problem
		cin >> answer;
		if(answer == x*this->getSubject())
		{// prints when correct and incriments total number correct and total tested
			this->setNbrCorrect(this->getNbrCorrect()+1);
			this->setTotalNbrTested(this->getTotalNbrTested()+1);
			cout<< "Correct!"<< endl;
		}
		else{//prints the incorrect result and incriments total tested
			this->setTotalNbrTested(this->getTotalNbrTested()+1);
			cout<< "incorrect :("<< endl;
		}
	}

		void result(MathQuiz q){
			cout<< "Result: " << q.getNbrCorrect()	<< "/" << q.getTotalNbrTested()<< endl; // prints the total number correct out of total tested
		}
};
//MathQuiz

int main(void){

//**************************************************************
// Try on computer problem 1

	MathQuiz a(5); //test case for math quiz and test question
	while (a.getTotalNbrTested()<10){
		a.testQuestion(a);
	}
	a.result(a);

	// test cases for box.
	Box Box1(3.3, 1.2, 1.5);
	   Box Box2(8.5, 6.0, 2.0);
	   Box Box3;
	   Box3 = Box1 + Box2;
	   Box Box4(5, 6, 7);
	   Box Box5(5, 6, 7);
	   Box Box6(5, 6, 8);
	   if(Box4 == Box5) // should evaluate true
	   cout << "true" << endl;
	   else
	   cout << "false" << endl;
	   if(Box5 == Box6) // should evaluate false.
	      cout << "true" << endl;
	      else
	      cout << "false" << endl;

	   double volume = Box3.getVolume();
	   cout << "Vol of Box3 : " << volume <<endl;


}



