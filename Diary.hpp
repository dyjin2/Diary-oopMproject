#include <string>
#include <vector>
#include <map>
using namespace std;

class Diary
{
private:
    string firstedit;       //creat time, filename=firstedit
    string lastedit;        //last edit time
    string name;            //set by user
    string text;            //diary
public:
    Diary();           //new diary, firstedit
    Diary(string filename);     //open exist diary
    ~Diary();
    string getfirstedit();  //return creat time for sort?
    string getlastedit ();  //return last edit time for sort?
    void setname();
    string getname();   //return name for display
    void display();     //when open
    void receive();    //update text from 输入框
    void save();   //update lastedit, save all the private info to filename.txt
};