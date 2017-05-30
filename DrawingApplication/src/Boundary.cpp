#include "Boundary.h"

Boundary::Boundary(){

}
Boundary::~Boundary(){

}

void Boundary::Show()
{
    std::cout<<"---BOUNDARY---"<<std::endl;
    Element::Show();
    std::cout<<"Points:\n";
    //size of dynamic array...???
    for(int i=0;i<sizeof(points)/sizeof(points[0]);i++)
    {
        std::cout<<"--["<<points[i].x_coord<<","<<points[i].y_coord<<"]\n";
    }
    std::cout<<"\nDATATYPE:"<<DATATYPE<<std::endl;
    std::cout<<"---END BOUNDARY---"<<std::endl;
}

void Boundary::SetDataType(short data_t)
{
    DATATYPE=data_t;
}
short Boundary::GetDataType(){
    return DATATYPE;
}

Point* Boundary::GetPoints()
{
    return points;
}

void Boundary::SetPoints(Point *points,int amount){
    amountOfPoints=0;
    for(int i=0;i<amount;i++)
    {
        this->points[i]=points[i];
        amountOfPoints++;
    }
}
