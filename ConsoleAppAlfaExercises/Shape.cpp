#include "Header.h"
#define M_PI (3.14159265358979323846264338327950288)

Circle::Circle(double r) : radius(r) {}

double Circle::circumference() const {
    return 2 * M_PI * radius;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::lateralSurfaceArea() const {
    return 0.0;  // Circles don't have lateral surface area
}

double Circle::volume() const {
    return 0.0;  // Circles don't have volume
}

void Circle::printInfo() const {
    std::cout << "Circle Info:" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Circumference: " << circumference() << std::endl;
    std::cout << "Area: " << area() << std::endl;
}
std::string Circle::Execute(std::string& x) {
    return "";
}

std::string Circle::Execute(std::vector<double>& x) {
    Circle circle(x.at(0));
    circle.printInfo();
    return "";

}

Cylinder::Cylinder(double r, double h) : radius(r), height(h) {}

double Cylinder::circumference() const {
    return 2 * M_PI * radius;
}

double Cylinder::area() const {
    return M_PI * radius * radius;
}

double Cylinder::lateralSurfaceArea() const {
    return 2 * M_PI * radius * height;
}

double Cylinder::volume() const {
    return M_PI * radius * radius * height;
}

void Cylinder::printInfo() const {
    std::cout << "Cylinder Info:" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Circumference: " << circumference() << std::endl;
    std::cout << "Area: " << area() << std::endl;
    std::cout << "Lateral Surface Area: " << lateralSurfaceArea() << std::endl;
    std::cout << "Volume: " << volume() << std::endl;
}

std::string Cylinder::Execute(std::string& x) {
    return "";
}

std::string Cylinder::Execute(std::vector<double>& x) {
    Cylinder cylinder(x.at(0), x.at(1));
    cylinder.printInfo();
    return "";
}
