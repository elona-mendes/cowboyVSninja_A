#include "Point.hpp"

using namespace std;
using namespace ariel; 


Point::Point(double xPnt, double yPnt): xPoint(xPnt), yPoint(yPnt){
    this->xPoint = xPnt;
    this->yPoint = yPnt;
}

string Point::print(){

    // take from chatGPT:
    std::stringstream ss;
    ss << "(" << this->xPoint << ", " << this->yPoint << ")";
    std::string str = ss.str();
    return str;

    // string str = "(" + this->xPoint + ", " + this->yPoint + " )";
    // return str;
}
double Point::distance(Point pntB){
    double distx = pow((pntB.getX() - this->xPoint), 2);
    double disty = pow((pntB.getY() - this->yPoint), 2);
    return sqrt(distx + disty);
}
Point moveTowards(Point src, Point dest, double dist);
