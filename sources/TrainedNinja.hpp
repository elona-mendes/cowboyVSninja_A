#include <iostream>
#include <stdexcept>
#include <string>
#include "Ninja.hpp"

using namespace std;

#ifndef TRAINEDNINJA_H
#define TRAINEDNINJA_H

namespace ariel{
    // class TrainedNinja{
    class TrainedNinja: public Ninja{
                     
        public:
        //constractor: hit = 120, speed = 12
            TrainedNinja(string name, Point pnt);
            
            // void move(Character* chrctr);

            // // If the Ninja is alive and distance from enemy < 1:
            // // enemy -40 hitPnt, else nithing happend.
            // void slash(Character* chrctr);
    };

}
#endif