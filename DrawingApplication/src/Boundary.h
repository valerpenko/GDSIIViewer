#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "Element.h"

class Boundary:public Element
{
    short DATATYPE;
    Point points[200];

public:
    Boundary();
    ~Boundary();
    void Show();
    void SetDataType(short data_t);
    short GetDataType();

    Point* GetPoints();
    void SetPoints(Point* points,int amount);

};

#endif // BOUNDARY_H
