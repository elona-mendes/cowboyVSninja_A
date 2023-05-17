#include "OldNinja.hpp"

using namespace std;
using namespace ariel; 

//constractor: hit = 150, speed = 8
OldNinja::OldNinja(string nme, Point pnt){
    this->name = nme;
    this->point = pnt;
    this->hitPnt = 150;
    this->speed = 8;
}