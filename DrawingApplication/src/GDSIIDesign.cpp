/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   GDSIIDesign.cpp
 * Author: Val
 *
 * Created on 2 января 2017 г., 18:39
 */

#include "GDSIIDesign.h"
#include <typeinfo>
#include <QTransform>

GDSIIDesign::GDSIIDesign() {
}

GDSIIDesign::GDSIIDesign(const GDSIIDesign& orig) {
}

GDSIIDesign::~GDSIIDesign() {
}

void GDSIIDesign::AddStructure(Structure *structure)
{
    structures.push_back(*structure);
}

/*old version
 * LayerForView* GDSIIDesign::GetLayerForView(int layer){
    LayerForView* layForView=new LayerForView();
    for(int i=0;i<(int)structures.size();i++)
    {
        Structure str=structures[i];
        for(int j=0;j<str.GetElementsCount();j++)
        {
            Element* curEl=str.GetElementByIndex(j);
            std::string typeName=typeid(*curEl).name();
            if(typeName==typeid(Path).name() && curEl->GetLayer()==layer)
                //RecountCoordsForElement(reinterpret_cast<Path*>(curEl),initPoint,angle,mag_coef,layForView);
                layForView->AddPath(reinterpret_cast<Path*>(curEl));
            else if(typeName==typeid(Boundary).name() && curEl->GetLayer()==layer)
                //RecountCoordsForElement(reinterpret_cast<Boundary*>(curEl),initPoint,angle,mag_coef,layForView);
                layForView->AddBoundary(reinterpret_cast<Boundary*>(curEl));

        }
        //ScanStructureForLayer(str,0,layer,0,0,layForView);

    }
    return layForView;
}
*/

LayerForView* GDSIIDesign::GetLayerForView(int layer){
    LayerForView* layForView=new LayerForView();
    for(int i=0;i<(int)structures.size();i++)
    {
        Structure str=structures[i];
        Point start_p;
        start_p.x_coord=0;
        start_p.y_coord=0;
        ScanStructureForLayer(&str, start_p,layer,0.0,1.0,layForView);

    }
    return layForView;
}

void  GDSIIDesign::ScanStructureForLayer(Structure *str, Point refPoint, int layer, double angle, double mag_coef, LayerForView *&layForView)
{
    for(int i=0;i<str->GetElementsCount();i++)
    {
        Element* curEl=str->GetElementByIndex(i);
        std::string typeName=typeid(*curEl).name();
        if(typeName==typeid(Path).name() && curEl->GetLayer()==layer)
            RecountCoordsForElement(reinterpret_cast<Path*>(curEl),refPoint,angle,mag_coef,layForView);
            //LayerForView.AddPath(reinterpret_cast<Path*>(curEl));
        else if(typeName==typeid(Boundary).name() && curEl->GetLayer()==layer)
            RecountCoordsForElement(reinterpret_cast<Boundary*>(curEl),refPoint,angle,mag_coef,layForView);
            //layForView->AddBoundary(reinterpret_cast<Boundary*>(curEl));
        else if(typeName==typeid(SREF).name())
        {
            SREF* sref=reinterpret_cast<SREF*>(curEl);
            Structure * str=GetStructureByName(sref->GetSNAME());
            if(str!=0)
            {
                Point refP=sref->GetPoints()[0];
                ScanStructureForLayer(str,refP,layer,sref->GetAngle(),sref->GetMAG(),layForView);
            }
        }

    }
}

void GDSIIDesign::RecountCoordsForElement(Element *el, Point refPoint, double angle, double mag_coef, LayerForView *&layerForView)
{
    std::string elTypeName=typeid(*el).name();
    Element* copy;

    if(elTypeName==typeid(Boundary).name())
    {
        Boundary* b=reinterpret_cast<Boundary*>(el);
        copy=new Boundary();
        reinterpret_cast<Boundary*>(copy)->SetDataType(b->GetDataType());
        reinterpret_cast<Boundary*>(copy)->SetElFlags(b->GetElFlags());
        reinterpret_cast<Boundary*>(copy)->SetPlex(b->GetPlex());
        reinterpret_cast<Boundary*>(copy)->SetLayer(b->GetLayer());
        reinterpret_cast<Boundary*>(copy)->SetPoints(b->GetPoints(),b->GetAmountOfPoints());
    }
    else if(elTypeName==typeid(Path).name())
    {
        Path* p=reinterpret_cast<Path*>(el);
        copy=new Path();
        reinterpret_cast<Path*>(copy)->SetDataType(p->GetDataType());
        reinterpret_cast<Path*>(copy)->SetElFlags(p->GetElFlags());
        reinterpret_cast<Path*>(copy)->SetPlex(p->GetPlex());
        reinterpret_cast<Path*>(copy)->SetLayer(p->GetLayer());
        reinterpret_cast<Path*>(copy)->SetPoints(p->GetPoints(),p->GetAmountOfPoints());
    }

    Point* newPoints=new Point[el->GetAmountOfPoints()];
    double radAngle=angle*M_PI/180;
    for(int i=0;i<copy->GetAmountOfPoints();i++)
    {
        Point point_i=copy->GetPoints()[i];

        QTransform moveToRef(1,0,refPoint.x_coord,0,1,refPoint.y_coord,0,0,1);
        QTransform rotMat(cos(radAngle),-sin(radAngle),0,sin(radAngle),cos(radAngle),0,0,0,1);
        QTransform magMat(mag_coef,0,0,0,mag_coef,0,0,0,1);
        QTransform pointMat(point_i.x_coord,0,0,point_i.y_coord,0,0,1,0,0);
        QTransform newCoordsMat=moveToRef*rotMat*magMat*pointMat;
        int x_val=newCoordsMat.m11()>0?newCoordsMat.m11()+0.5:newCoordsMat.m11()-0.5;
        int y_val=newCoordsMat.m21()>0?newCoordsMat.m21()+0.5:newCoordsMat.m21()-0.5;
        newPoints[i].x_coord=x_val;
        newPoints[i].y_coord=y_val;
    }
    delete [] copy->GetPoints();
    copy->SetPoints(newPoints,el->GetAmountOfPoints());
    if(elTypeName==typeid(Boundary).name())
        layerForView->AddBoundary(reinterpret_cast<Boundary*>(copy));
    else if(elTypeName==typeid(Path).name())
        layerForView->AddPath(reinterpret_cast<Path*>(copy));
    delete copy;
}

void GDSIIDesign::SetUnitsData(double userSize, double metersSize){
    sizeInUserUnits=userSize;
    sizeInMeters=metersSize;
}

double GDSIIDesign::GetSizeInUserUnits(){
    return sizeInUserUnits;
}
double GDSIIDesign::GetSizeInMeters(){
    return sizeInMeters;
}

Structure* GDSIIDesign::GetStructureByName(std::__cxx11::string sname)
{
    Structure* strs=structures.data();
    for(int i=0;i<structures.size();i++)
    {
        Structure* curStr=&strs[i];
        if(curStr->GetStructureName()==sname)
        {
            return curStr;
        }
    }
    return 0;
}
