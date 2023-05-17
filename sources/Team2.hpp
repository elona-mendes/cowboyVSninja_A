#include <iostream>
#include <stdexcept>
#include <string>
#include "Team.hpp"

using namespace std;

#ifndef TEAM2_H
#define TEAM2_H

namespace ariel{
    class Team2: public Team{

//Going over all members of the group (for attacking, printing, or comparing) 
//will always be done in the following order: 
//The transition will be made according to the order in which the characters were added.
                      
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