#include <string>
#include <iostream>
#include <fstream>
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

Manager::Manager()
{
    char c[40];
    ifstream inFile("list.txt", ios::in | ios::binary);
    //连续以行为单位，读取 list.txt 文件中的数据
    while (inFile.getline(c, 40)) {
        cout << c << endl;
        //Manage.filelist 初始化
    }
    inFile.close();
}