#include "Text.h"

Text::Text():Element(){
    presentFlag=false;
    pathTypeFlag=false;
    widthFlag=false;
    magFlag=false;
    angleFlag=false;
}

Text::~Text(){

}

void Text::Show()
{
    std::cout<<"---TEXT---"<<std::endl;

    Element::Show();
    std::cout<<"\nTEXTTYPE:"<<TEXTTYPE<<std::endl
             <<"STRING:"<<STRING<<std::endl
             <<"PRESENTATION:";
    if(HasPresentation())
    {
        std::cout<<"[";
        for(int i=0;i<16;i++)
        {
            std::cout<<"["<<PRESENTATION[i]<<" ";
        }
        std::cout<<"]\n";
    }
    else std::cout<<"not set\n";
    std::cout<<"Point:"<<"["<<point.x_coord<<","<<point.y_coord<<"]\n";

    std::cout<<"PATHTYPE:"<<(HasPathType()? std::to_string(PATHTYPE):"not set")<<std::endl
             <<"WIDTH:"<<(HasWidth()? std::to_string(WIDTH):"not set")<<std::endl
             <<"MAG:"<<(HasMag()? std::to_string(MAG):"not set")<<std::endl
             <<"ANGLE:"<<(HasAngle()? std::to_string(ANGLE):"not set")<<std::endl;

    std::cout<<"---END TEXT---"<<std::endl;
}

void Text::SetPathType(short p_type){
    PATHTYPE=p_type;
}
short Text::GetPathType(){
    if(HasPathType())
        return PATHTYPE;
    return 0;//throw AnError();
}

void Text::SetTextType(short t_type){
    TEXTTYPE=t_type;
}
short Text::GetTextType(){
    return TEXTTYPE;
}

void Text::SetPresentation(std::bitset<16> bits){
    presentFlag=true;
    PRESENTATION=bits;
}
std::bitset<16> Text::GetPresentation()
{
    if(HasPresentation())
        return PRESENTATION;
    return 0;//throw AnError();
}

void Text::SetMag(double mag){
    magFlag=true;
    MAG=mag;
}
double Text::GetMag(){
    if(HasMag())
        return MAG;
    return 0;//throw AnError();
}

void Text::SetAngle(double angle){
    angleFlag=true;
    ANGLE=angle;
}
double Text::GetAngle(){
    if(HasAngle())
        return ANGLE;
    return 0;//throw AnError();
}

void Text::SetWidth(int width){
    widthFlag=true;
    WIDTH=width;
}
int Text::GetWidth(){
    if(HasWidth())
        return WIDTH;
    return 0;//throw AnError();
}

void Text::SetString(std::__cxx11::string str){
    STRING=str;
}
std::string Text::GetString(){
    return STRING;
}


bool Text::HasAngle(){
    return angleFlag;
}
bool Text::HasMag(){
    return magFlag;
}
bool Text::HasPathType(){
    return pathTypeFlag;
}
bool Text::HasPresentation(){
    return presentFlag;
}
bool Text::HasWidth(){
    return widthFlag;
}

Point* Text::GetPoints(){
    return &point;
}
void Text::SetPoints(Point* p,int amount)
{
    point=*p;
    amountOfPoints=1;
}
