#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>

#ifndef POINT_H
#define POINT_H

namespace ariel{
    class Point{
      
        private:
            double xPoint;
            double yPoint;
                   
        public:

            //Constructor
            Point(double xPnt, double yPnt);

            Point(){
                this->xPoint=0;
                this->yPoint=0;
            }

            //Getters
            double getX(){
                return this->xPoint;
            }
            double getY(){
                return this->yPoint;
            }

            std::string print();
            double distance(Point pntB);
            Point moveTowards(Point src, Point dest, double dist);

    };

}
#endif