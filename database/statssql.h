#ifndef STATSSQL_H
#define STATSSQL_H

#include "../Node.h"

#include <QHash>
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
    static void addLoadStat(Node* n, double l);
    static void addMemoryStat(Node* n, double m);
    static void addGeneralStats(GeneralStatType type, double value);

    static void processStats();

private:
    static QMap<GeneralStatType, double> generalStats;
    static QHash<Node*, short> clients;
    static QHash<Node*, double> load;
    static QHash<Node*, double> memory;
};

#endif // STATSSQL_H
