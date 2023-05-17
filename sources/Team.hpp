#include <iostream>
#include <stdexcept>
#include <string>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

using namespace std;

#ifndef TEAM_H
#define TEAM_H

namespace ariel{
    class Team{

//Going over all members of the group (for attacking, printing, or comparing) 
//will always be done in the following order: 
//first go over all the cowboys, then go over all the ninjas. 
//Within each group, the transition will be made according to the order in which the characters were added.
        protected:
            Character* pointsArray[10];
            Character* leader;
            
        public:
            // Constructor
            Team(Character* chrctr);
            // Destructor
            ~Team(){
                
            }
            // Add character to your group
            void add(Character* chrctr);
            // Verify if enemy leader is alive: 
            // if alive, attack him
            // else, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
            // All the team that alive attacks the leader.
            // Cowboy that have balls shoot the leader, and cowboy that havn't balls reload theme.
            // Ninja that are close to the leader slash him, and approach otherwise. 
            // If the leader died in the attack - choose another one like the begining.
            // If there no alive person in our team, or enemy team: stop.
            void attack(Team* tEnemy);
            // Return the number of team character that alive.       
            int stillAlive();
            // Print all character details.
            void print();
            

    };

}
#endif