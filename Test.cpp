#include "doctest.h"

#include <stdexcept>
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

#include "sources/Team.hpp"
using namespace ariel;

TEST_SUITE("Point") {
    TEST_CASE("Init point whith prameter") {
        Point p(0, 0.1);

        CHECK(p.getX() == 0);
        CHECK(p.getY() == 0.1);
    }

    TEST_CASE("Init point whithout prameter") {
        Point p(0.0, 0.0);
        Point p1;

        CHECK(p.getX() == p1.getX());
        CHECK(p.getY() == p1.getY());
    }

    TEST_CASE("Print point"){
        Point a(32.3,44);
        CHECK(a.print() == "(32.3, 44)");
    }

    TEST_CASE("Point distance"){
        Point a(0, 1);
        Point b(0, 2);
        Point e(2, 1);
        Point c(2, 1);
        CHECK(a.distance(e) == 2.0);
        CHECK(a.distance(b) == 1.0);
        CHECK(e.distance(c) == 0);
        CHECK(b.distance(c) <= 2.24);
        CHECK(b.distance(c) >= 2.23);
    }
}

TEST_SUITE("Characters constractors"){
    TEST_CASE("Cowboy constractor"){
        Point a(33, 44);
        Cowboy *tom = new Cowboy("Tom", a);
        CHECK(tom->getLocation().getX() == 33);
        CHECK(tom->getLocation().getY() == 44);
        CHECK(tom->getName() == "Tom");
        CHECK(tom->isAlive() == true);
        CHECK(tom->getNumBalls() == 6);
        CHECK(tom->getHitPoint() == 110);
    }

    TEST_CASE("Ninja constractor"){
        Point a(32.3,44),b(1.3,3.5), c(2, 55);
        OldNinja *sushi = new OldNinja("sushi", a);
        TrainedNinja *nigiri = new TrainedNinja("nigiri", b);
        YoungNinja *baget = new YoungNinja("baget", c);

        CHECK(sushi->getLocation().getX() == 32.3);
        CHECK(sushi->getLocation().getY() == 44);

        CHECK(sushi->getName() == "sushi");
        CHECK(nigiri->getName() == "nigiri");
        CHECK(baget->getName() == "baget");

        CHECK(sushi->isAlive() == true);

        CHECK(sushi->getHitPoint() == 150);
        CHECK(sushi->getSpeed() == 8);

        CHECK(nigiri->getHitPoint() == 120);
        CHECK(nigiri->getSpeed() == 12);

        CHECK(baget->getHitPoint() == 100);
        CHECK(baget->getSpeed() == 14);
    }
}


// TEST_CASE("Test play one turn after empty stack - Error (5)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     //if its stop, the two players cant play another turn because they havn't cards.
//     for (int i=0;i<10;i++) {
//         game.playTurn();
//     } 
//     // while (p1.stacksize()>0) {
//     //     game.playTurn();
//     // }
//     CHECK_THROWS(game.playTurn());  // check that some exception is thrown
// }

// TEST_CASE("Play two games at same time (6)"){
//     Player p1("Alice");
//     Player p2("Bob");
//     Player p3("Anna");
//     Player p4("Dani");

//     Game game1(p1,p2);
//     Game game2(p3,p4);
//     game1.playTurn();
//     game2.playTurn();
//     CHECK(p1.stacksize() < 25); 
//     CHECK(p2.stacksize() < 25); 
//     CHECK(p3.stacksize() < 25); 
//     CHECK(p4.stacksize() < 25); 
// }

// TEST_CASE("Print last turn after one turn (7)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     game.playTurn();
//     //== 0 mean print succesfuly
//     CHECK(game.printLastTurn() == 0);
// }

// TEST_CASE("Try to print last turn before play a turn - Error (8)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     //cant print last turn because havn't turns
//     CHECK_THROWS(game.printLastTurn());
// }

// TEST_CASE("Try to printLog after 2 turn (9)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     game.playTurn();
//     game.playTurn();
//     //cant print last turn because havn't last turn
//     CHECK(game.printLog() == 0);
// }

// TEST_CASE("Try to printLog before play a turn - Error (10)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     //cant print log because havn't last turns
//     CHECK_THROWS(game.printLog());
// }

// TEST_CASE("Print the winner at the end of the game (11)"){

//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     game.playAll();

//     CHECK( game.printWiner() == 0);
// }

// TEST_CASE("Try to printWiner before the end of the game - Error (12)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);

//     for (int i=0;i<5;i++) {
//         game.playTurn();
//     } 

//     if(p1.stacksize()!=0){
//         //cant print winner because the game not end 
//         CHECK_THROWS(game.printWiner());
//     }
// }

// TEST_CASE("Try to printWiner before the beginning of thr game - Error (13)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     CHECK_THROWS(game.printWiner());
// }

// TEST_CASE("player try to play in 2 games at same time - Error (14)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     Game game1(p1,p2);
//     //the players cant play if there are in two games.
//     CHECK_THROWS(game.playTurn());
// }

// TEST_CASE("check card without aquality (15)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     game.playTurn();
//     //when game make a turn the player take a card, and after that the last card that was played are in  player.card()
//     if (p1.cardesTaken() < 6 && p2.cardesTaken() < 6){
//         if(p1.card() > p2.card()){
//         CHECK(p1.cardesTaken() == 2);
//         CHECK(p2.cardesTaken() == 0);
//         }
//         else{
//             CHECK(p1.cardesTaken() == 0);
//             CHECK(p2.cardesTaken() == 2);
//         }
//     }
// }

// TEST_CASE("check set card (16)"){
//     Player p1("Alice");
//     Player p2("Bob");

//     Game game(p1,p2);
//     p1.setCrd(6);
//     p2.setCrd(6);
//     CHECK(p2.card() == p1.card());

//     p2.setCrd(9);
//     CHECK(p2.card() > p1.card());

//     p1.setCrd(11);
//     CHECK(p2.card() < p1.card());
// }

// TEST_CASE("check set card with duplicated values (17)"){
//     //Each number has 4 options to be and no more, we will check that an error is 
//     //issued for times.

//     Player p1("Alice");
//     Player p2("Bob");

//     p1.setCrd(6);
//     p1.setCrd(6);
//     p1.setCrd(6);
//     p1.setCrd(6);

//     CHECK_THROWS(p1.setCrd(6));
// }

// TEST_CASE("check set card with errors values (18)"){

//     Player p1("Alice");

//     CHECK_THROWS(p1.setCrd(0));
//     CHECK_THROWS(p1.setCrd(14));
//     CHECK_THROWS(p1.setCrd(-2));
// }

// TEST_CASE("Init player without name, default player (19)"){
//     Player p1;

//     CHECK(p1.getName().compare("None"));
//     CHECK(p1.stacksize() == 26);
//     CHECK(p1.cardesTaken() == 0);
//     CHECK(p1.getSumpnt() == 0);
// }

// TEST_CASE("Init game without players, default players (20)"){
//     Game game;
//     CHECK(game.getp1().getName().compare("None1"));
//     CHECK(game.getp2().getName().compare("None2"));
//     CHECK(game.getp1().stacksize() == 26);
//     CHECK(game.getp1().cardesTaken() == 0);
//     CHECK(game.getp1().getSumpnt() == 0);
// }