#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include<string>
#include<vector>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyReleaseEvent(QKeyEvent *event);
    void drawMaze(vector<string>&maze);
    void move1(vector<string>&maze,string &s,int &cnt);



private slots:
    void on_startbtn_clicked();

    void on_btn2_clicked();

    void on_pushButton_clicked();
    void step();


    void on_restartbtn_clicked();

    void on_jsonbtn_clicked();

    void on_forbtn_clicked();

    void on_greedbtn_clicked();

    void on_lockbtn_clicked();




    void on_returnbtn_clicked();

    void on_bossbtn_clicked();

    void on_returnbtn2_clicked();

private:
    Ui::MainWindow *ui;
    int cnt;
    string sss;
    bool isdp;

};
#endif // MAINWINDOW_H
