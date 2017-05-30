#ifndef LAYERFORVIEW_H
#define LAYERFORVIEW_H

#include <vector>
#include "Boundary.h"
#include "Path.h"
#include "SREF.h"
#include "AREF.h"
#include "LineContainer.h"

class LayerForView
{
    std::vector<Boundary> boundaries;
    std::vector<Path> paths;

    int layerWidth;
    int layerHeight;

public:
    LayerForView();

    int GetLayerWidth();
    int GetLayerHeight();

    Boundary* GetBoundaries();
    Path* GetPaths();

    void AddBoundary(Boundary* boundary);
    void AddPath(Path* path);

    LineContainer* GetLineContainerForArea(int x_min,int y_min,int x_max,int y_max);

};

#endif // LAYERFORVIEW_H
