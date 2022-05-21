#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;

class Manager
{
private:
    map<int, string> filelist;       //firstedit-name
public:
    Manager();      //initialize through list.txt
    ~Manager(){}
    void newdiary();   //instance diary
    void editdiary(int fname);    //instance diary
    void savediary(int fname);    //when close a diary, update filelist
    void deletediary(int fname);      //update filelist
    void savelist();    //save filelist to list.txt
};

Manager::Manager()
{
    char c[40];
    ifstream inFile("list.txt", ios::in);
    //连续以行为单位，读取 list.txt 文件中的数据
    int fname;
    while (inFile >> fname) {
        inFile >> filelist[fname];
        cout << fname << ' ' << filelist[fname] << endl;
        //Manage.filelist 初始化
    }
    inFile.close();
}
void Manager::newdiary()
{
    time_t now = time(0);
    int fname = int(now);
    //call Diary function to save a empty txt file
    filelist[fname] = to_string(fname);
}
void Manager::editdiary(int fname)
{
    //call Diary function to display diary
}
void Manager::savediary(int fname)
{
    //call Diary function to save txt file 
}
void Manager::deletediary(int fname)
{
    map<int, string>::iterator key = filelist.find(fname);
    if(key!=filelist.end())
    {
        filelist.erase(key);
    }
    //call diary to delete file
}
void Manager::savelist()
{
    ofstream listFile;
    listFile.open("list.txt", ios::out);
    listFile.clear();
    
    for (auto &f:filelist)
    {
        listFile << f.first << ' ' << f.second << endl;
    }    
}

int main()
{
    //test
    Manager manager;
    manager.newdiary();
    int del=1653121532;
    manager.deletediary(del);
    manager.savelist();

    cout << "success" << endl;
    return 0;
}