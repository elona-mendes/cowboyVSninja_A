#include <iostream>
#include <stdexcept>
#include <string>
#include "Team.hpp"

using namespace std;

#ifndef SMARTTEAM_H
#define SMARTTEAM_H

namespace ariel{
    class SmartTeam: public Team{

// The same as the team, the transition to the characters will be by choice in whatever order you want. 
// It is permissible and desirable at this stage to "ask" the other group 
// about the positions of their forces and their status 
// as well as consider the situation of the attacking group in order to maximize damage.
                      
        protected:
            // Verify if enemy leader is alive: 
            // if alive, attack him
            // else, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
            // All the team that alive attacks the leader.
            // Cowboy that have balls shoot the leader, and cowboy that havn't balls reload theme.
            // Ninja that are close to the leader slash him, and approach otherwise. 
            // If the leader died in the attack - choose another one like the begining.
            // If there no alive person in our team, or enemy team: stop.
            void attack(Team* tEnemy);
            // Print all character details.
            void print();
            
    };

}
#endif