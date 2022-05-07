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

class Manager
{
private:
    map<string, string> filelist;       //firstedit-name
public:
    Manager();      //initialize through list.txt
    ~Manager();
    void creatdiary();   //instance diary
    void editdiary();    //instance diary
    void savediary();    //when close a diary, update filelist
    void deletediary();      //update filelist
    void savelist();    //save filelist to list.txt
};

class User
{
private:
    /* data */
public:
    User(/* args */);
};