#include <iostream>
#include"Doctor.h"
#include "Doctor_LL.h"
using namespace std;

doctor_LL::doctor_LL(){
       hil=NULL;
       size=0;
}

doctor_LL::~doctor_LL(){
       int i;
	Doctor *t;
	for(i=0;i<size;i++){
		t=hil;
		hil=hil->move_next();
		delete t;
	}
	
}

void doctor_LL::show_all(){
     Doctor* t=hil;
     int i;
     for(i=0;i<size;i++){
             t->show_Doctor();
	      t=t->move_next();    
     }
}

void doctor_LL::add_doctor(Doctor *&A){
          hil->insert(A);
          hil=A;
       size++;

 }

 int doctor_LL::check_doctor_name(string A, int B){
   Doctor *t=hil;
   int i,n=0,pass=0;
   string names;
   for(i=0;i<size;i++){
        names =t->return_name();
        pass = t->return_pass();
	      t=t->move_next();
        if(A==names&&B==pass){n = 5;break;} 
     }
     return n;
 }