#include <string.h>
using namespace std;
class Doctor{
private:
      string name;
      int password;
      Doctor* next;
public:
        Doctor(string, int);
        void show_Doctor();
        void insert(Doctor*&);
        Doctor* move_next();
        ~Doctor();
        string return_name();
        int return_pass();
};
