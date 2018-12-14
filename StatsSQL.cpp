#include "StatsSQL.h"
#include "DataGen.h"

#include <QMap>

QMap<GeneralStatType, double> StatsSQL::generalStats = QMap<GeneralStatType, double>();
QMap<Node*, short> StatsSQL::clients = QMap<Node*, short>();
QMap<Node*, float> StatsSQL::load = QMap<Node*, float>();
QMap<Node*, double> StatsSQL::memory = QMap<Node*, double>();

void StatsSQL::addClientStat(Node* n, short clients)
{
    StatsSQL::clients.insert(n, clients);
}

void StatsSQL::addLoadStat(Node* n, float load)
{
    StatsSQL::load.insert(n, load);
}

void StatsSQL::addMemoryStat(Node* n, double mem)
{
    StatsSQL::memory.insert(n, mem);
}

void StatsSQL::addGeneralStats(GeneralStatType type, double value)
{
    StatsSQL::generalStats.insert(type, value);
}

void StatsSQL::processStats()
{
    if (!StatsSQL::clients.isEmpty()) {
        QString query = "INSERT INTO statsClients (node, value) VALUES ";
        for (int i = 0; i < StatsSQL::clients.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        for (Node* p : StatsSQL::clients.keys()) {
            ps.addBindValue(p->getId());
            ps.addBindValue(StatsSQL::clients.value(p));
        }
        DataGen::getDatabase()->execPS(ps);
    }
    if (!StatsSQL::load.isEmpty()) {
        QString query = "INSERT INTO statsLoad (node, value) VALUES ";
        for (int i = 0; i < StatsSQL::load.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        for (Node* p : StatsSQL::load.keys()) {
            ps.addBindValue(p->getId());
            ps.addBindValue(static_cast<double>(StatsSQL::load.value(p)));
        }
        DataGen::getDatabase()->execPS(ps);
    }
    if (!StatsSQL::memory.isEmpty()) {
        QString query = "INSERT INTO statsMemory (node, value) VALUES ";
        for (int i = 0; i < StatsSQL::memory.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        for (Node* p : StatsSQL::memory.keys()) {
            ps.addBindValue(p->getId());
            ps.addBindValue(StatsSQL::memory.value(p));
        }
        DataGen::getDatabase()->execPS(ps);
    }
    if (!StatsSQL::generalStats.isEmpty()) {
        QString query = "INSERT INTO statsGeneral (type, value) VALUES ";
        for (int i = 0; i < StatsSQL::generalStats.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        for (GeneralStatType p : StatsSQL::generalStats.keys()) {
            ps.addBindValue(p);
            ps.addBindValue(StatsSQL::generalStats.value(p));
        }
        DataGen::getDatabase()->execPS(ps);
    }
}
