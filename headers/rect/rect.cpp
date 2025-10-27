#include "rect.h"

Rectangle::Rectangle(double h, double w): height(h), width(w) {}

double Rectangle::getHeight() const { return this->height; }
double Rectangle::getWidth() const { return this->width; }

void Rectangle::setHeight(const double h) { this->height = h; }
void Rectangle::setWidth(const double w) { this->width = w; }

double Rectangle::area() const {
    return this->height * this->width;
}
