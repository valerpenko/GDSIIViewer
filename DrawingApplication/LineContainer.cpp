#include "LineContainer.h"

LineContainer::LineContainer()
{
    areaHeight=0;
    areaWidth=0;
}

QLine* LineContainer::GetArray()
{
    return lineArray.data();
}

int LineContainer::GetAmount()
{
    return lineArray.size();
}

void LineContainer::AddLine(QLine line)
{
    lineArray.append(line);
}

void LineContainer::SetAreaWidth(int width)
{
    areaWidth=width;
}
void LineContainer::SetAreaHeight(int height)
{
    areaHeight=height;
}
void LineContainer::SetBottomX(int x_value)
{
    bottomX=x_value;
}
void LineContainer::SetBottomY(int y_value){
    bottomY=y_value;
}
int LineContainer::GetBottomX()
{
    return bottomX;
}
int LineContainer::GetBottomY()
{
    return bottomY;
}

int LineContainer::GetAreaWidth()
{
    return areaWidth;
}
int LineContainer::GetAreaHeight()
{
    return areaHeight;
}
