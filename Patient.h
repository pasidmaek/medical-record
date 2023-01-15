class patient:public Consumer{
  private:
  string symptoms="N/A",doc_name;
  int emergency=0,dayo=0,montho=0,yearo=0;
  public:
  
  patient(int x, string n, string s, string g,int a, string c,string dn,int e,int di,int mi,int yi):Consumer(x,n,s,g,a,c,dn,di,mi,yi)
  {
    emergency = e;
    doc_name=dn;
    cout<<name<<" is Patient of Dr."<<dn<<endl;
  }
  
  void add_emergency(){
    emergency = 1;
  }
  void show_consumer(){
    cout<<endl<<endl;
    if(emergency==1)cout<<"Emergency Person"<<endl;
    cout<<"Patient data"<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Full-Name: "<<name<<" - "<<surname<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Covid-Test: "<<covid_test<<endl;
    cout<<"Symptoms: "<<symptoms<<endl;
    cout<<"Caring Doctor: "<<doc_name<<endl<<endl;
  }

  void add_symptom(){
    cout<<endl<<"------------------ Adding symptoms ------------------"<<endl;
    cout<<"             ***Commonly seen symptoms***      "<<endl;
    cout<<"      - Fever        - Cough          - Dyspnea" <<endl;
    cout<<"      - Fatigue      - Muscle aches   - Headache"<<endl;
    cout<<"      - Sorethroat   - Runny nose     - Vomiting"<<endl;
    cout<<"      - Diarrhea     - Smell and taste disorder "<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl<<"Your symptoms => ";//ใส่อาการ
    getline(cin>>ws,symptoms);
  }


  ~patient(){
    cout<<"Removed Patient "<<name<<endl;
    display_out();
  }


  void display_out(){
  cout<<"Date-out: "<<setw(2)<<setfill('0')<<dayo<<"/"<<setw(2)<<setfill('0')<<montho<<"/"<<yearo<<endl;
}

void date_out(int day,int month,int year){
  dayo=day;
  montho=month;
  yearo=year;
  dayo=dayo+14;
  if(montho==1||montho==3||montho==5||montho==7||montho==8||montho==10||montho==12)
  {
    if(dayo>31){
      dayo=dayo-31;
      montho=montho+1;
    }
  }
  else if(montho==2)
  {
    if(yearo%4==0)
        {
          if(yearo%100==0)
            {
              if(yearo%400==0)
              {
                if(dayo>29)
                {
                  dayo=dayo-29;
                  montho=montho+1;
                }
              }else{
                if(dayo>28) {
                  dayo=dayo-28;
                  montho=montho+1;
                }
              }
            }
          else{
            if(dayo>29)
                {
                  dayo=dayo-29;
                  montho=montho+1;
                }
          }
        }
        else
        {
          if(dayo>28) {
                  dayo=dayo-28;
                  montho=montho+1;
                }
        }
  }
  else if(montho==4||montho==6||montho==9||montho==11)
  {
    if(dayo>30){
      dayo=dayo-30;
      montho=montho+1;
    }
  }

  if(montho>12)
  {
    montho=montho-12;
    yearo=yearo+1;
  }
}

  int return_dayo(){
    return dayo;
  }
  int return_montho(){
    return montho;
  }
  int return_yearo(){
    return yearo;
  }

  int return_emergency(){
    return emergency;
  }
};
