
#include "curves.hpp"
#include <cmath>
#include <iostream>

Point3D::Point3D(double dX, double dY, double dZ) : 
    dX(dX), dY(dY), dZ(dZ) {}

Vector3D::Vector3D(double dX, double dY, double dZ) : 
    Point3D(dX, dY, dZ) {}

/* A positive value must be passed to the function: it is checked and negated if any negarive */
Circle::Circle(double dRadius) : dRadius(dRadius) {
    if (dRadius < 0)
        this->dRadius = -dRadius;
}

Point3D Circle::getPoint3D(double t) {
    return Point3D(dRadius * cos(t), dRadius * sin(t), 0);
}

Vector3D Circle::getDerivative(double t) {
    return Vector3D(-dRadius * sin(t), dRadius * cos(t), 0);
}

double Circle::getRadius() {
    return dRadius;
}

/* A positive values must be passed to the function: they are checked and negated if any negarive */
Ellipse::Ellipse(double dRadiusX, double dRadiusY) : dRadiusX(dRadiusX), dRadiusY(dRadiusY) {
    if (dRadiusX < 0)
        this->dRadiusX = -dRadiusX;
    if (dRadiusY < 0)
        this->dRadiusY = -dRadiusY;
}

Point3D Ellipse::getPoint3D(double t) {
    return Point3D(dRadiusX * cos(t), dRadiusY * sin(t), 0);
}

Vector3D Ellipse::getDerivative(double t) {
    return Vector3D(-dRadiusX * sin(t), dRadiusY * cos(t), 0);
}

/* A positive value must be passed to the function: it is checked and negated if any negarive */
Helix::Helix(double dRadius, double dStep) : dRadius(dRadius), dStep(dStep) {
    if (dRadius < 0)
        this->dRadius = -dRadius;
}

Point3D Helix::getPoint3D(double t) {
    return Point3D(dRadius * cos(t), dRadius * sin(t), dStep * t / (2 * M_PI));
}

Vector3D Helix::getDerivative(double t) {
    return Vector3D(-dRadius * sin(t), dRadius * cos(t), dStep / (2 * M_PI));
}

const char * Circle::getName(void)  {
    return "Circle";
}

const char * Ellipse::getName(void)  {
    return "Ellipse";
}

const char * Helix::getName(void)  {
    return "Helix";
}
