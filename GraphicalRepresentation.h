#pragma once

#include "LeakedObjectDetector.h"

struct GraphicalRepresentation
{
    enum Color {white, grey, black, blue};

    int xCoordinate = 0;
    int yCoordinate = 0;
    int width = 40;
    int height = 20;
    Color backgroundColor = black;
    bool drawRepresentation = false;
    std::string name = "";

    GraphicalRepresentation(int newXCoord, int newYCoord, int newWidth, int newHeight);
    GraphicalRepresentation(Color newBackgroundColor);
    ~GraphicalRepresentation();

    void printDimensions();
    bool moveToXCoord(int newXCoord, int stepsize = 16);
    bool moveToYCoord(int newYCoord, int stepsize = 10);
    void attachLeftOf(GraphicalRepresentation targetRepresentation);

    JUCE_LEAK_DETECTOR(GraphicalRepresentation)
};
