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
        QMap<Node*, short>::key_value_iterator it = StatsSQL::clients.keyValueBegin();
        QMap<Node*, short>::key_value_iterator end = StatsSQL::clients.keyValueEnd();
        while (it != end) {
            std::pair<Node*, short> p = *it;
            ps.addBindValue(p.first->getId());
            ps.addBindValue(p.second);
        }
        ps.exec();
    }
    if (!StatsSQL::load.isEmpty()) {
        QString query = "INSERT INTO statsLoad (node, value) VALUES ";
        for (int i = 0; i < StatsSQL::load.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        QMap<Node*, float>::key_value_iterator it = StatsSQL::load.keyValueBegin();
        QMap<Node*, float>::key_value_iterator end = StatsSQL::load.keyValueEnd();
        while (it != end) {
            std::pair<Node*, float> p = *it;
            ps.addBindValue(p.first->getId());
            ps.addBindValue(static_cast<double>(p.second));
        }
        ps.exec();
    }
    if (!StatsSQL::memory.isEmpty()) {
        QString query = "INSERT INTO statsMemory (node, value) VALUES ";
        for (int i = 0; i < StatsSQL::memory.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);
        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        QMap<Node*, double>::key_value_iterator it = StatsSQL::memory.keyValueBegin();
        QMap<Node*, double>::key_value_iterator end = StatsSQL::memory.keyValueEnd();
        while (it != end) {
            std::pair<Node*, double> p = *it;
            ps.addBindValue(p.first->getId());
            ps.addBindValue(p.second);
        }
        ps.exec();
    }
    if (!StatsSQL::generalStats.isEmpty()) {
        QString query = "INSERT INTO statsGeneral (type, value) VALUES ";
        for (int i = 0; i < StatsSQL::generalStats.size(); i++) {
            query += "(?,?),";
        }
        query.resize(query.length() - 1);

        QSqlQuery ps = DataGen::getDatabase()->prepareStatement(query);
        QMap<GeneralStatType, double>::key_value_iterator it = StatsSQL::generalStats.keyValueBegin();
        QMap<GeneralStatType, double>::key_value_iterator end = StatsSQL::generalStats.keyValueEnd();
        while (it != end) {
            std::pair<GeneralStatType, double> p = *it;
            ps.addBindValue(p.first);
            ps.addBindValue(p.second);
        }
        ps.exec();
    }
}
