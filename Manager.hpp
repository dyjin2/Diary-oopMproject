#include <string>
#include <vector>
#include <map>
using namespace std;

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