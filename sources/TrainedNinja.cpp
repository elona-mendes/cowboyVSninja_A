#include "TrainedNinja.hpp"

using namespace std;
using namespace ariel; 

//constractor: hit = 150, speed = 8
TrainedNinja::TrainedNinja(string nme, Point pnt){
    this->name = nme;
    this->point = pnt;
    this->hitPnt = 120;
    this->speed = 12;
}