// taken from Phil's guide to object-oriented ANSI C
// here http://www.bolthole.com/OO-C-programming.html

#include "FooOBJ.h"

void diddle(FooOBJ obj){
	/* Perform member functions on FooOBJ.
	 * If you try these functions on a different type of object,
	 * you will get a compile-time error
	 */
	setFooNumber(obj, 1);
	setFooString(obj, "somestring");

}

int main(void){
	FooOBJ fobj;
	fobj=newFooOBJ(); /* create a new object of type "FooOBJ" */

	dumpFooState(fobj);
	puts("Tweaking object");
	diddle(fobj);

	dumpFooState(fobj);
	deleteFooOBJ(fobj);

	return 0;
}