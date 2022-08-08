#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <vector>
using namespace std;

class Manager
{
private:
    map<int, string> filelist;       //fname-title
    string fname2title(int fname);
public:
    Manager();      //initialize through list.txt
    ~Manager(){}
    void newdiary(string & title);   //instance diary
    void editdiary(const string title,string &content);    //instance diary
    void savediary(string *title,string *content);    //when close a diary, update filelist
    void deletediary(string *title);      //update filelist
    void savelist();    //save filelist to list.txt
    void getlist();
    int find(string title);
    bool getALLTitles(vector<std::string>&title);
};

#endif
