#include <iostream>
#include <stdexcept>
#include <string>
#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H

namespace ariel{
    class YoungNinja: public Ninja{
      
        public:
        //constractor: hit = 100, speed = 14
            YoungNinja(string name, Point pnt);

            // void move(Character* chrctr);

            // // If the Ninja is alive and distance from enemy < 1:
            // // enemy -40 hitPnt, else nithing happend.
            // void slash(Character* chrctr);
    };

}
#endif