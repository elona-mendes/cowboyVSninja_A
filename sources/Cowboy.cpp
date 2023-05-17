#include "Cowboy.hpp"
#include "Point.hpp"

using namespace std;
using namespace ariel; 


Cowboy::Cowboy(string nme, Point pnt){
    this->name = nme;
    this->location= pnt;
    this->numBalls = 6;
    this->hitPnt = 110;
}

void Cowboy::shoot(Character* chrctr){
    return;
}

// Return true if the cowboy had Balls, else return false.
bool Cowboy::hasboolets(){
    return 0;
}
// Reload the cowboy balls, set them to 6.
void Cowboy::reload(){
    return;
}