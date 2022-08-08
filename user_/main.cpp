#include "mainwindow.h"
#include <QApplication>
#include <direct.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Manager manager;

    QWidget widget;
    widget.setWindowTitle("We Diary");
    widget.resize(1920,1080);

    MainWindow window(&widget,&manager);
    //connect函数应该写在主函数里，不能写在类中，但槽函数和信号函数应该写在类里面
    //将新建按钮和对应的槽函数连接
    QObject::connect(window.getButton_create(),&QPushButton::clicked,&window,&MainWindow::new_diary);
    //将删除按钮和对应的槽函数连接
    QObject::connect(window.getButton_delete(),&QPushButton::clicked,&window,&MainWindow::delete_diary);
    //选中日记后和对应的显示日记内容的槽函数连接
    QObject::connect(window.getList(),&QListWidget::itemDoubleClicked,&window,&MainWindow::dispaly_content);
    //将保存按钮和对应的槽函数连接
    //QObject::connect(window.getList(),&QListWidget::itemSelectionChanged,&window,&MainWindow::save_content);
    QObject::connect(window.getButton_save(),&QPushButton::clicked,&window,&MainWindow::save_content);

    widget.show();
    return a.exec();
}
