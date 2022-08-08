#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent,Manager *manager_)
    : QMainWindow(parent),
      parent(parent),
      manager(manager_)
{
    //创建+按钮，设置边框不显示，并设置字体
    cre=new QPushButton("+",parent);
    cre->setFlat(true);
    cre->setStyleSheet("QPushButton{font:40px;}");
    //QObject::connect(cre,QPushButton::clicked,&);

    //创建-按钮，设置边框不显示，并设置字体
    del=new QPushButton("-",parent);
    del->setStyleSheet("QPushBUtton{font:40px;}");
    del->setFlat(true);

    //创建保存按钮
    save=new QPushButton("save",parent);
    save->setStyleSheet("QPushBUtton{font:40px;}");
    save->setFlat(true);

    //QObject::connect(del,QPushButton::clicked,&);

    //日记列表相关属性
    //初始化的时候需要将map里面的日记全部添加到这里
    cata=new QListWidget();
    cata->setFont(QFont("宋体",14));
    vector<std::string>title;
    if(manager->getALLTitles(title)){
        for(vector<std::string>::iterator t=title.begin();t<title.end();t++){
            cata->addItem(QString::fromStdString(*t));
        }
    }

    //文本编辑框
    text=new QPlainTextEdit();//将文本框放在窗口内，使用窗口来布局

    //布局控件
    hlayout=new QHBoxLayout;//水平布局新建和删除按钮
    hlayout->addWidget(cre,1);
    hlayout->addWidget(del,1);
    hlayout->addWidget(save,1);

    vlayout=new QVBoxLayout;
    vlayout->addLayout(hlayout,1);
    vlayout->addWidget(cata,3);

    layout=new QHBoxLayout;
    layout->addLayout(vlayout,1);
    layout->addWidget(text,4);

    parent->setLayout(layout);
}

MainWindow::~MainWindow(){
    close();
    manager->savelist();
    delete manager;
    delete cre;
    delete del;
    delete save;
    delete cata;
    delete text;
    delete hlayout;
    delete vlayout;
    delete layout;
}

void MainWindow::new_diary(){

    //默认日记没有标题，以日记创建的时间为标题，后续可以考虑实现日记命名功能,或许可以用qt提供的item实现

    //管理员实例化一个日记类，并将日记名字的指针传回来
    std::string title="";
    manager->newdiary(title);
    if(title!=""){
        QString Qtitle=QString::fromStdString(title);
        cata->addItem(Qtitle);
        //默认选中新建项
        int row=cata->count();
        cata->setCurrentRow(row-1);
        text->setPlainText("");
    }
}

void MainWindow::delete_diary(){
    //找到当前选中的日记,如果没选中返回null
    QListWidgetItem *item=cata->currentItem();
    if(item!=nullptr){
        //获得日记的标题并转化成C++提供的字符串
        QString Qtitle=item->text();
        std::string title=Qtitle.toStdString();
        //将日记的标题传回字符串并使管理员删除日记
        manager->deletediary(&title);
        //将该日记对应的item从list中删除
        cata->removeItemWidget(item);
        delete item;
        //将text中的内容清空
        text->setPlainText("");
    }
}


void MainWindow::dispaly_content(){
    //找到当前选中的日记,如果没选中返回null
    QListWidgetItem *item=cata->currentItem();
    if(item!=nullptr){
        //将日记的标题传递给管理员，管理员返回日记的内容
        std::string content="";
        manager->editdiary(item->text().toStdString(),content);
        if(content==""){
            //如果日记没有内容，显示空字符串
            text->setPlainText("");
        }else{
            //否则显示字符串内容
            QString Qcontent=QString::fromStdString(content);
            text->setPlainText(Qcontent);
        }
    }
}


void MainWindow::save_content(){
    //找到当前正在编辑的日记
    QListWidgetItem *item=cata->currentItem();
    //获取目前text的内容并转化为C++string类
    QString Qcontent=text->toPlainText();
    std::string content=Qcontent.toStdString();//这里可能会出现安全性问题，当text内容是空的时候这里可能会报错
    //获取当前日记的标题
    QString Qtitle=item->text();
    std::string title=Qtitle.toStdString();//这里可能会出现安全性问题，当text内容是空的时候这里可能会报错
    //将日记的标题和内容传给管理员，管理员将日记的内容写入磁盘中
    manager->savediary(&title,&content);

}


void MainWindow::closeEvent(QCloseEvent *e){
    //窗口关闭时弹出的提示窗口
    QMessageBox msgBox;
    msgBox.setParent(parent);
    msgBox.setWindowFlags(Qt::Dialog);
    msgBox.setWindowTitle("提示");
    msgBox.setText("您的内容未保存，是否保存？");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Ok){
        //若用户点击确认，则接收这个事件,当前窗口会关闭
        QListWidgetItem *item=cata->currentItem();
        QString Qcontent=text->toPlainText();
        std::string content=Qcontent.toStdString();
        QString Qtitle=item->text();
        std::string title=Qtitle.toStdString();
        manager->savediary(&title,&content);
        e->accept();
    }else{
        //若用户点击取消，则忽略这个事件，当前窗口不会关闭
        e->ignore();
    }
}
