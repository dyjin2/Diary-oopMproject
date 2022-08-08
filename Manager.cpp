#include "Manager.h"
#include "Diary.h"

string Manager::fname2title(int fname)
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

Manager::Manager()
{
    char c[40];
    ifstream inFile("list.txt", ios::in);
    if (!inFile) {
        exit(-1);
    }
    //连续以行为单位，读取 list.txt 文件中的数据
    int fname;
    while (inFile >> fname) {
        inFile >> filelist[fname];
        //Manage.filelist 初始化
    }
    inFile.close();
}

void Manager::newdiary(string & title)
{
    time_t now = time(0);
    int fname = int(now);
    auto p=filelist.find(fname);
    if (p==filelist.end())
    {
        title = fname2title(fname);
        Diary nd(fname);
        filelist[fname] = title;
    }
    else{
        title="";
    }
}

void Manager::editdiary(const string title,string &content)
{
    int fname = find(title);
    Diary nd(fname);
    nd.display(content);
}

void Manager::savediary(string *title,string *content)  //
{
    int fname = find(*title);
    Diary nd(fname);
    nd.save(content);
}

void Manager::deletediary(string *title)
{
    int fname = find(*title);
    map<int, string>::iterator key = filelist.find(fname);
    if(key!=filelist.end())
    {
        filelist.erase(key);
    }
    Diary nd(fname);
    nd.deletefile();
}

void Manager::savelist()
{
    ofstream listFile;
    listFile.open("list.txt", ios::out);
    if (!listFile) {
        exit(-1);
    }
    listFile.clear();
    for (auto &f:filelist)
    {
        listFile << f.first << ' ' << f.second << endl;
    }    
}

void Manager::getlist()
{
    int count=0;
    for (auto item:filelist)
    {
        count++;
        cout << count << " " << item.first << " " << item.second << endl;
    }
}

int Manager::find(string title)
{
    map<int, string>::iterator iter;
    for ( iter = filelist.begin(); iter != filelist.end(); iter++)
    {
        if (iter->second==title)
        {
            return iter->first;
        }
    }
    return -1;
}

bool Manager::getALLTitles(vector<std::string>&title){
    auto p=filelist.begin();
    if(filelist.empty()){
        return false;
    }
    for(;p!=filelist.end();p++){
        title.push_back(p->second);
    }
    return true;
}
/*
int main()
{
    //test
    Manager manager;
    string title, smt;
    manager.newdiary(title);
    cout << title << endl;
    cin >> smt;
    manager.newdiary(title);
    cout << title << endl;
    cout << "added" << endl;
    cin >> smt;
    manager.deletediary(&title);
    cout << "deleted" << endl;

    manager.getlist();
    manager.savelist();

    cout << "success" << endl;
    return 0;
}
*/