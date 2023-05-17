#include <iostream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
// #include "Cowboy.hpp"
// #include "OldNinja.hpp"
// #include "TrainedNinja.hpp"
// #include "YoungNinja.hpp"
// #include "Ninja.hpp"

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

namespace ariel{
    class Character{
    // class Character: public Cowboy, public Ninja{
    // class Character: public Cowboy, public YountNinja, public OldNinja, public TrainedNinja{
    // class Character: public Cowboy, public Ninja{
      
        protected:
            Point location;
            string name;
            int hitPnt;
                   
        public:

            Character(){
                printf("None character \n");
                this->name = "None";
                this->location = Point(32.3,44);
                this->hitPnt = 0;
            }

            Character(Point lctin, string nme):name(nme), location(lctin){
                printf("Named character \n");
                this->name = nme;
                this->location = lctin;
            }
            //Getters
            string getName(){
                return this->name;
            }
            Point getLocation(){
                return this->location;
            }

            int getHitPoint(){
                return this->hitPnt;
            }

            string print();
            bool isAlive();
            double distance(Character* place1);
            void hit(int hits){
                this->hitPnt = this->hitPnt - hits;
            }

    };

}
#endif