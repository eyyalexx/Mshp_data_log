#include <stdio.h>
#include <iostream>
using namespace std;


const float x = 14.7;    //can't be changed. (const)
const int y = 6;		//can't be changed.	(const)
int num;



//"num_ptr1" and "num_ptr2" are pointers
const int * num_ptr1;	//Preferred decleration
int const * num_ptr2;	//Also compiles OKAY ^^


int main (){	//"int" is the return type.
	
	//cout << "Hello World!" << endl;
	
	num = 7;
	
	num_ptr1 = &num;	// reference to "num"(points to num)
	num_ptr2 = &num;	// reference to "num"(points to num);
	// both point to "num"
	
	printf("%d %d \n", num, *num_ptr1);
	
	num = 18;
	
	printf("%d %d \n", num, *num_ptr1);
	
	
	

	
	return 0;
	
}



/*

//decleration of student struct
//a struct has a tpye
struct student {		//"student" is the tag
	int age;
	float fee;
}// can declare structs her aswell ie. mystrct1, mystrct2 after "}"

//do this so later you can | stu_type mystrct1, mystrct1 |
*/

















