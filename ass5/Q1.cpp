#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    Point p1 = Point(4.1, 3.2);
    Point p2 = Point(9.3, 4.7);

    Line line = Line(p1, p2);

    Point p3 = Point( 5.8, 7.3);
    Triangle triangle = Triangle(p1, p2, p3);

    Point p = Point(2.5, 8.4);
    Circle c = Circle(p, 2.9);

    std::ofstream output_file("output.txt");
    if (!output_file) {
        std::cout << "failed to open file output.txt for writing\n";
    }

    output_file << p1.Print() << std::endl;
    output_file << p2.Print() << std::endl;
    output_file << line.Print() << std::endl;

    output_file << p3.Print() << std::endl;
    output_file << triangle.Print() << std::endl;
    output_file << p.Print() << std::endl;
    output_file << c.Print() << std::endl;

    output_file.close();
}