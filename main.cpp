
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#include <ctime>
#include <iomanip>

#include "curves.hpp"

using namespace std;

#define TARGET_POINT    (M_PI / 4)
#define MIN_RANDOM      (1.0)
#define MAX_RANDOM      (5.0)

double dTakeRandom(void) {
    return (double)(rand())/RAND_MAX * (MAX_RANDOM - MIN_RANDOM);
}

int main() {
    vector<shared_ptr<Curve>> vpCurves;

    // fill up the vpCurves vector with random objects and random parameters
    srand(unsigned(time(0)));
    for (int i = 0; i < 10; i++) {
        int iCurveType = rand() % 3;
        if (iCurveType == 0)
            vpCurves.push_back(
                make_shared<Circle>(dTakeRandom())
            );
        else if (iCurveType == 1)
            vpCurves.push_back(
                make_shared<Ellipse>(dTakeRandom(), dTakeRandom())
            );
        else
            vpCurves.push_back(
                make_shared<Helix>(dTakeRandom(), dTakeRandom())
            );
    }

    // just to print out all objects in vector with their parameters
    cout << fixed << setprecision(3);
    for (const auto & pCurve : vpCurves) {
        Point3D Point = pCurve->getPoint3D(TARGET_POINT);
        Vector3D derivative = pCurve->getDerivative(TARGET_POINT);
        cout  << pCurve->getName()           
              << ":\n  { Point3D: (" 
              << Point.dX << ", " << Point.dY << ", " << Point.dZ 
              << "), "
              << "Derivative: (" 
              << derivative.dX << ", " << derivative.dY << ", " << derivative.dZ 
              << ") }" << endl;
    }

    // make new vector with circles only from vpCurves vector
    vector<shared_ptr<Circle>> vpCircles;
    for (const auto & pCurve : vpCurves) {
        if (auto pCircle = dynamic_pointer_cast<Circle>(pCurve)) {
            vpCircles.push_back(pCircle);
        }
    }

    // sort circles vector
    sort(vpCircles.begin(), vpCircles.end(), [](shared_ptr<Circle> a, shared_ptr<Circle> b) {
        return a->getRadius() < b->getRadius();
    });

    double dTotalRadiusSum = 0;
    for (const auto & pCircle : vpCircles)
        dTotalRadiusSum += pCircle->getRadius();

    cout << "Total sum of radii: " << endl << dTotalRadiusSum << endl;

    return 0;
}
