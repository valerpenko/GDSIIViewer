#include "Box.h"

Box::Box()
{

}

Box::~Box()
{

}

void Box::Show()
{
    std::cout<<"---BOX---"<<std::endl;
    Element::Show();
    std::cout<<"Points:\n";
    for(int i=0;i<sizeof(points)/sizeof(points[0]);i++)
    {
        std::cout<<"--["<<points[i].x_coord<<","<<points[i].y_coord<<"]\n";
    }
    std::cout<<"\nBOXTYPE:"<<BOXTYPE<<std::endl;
    std::cout<<"---END BOX---"<<std::endl;
}

void Box::SetBoxType(short b_type){
    BOXTYPE=b_type;
}
short Box::GetBoxType()
{
    return BOXTYPE;
}

Point* Box::GetPoints(){
    return points;
}
void Box::SetPoints(Point *points,int amount){
    for(int i=0;i<amount;i++)
    {
        this->points[i]=points[i];
        amountOfPoints++;
    }

}
