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

Diary::Diary(int fname)
{
    firstedit = fname;
    filename = to_string(firstedit) + ".txt";

    ifstream srcFile;
    srcFile.open("log\\" + filename, ios::in);
    char c[100];
    if (srcFile >> firstedit >> lastedit >> name)
    {
        srcFile.close();
    }
    else
    {
        lastedit = firstedit;
        name = to_string(firstedit);
        srcFile.close();
        ofstream destFile;
        destFile.open("log\\" + filename, ios::out);
        destFile.clear();
        destFile << firstedit << endl;
        destFile << lastedit << endl;
        destFile << name << endl;
        destFile.close();
    }
}
void Diary::display()
{
    ifstream srcFile;
    srcFile.open("log\\" + filename, ios::in);
    char c[100];
    for (size_t i = 0; i < 3; i++)
    {
        srcFile.getline(c, 100);
    }
    while (srcFile.getline(c, 100)) {
        cout << c << endl;
    }
    srcFile.close();
}
void Diary::save()
{
    time_t now = time(0);
    lastedit = int(now);

    ofstream destFile;
    destFile.open("log\\" + filename, ios::out);
    destFile.clear();
    
    destFile << firstedit << endl;
    destFile << lastedit << endl;
    destFile << name << endl;
    
    //根据接口改动
    char c[100];
    while (cin.getline(c, 100)) {
        // cout << c << endl;
        destFile << c << endl;
    }
    destFile.close();
}
void Diary::deletefile()
{
    string delename = "log\\"+ filename;
    if(remove(delename.c_str())==0)
    {
        cout<<"delete success"<<endl;
    }
    else
    {
        cout<<"delete error"<<endl;
    }
}
int Diary::getfirstedit()
{
    return firstedit;
}
int Diary::getlastedit()
{
    return lastedit;
}
string Diary::getname()
{
    return name;
}
void Diary::setname(string str)
{
    name = str;
}

int main()
{
    //test
    int i=1653111266;
    Diary mydiary(i);
    string name;
    cout << "rename" << endl;
    cin >> name;
    mydiary.setname(name);

    cout << "type in something" << endl;
    mydiary.save();
    
    return 0;
}