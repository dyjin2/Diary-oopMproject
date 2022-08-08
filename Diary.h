#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Diary
{
private:
    int firstedit;       //creat time, eg.1653109452 = fname
    int lastedit;        //last edit time
    string title;            //eg.2022/06/08/21:05:32
    string content;            //content
    string filename;        //1653109452.txt
    string fname2title(int fname);
public:
    Diary() {}           //no use
    Diary(int fname);     //open exist diary, fname=firstedit
    ~Diary(){}
    int getfirstedit();  //return creat time for sort?
    int getlastedit();  //return last edit time for sort?
    void setname(string str);
    string getname();   //return name for display
    void display(string &content);     //when open
    void save(string *content);   //update lastedit, save all the private info to filename.txt
    void deletefile();
};

#endif