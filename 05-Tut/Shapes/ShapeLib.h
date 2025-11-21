#ifndef SHAPELIB
#define SHAPELIB

// Definitions structs, enum, union -> order matters! Declaring the functions before these definitions will give errors
struct rectangle
{
    double length;
    double width;
};

struct triangle
{
    double hypLength;
    double altitude;
};

struct circle
{
    double radius;
};
// Extra Übung:
enum shape_type
{
    RECTANGLE,
    TRIANGLE,
    CIRCLE
};

union geometry
{
    struct triangle triangle;
    struct rectangle rectangle;
    struct circle circle;
};

struct shape
{
    enum shape_type type;
    union geometry geometry;
};

// declaration of functions

double areaCircle(struct circle circ);
double areaTriangle(struct triangle tri);
double areaRectangle(struct rectangle rec);
// Extra Übung:
double shapeArea(struct shape);

#endif