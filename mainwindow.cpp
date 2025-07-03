#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include <QLabel>
#include <QPixmap>
#include<QMovie>
#include<QSpinBox>
#include<iostream>
#include<QGridLayout>
#include<string>
#include<QDebug>
#include<vector>
#include<QMessageBox>
#include <QVBoxLayout>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>
#include <QFile>
#include<QFileDialog>
#include <QTimer>
#include <QThread>
#include<QDebug>
using namespace std;
const int SIZE=50;
int n=0;
int value = 0;//资源记录
bool isend=false;
int np=0;
int tanxin=0;
int bnp=0;
vector<string>maze1,maze2;
QLabel* labellist[1000][1000];
extern int validCount;
extern vector<string> init_map(int seed);
extern string judge(vector<string>&mp);
extern vector<int>order;
extern vector<vector<int>>validPasswords;
extern vector<int>b;
vector<int>boss1;
vector<int>cd;
extern vector<pair<int,int>>skills;
string resultt;
int j=0;
int num=0;
extern string greed(vector<string>& maze);
extern vector<vector<int>> lock(string& input, string& userPassword);
extern vector<int> BOSS_PK(string &b,string&s);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    isdp=false;

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QMovie *movie = new QMovie(":/n/doro.gif");
    QLabel *label=ui->label1;
    label->setScaledContents(true);
     label->setMovie(movie); // 1. 设置要显示的 GIF 动画图片
     movie->start();         // 2. 启动动画
        cnt=0;
        sss="";
     QPixmap trap ;
         trap.load(":/title2.png");
         ui->label3->setPixmap(trap);
         ui->label3->setScaledContents(true);//自适应大小
        ui->label3->setStyleSheet("color: red; background-color: transparent;");

        QPixmap map;
        map.load(":/ne/think.gif");
        ui->maplab->setPixmap(map);
        ui->maplab->setScaledContents(true);//自适应大小
        QPixmap dmap;
        dmap.load(":/fight.jpg");
        ui->dlab->setPixmap(dmap);
        ui->dlab->setScaledContents(true);//自适应大小
        ui->lab1->setStyleSheet("color: black; background-color: transparent;");
        ui->lab2->setStyleSheet("color: black; background-color: transparent;");
        ui->lab3->setStyleSheet("color: black; background-color: transparent;");
        ui->lab4->setStyleSheet("color: black; background-color: transparent;");
        ui->lab5->setStyleSheet("color: black; background-color: transparent;");
        ui->ilab->setStyleSheet("color: black; background-color: transparent;");
        ui->bloodlab->setStyleSheet("color: black; background-color: transparent;");
        ui->bnlab->setStyleSheet("color: black; background-color: transparent;");
        ui->vslab->setStyleSheet("color: black; background-color: transparent;");
        QPixmap bmap;
        bmap.load(":/ne/boss.jpg");
        ui->blab->setPixmap(bmap);
        ui->blab->setScaledContents(true);//自适应大小
        QPixmap vsmap;
        vsmap.load(":/n/vs.png");
        ui->vslab->setPixmap(vsmap);
        ui->vslab->setScaledContents(true);//自适应大小
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
       this->close();
    }

}



void showCustomMessageBox(QWidget *parent)//最后一步提示框函数
{
    // 创建自定义对话框
    QDialog dialog(parent);
    dialog.setWindowTitle("doro提醒你");
    dialog.setMinimumWidth(300);

    // 创建主布局
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // 添加文本标签
    QLabel *textLabel = new QLabel("doro已经到终点了", &dialog);
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setStyleSheet("color: black;");
    textLabel->setWordWrap(true);
    layout->addWidget(textLabel);

    // 添加图片标签
    QLabel *imageLabel = new QLabel(&dialog);
    QPixmap pixmap(":/n/happy.jpg");

    if (pixmap.isNull()) {
        imageLabel->setText("图片加载失败");
        imageLabel->setAlignment(Qt::AlignCenter);
    } else {
        imageLabel->setPixmap(pixmap.scaled(
            200, 200,                 // 调整图片大小
            Qt::KeepAspectRatio,      // 保持宽高比
            Qt::SmoothTransformation  // 平滑缩放
        ));
        imageLabel->setAlignment(Qt::AlignCenter);
    }

    layout->addWidget(imageLabel);

    // 添加确认按钮
    QPushButton *okButton = new QPushButton("确定", &dialog);
    layout->addWidget(okButton);
    QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    // 显示对话框
    dialog.exec();
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startbtn_clicked()
{
    QMovie *movie2 = new QMovie(":/ne/think.gif");
    QLabel *label2=ui->label2;
    label2->setScaledContents(true);
     label2->setMovie(movie2); // 1. 设置要显示的 GIF 动画图片
     movie2->start();         // 2. 启动动画

    ui->stackedWidget->setCurrentIndex(1);
    ui->spinBox->setRange(0, 1000);
    ui->spinBox->setSingleStep(5);      // 设置每次增减的步长（默认值为1）
    ui->spinBox->setValue(50);


}
void MainWindow::drawMaze(vector<string>& maze)
{

    n=maze.size();
    int line=0,row=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(maze[i][j]=='#')
            {
                QLabel *label;
                label = new QLabel("");

                label->setParent(ui->mazepage);
                label->setFixedSize(SIZE, SIZE);
                label->setObjectName("blackLabel");//黑色
                label->move(line,row);
                labellist[i][j]=label;
                row+=SIZE;
            }
            else if(maze[i][j]==' ')
            {
                QLabel *label;
                label = new QLabel("");
                label->setParent(ui->mazepage);
                label->setFixedSize(SIZE, SIZE);
                label->setObjectName("whiteLabel");//白色
                label->move(line,row);
                labellist[i][j]=label;
                row+=SIZE;
            }
            //陷阱
            else if(maze[i][j]=='T')
            {
                QPixmap trap ;
                QLabel *label;
                    trap.load("://trap.png");
                    label = new QLabel(ui->mazepage);
                    label->setPixmap(trap);
                    label->setScaledContents(true);//自适应大小
                    label->resize(SIZE,SIZE);
                    label->move(line,row);
                    labellist[i][j]=label;
                    row+=SIZE;
            }
            else if(maze[i][j]=='L')
            {
                QPixmap trap ;
                QLabel *label;
                    trap.load(":/ne/lock.png");
                    label = new QLabel(ui->mazepage);
                    label->setPixmap(trap);
                    label->setScaledContents(true);//自适应大小
                    label->resize(SIZE,SIZE);
                    label->move(line,row);
                    labellist[i][j]=label;
                    row+=SIZE;
            }
            else if(maze[i][j]=='B')
            {
                QPixmap trap ;
                QLabel *label;
                    trap.load(":/ne/boss.jpg");
                    label = new QLabel(ui->mazepage);
                    label->setPixmap(trap);
                    label->setScaledContents(true);//自适应大小
                    label->resize(SIZE,SIZE);
                    label->move(line,row);
                   labellist[i][j]=label;
                    row+=SIZE;
            }
            else if(maze[i][j]=='G')
            {
                QPixmap trap ;
                QLabel *label;
                    trap.load(":/ne/coin.jpg");
                    label = new QLabel(ui->mazepage);
                    label->setPixmap(trap);
                    label->setScaledContents(true);//自适应大小
                    label->resize(SIZE,SIZE);
                    label->move(line,row);
                    labellist[i][j]=label;
                    row+=SIZE;
            }
           else if(maze[i][j]=='E')
            {
                QPixmap trap ;
                QLabel *label;
                    trap.load(":/ne/flag.png");
                    label = new QLabel(ui->mazepage);
                    label->setPixmap(trap);
                    label->setScaledContents(true);//自适应大小
                    label->resize(SIZE,SIZE);
                    label->move(line,row);
                    labellist[i][j]=label;
                    row+=SIZE;
            }
            else if(maze[i][j]=='S')
             {
                 QPixmap trap ;
                 QLabel *label;
                     trap.load(":/ne/character.jpg");
                     label = new QLabel(ui->mazepage);
                     label->setPixmap(trap);
                     label->setScaledContents(true);//自适应大小
                     label->resize(SIZE,SIZE);
                     label->move(line,row);
                     labellist[i][j]=label;
                     row+=SIZE;
             }

        }
        line+=SIZE;
        row=0;
    }

}
void MainWindow::on_btn2_clicked()
{
    vector<string>maze;
    sss.clear();
    int value = ui->spinBox->value();   // 获取当前整数值
    while(sss.empty()){
        value += time(0);
        maze = init_map(value);
        sss=judge(maze);
    }
    for(int i=0;i<maze.size();i++)
    {
        maze1.push_back(maze[i]);
        maze2.push_back(maze[i]);
    }
    drawMaze(maze1);
    //s=dp(maze1);//求路径
    std::cout<<"dplujing"<<sss<<endl;
    for(int i=0;i<maze1.size();i++)
    {
        for(int j=0;j<maze1.size();j++)
        {
            cout<<maze1[i][j];
        }
        cout<<endl;
    }

    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::step()
{
    cout<<"come in"<<endl;
    if(cnt<sss.size())
    {

        pair<int, int>now;

            for (int i = 0; i < maze1.size(); i++)
            {
                for (int j = 0; j < maze1[i].size(); j++)
                {
                    if (maze1[i][j] == 'S')now.first = i, now.second = j;
                }
            }
                maze1[now.first][now.second] = ' ';

                labellist[now.first][now.second]->clear();
                labellist[now.first][now.second]->setObjectName("whiteLabel");

                if (sss[cnt] == 'R')now.second++;
                else if (sss[cnt] == 'L')now.second--;
                else if (sss[cnt] == 'D')now.first++;
                else now.first--;
                if (maze1[now.first][now.second] == 'G')
                {
                 value += 50;
                QString str;
                str=QString::number(value);
                QString strr="当前资源为："+str;
                ui->ziyuanlab->setText(strr);
                }

                else if (maze1[now.first][now.second] == 'T')
                {

                    value -= 30;
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);
                }
                else if(maze1[now.first][now.second] == 'B')
                {
                    value-=order.size();
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);
                }
                else if(maze1[now.first][now.second] == 'L')
                {
                    value-=validCount;
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);
                }
                    maze1[now.first][now.second] = 'S';

                QPixmap trap ;
                trap.load(":/ne/character.jpg");
                labellist[now.first][now.second]->setPixmap(trap);
                labellist[now.first][now.second]->setScaledContents(true);


        cnt++;
        cout<<"come out"<<endl;
    }
    else
    {
        isend=true;
        showCustomMessageBox(this);

        cout<<"more"<<endl;
    }

}
void MainWindow::on_pushButton_clicked()
{
    isdp=true;
    if(cnt<sss.size())
    {

        pair<int, int>now;

            for (int i = 0; i < maze1.size(); i++)
            {
                for (int j = 0; j < maze1[i].size(); j++)
                {
                    if (maze1[i][j] == 'S')now.first = i, now.second = j;
                }
            }
                maze1[now.first][now.second] = ' ';

                labellist[now.first][now.second]->clear();
                labellist[now.first][now.second]->setObjectName("whiteLabel");

                if (sss[cnt] == 'R')now.second++;
                else if (sss[cnt] == 'L')now.second--;
                else if (sss[cnt] == 'D')now.first++;
                else now.first--;
                if (maze1[now.first][now.second] == 'G')
                {
                 value += 50;
                QString str;
                str=QString::number(value);
                QString strr="当前资源为："+str;
                ui->ziyuanlab->setText(strr);
                }

                else if (maze1[now.first][now.second] == 'T')
                {

                    value -= 30;
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);
                }
                else if(maze1[now.first][now.second] == 'B')
                {
                    value-=order.size();
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);
                    //进入boss
                    ui->stackedWidget->setCurrentIndex(4);


                }
                else if(maze1[now.first][now.second] == 'L')
                {
                    value-=validCount;
                    QString str;
                    str=QString::number(value);
                    QString strr="当前资源为："+str;
                    ui->ziyuanlab->setText(strr);

                    //进入锁
                    ui->stackedWidget->setCurrentIndex(3);

                }
                    maze1[now.first][now.second] = 'S';

                QPixmap trap ;
                trap.load(":/ne/character.jpg");
                labellist[now.first][now.second]->setPixmap(trap);
                labellist[now.first][now.second]->setScaledContents(true);


        cnt++;

    }
    else
    {
        isend=true;
        showCustomMessageBox(this);


    }

}

void MainWindow::on_restartbtn_clicked()
{
    if(isend==false)
    {
        QMessageBox::information(this, "提示", "您还未结束当前游戏");
    }
    else
    {
       std::string().swap(sss);

        value=0;
        cnt=0;
        for(int i=0;i<maze1.size();i++)
        {
            for(int j=0;j<maze1.size();j++)
            {
                delete labellist[i][j];
                labellist[i][j]=nullptr;
            }

        }
        maze1.clear();
        ui->ziyuanlab->setText("当前资源为：0");
        isend=false;
                n=0;
                np=0;
                validCount=0;
                tanxin=0;
                order.clear();
                validPasswords.clear();
                resultt.clear();
                bnp=0;
                isdp=false;
                sss.clear();
                b.clear();
                skills.clear();
                boss1.clear();
                cd.clear();
                j=0;
                num=0;

        ui->stackedWidget->setCurrentIndex(0);
    }
}





void MainWindow::on_jsonbtn_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"选择json文件","", "JSON文件 (*.json);;所有文件 (*)");
        qDebug() << file_name;
        QFile file(file_name);
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "can't open error!";
            return;
        }

        // 读取文件的全部内容
        QByteArray data = file.readAll();
         file.close();

            QJsonParseError parseError;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);

            if (parseError.error != QJsonParseError::NoError)
            {
                qDebug() << "JSON解析错误:" << parseError.errorString();
                return;
            }

            // 检查根元素是否为对象
            if (!jsonDoc.isObject()) {
                qDebug() << "JSON根元素不是对象";
               return;
            }

            QJsonObject rootObj = jsonDoc.object();

            // 检查是否包含"maze"字段
            if (!rootObj.contains("maze")) {
                qDebug() << "JSON对象不包含'maze'字段";
                return;
            }

            // 获取"maze"字段的值
            QJsonValue mazeValue = rootObj.value("maze");

            // 检查"maze"是否为数组
            if (!mazeValue.isArray()) {
                qDebug() << "'maze'字段不是数组";
               return;
            }

            QJsonArray mazeArray = mazeValue.toArray();
            maze1.clear();

            // 遍历外层数组（行）
            for (const auto& rowValue : mazeArray)
            {
                if (!rowValue.isArray())
                {
                    qDebug() << "maze的元素不是数组";
                    return;
                }

                QJsonArray rowArray = rowValue.toArray();
                std::string rowStr;

                // 遍历内层数组（列）
                for (const auto& cellValue : rowArray)
                {
                    // 将JSON值转换为char并添加到行字符串
                    if (cellValue.isString())
                    {
                        QString str = cellValue.toString();
                        if (!str.isEmpty())
                        {
                            // 取第一个字符
                            rowStr += str.at(0).toLatin1();
                        } else
                        {
                            rowStr += '\0'; // 空字符串处理
                        }
                    } else
                    {
                        qDebug() << "单元格值不是字符串类型";

                    }
                }

                maze1.push_back(rowStr);
            }
            //读入C
            QJsonDocument doc = QJsonDocument::fromJson(data);
                if (doc.isNull() || !doc.isObject()) {
                    qDebug() << "JSON解析失败";
                    return;
                }
            QJsonObject obj = doc.object();
                if (!obj.contains("C") || !obj["C"].isArray()) {
                    qDebug() << "未找到有效的c数组";
                    return;
                }

                QJsonArray arrayC = obj["C"].toArray();
                    string result = "[";

                    // 遍历外层数组
                    for (int i = 0; i < arrayC.size(); ++i) {
                        if (!arrayC[i].isArray()) continue;

                        QJsonArray innerArray = arrayC[i].toArray();
                        result += "[";

                        // 遍历内层数组
                        for (int j = 0; j < innerArray.size(); ++j) {
                            result += std::to_string(innerArray[j].toInt());
                            if (j < innerArray.size() - 1) {
                                result += ",";
                            }
                        }

                        result += "]";
                        if (i < arrayC.size() - 1) {
                            result += ",";
                        }
                    }
                    result += "]";
                    resultt=result;



                    cout<<result<<endl;
                    cout<<resultt<<endl;


                    //读入L
            if (!rootObj.contains("L") || !rootObj["L"].isString()) {
                    std::cerr << "未找到有效的L字符串" << std::endl;
                    return;
                }

                QString qtStringL = rootObj["L"].toString();
                string stringL = qtStringL.toStdString();

                cout<<stringL;
                //读入B


                QJsonDocument docu = QJsonDocument::fromJson(data);
                    if (docu.isNull() || !docu.isObject()) {
                        std::cerr << "JSON解析失" << std::endl;
                        return;
                    }

                    QJsonObject objj = docu.object();

                if (!objj.contains("B") || !objj["B"].isArray()) {
                        std::cerr << "未找到有效的数组B" << std::endl;
                        return;
                    }

                    QJsonArray arrayB = objj["B"].toArray();
                    string resu = "[";

                    // 遍历数组元素
                    for (int i = 0; i < arrayB.size(); ++i) {
                            QJsonValue value = arrayB[i];

                            // 检查是否为整数（整数在JSON中以double形式存储）
                            if (value.isDouble()) {
                                // 转换为整数（截断小数部分）
                                int intValue = static_cast<int>(value.toDouble());
                                resu += std::to_string(intValue);
                            } else {
                                // 非整数类型给出警告并跳过
                                std::cerr << "警告: 数组B的元素" << i << "不是整数类型，已跳过" << std::endl;
                                continue;
                            }

                        // 添加逗号（最后一个元素除外）
                        if (i < arrayB.size() - 1) {
                            resu += ",";
                        }
                    }

                    resu += "]";
                cout << "数组B转换后的字符串: " << resu << endl;

                //读入PlayerSkills



    // 解析JSON
    QJsonDocument docum = QJsonDocument::fromJson(data);
    if (docum.isNull() || !docum.isObject()) {
        std::cerr << "JSON解析cuo" << std::endl;
        return;
    }

    QJsonObject objjj = docum.object();

    // 读取PlayerSkills数组
    if (!objjj.contains("PlayerSkills") || !objjj["PlayerSkills"].isArray()) {
        std::cerr << "未找到有效的PlayerSkills数组" << std::endl;
        return;
    }

    QJsonArray playerSkillsArray = objjj["PlayerSkills"].toArray();
    std::string re = "[";

    // 遍历外层数组
    for (int i = 0; i < playerSkillsArray.size(); ++i) {
        if (!playerSkillsArray[i].isArray()) {
            std::cerr << "警告: PlayerSkills的元素" << i << "不是数组类型，已跳过" << std::endl;
            continue;
        }

        QJsonArray innerArray = playerSkillsArray[i].toArray();
        re += "[";

        // 遍历内层数组（确保每个元素都是整数）
        for (int j = 0; j < innerArray.size(); ++j) {
            QJsonValue value = innerArray[j];

            if (value.isDouble()) {
                // 转换为整数并添加到结果
                int intValue = static_cast<int>(value.toDouble());
                re += std::to_string(intValue);
            } else {
                std::cerr << "警告: PlayerSkills的元素[" << i << "][" << j
                          << "]不是整数类型，已跳过" << std::endl;
                re += "0"; // 默认填充0或跳过该元素
            }

            // 添加内层元素分隔符
            if (j < innerArray.size() - 1) {
                re += ",";
            }
        }

        re += "]";

        // 添加外层元素分隔符
        if (i < playerSkillsArray.size() - 1) {
            re += ",";
        }
    }

    re += "]";

    // 输出结果
    std::cout << "PlayerSkills转换后的字符串: " << re << std::endl;




            //处理数据
           validPasswords=lock(resultt,stringL);
            drawMaze(maze1);


            order=BOSS_PK(resu,re);

            sss.clear();
            for(string ms:maze1)
            {
                cout<<ms<<endl;
            }
            cout<<"sss为："<<sss<<endl;
            cout<<"new sss"<<endl;
            cnt=0;
            sss=judge(maze1);
            cout<<"数据json"<<sss<<endl;

            ui->stackedWidget->setCurrentIndex(2);


      }

void MainWindow::on_forbtn_clicked()
{
    isdp=true;
    ui->greedbtn->setEnabled(false);
    QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            // 循环逻辑

            step();
            if (cnt >=sss.size()) {
                timer->stop();
                timer->deleteLater();
                ui->greedbtn->setEnabled(true);
                return;
            }


        });

        timer->start(200);  // 每0.2秒触发一次
}




void MainWindow::on_greedbtn_clicked()
{

    if(isdp==true)
    {
        QMessageBox::information(this, "提示", "您已选择其他路线");
    }
    else
    {
        std::string().swap(sss);
        if(tanxin==0)
        {
            tanxin++;
            cout<<"greed"<<endl;


            for(int i=0;i<maze1.size();i++)cout<<maze1[i]<<endl;
             //sss进行贪新路线接收
            sss=greed(maze1);
                cout<<"tanxin"<<sss<<endl;
                ui->pushButton->setEnabled(false);
                ui->forbtn->setEnabled(false);
                ui->greedbtn->setEnabled(false);
                QTimer* timer = new QTimer(this);
                    connect(timer, &QTimer::timeout, [=]() {
                        // 循环逻辑

                        step();
                        if (cnt >=sss.size()) {
                            timer->stop();
                            timer->deleteLater();
                            ui->pushButton->setEnabled(true);
                            ui->forbtn->setEnabled(true);
                            ui->greedbtn->setEnabled(true);
                            return;
                        }


                    });

                    timer->start(200);  // 每0.2秒触发一次
        }
          else
            {
                ;
            }


    }


}
int i = 0;

void MainWindow::on_lockbtn_clicked()
{

    if(np!=0)
    {
        QMessageBox::information(this, "提示", "已成功解密");

    }
    else
    {
        np++;
        i=0;
        cout<<"validCount "<<validCount<<endl;
        cout<<validPasswords.size()<<endl;
        QTimer* timer = new QTimer(this);
            connect(timer, &QTimer::timeout, [=]() {
                // 循环逻辑
                vector<int> a=validPasswords[i++];
                ui->flabel->setText(QString::number(a[0]));
                ui->slabel->setText(QString::number(a[1]));
                ui->tlabel->setText(QString::number(a[2]));

                if(i>validCount)
                {
                    QPixmap map;
                    map.load(":/n/happy.jpg");
                    ui->maplab->setPixmap(map);
                    ui->maplab->setScaledContents(true);//自适应大小
                    timer->stop();
                    timer->deleteLater();
                    return;
                }
                else
                {
                    QPixmap map;
                    map.load(":/cry.jpg");
                    ui->maplab->setPixmap(map);
                    ui->maplab->setScaledContents(true);//自适应大小
                }
            });

            timer->start(20);  // 每0.02秒触发一次

    }

}




void MainWindow::on_returnbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->flabel->clear();
    ui->slabel->clear();
    ui->tlabel->clear();
    QPixmap map;
    map.load(":/ne/think.gif");
    ui->maplab->setPixmap(map);
    ui->maplab->setScaledContents(true);
}







void MainWindow::on_bossbtn_clicked()
{

//first伤害，second冷却
if(bnp==0)
{

     bnp++;
    ui->bossbtn->setEnabled(false);
    cout<<0<<endl;
    ui->lab1->clear();
    ui->lab2->clear();
    ui->lab3->clear();
    ui->lab4->clear();
    ui->lab5->clear();
    ui->bloodlab->clear();
    ui->bnlab->clear();
    ui->ilab->clear();
    ui->bnlab->setText("boos总数:"+QString::number(b.size()));


    for(int i=0;i<skills.size();i++)
        cd.push_back(0);//动态cd
    for(int i=0;i<b.size();i++)
        boss1.push_back(b[i]);//boss当前血量

    j=0;
    QTimer* timer = new QTimer(this);
    cout<<1<<endl;
    cout<<skills.size();
        connect(timer, &QTimer::timeout, [=]() {

             //循环逻辑
            ui->ilab->setText("当前回合:"+QString::number(j+1));
            QString boosstr;
            QStringList cdstr;
            QLabel* list[5]={ui->lab1,ui->lab2,ui->lab3,ui->lab4,ui->lab5};
            cout<<2<<endl;
            for(int i=0;i<b.size();i++)
            {
                cout<<3<<endl;
                cout<<boss1[i]<<"/"<<b[i]<<endl;//
                boosstr+="boss"+QString::number(i+1)+":";
                boosstr+=QString::number(boss1[i])+"/"+QString::number(b[i])+"\n";

            }
            qDebug()<<boosstr;
            ui->bloodlab->setText(boosstr);
            boosstr.clear();
            cout<<"6"<<endl;

            for(int i=0;i<skills.size();i++)
            {
                cout<<4<<endl;
                cout<<cd[i];//
                QString str="伤害:"+QString::number(skills[i].first)+"\n"+"冷却:"+QString::number(skills[i].second)+"\n"+"技能CD:"+QString::number(cd[i]);
                 //ui->lab1->setText("技能CD:"+str);
                list[i]->setText(str);
                if(cd[i]!=0)cd[i]--;
            }
            cout<<"7"<<endl;
            if(j<order.size()){

            boss1[num]=max(boss1[num]-skills[order[j]].first,0);
                if(boss1[num]==0)num++;
                cd[order[j]]=skills[order[j]].second;
            }
            j++;
            if(j>order.size())
            {
                cout<<5<<endl;;
                timer->stop();
                timer->deleteLater();
                 ui->bossbtn->setEnabled(true);
                return;
            }
        });

        timer->start(1000);  // 每0.2秒触发一次

}
    else
{
    QMessageBox::information(this, "提示", "已击败boss");
    bnp=-1;
}


}

void MainWindow::on_returnbtn2_clicked()
{
    if(bnp==-1)
    {

        ui->stackedWidget->setCurrentIndex(2);
        ui->lab1->clear();
        ui->lab2->clear();
        ui->lab3->clear();
        ui->lab4->clear();
        ui->lab5->clear();
        ui->bloodlab->clear();
        ui->bnlab->clear();
        ui->ilab->clear();
    }
    else
    {
        QMessageBox::information(this, "提示", "还未击败boss");
    }

}
