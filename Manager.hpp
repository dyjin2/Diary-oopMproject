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

class User
{
private:
    /* data */
public:
    User(/* args */);
};