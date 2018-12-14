#ifndef MYSQL_H
#define MYSQL_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class MySQL {
public:
    MySQL();
    virtual ~MySQL();
    
    bool hasConnection();
    void closeConnection();
    
    bool execute(QString query);
    QSqlQuery executeQuery(QString query);
    QSqlQuery prepareStatement(QString query);
private:
    void createCfg();

    bool loadCfg();
    bool openConnection();
    
    QSqlDatabase connection;
    QString host;
    short port;
    QString username;
    QString password;
    QString database;
};

#endif /* MYSQL_H */

