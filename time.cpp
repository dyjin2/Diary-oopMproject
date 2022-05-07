#include <iostream>
#include <ctime>
 
using namespace std;
 
int main()
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
 
   cout << "since 1970: " << now << endl;
 
   tm *ltm = localtime(&now);
 
   // 输出 tm 结构的各个组成部分
   cout << "year: "<< 1900 + ltm->tm_year << endl;
   cout << "month: "<< 1 + ltm->tm_mon<< endl;
   cout << "day: "<<  ltm->tm_mday << endl;
   cout << "time: "<< ltm->tm_hour << ":";
   cout << ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}