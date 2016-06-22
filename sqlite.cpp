#include "sqlite.h"
#include "helper.h"
#include <iostream>
#include <string>
Sqlite::Sqlite()
{
    dbconn=QSqlDatabase::addDatabase("QSQLITE");    //添加数据库驱动
    dbconn.setDatabaseName("mytest.db");  //在工程目录新建一个mytest.db的文件
    if(!dbconn.open())    {
        exit(-1);
    }
}

Sqlite::~Sqlite()
{
    dbconn.close();
}

bool Sqlite::checkpassword(char *username, char *password)
{
    QSqlQuery query;
    //query.prepare(checkpasswordsql);
    //query.bindValue(":user",username);
    QString u=username;
    QString sqltext="select password,salt from users where username='"+u+"'";
    query.exec(sqltext);
    query.next();
    QString pass=query.value(0).toString();
    QString salt=query.value(1).toString();
    QString tohash=password+salt;
    if(pass==Helper::hash(Helper::tochararray(tohash)))
        return true;
    else
        return false;
}

bool Sqlite::reguser(char* username,char* password,char* vip)//salt,regdate,sha-256
{
    QSqlQuery query;
    char* salt=Helper::getsalt();
    char* tohash=(char*)malloc(sizeof(char)*(Helper::lenofchararrau(password)+8+1));
    strcpy(tohash,password);
    strcat(tohash,salt);
    QString u=username;
    QString p=Helper::hash(tohash);
    QString s=salt;
    QString v=vip;
    QString sqltext="insert into users (username,password,salt,regdate,vip) values('"+u+"','"+p+"','"+s+"','"+"2000-1-1 00:00"+"',"+v+")";
    if(query.exec(sqltext))
        return true;
    else
        return false;
}
