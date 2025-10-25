#ifndef RECT_H
#define RECT_H

class Rectangle {
    double height;
    double width;

    public:
        Rectangle(double h, double w);

        //getters
        double getHeight() const;
        double getWidth() const;

        //setters
        void setHeight(const double height);
        void setWidth(const double width);

        double area() const;
};

#endif