#ifndef MYSQL_H
#define MYSQL_H

#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/sqlstring.h>

class MySQL {
public:
    MySQL();
    virtual ~MySQL();
    
    bool hasConnection();
    void closeConnection();
    
    bool execute(sql::SQLString sql);
    sql::ResultSet* executeQuery(sql::SQLString sql);
    sql::PreparedStatement* prepareStatement(sql::SQLString sql);
private:
    void createCfg();

    bool loadCfg();
    bool openConnection();
    
    sql::Connection* connection = nullptr;
    sql::SQLString host;
    sql::SQLString username;
    sql::SQLString password;
    sql::SQLString database;
};

#endif /* MYSQL_H */

