#include "Path.h"

Path::Path():Element()
{
    pathTypeFlag=false;
    widthFlag=false;
    bgnExtnFlag=false;
    endExtnFlag=false;
}
Path::~Path(){

}
void Path::Show()
{
    std::cout<<"---PATH---"<<std::endl;
    Element::Show();
    std::cout<<"Points:\n";
    //size of dynamic array...???
    for(int i=0;i<sizeof(points)/sizeof(points[0]);i++)
    {
        std::cout<<"--["<<points[i].x_coord<<","<<points[i].y_coord<<"]\n";
    }
    std::cout<<"\nDATATYPE:"<<DATATYPE<<std::endl
             <<"PATHTYPE:"<<(HasPathType()? std::to_string(PATHTYPE):"not set")<<std::endl
             <<"WIDTH:"<<(HasWidth()? std::to_string(WIDTH):"not set")<<std::endl
             <<"EXTENSIONS:\n"
             <<"--BGNEXTN:"<<(HasBgnExtn()? std::to_string(BGNEXTN):"not set")<<std::endl
             <<"--ENDEXTN:"<<(HasEndExtn()? std::to_string(ENDEXTN):"not set")<<std::endl;
    std::cout<<"---END PATH---"<<std::endl;
}

void Path::SetBgnExtn(int b_extn){
    bgnExtnFlag=true;
    BGNEXTN=b_extn;
}
int Path::GetBgnExtn(){
    if(HasBgnExtn())
        return BGNEXTN;
    else return 0;//throw AnError();
}


void Path::SetEndExtn(int e_extn)
{
    endExtnFlag=true;
    ENDEXTN=e_extn;
}
int Path::GetEndExtn(){
    if(HasEndExtn())
        return ENDEXTN;
    else return 0;//throw AnError();
}

void Path::SetPathType(short p_type)
{
    pathTypeFlag=true;
    PATHTYPE=p_type;
}
short Path::GetPathType(){
    if(HasPathType())
        return PATHTYPE;
    else return 0;//throw AnError();
}

void Path::SetWidth(int width){
    widthFlag=true;
    WIDTH=width;
}
int Path::GetWidth()
{
    if(HasWidth())
        return WIDTH;
    else return 0;//throw AnError();
}

void Path::SetDataType(short data_t)
{
    DATATYPE=data_t;
}
short Path::GetDataType(){
    return DATATYPE;
}


bool Path::HasBgnExtn(){
    return bgnExtnFlag;
}
bool Path::HasEndExtn(){
    return endExtnFlag;
}
bool Path::HasPathType(){
    return pathTypeFlag;
}
bool Path::HasWidth(){
    return widthFlag;
}

Point* Path::GetPoints()
{
    return points;
}
void Path::SetPoints(Point *pArray,int amount){
    for(int i=0;i<amount;i++)
    {
        this->points[i]=pArray[i];
    }
    amountOfPoints=amount;
}

