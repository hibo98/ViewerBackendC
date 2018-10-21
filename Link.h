
/* 
 * File:   Link.h
 * Author: NMerkelt
 *
 * Created on 13. Oktober 2018, 15:06
 */

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
    Link(LinkType type, Node* source, Node* target, signed char sourceTq = -1, signed char targetTq = -1);
    Link(const Link& orig);
    virtual ~Link();

    Node* getSource();
    Node* getTarget();
    signed char getSourceTq();
    void setSourceTq(signed char tq);
    signed char getTargetTq();
    void setTargetTq(signed char tq);
    LinkType getLinkType();

    QString getTypeHopglass();
    QString getTypeMeshViewer();
    
    static LinkType getLinkTypeByInterface(QString s);
    static LinkType getLinkTypeByType(QString s);
private:
    signed char sourceTq = -1;
    signed char targetTq = -1;
    LinkType type;
    Node* source;
    Node* target;
};

#endif /* LINK_H */

