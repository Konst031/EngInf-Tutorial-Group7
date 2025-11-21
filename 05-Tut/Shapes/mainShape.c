#include <stdlib.h>
#include <stdio.h>

#include "ShapeLib.h"

int main(int argc, char const *argv[])
{
    struct circle cir1 = {2.1};
    struct rectangle rec1 ={3.1, 4.2};
    struct triangle tri1 = {2.3, 1.3};

    printf("Area of circle: %f\nArea of rectangle: %f\nArea of triangle: %f\n", areaCircle(cir1), areaRectangle(rec1), areaTriangle(tri1));

    // Extra Übungen: 
    union geometry geom1;
    geom1.circle = cir1;
    union geometry geom2;
    geom2.rectangle = rec1;
    union geometry geom3;
    geom3.triangle = tri1;

    struct shape shape1 = {CIRCLE, geom1};
    struct shape shape2 = {RECTANGLE, geom2};
    struct shape shape3 = {TRIANGLE, geom3};

    shapeArea(shape1);
    shapeArea(shape2);
    shapeArea(shape3);
    return 0;
}

