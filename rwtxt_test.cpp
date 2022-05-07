#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char c[100];
    fstream destFile;
    destFile.open("tmp\\diary.txt", ios::out);
    if (!destFile) {
        cout << "error opening destination file." << endl;
        return 0;
    }
    //连续以行为单位，读取 commandline 中的数据
    while (cin.getline(c, 100)) {
        // cout << c << endl;
        destFile << c << endl;
    }
    destFile.close();
    
    return 0;
}