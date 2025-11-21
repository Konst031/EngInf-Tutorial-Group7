#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ShapeLib.h"


double areaRectangle(struct rectangle rec)
{
    return rec.length * rec.width;
}

double areaTriangle(struct triangle tri)
{
    return 0.5 * tri.altitude * tri.hypLength;
}

double areaCircle(struct circle circ)
{
    return M_PI * circ.radius * circ.radius;
}

// Extra Übung
double shapeArea(struct shape form )
{
    double area = 0;
    switch (form.type)
    {
    case RECTANGLE:
        area =areaRectangle(form.geometry.rectangle);
        printf("The shape is a rectangle with area %f\n",area);
        return area;
        break;
    case TRIANGLE:
        area =areaTriangle(form.geometry.triangle);
        printf("The shape is a triangle with area %f\n",area);
        return area;
        break;
    case CIRCLE:
        area =areaCircle(form.geometry.circle);
        printf("The shape is a circle with area %f\n",area);
        return area;
        break;
    }
    return -1; //denotes error in function
}
