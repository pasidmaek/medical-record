#include <iostream>
#include <string.h>
using namespace std;
#include"Consumer.h"

class wc: public exception{
    const char* what()
    const throw()
    {//return string
        return "Please Enter Integer";
    }
}fc;

Consumer:: ~Consumer(){
      cout<<"Consumer "<<name<<" is fine"<<endl;
}

Consumer* Consumer::move_next(){
      return next;
}

/*Consumer* Consumer::move_prev(){
      return prev;
}*/

void  Consumer:: show_consumer(){
      cout<<"Consumer data"<<endl;
      cout<<"ID: "<<id<<endl;
      cout<<"Full-Name: "<<name<<" - "<<surname<<endl;
      cout<<"Gender: "<<gender<<endl;
      cout<<"Age: "<<age<<endl;
      cout<<"Covid-Test: "<<covid_test<<endl;
      cout<<"Doctor Name : "<<doctorname<<endl;
}

void Consumer::change_ct(string b){
  covid_test = b;
}

void Consumer::insert(Consumer*& x){
     x->next=this;
}

void Consumer::inserts(Consumer *&x){
  this->next = x;
}
int Consumer::return_id(){
  return id;
}

string Consumer::return_name(){
  return name;
}
string Consumer::return_surname(){
  return surname;
}
string Consumer::return_gender(){
  return gender;
}
int Consumer::return_age(){
  return age;
}
int Consumer::return_day(){
  return day;
}
int Consumer::return_month(){
  return month;
}

int Consumer::return_year(){
  return year;
}
 void Consumer::get_Date(){
    int check=0,dd=0,mm=0,yy=0;
    do{
      do{try{cout<<endl<<"Date is ";
      cin>>day;
      if(cin.fail())
      {
        throw fc;
      }
      dd=1;
      }catch (exception &e) {
	    cout<<"## "<< e.what()<<" ##"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
      }}while(dd!=1);
      do{try{cout<<endl<<"Month is ";
      cin>>month;
      if(cin.fail())
      {
        throw fc;
      }
      mm=1;
      }catch (exception &e) {
	    cout<<"## "<< e.what()<<" ##"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
      }}while(mm!=1);
      do{try{cout<<endl<<"Year is ";
      cin>>year;
      if(cin.fail())
      {
        throw fc;
      }
      yy=1;
      }catch (exception &e) {
	    cout<<"## "<< e.what()<<" ##"<<endl;
      cin.clear();
      cin.ignore(500, '\n');
      }}while(yy!=1);
      if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
      {
        if(day<1||day>31) {
                  cout<<"try again?\n";
                  continue;
                }
        else check=1;
      }
      else if(month==2)
      {
        if(year%4==0)
        {
          if(year%100==0)
            {
              if(year%400==0)
              {
                if(day<1||day>29)
                {
                  cout<<"try again?\n";
                  continue;
                }
                else check=1;
              }else{
                if(day<1||day>28) {
                  cout<<"try again?\n";
                  continue;
                }
                else check=1;
              }
            }
          else{
            if(day<1||day>29){
                  cout<<"try again?\n";
                  continue;
                }
                else check=1;
          }
        }
        else
        {
          if(day<1||day>28) {
                  cout<<"try again?\n";
                  continue;
                }
          else check=1;
        }
      }
    else if(month==4||month==6||month==9||month==11)
    {
      if(day<1||day>30) {
                  cout<<"try again?\n";
                  continue;
                }
        else check=1;
    }
    if(month>12||month<0)
    {
      cout<<"try again?\n";
      continue;
    }

    if(year<=0)
    {
      cout<<"try again?\n";
      check=0;
      continue;
    }

    }while(check!=1);
  }

void Consumer::display_in(){
  cout<<"Date-in: "<<setw(2)<<setfill('0')<<day<<"/"<<setw(2)<<setfill('0')<<month<<"/"<<year<<endl;
}



//Date Consumer::return_date_in(){}