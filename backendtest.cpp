#include "Manager.h"

int main()
{
    //for test
    Manager manager;
    string title, smt;
    manager.newdiary(title);
    cout << title << endl;
    cin >> smt;
    manager.savediary(&title, &smt);
    manager.newdiary(title);
    cout << title << endl;
    cout << "added" << endl;
    cin >> smt;
    manager.deletediary(&title);
    cout << "deleted" << endl;
    string content;
    manager.editdiary(title, content);
    cout << content;

    manager.getlist();
    manager.savelist();

    cout << "success" << endl;
    return 0;
}