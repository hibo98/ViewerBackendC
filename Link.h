#ifndef LINK_H
#define LINK_H

#include <QString>

class Node;

enum LinkType {
    WIRELESS,
    TUNNEL,
    OTHER
};

class Link {
public:
    Link(LinkType type, Node* source, Node* target, short sourceTq = -1, short targetTq = -1);
    Link(const Link& orig);
    virtual ~Link();

    Node* getSource();
    Node* getTarget();
    short getSourceTq();
    void setSourceTq(short tq);
    short getTargetTq();
    void setTargetTq(short tq);
    LinkType getLinkType();

    QString getTypeHopglass();
    QString getTypeMeshViewer();
    
    static LinkType getLinkTypeByInterface(QString s);
    static LinkType getLinkTypeByType(QString s);
    
    static double convertToHopGlass(short tq);
    static double convertToMeshViewer(short tq);
private:
    short sourceTq = -1;
    short targetTq = -1;
    LinkType type;
    Node* source;
    Node* target;
};

#endif /* LINK_H */

