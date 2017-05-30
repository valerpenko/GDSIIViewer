#ifndef NODE_H
#define NODE_H

#include "Element.h"

class Node:public Element
{
    short NODETYPE;
    Point points[50];
public:
    Node();
    ~Node();
    void Show();

    Point* GetPoints();
    void SetPoints(Point *points, int amount);

    void SetNodeType(short n_type);
    short GetNodeType();
};

#endif // NODE_H
