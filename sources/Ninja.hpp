#include <iostream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

#ifndef NINJA_H
#define NINJA_H

namespace ariel{
    // class Ninja{
    class Ninja: public Character{
//    class Ninja: public YountNinja, public OldNinja, public TrainedNinja{

        protected:

            string name;
            Point point;
            int speed;

        public:
                   
            // Recive poiter to character and move to him the same as his speed 
            // (if speed = 6, move distance 6).
            void move(Character* chrctr);

            // If the Ninja is alive and distance from enemy < 1:
            // enemy -40 hitPnt, else nithing happend.
            void slash(Character* chrctr);

            int getSpeed(){
                return this->speed;
            }
            

    };

}
#endif