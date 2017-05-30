#include "Structure.h"
#include <iostream>
Structure::Structure()
{}

Structure::~Structure()
{

}

void Structure::SetStructureName(std::string name)
{
    STRNAME=name;
}

std::string Structure::GetStructureName()
{
    return STRNAME;
}

void Structure::AddElement(Element *element)
{
    elements.push_back(element);
}

void Structure::SetStrClass(std::bitset<16> bitset)
{
    STRCLASS=bitset;
}

std::bitset<16> Structure::GetStrClass()
{
    return STRCLASS;
}

void Structure::Show(){
    std::cout<<"STRUCTURE '"<<STRNAME<<"':\n";
    for(int i=0;i<elements.size();i++)
    {
        elements[i]->Show();
    }
    std::cout<<"END STRUCTURE '"<<STRNAME<<"'\n";
}

int Structure::GetElementsCount()
{
    elements.size();
}

Element* Structure::GetElementByIndex(int index)
{
    if(index<GetElementsCount())
    {
        return elements[index];
    }
    return 0;//throw AnError();
}
