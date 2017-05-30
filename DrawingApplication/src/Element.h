#ifndef ELEMENT_H
#define ELEMENT_H

#include "point.h"
#include <iostream>
#include <bitset>
#include <vector>

class Element
{
public:
    Element();
    virtual ~Element()=0;
    virtual void Show()=0;

    virtual Point* GetPoints()=0;
    virtual void SetPoints(Point* points, int amount)=0;

    int GetAmountOfPoints();

    int GetLayer();
    void SetLayer(int layer);

    void SetElFlags(std::bitset<16> bitset);
    std::bitset<16> GetElFlags();

    void SetPlex(int plex);
    int GetPlex();

    bool HasELFLAGS();
    bool HasPLEX();
    bool HasProps();

    void AddPropAttr(short prop_attr);
    void AddPropValue(std::string prop_value);

    std::vector<short> GetPropAttr();
    std::vector<std::string> GetPropValue();

protected:
    std::bitset<16> ELFLAGS;
    int PLEX;
    int amountOfPoints;
    //Point* _points;
    int _layer;
    std::vector<short> propAttributes;
    std::vector<std::string> propValues;

    bool elfFlag;
    bool plexFlag;
    bool propFlag;

};

#endif // ELEMENT_H
