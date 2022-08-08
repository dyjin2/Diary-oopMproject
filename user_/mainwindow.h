#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QListWidget>
#include <QLabel>
#include <QListWidgetItem>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QStackedLayout>
#include <string>
#include <QString>
#include <QListWidgetItem>
#include<QMessageBox>
#include<QCloseEvent>
#include "Manager.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,Manager *manager=nullptr);

    ~MainWindow();

    QPushButton* getButton_create(){return cre;}

    QPushButton* getButton_delete(){return del;}

    QPushButton* getButton_save(){return save;}

    QListWidget* getList(){return cata;}

    void closeEvent(QCloseEvent *e);//重载closeEvent函数

public slots:

    //新建一个日记的槽函数
    void new_diary();

    //删除一个日记的槽函数
    void delete_diary();

    //选中一个日记显示日记内容的槽函数
    void dispaly_content();

    //保存日记的内容
    void save_content();

private:
    QWidget *parent;
    Manager *manager;      //日记内容的管理员
    QPushButton *cre;
    QPushButton *del;
    QPushButton *save;
    QListWidget *cata;
    QPlainTextEdit *text;
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QHBoxLayout *layout;
};

#endif // MAINWINDOW_H
