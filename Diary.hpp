#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

class Diary
{
private:
    int firstedit;       //creat time, eg.1653109452
    int lastedit;        //last edit time
    string name;            //set by user, eg.diary1
    string text;            //content
    string filename;        //1653109452.txt
public:
    Diary();           //new diary, firstedit
    Diary(int fname);     //open exist diary, fname=firstedit
    ~Diary(){}
    int getfirstedit();  //return creat time for sort?
    int getlastedit();  //return last edit time for sort?
    void setname(string str);
    string getname();   //return name for display
    void display();     //when open
    void save();   //update lastedit, save all the private info to filename.txt
    void deletefile();
};