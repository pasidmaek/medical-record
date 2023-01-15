#include <iostream>
using namespace std;
#include"Doctor.h"

Doctor::Doctor(string x,int y){
      name=x;
      password=y;
      next=NULL;
}

  Doctor:: ~Doctor(){
      cout<<"Doctor "<<name<<" is being deleted"<<endl;
}
Doctor* Doctor::move_next(){
      return next;
}

void  Doctor:: show_Doctor(){
         cout<<"Available Dr."<<name<<endl;
 }
 
void Doctor::insert(Doctor*& x){
     x->next=this;

     }
     
string Doctor::return_name(){
  return name;
}

int Doctor::return_pass(){
  return password;
}