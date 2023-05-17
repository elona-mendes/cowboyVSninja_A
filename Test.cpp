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

TEST_SUITE("Attack actions"){

    TEST_CASE("Cowboy attack"){

        Point a(33, 44);
        Cowboy *tom = new Cowboy("Tom", a);
        OldNinja *sushi = new OldNinja("sushi", Point(1.3,3.5));
        
        CHECK(tom->hasboolets());
        tom->shoot(sushi);
        CHECK(tom->getNumBalls() == 5);
        CHECK(sushi->getHitPoint() == 140);

        for (int i = 5; i > 0; i--)
        {
            tom->shoot(sushi);
        }
        CHECK(tom->hasboolets() == false);
        CHECK(tom->getNumBalls() == 0);
        CHECK(sushi->getHitPoint() == 80);

        tom->reload();
        CHECK(tom->getNumBalls() == 6);
        
    }

    TEST_CASE("Ninja attack"){
        Point b(1.3,3.5), c(2, 3);
        TrainedNinja *nigiri = new TrainedNinja("nigiri", b);
        YoungNinja *baget = new YoungNinja("baget", c);

        Cowboy *tom = new Cowboy("Tom", Point(32.3,44));

        nigiri->slash(baget);
        CHECK(baget->getHitPoint() == 60);

        baget->slash(tom);
        CHECK(tom->getHitPoint() == 110);

        int i = 0;
        // i avoid infinit loop in the case "move" or "distance" doesn't works.
        while (baget->distance(tom) > 1 && i<15)
        {
           baget->move(tom);
           i +=1;
        }
        CHECK(baget->getLocation().getX() != 2);
        CHECK(baget->getLocation().getY() != 3);
        CHECK(baget->distance(tom) < 1);

        baget->slash(tom);
        CHECK(tom->getHitPoint() == 70);
    }
}

TEST_SUITE("Team"){
    TEST_CASE("Init team"){
        Cowboy *tom = new Cowboy("Tom", Point(32.3,44));
        YoungNinja *baget = new YoungNinja("baget", Point(1, 2));

        CHECK_NOTHROW(Team team_A(tom)); 
        CHECK_NOTHROW(Team team_B(baget));

    }

    TEST_CASE("Add members"){
        Cowboy *tom = new Cowboy("Tom", Point(32.3,44));
        YoungNinja *baget1 = new YoungNinja("baget", Point(32.3,42));
        YoungNinja *baget2 = new YoungNinja("baget", Point(12.3,42));
        YoungNinja *baget3 = new YoungNinja("baget", Point(22.1,42));
        YoungNinja *baget4 = new YoungNinja("baget", Point(32.3,42));
        YoungNinja *baget5 = new YoungNinja("baget", Point(34.3,52));
        YoungNinja *baget6 = new YoungNinja("baget", Point(35.3,42));
        YoungNinja *baget7 = new YoungNinja("baget", Point(36.3,42));
        YoungNinja *baget8 = new YoungNinja("baget", Point(37,78));
        YoungNinja *baget9 = new YoungNinja("baget", Point(38,12));

        Team team_A(tom);
        CHECK_NOTHROW(team_A.add(new YoungNinja("Yogi", Point(62,57))));
        team_A.add(new YoungNinja("Yogi", Point(64,57)));
        team_A.add(baget1);
        team_A.add(baget2);
        team_A.add(baget3);
        team_A.add(baget4);
        team_A.add(baget5);
        team_A.add(baget6);
        team_A.add(baget7);
        team_A.add(baget8);
        
        CHECK_THROWS(team_A.add(new YoungNinja("Yogi", Point(64,57))));
    }

    TEST_CASE("Attack"){
        Cowboy *tom = new Cowboy("Tom", Point(1.3, 3));
        YoungNinja *baget = new YoungNinja("baget", Point(1, 2));

        Team team_A(tom);
        Team team_B(baget);

        CHECK(team_A.stillAlive() == 1); 
        CHECK(team_B.stillAlive() == 1);

        while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
            team_A.attack(&team_B);
            team_B.attack(&team_A);
        }
        CHECK(team_A.stillAlive() == 0); 
        CHECK(team_B.stillAlive() == 1); 
        CHECK_NOTHROW(Team team_B(baget));
    }
}