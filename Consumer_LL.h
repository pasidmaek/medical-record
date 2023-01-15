class consumer_LL{
      Consumer*hol;
      int size;
public:
       void add_consumer(Consumer*&);
       void insertion(Consumer *&);
       void show_all();
       void show(int);
       ~consumer_LL();
       consumer_LL();
       int check_consumer_id(int);
       int chksortid(Consumer *&);
       Consumer* create_pat(int,string,int);
       int chksortdate(Consumer *&,int);
       void sortdate(int, Consumer*&);
       void Normal(int);
       Consumer* create_con(int,string);
};
