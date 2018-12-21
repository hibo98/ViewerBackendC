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
    
    bool execute(const QString& query);
    QSqlQuery executeQuery(const QString& query);
    QSqlQuery prepareStatement(const QString& query);
    bool execPS(QSqlQuery ps);
private:
    void createCfg();

    bool loadCfg();
    bool openConnection();
    bool reconnect();
    
    QSqlDatabase connection;
    QString host;
    short port = 3306;
    QString username;
    QString password;
    QString database;
};

#endif /* MYSQL_H */

