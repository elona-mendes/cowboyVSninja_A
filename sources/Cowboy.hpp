#include <iostream>
#include <stdexcept>
#include <string>
#include "Character.hpp"

using namespace std;

#ifndef COWBOY_H
#define COWBOY_H

namespace ariel{
    // class Cowboy{
    class Cowboy: public Character{
      
        private:
            int numBalls;
                
        public:

            Cowboy(string name, Point pnt);

            int getNumBalls(){
                return this->numBalls;
            }

            // Point::Point(double& xPnt, double& yPnt): xPoint(xPnt), yPoint(yPnt){
            //     this->xPoint = xPnt;
            //     this->yPoint = yPnt;
            // }

            // If the cowboy is alive: "shoot" the enemy, 
            //-10 to enemy "hitPnt" and -1 to "numBalls". 
            void shoot(Character* chrctr);
            // Return true if the cowboy had Balls, else return false.
            bool hasboolets();
            // Reload the cowboy balls, set them to 6.
            void reload();

    };

}
#endif