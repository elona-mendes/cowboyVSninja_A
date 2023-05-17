#include <iostream>
#include <stdexcept>
#include <string>
#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

#ifndef OLDNINJA_H
#define OLDNINJA_H

namespace ariel{
    class OldNinja: public Ninja{

    // class OldNinja{

        public:
        //constractor: hit = 150, speed = 8
            OldNinja(string name, Point pnt);

            // void move(Character* chrctr);

            // // If the Ninja is alive and distance from enemy < 1:
            // // enemy -40 hitPnt, else nithing happend.
            // void slash(Character* chrctr);
            
    };

}
#endif