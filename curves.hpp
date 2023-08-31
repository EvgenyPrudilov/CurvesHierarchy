
#ifndef CURVES_HPP
#define CURVES_HPP

class Point3D {
    public:
        double dX, dY, dZ;

        Point3D(double dX, double dY, double dZ);
};

class Vector3D : public Point3D { 
    public:
        Vector3D(double dX, double dY, double dZ);
};

class Curve {
    public:
        virtual const char * getName(void) const = 0;       
        virtual Point3D getPoint3D(double t) const = 0;
        virtual Vector3D getDerivative(double t) const = 0;
};

class Circle : public Curve {
    private:
        double dRadius;

    public:
        Circle(double dRadius);
        const char * getName(void) const override;
        Point3D getPoint3D(double t) const override;
        Vector3D getDerivative(double t) const override;
        double getRadius() const;
};

class Ellipse : public Curve {
    private:
        double dRadiusX, dRadiusY;

    public:
        Ellipse(double dRadiusX, double dRadiusY);
        const char * getName(void) const override;
        Point3D getPoint3D(double t) const override;
        Vector3D getDerivative(double t) const override;
};

class Helix : public Curve {
    private:
        double dRadius, dStep;

    public:
        Helix(double dRadius, double dStep);
        const char * getName(void) const override;
        Point3D getPoint3D(double t) const override;
        Vector3D getDerivative(double t) const override;
};

#endif