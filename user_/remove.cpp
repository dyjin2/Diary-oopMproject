#include <iostream>
// #include <stdio.h>
// #include <string.h>
#include <string>
 
using namespace std;
 
int main()
{
    string savePath = "log\\";
    string fix = ".txt";
    string fl = "a";
    
    savePath+=fl;
    savePath+=fix;

    cout << savePath <<endl;
    cout << savePath.c_str() <<endl;
 
    if(remove(savePath.c_str())==0)
    {
        cout<<"delete success"<<endl;
    }
    else
    {
        cout<<"delete error"<<endl;
    }
    
    return 0;
}
