#include <iostream>
//#include"Doctor.h"
#include "Consumer.h"
#include "Patient.h"
#include"Consumer_LL.h"
using namespace std;

consumer_LL::consumer_LL(){
       hol=NULL;
       size=0;
}

consumer_LL::~consumer_LL(){
	Consumer *t=hol;
	while(hol!=NULL)
             {
               hol=t->move_next();
               delete t;
               t=hol;
             }
  cout<<"Consumer left"<<endl;
  }
	

void consumer_LL::show_all(){
     Consumer* t=hol;
     int i;
     for(i=0;i<size;i++){
        if(t->return_id()!=0){
        t->show_consumer();
        t->display_in();
        t->display_out();
        cout<<endl<<"------------------------------------"<<endl;}
	      t=t->move_next();    
     }
}

void consumer_LL::show(int b){
  Consumer* t=hol;
     int i,temp;
     for(i=0;i<size;i++){
       temp = t->return_id();
       if(temp==b){
             t->show_consumer();
             t->display_in();
             t->display_out();
	      break;
     }
     t=t->move_next();
    }
}

void consumer_LL::add_consumer(Consumer *&A){
          hol->insert(A);
          hol=A;
       size++;
}//add หน้า

void consumer_LL::insertion(Consumer *&A){
  Consumer *t=hol,*l=hol;
  while(l->move_next()!=NULL){
    l=l->move_next();
  }
  l->inserts(A);
  size++;
}//add หลัง

/* void consumer_LL::check_consumer(Consumer *&A){
        Consumer *d;
        d->check_id(A);
        d=A;
 }*/

int consumer_LL::check_consumer_id(int a){
  Consumer *t=hol;
  int i,n=0,id=0,s=-1;
  for(i=0;i<size;i++){
      id =t->return_id();
      if(a==id){n = i;
      return i;
      break;}
      t=t->move_next();
    }
    return s;
}

Consumer* consumer_LL::create_pat(int b,string nd,int em){
  Consumer *t=hol,*p,*prev=t,*next;
  
  int i,id,age,dayi,monthi,yeari,e;
  string name,surname,gender;
  //cout<<"w";

  if(b==0){
        //cout<<"w";
        id =t->return_id();
        name = t->return_name();
        surname = t->return_surname();
        age = t->return_age();
        gender = t->return_gender();
        dayi = t->return_day();
        monthi = t->return_month();
        yeari = t->return_year();
        hol=hol->move_next();
        //cout<<"w";
        delete t;
        system("clear");
        size--;
        //break;
    }else{
    for(i=0;i<b;i++){prev =t; t=t->move_next();}
        //cout<<"w";
        id =t->return_id();
        name = t->return_name();
        surname = t->return_surname();
        age = t->return_age();
        gender = t->return_gender();
        dayi = t->return_day();
        monthi = t->return_month();
        yeari = t->return_year();
        //cout<<"w";
        next = t->move_next();
        //cout<<"w";
        next->insert(prev);
        //cout<<"w";
        delete t;
        system("clear");
        size--;
        //break;
        }
    e=em;
    p = new patient(id,name,surname,gender,age, "Positive",nd,e,dayi,monthi,yeari);
    p->add_symptom();
    p->date_out(dayi,monthi,yeari); 
    return p;
}

Consumer* consumer_LL::create_con(int b,string nd){
  Consumer *t=hol,*p,*prev=t,*next;
  
  int i,id,age,dayi,monthi,yeari,e;
  string name,surname,gender;
  //cout<<"w";

  if(b==0){
        //cout<<"w";
        id =t->return_id();
        name = t->return_name();
        surname = t->return_surname();
        age = t->return_age();
        gender = t->return_gender();
        dayi = t->return_day();
        monthi = t->return_month();
        yeari = t->return_year();
        hol=hol->move_next();
        //cout<<"w";
        delete t;
        system("clear");
        size--;
        //break;
    }else{
    for(i=0;i<b;i++){prev =t; t=t->move_next();}
        //cout<<"w";
        id =t->return_id();
        name = t->return_name();
        surname = t->return_surname();
        age = t->return_age();
        gender = t->return_gender();
        dayi = t->return_day();
        monthi = t->return_month();
        yeari = t->return_year();
        //cout<<"w";
        next = t->move_next();
        //cout<<"w";
        next->insert(prev);
        //cout<<"w";
        delete t;
        system("clear");
        size--;
        //break;
        }
    p = new Consumer(id,name,surname,gender,age, "Negative",nd,dayi,monthi,yeari);
    p->date_out(dayi,monthi,yeari); 
    return p;
}



int consumer_LL::chksortid(Consumer *&A)
{
  int i=0,id1=0,id=0;
  long sum=0,sumcheck=0;
  id = A->return_id();
  Consumer *t=hol;
  for(i=0;i<size;i++)
  {
    id1 = t->return_id();
    if(id1>id){
      return i;
    }
    
    t =t->move_next();
  }return -1;
}


int consumer_LL::chksortdate(Consumer *&A,int b)
{
  int i=0,d1,y3,m2;
  long sum=0,sumcheck=0;
  int d = A->return_dayo();
  int y = A->return_yearo();
  int m = A->return_montho();
  sum=d+(30*m)+(y*365);
  Consumer *t=hol;
  for(i=b;i<size;i++)
  {
    d1 = t->return_dayo();
    m2 = t->return_montho();
    y3 = t->return_yearo();
    sumcheck = d1+(30*m2)+(y3*365);
    if(sumcheck>sum){
      return i;
    }
    
    t =t->move_next();
  }return -1;
}

void consumer_LL::sortdate(int b, Consumer *&A){
  Consumer *t = hol,*prev;
  int i;
  for(i=0;i<b;i++){
    prev =t; 
    t=t->move_next();
  }
  prev->inserts(A);
  A->inserts(t);
  size++;
}



void consumer_LL::Normal(int b){
  Consumer *t = hol;
  int i;
  for(i=0;i<size;i++){
    if(i==b){
      t->change_ct("Negative");
      cout<<"Change complete"<<endl;
    }
    t=t->move_next();
  }
}