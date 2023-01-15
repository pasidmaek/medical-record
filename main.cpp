#include <iostream>
using namespace std;
#include <cstdlib>
#include <exception>
#include <fstream>
#include <string>
//#include "Date.h"
#include "Exception.h"
#include "Consumer.h"
#include "Patient.h"
#include "Doctor.h"
#include "Doctor_LL.h"
#include "Consumer_LL.h"
int y;

/*class patient:public Consumer{
  private:
  string symptoms,doc_name;
  int emergency;
  //Date date_out;
  public:
  
  patient(int x, string n, string s, string g,int a, string c,string dn,string sy,int e):Consumer(x,n,s,g,a,c)
  {
    emergency = e;
    symptoms = sy;
    doc_name=dn;
    cout<<"You are Patient"<<endl;
  }
  
  void add_emergency(){
    emergency = 1;
  }
  void show_consumer(){
    cout<<"Patient data"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Full-Name: "<<name<<" - "<<surname<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Age: "<<age<<endl;
    //date_in.display_in();
    //date_out=date_in.date_out();
    //date_out.display_out;
    cout<<"Covid-Test: "<<covid_test<<endl;
    cout<<"Symptoms: "<<symptoms<<endl;
  }

  void add_symptom(){
    cout<<"---------adding symptoms--------- "<<endl;
    cout<<"  ***Commonly seen symptoms***: "<<endl;
    cout<<"Fever        Cough          Dyspnea"<<endl;
    cout<<"Fatigue      Muscle aches   Headache"<<endl;
    cout<<"Sorethroat   Runny nose     Vomiting"<<endl;
    cout<<"Diarrhea     Smell and taste disorder "<<endl;
    cout<<""<<endl;//ใส่อาการ
    cin>>symptoms;
  }
  ~patient(){
    cout<<"Removed Patient";
  }
};*/


void menu(doctor_LL*,consumer_LL*,consumer_LL*,int);
void doctor_function(doctor_LL *,consumer_LL*,consumer_LL*,int);
void clrscr();
void Medical_certificate(consumer_LL *a,int b);
bool check_number(string);
Consumer* newConsumer(consumer_LL*,string doc);

int main()
{
  int first = 0;
  //Consumer *p = new Consumer(0,"Patient","Base","N/A",0,"N/A");
  consumer_LL b,pa;
  Consumer *d = new Consumer(0,"Consumer","Base","N/A",0,"N/A","N/A",0);
  Consumer *s = new patient(0,"Patient","Base","N/A",0,"N/A","N/A",0,0,0,0);
  b.add_consumer(d);
  pa.add_consumer(s);
  system("clear");
  //patient p1(8,"s","s","s",7,"s","s","s",8);
  Doctor *t;
  doctor_LL A;
  t = new Doctor("Thanawat",12456);
  A.add_doctor(t);
  t = new Doctor("Pasid",12345);
  A.add_doctor(t);
  t = new Doctor("Pisit",458089);
  A.add_doctor(t);
  t = new Doctor("Napat",123455);
  A.add_doctor(t);
  t = new Doctor("Natthabodi",1234325);
  A.add_doctor(t);
  menu(&A,&b,&pa,first);
}

void menu(doctor_LL*A,consumer_LL*b,consumer_LL*pa,int first)
{
  int choice,chk;
  do{
  try{
    cout<<"___________________________________________________________________________________________"<<endl<<endl;
  cout<<"                                     Doctor Avialable"<<endl;
  cout<<"___________________________________________________________________________________________"<<endl<<endl;
  A->show_all();
  cout<<"___________________________________________________________________________________________"<<endl<<endl;
    cout<<"                                         MAIN MENU"<<endl;
    cout<<"                                    Welcome To Hospital"<<endl;
    cout<<"                                       Who are you??"<<endl<<endl;
    cout<<"                            1. Patient || 2. Doctor || 0. Exit"<<endl<<endl;
    cout<<"Choose : ";
    cin>>choice;
    if(cin.fail())
    {
      throw failchoice;
    }
    if(choice==1||choice==2||choice==0)
    {
      break;
    }
    else 
    {
      throw wrong;
    }
  }
  catch (exception &e) {
    system("clear");
	    cout<<"## "<< e.what()<<" ##"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
      choice=3;
   }
  }while(choice!=0&&choice!=1&&choice!=2);
  system("clear");

  if(choice==1)
  {
    do{
    try
    {
    int id;
    cout<<"What is your id?"<<endl<<"Insert ID -> ";
    cin>>id;
    if(cin.fail())
    {
      throw failchoice;
    }
    if(id==0)throw zero;
    chk = b->check_consumer_id(id);

    //เปรียบเทียบไอดีแล้วโชว์ข้อมูลของผู้ป่วยโดยเฉพาะ
    if(chk==-1){
      chk = pa->check_consumer_id(id);
      if(chk==-1)
      cout<<endl<<"-------------------"<<endl<<":  ID not found!  :"<<endl<<"-------------------"<<endl;
      else {pa->show(id);
      cout<<endl<<"Do you want to get Medical certificate"<<endl<<endl;
      cout<<"     1. Yes || 2. No"<<endl<<endl<<"=> ";
      int told=0;
      cin>>told; 
    if(cin.fail()){system("clear");throw failchoice;}
      if(told==1)
      {
        Medical_certificate(pa,id);
      }else if(told==2){
        system("clear");
        }else {
          system("clear");
          throw fail;
          }
        }
    }else {b->show(id);
    cout<<endl<<"Do you want to get Medical certificate"<<endl<<endl;
      cout<<"     1. Yes || 2. No"<<endl<<endl<<"=> ";
      int told=0;
      cin>>told;
    if(cin.fail()){system("clear");throw failchoice;}
      if(told==1)
      {
        Medical_certificate(b,id);
      }else if(told==2){
        system("clear");
        }
      else {
        system("clear");throw fail;
        }
      }
    }
    catch (exception &e) {
	    cout<<"*****"<< e.what()<<"*****"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
   int tt=0;
   do{
  try{
    cout<<endl<<"What do you want to do next?"<<endl<<endl;
    cout<<"     1. Back to main menu | | 2. Search ID"<<endl<<endl<<"=> ";
    cin>>y;
    if(y==1||y==2)break; 
    else throw fail;
  }
  catch (exception &e){
    system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
  }while(y!=1&&y!=2);
  if(y==1){system("clear");
  menu(A,b,pa,first);
  };system("clear");
  }while(y!=1);
  }
  else if (choice==2){
    doctor_function(A,b,pa,first);
  }
  else if (choice==0){
    cout<<"See You"<<endl;

  }
}

void doctor_function(doctor_LL *A,consumer_LL*b,consumer_LL*pa,int first)
{
  int i,ids;
  Consumer *p1;
  //A.show_all();
    string name_doc;
    int password,yn=0,check=0,function=0,log_in_chk=0,id,consumer_chk;
    
    try{
    cout<<"What is your username?"<<endl<<"Insert USERNAME -> ";
    cin>>name_doc;
    cout<<endl<<"What is your password?"<<endl<<"Insert PASSWORD -> ";
    cin>>password;
    if(cin.fail())throw failpass;
    log_in_chk = A->check_doctor_name(name_doc,password);
    if(log_in_chk!=5)throw failpass;
    }catch (exception &e) {
            system("clear");
            cout<<"~~~~ "<< e.what()<<" ~~~~"<<endl;
            cin.clear();
            cin.ignore(500, '\n');
            }
    if(log_in_chk==5)//เช็ค user,pass
    {  
      system("clear");
      do{
      try
      {cout<<"          What function do you want to do?"<<endl;
      cout<<endl<<"(1.) Create new patient platform"<<endl;
      cout<<endl<<"(2.) Change to Positive Covid patient information"<<endl;
      cout<<endl<<"(3.) Change to Negative Covid-test person"<<endl;
      cout<<endl<<"(4.) Show all patient information"<<endl;
      cout<<endl<<"(5.) Show all consumer information"<<endl;
      cout<<endl<<"(0.) Back to Menu"<<endl;
      cout<<endl<<"-----------------------------------------------------"<<endl<<"Choose --> ";
      cin>>function;
      if(cin.fail())throw failchoice;
      if(function==1||function==2||function==3||function==0||function==4||function==5)check=1;
      else{
        check=0;
        throw fail14;
      }
      }
      catch (exception &e) {
            system("clear");
            cout<<"        ++++++++"<<e.what()<<"++++++++"<<endl;
            cin.clear();
            cin.ignore(500, '\n');
            }
      }while(check!=1);
      int loop=0;
      if(function==1){
        do{
        system("clear");
        cout<<"-----------------------------------------------------"<<endl<<"                Consumer information"<<endl<<"-----------------------------------------------------"<<endl;
        p1 = newConsumer(b,name_doc);
        int te=0;
          te=b->chksortid(p1);
          if(te==-1)b->insertion(p1);
          else{b->sortdate(te,p1);}
        do{
  try{
    cout<<endl<<"What do you want to do next?"<<endl<<endl;
    cout<<"     1. Back to main menu | | 2. Add new consumer"<<endl<<endl<<"=> ";
    cin>>y;
    if(y==1||y==2)break; 
    else throw fail;
  }
  catch (exception &e) {
    system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
  }while(y!=1&&y!=2);
  if(y==1){system("clear");
  menu(A,b,pa,first);
  };system("clear");
  }while(y!=1);
      }
      else if(function==2){
        do{
        system("clear");
        do{
          try{
        cout<<"Enter ID: ";
        cin>>ids;
        if(cin.fail()){throw failchoice;}
        if(ids==0){throw zero;}
        }
      catch (exception &e) {
      system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
        }}while(ids==0);
        //cout<<"e";
        consumer_chk = b->check_consumer_id(ids);
        //cout<<consumer_chk;
        ////cout<<"e";
        
        if(consumer_chk!=-1){
          //cout<<"s";
          
        int Emer=0,em;
      do{
        try{
            cout<<"Is this patient in Emergency?"<<endl;
            cout<<"1. Yes || 2. No"<<endl;
            cin>>Emer;
            if(cin.fail())throw fail;
            if(Emer==1){
            em=1; }
            else if(Emer==2){
            em=0;}
            else throw fail;
            }   
        catch (exception &e){
           system("clear");
	         cout<< e.what()<<endl;
           cin.clear();
           cin.ignore(500, '\n');
            }
        }while(Emer!=1&&Emer!=2);
        system("clear");


          p1 = b->create_pat(consumer_chk,name_doc,em);
         // cout<<"ew";
         int sort;
          if(em==1){
            sort = pa->chksortdate(p1,0);
          if(first==0)
          {
            pa->add_consumer(p1);
          }
        else
          {
            pa->sortdate(first, p1);
          }
          first++;
        }
        else{
          sort = pa->chksortdate(p1,first);
        if(sort==-1){
          pa->insertion(p1);
        }else{
          pa->sortdate(sort, p1);
        } 
      }
    }
        else{
          if(pa->check_consumer_id(ids)!=-1)
          {
          cout<<"This ID is curing"<<endl;
          }
          else
          {
          cout<<"This ID is not Exist"<<endl;
          }
        }
        do{
  try{
    cout<<endl<<"What do you want to do next?"<<endl<<endl;
    cout<<"     1. Back to main menu | | 2. Add new patient"<<endl<<endl<<"=> ";
    cin>>y;
    if(y==1||y==2)break; 
    else throw fail;
  }
  catch (exception &e){
    system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
  }while(y!=1&&y!=2);
  if(y==1){system("clear");
  menu(A,b,pa,first);
  };system("clear");
  }while(y!=1);
      }
      else if(function==3){
        do{
        system("clear");
        cout<<"Enter ID: ";
       
       cin>>ids;
        consumer_chk = b->check_consumer_id(ids);
        if(consumer_chk != -1){
          b->Normal(consumer_chk);
        }else{
          consumer_chk = pa->check_consumer_id(ids);
          if(consumer_chk != -1){
          pa->Normal(consumer_chk);
          Consumer *p2;
          p2=pa->create_con(consumer_chk,name_doc);
          int te=0;
          te=b->chksortid(p2);
          if(te==-1)b->insertion(p2);
          else{b->sortdate(te,p2);}
          }//420
          else{
          cout<<"This ID's COVID test is not found"<<endl;}
        }
        do{
  try{
    cout<<endl<<"What do you want to do next?"<<endl<<endl;
    cout<<"     1. Back to main menu | | 2. Add new result"<<endl<<endl<<"=> ";
    cin>>y;
    if(y==1||y==2)break; 
    else throw fail;
  }
  catch (exception &e){
    system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
  }while(y!=1&&y!=2);
  if(y==1){system("clear");
  menu(A,b,pa,first);
  };system("clear");
  }while(y!=1);
      }
      else if(function==4)
      {
        system("clear");
        int test=1;
        do{
          try{
        test=1;
        cout<<"Patient"<<endl;
        pa->show_all();
        cout<<"Type 0 to go back to menu"<<endl;
        cin>>test;
        if(cin.fail()){test = 1;throw zerox;}
        if(test!=0)throw zerox;
        }catch (exception &e){
      system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
        }while(test!=0);
        system("clear");
        menu(A,b,pa,first);
      }
      else if(function==5)
      {
        system("clear");
        int test=1;
        do{
          try{
        test=1;
        cout<<"Consumer"<<endl<<endl<<endl;
        pa->show_all();
        b->show_all();
        cout<<"Type 0 to go back to menu"<<endl;
        cin>>test;
        if(cin.fail()){test = 1;throw zerox;}
        if(test!=0)throw zerox;
        }catch (exception &e){
      system("clear");
	    cout<< e.what()<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
        }while(test!=0);
        system("clear");
        menu(A,b,pa,first);
      }
      else if(function==0){
        system("clear");
        menu(A,b,pa,first);
      }
    }
    else/*ไอดีพาสเวิร์ดไม่ตรง*/{
      do{
  try{
    cout<<"         Do you want to try again?"<<endl;
    cout<<"              1. Yes || 2. No"<<endl;
    cout<<"=>";
    cin>>yn;
    if(yn==1||yn==2)break; 
    else throw fail;
  }
  catch (exception &e) {
      system("clear");
	    cout<<"~~~~~~~~~~~~"<< e.what()<<"~~~~~~~~~~~~"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
   }
  }while(yn!=1&&yn!=2);
      if(yn==1){
        system("clear");
        doctor_function(A,b,pa,first);
      }
      else 
      {
        system("clear");
        menu(A,b,pa,first);
      }
    }
  }



  Consumer* newConsumer(consumer_LL *b, string doc)
{ string name, surname, gender,result,doctor1;
  Consumer *p;
  int id,age,idc=0,consumer_chk;
  doctor1=doc;
    do{
        cout<<endl<<"Consumer ID      : ";
        cin>>id;
        idc=1;
        try
        {
          if(cin.fail())
          {
             idc=0;
             throw failchoice;
          }
          consumer_chk = b->check_consumer_id(id);
          if(consumer_chk!=-1)
          {
            idc=0;
            throw sameid;
          }
        }
        catch (exception &e)
        {
          cout<< e.what()<<endl;
          cin.clear();
          cin.ignore(500, '\n');
        } 
      }while(idc!=1);
    do{
        try{
      cout<<endl<<"Consumer name    : ";
      cin>>name;
      if(check_number(name)!=0){
        idc=0;
        throw strings;  
      }else
      idc=1;
         }catch (exception &e)
        {
          cout<< e.what()<<endl;
          cin.clear();
          cin.ignore(500, '\n');
        } 
      }while(idc!=1);
    do{
        try{
      cout<<endl<<"Consumer surname : ";
      cin>>surname;
      if(check_number(surname)!=0){
        idc=0;
        throw strings;  
      }else
      idc=1;
         }catch (exception &e)
        {
          cout<< e.what()<<endl;
          cin.clear();
          cin.ignore(500, '\n');
        } 
      }while(idc!=1);
    do{
    cout<<endl<<"Consumer gender [M/F] : ";
    cin>>gender;
    idc=1;
     try
        {
          if(cin.fail())
          {
             idc=0;
             throw MF;
          }
          if(gender=="m")gender="M";
          if(gender=="f")gender="F";
          if(gender!="M"&&gender!="F")
          {
            idc=0;
            throw MF;
          }
        }
        catch (exception &e)
        {
          cout<< e.what()<<endl;
          cin.clear();
          cin.ignore(500, '\n');
        } 
    }while(idc!=1);
    do{
      cout<<endl<<"[If it's a baby please type 1]"<<endl;
          cout<<"Consumer age     : ";
          cin>>age;
          idc=1;
          try{
            if(cin.fail())
          {
             idc=0;
             throw failchoice;
          }
          if(age<1){
            idc=0;
            throw ages;
          }
          }
          catch (exception &e)
        {
          cout<< e.what()<<endl;
          cin.clear();
          cin.ignore(500, '\n');
        } 

    }while(idc!=1);

    p = new Consumer(id,name,surname,gender,age,"N/A",doctor1);
    p->get_Date();
    return p;
}

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

void Medical_certificate(consumer_LL *a,int b){
  system("clear");
  cout<<"------------------------------------------"<<endl;
  cout<<"-------------Mahidol Hospital-------------"<<endl;
  cout<<"-----------Medical certificate------------"<<endl<<endl;
  a->show(b);
  cout<<endl<<"------------------------------------------"<<endl;
  cout<<"---------The hospital confirm this is true"<<endl<<endl<<endl<<endl<<endl<<endl;
}
