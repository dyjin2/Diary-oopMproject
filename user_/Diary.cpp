#include "Diary.hpp"

string Diary::fname2title(int fname)
{
   time_t now = fname;
   tm *ltm = localtime(&now);

   string y = to_string(1900 + ltm->tm_year);
   string m = to_string(1 + ltm->tm_mon);
   string d = to_string(ltm->tm_mday);
   string h = to_string(ltm->tm_hour);
   string min = to_string(ltm->tm_min);
   string sec = to_string(ltm->tm_sec);
   string ntime = y+'/';
   if (ltm->tm_mon<9)
   {
      ntime+='0';
   }
   ntime+=m+'/';
   if (ltm->tm_mday<10)
   {
      ntime+='0';
   }
   ntime+=d+'/';
   if (ltm->tm_hour<10)
   {
      ntime+='0';
   }
   ntime+=h+':';
   if (ltm->tm_min<10)
   {
      ntime+='0';
   }
   ntime+=min+':';
   if (ltm->tm_sec<10)
   {
      ntime+='0';
   }
   ntime+=sec;
   return ntime;
}

Diary::Diary(int fname)
{
    firstedit = fname;
    filename = to_string(firstedit) + ".txt";

    ifstream srcFile;
    srcFile.open("log\\" + filename, ios::in);
    if (srcFile >> firstedit >> lastedit >> title)
    {
        srcFile.close();
    }
    else
    {
        lastedit = firstedit;
        title = fname2title(firstedit);
        srcFile.close();
        ofstream destFile;
        destFile.open("log\\" + filename, ios::out);
        destFile.clear();
        destFile << firstedit << endl;
        destFile << lastedit << endl;
        destFile << title << endl;
        destFile.close();
    }
}

void Diary::display(string &content)
{
    ifstream srcFile;
    srcFile.open("log\\" + filename, ios::in);
    char c[100];
    string str = "";
    for (size_t i = 0; i < 3; i++)
    {
        srcFile.getline(c, 100);
    }
    while (srcFile.getline(c, 100)) {
        str += string(c);
        str += '\n';
    }
    srcFile.close();
    content = str;
}

void Diary::save(string *content)
{
    time_t now = time(0);
    lastedit = int(now);

    ofstream destFile;
    destFile.open("log\\" + filename, ios::out);
    destFile.clear();

    destFile << firstedit << endl;
    destFile << lastedit << endl;
    destFile << title << endl;

    destFile << *content << endl;   //content

    destFile.close();
}

void Diary::deletefile()
{
    string delename = "log\\"+ filename;
    if(remove(delename.c_str())==0)
    {
        cout<<"delete success"<<endl;
    }
    else
    {
        cout<<"delete error"<<endl;
    }
}

int Diary::getfirstedit()
{
    return firstedit;
}

int Diary::getlastedit()
{
    return lastedit;
}

string Diary::getname()
{
    return title;
}

void Diary::setname(string str)
{
    title = str;
}
/*
int main()
{
    //test
    //1654782607
    int i=1653116125;
    Diary mydiary(i);

    // string *str;
    // string strin = "test\nfsafas\ngfs\njdy";
    // str = &strin;
    // mydiary.save(str);
    string dis;
    mydiary.display(dis);
    cout << dis;

    return 0;
}
*/
