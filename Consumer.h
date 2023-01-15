#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Consumer{
  protected : 
    string name, gender,covid_test,surname,doctorname;
    int id=0, age=0,day=0,month=0,year=0;
    
    Consumer *next;
  public :
  Consumer(int x=0,string n="N/A",string s="N/A",string g="N/A",int a=0,string c="N/A",string dn="N/A",int d=0,int m=0,int y=0){
      id = x;
      name = n;
      surname = s;
      gender = g;
      age = a;
      covid_test = c;
      day=d;
      month=m;
      year=y;
      doctorname=dn;
      next=NULL;
      cout<<"Adding"<<endl;
      cout<<"ID: "<<id<<endl;
      cout<<"Full-Name: "<<name<<" - "<<surname<<endl;
}
  virtual void show_consumer();//virtual
  Consumer* move_next();
  void insert(Consumer*&);
  void inserts(Consumer*&);
  int return_id();
  string return_name();
  string return_surname();
  string return_gender();
  int return_age();
  int return_day();
  int return_month();
  int return_year();
  void change_ct(string);
  virtual void add_symptom(){
    cout<<"covid_test";
 } 
  virtual ~Consumer();//virtual
  void get_Date();
  void display_in();
  virtual void display_out(){}
  virtual void date_out(int,int,int){}
  virtual int return_dayo(){return 1;}
  virtual int return_montho(){return 1;}
  virtual int return_yearo(){return 1;}
  virtual int return_emergency(){return 0;}
};
