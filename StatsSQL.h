#ifndef STATSSQL_H
#define STATSSQL_H

#include "Node.h"

#include <QMap>

enum GeneralStatType {
    CLIENTS,
    NODES,
    NODES_ONLINE
};

class StatsSQL
{
public:
    static void addClientStat(Node* n, short c);
    static void addLoadStat(Node* n, float l);
    static void addMemoryStat(Node* n, double m);
    static void addGeneralStats(GeneralStatType type, double value);

    static void processStats();

private:
    static QMap<GeneralStatType, double> generalStats;
    static QMap<Node*, short> clients;
    static QMap<Node*, float> load;
    static QMap<Node*, double> memory;
};

#endif // STATSSQL_H
