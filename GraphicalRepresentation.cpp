#include <iostream>
#include "GraphicalRepresentation.h"


GraphicalRepresentation::GraphicalRepresentation(int newXCoord, int newYCoord, int newWidth, int newHeight) : 
    xCoordinate(newXCoord), 
    yCoordinate(newYCoord), 
    width(newWidth), 
    height(newHeight) 
{
}

GraphicalRepresentation::GraphicalRepresentation(Color newBackgroundColor)
{
    backgroundColor = newBackgroundColor;
}

GraphicalRepresentation::~GraphicalRepresentation()
{
}

void GraphicalRepresentation::printDimensions()
{
    std::cout << "Your new Plugin has size " << this->width << " x " << this->height << "." << std::endl;
}

bool GraphicalRepresentation::moveToXCoord(int newXCoord, int stepsize)
{
    while (xCoordinate < newXCoord)
    {
        xCoordinate += stepsize;
        std::cout << "xCoordinate = " << xCoordinate << std::endl;
    }
    return true;
}

bool GraphicalRepresentation::moveToYCoord(int newYCoord, int stepsize)
{
    while (yCoordinate < newYCoord){
        yCoordinate += stepsize;
        std::cout << "yCoordinate = " << yCoordinate << std::endl;
    }
    return true;
}

void GraphicalRepresentation::attachLeftOf(GraphicalRepresentation targetRepresentation)
{
    xCoordinate = targetRepresentation.xCoordinate - width;
    yCoordinate = targetRepresentation.yCoordinate;
    std::cout << "New xCoordinate = " << xCoordinate << ", new yCoordinate = " << yCoordinate << std::endl;
}
