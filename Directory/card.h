#ifndef _CARD_H_
#define _CARD_H_
#include "subject.h"
#include "observer.h"
#include <string>
#include "state.h"
class GameController;
class Player;

// so for minions, they can only be in first three states, but for spells, 
// rituls and enchantments, if they are out of scope, then they are simply
// removed from the game;

class Card : public Observer {
        std::string name;
        int cost;
        State state;
        Player* owner;
    protected:
        GameController* gameController;
    public:
        Card(std::string name, int cost, GameController* gameController, Player* owner) : 
        name{name}, cost{cost}, gameController{gameController}, owner{owner} {
            state = State::onDeck; // by default, all cards are in deck;
        }
        std::string getName() {return name;}
        int getCost() {return cost;}
        Player* getOwner() { return owner; }
        void setState(State newState) { state = newState; }
        State getState() {return state; }
};

#endif
