#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include "Diary.hpp"
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
    void getlist();
};

Manager::Manager()
{
    char c[40];
    ifstream inFile("list.txt", ios::in);
    //连续以行为单位，读取 list.txt 文件中的数据
    int fname;
    while (inFile >> fname) {
        inFile >> filelist[fname];
        // cout << fname << ' ' << filelist[fname] << endl;
        //Manage.filelist 初始化
    }
    inFile.close();
}
void Manager::newdiary()
{
    time_t now = time(0);
    int fname = int(now);
    Diary nd(fname);
    filelist[fname] = to_string(fname);
}
void Manager::editdiary(int fname)
{
    Diary nd(fname);
    nd.display();
}
void Manager::savediary(int fname)
{
    Diary nd(fname);
    nd.save();
}
void Manager::deletediary(int fname)
{
    map<int, string>::iterator key = filelist.find(fname);
    if(key!=filelist.end())
    {
        filelist.erase(key);
    }
    Diary nd(fname);
    nd.deletefile();
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
void Manager::getlist()
{
    int count=0;
    for (auto item:filelist)
    {
        count++;
        cout << count << " " << item.first << " " << item.second << endl;
    }
    
}

int main()
{
    //test
    Manager manager;
    // manager.newdiary();
    // int del=1653121532;
    // manager.deletediary(del);
    // manager.savelist();
    manager.getlist();

    cout << "success" << endl;
    return 0;
}