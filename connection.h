#ifndef CONNECTION_H
#define CONNECTION_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QVariant>
#include<QString>
#include<QLabel>
#include<QPixmap>
#include<QFileDialog>
#include<QByteArray>
#include<QBuffer>
#include<QFile>

static bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL","testconn");
    db.setHostName("w.rdc.sae.sina.com.cn");
    db.setPort(3306);
    db.setDatabaseName("app_geodatainnovation");
    db.setUserName("2kk0013yzz");
    db.setPassword("jj1mmikmzj1wjw2m4z0iyw000wk4w223zzmm24ly");
    bool ok=db.open();
    if(ok)
    {
        QSqlQuery query;
        query=QSqlQuery(db);
            //query.exec("select * from userinfo");
        //QString select = "select * from picture";
        //query.exec(select);
            //qDebug()<<query.value(0)<<query.value(1);
        //QLabel *PicLabel = new QLabel();

        //QPixmap photo;

        //query.next();
        //photo.loadFromData(query.value(1).toByteArray(), "JPG"); //从数据库中读出图片为二进制数据，图片格式为JPG，然后显示到QLabel里
        //PicLabel->setPixmap(photo);
        //PicLabel->setScaledContents(true);
        //PicLabel->setAutoFillBackground(true);
        //PicLabel->show();

        query.exec("insert into picture(name,image) values('2',LOAD_FILE('C:\\Users\\fanxin806\\Pictures\\2.JPG'))");
        QLabel *PicLabel = new QLabel();

        QPixmap photo;

        while(query.next())
        {
            photo.loadFromData(query.value(1).toByteArray(), "JPG"); //从数据库中读出图片为二进制数据，图片格式为JPG，然后显示到QLabel里
            PicLabel->setPixmap(photo);
            PicLabel->setScaledContents(true);
            //PicLabel->setAutoFillBackground(true);
            PicLabel->show();
        }
    }

    return true;
}
#endif // CONNECTION_H
