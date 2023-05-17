#include "YoungNinja.hpp"

using namespace std;
using namespace ariel; 

//constractor: hit = 150, speed = 8
YoungNinja::YoungNinja(string nme, Point pnt){
    this->name = nme;
    this->point = pnt;
    this->hitPnt = 100;
    this->speed = 14;
}