#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QString>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QString> strList;
    strList<<"Hello"<<"Qt" <<" my name is Lan";
    qDebug()<< strList;
    strList.append("I'm learing");
    strList.append("Qt");
    qDebug()<< strList;
    qDebug()<< strList[1];
    qDebug()<< strList.size();
    for(int i=0; i< strList.size(); i++)
    {
        qDebug()<<"The element at index "<<QString::number(i)<<"is"<<strList[i];
    }
    return a.exec();
}
