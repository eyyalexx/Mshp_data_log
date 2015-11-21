#include <stdio.h>
#include <iostream>
using namespace std;




const float x = 14.7;    //can't be changed. (const)
const int y = 6;		//can't be changed.	(const)
int num;

void fred(int a, int *b);	//this is the prototype for the function made below.

//"num_ptr1" and "num_ptr2" are pointers
const int * num_ptr1;	//Preferred decleration
int const * num_ptr2;	//Also compiles OKAY ^


struct student{

	int age;
	float fee;
}; //make sure to and with a semi-colen after declaring struct.


int main (){	//"int" is the return type.
	
	//cout << "Hello World!" << endl;
	
	num = 7;
	
	num_ptr1 = &num;	// reference to "num"(points to num)
	num_ptr2 = &num;	// reference to "num"(points to num);
	// both point to "num"
	
	printf("%d %d \n", num, *num_ptr1);
	
	num = 18;
	
	printf("%d %d \n", num, *num_ptr1);
	
	
	student stdnt1;
	student * std_ptr;

	stdnt1.age = 20;
	std_ptr = &stdnt1;

	std_ptr->fee = 1000;

	cout << stdnt1.fee << endl;


	int x = 7, y = 8;

	cout << "M1 " << x << " " << y << endl;

	fred(x, &y);

	cout << "M2 " << x << " " << y << endl;


	return 0;
	
	//strcat(a, b); joins two things together ie. 2 characters

}


void fred (int a, int * b){
	cout << "F1 " << a << " " << *b << endl;

	a = 3;
	*b = 4;

	cout << "F2 " << a << " " << *b << endl;

}
		


















