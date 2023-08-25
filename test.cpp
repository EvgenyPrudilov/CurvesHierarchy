
#include <gtest/gtest.h>
#include <iostream>

#include "curves.hpp"
#include <cmath>

// Point3D class constructor testing
TEST(Point3D_Test, Constructor) {
    Point3D * point1 = new Point3D(1.0, 2.0, 3.0);
    ASSERT_DOUBLE_EQ(point1->dX, 1.0);
    ASSERT_DOUBLE_EQ(point1->dY, 2.0);
    ASSERT_DOUBLE_EQ(point1->dZ, 3.0);

    Point3D * point2 = new Point3D(-1.0, -2.0, -3.0);
    ASSERT_DOUBLE_EQ(point2->dX, -1.0);
    ASSERT_DOUBLE_EQ(point2->dY, -2.0);
    ASSERT_DOUBLE_EQ(point2->dZ, -3.0);
}

// Vector3D class constructor testing
TEST(Vector3D_Test, Constructor) {
    Vector3D * point1 = new Vector3D(1.0, 2.0, 3.0);
    ASSERT_DOUBLE_EQ(point1->dX, 1.0);
    ASSERT_DOUBLE_EQ(point1->dY, 2.0);
    ASSERT_DOUBLE_EQ(point1->dZ, 3.0);

    Vector3D * point2 = new Vector3D(-1.0, -2.0, -3.0);
    ASSERT_DOUBLE_EQ(point2->dX, -1.0);
    ASSERT_DOUBLE_EQ(point2->dY, -2.0);
    ASSERT_DOUBLE_EQ(point2->dZ, -3.0);
}

// Circle class constructor and Circle.getRadius() method testing
TEST(Circle_Test, ConstructorAndGetRadius) {
    Circle * circle1 = new Circle(1.0);
    ASSERT_DOUBLE_EQ(circle1->getRadius(), 1.0);

    Circle * circle2 = new Circle(0.0);
    ASSERT_DOUBLE_EQ(circle2->getRadius(), 0.0);

    Circle * circle3 = new Circle(-1.0);
    ASSERT_DOUBLE_EQ(circle3->getRadius(), 1.0);
}

// Circle.getPoint3D() method testing
TEST(Circle_Test, GetPoint3D) {
    Circle * circle1 = new Circle(1.0);
    auto point1 = circle1->getPoint3D(0.0);
    ASSERT_NEAR(point1.dX, 1.0, 0.0009);
    ASSERT_NEAR(point1.dY, 0.0, 0.0009);
    ASSERT_NEAR(point1.dZ, 0.0, 0.0009);

    Circle * circle2 = new Circle(1.0);
    auto point2 = circle2->getPoint3D(0.7853981);
    ASSERT_NEAR(point2.dX, 0.707, 0.0009);
    ASSERT_NEAR(point2.dY, 0.707, 0.0009);
    ASSERT_NEAR(point2.dZ, 0.0, 0.0009);

    Circle * circle3 = new Circle(1.0);
    auto point3 = circle3->getPoint3D(-0.7853981);
    ASSERT_NEAR(point3.dX, 0.707, 0.0009);
    ASSERT_NEAR(point3.dY, -0.707, 0.0009);
    ASSERT_NEAR(point3.dZ, 0.0, 0.0009);
}

// Circle.getDerivative() method testing
TEST(Circle_Test, GetDerivative) {
    Circle * circle1 = new Circle(1.0);
    auto point = circle1->getDerivative(0.7853981);

    ASSERT_NEAR(point.dX, -0.707, 0.0009);
    ASSERT_NEAR(point.dY, 0.707, 0.0009);
    ASSERT_NEAR(point.dZ, 0.0, 0.0009);
}

// Ellipse.getPoint3D() method testing
TEST(Ellipse_Test, GetPoint3D) {
    Ellipse * circle1 = new Ellipse(1.0, 1.0);
    auto point1 = circle1->getPoint3D(0.0);
    ASSERT_NEAR(point1.dX, 1.0, 0.0009);
    ASSERT_NEAR(point1.dY, 0.0, 0.0009);
    ASSERT_NEAR(point1.dZ, 0.0, 0.0009);

    Ellipse * circle2 = new Ellipse(1.0, 1.0);
    auto point2 = circle2->getPoint3D(0.7853981);
    ASSERT_NEAR(point2.dX, 0.707, 0.0009);
    ASSERT_NEAR(point2.dY, 0.707, 0.0009);
    ASSERT_NEAR(point2.dZ, 0.0, 0.0009);

    Ellipse * circle3 = new Ellipse(1.0, 1.0);
    auto point3 = circle3->getPoint3D(-0.7853981);
    ASSERT_NEAR(point3.dX, 0.707, 0.0009);
    ASSERT_NEAR(point3.dY, -0.707, 0.0009);
    ASSERT_NEAR(point3.dZ, 0.0, 0.0009);
}

// Ellipse.getDerivative() method testing
TEST(Ellipse_Test, GetDerivative) {
    Ellipse * circle1 = new Ellipse(1.0, 1.0);
    auto point = circle1->getDerivative(0.7853981);

    ASSERT_NEAR(point.dX, -0.707, 0.0009);
    ASSERT_NEAR(point.dY, 0.707, 0.0009);
    ASSERT_NEAR(point.dZ, 0.0, 0.0009);
}

/*// Helix.getPoint3D() method testing
TEST(Helix_Test, GetPoint3D) {
    Helix * circle1 = new Helix(1.0, M_PI * 2);
    auto point1 = circle1->getPoint3D(0.0);
    ASSERT_NEAR(point1.dX, 1.0, 0.0009);
    ASSERT_NEAR(point1.dY, 0.0, 0.0009);
    ASSERT_NEAR(point1.dZ, 0.0, 0.0009);

    Helix * circle2 = new Helix(1.0, M_PI * 2);
    auto point2 = circle2->getPoint3D(0.7853981);
    ASSERT_NEAR(point2.dX, 0.707, 0.0009);
    ASSERT_NEAR(point2.dY, 0.707, 0.0009);
    ASSERT_NEAR(point2.dZ, 0.0, 0.0009);

    Helix * circle3 = new Helix(1.0, M_PI * 2);
    auto point3 = circle3->getPoint3D(-0.7853981);
    ASSERT_NEAR(point3.dX, 0.707, 0.0009);
    ASSERT_NEAR(point3.dY, -0.707, 0.0009);
    ASSERT_NEAR(point3.dZ, 0.0, 0.0009);
}

// Helix.getDerivative() method testing
TEST(Helix_Test, GetDerivative) {
    Helix * circle1 = new Helix(1.0, M_PI * 2);
    auto point = circle1->getDerivative(0.7853981);

    ASSERT_NEAR(point.dX, -0.707, 0.0009);
    ASSERT_NEAR(point.dY, 0.707, 0.0009);
    ASSERT_NEAR(point.dZ, 0.0, 0.0009);
}*/

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
