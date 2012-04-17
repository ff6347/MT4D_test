//based on Phil's guide to object-oriented ANSI C
// http://www.bolthole.com/OO-C-programming.html
// and some stackoverflow.com questions about Object orientation in ANSI C

#include <stdio.h>
#include <stdlib.h>

// this is something like the class
typedef struct OBJECT {
  int res; // the object knows it result
  char *name; // the char array for the name
} OBJECT

typedef OBJECT* Object;
 // ------------ now the methods of the "class" ------------ 

//Create a new objact based on struct OBJECT
Object obj_create() {
  Object s;
  s = (Object) malloc(sizeof(OBJECT));
  // set the fields to inital values
  s->res = 0;
  s->name = "undefined";

  return(s);// gibe back the object
}
// need to remove this object again
void obj_destroy(Object s) { free(s); }
// this is the compare method
int obj_compare(Object s, int a, int b){
		if(a>b){
			s->res = a;
		}else if (b>a){
			s->res = b;
		}else if(b == a){
		s->res = 0;
	}
	return s->res;
}

void obj_set_name(Object s, char *n){
s->name = n;
}


int main(void) {
  Object s = obj_create();

    s.compare_ptr = compare;

  obj_set_name(s,"Hello ANSI C");
  int a = 23, b = 5;

  printf("The Object named \"%s\" compared %d with %d. The result is %d \n",s->name, a,b, obj_compare(s, a, b));
obj_destroy(s);
  return 0;
}




