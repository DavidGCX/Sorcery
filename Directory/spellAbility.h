#ifndef __SPELLABILITY_H__
#define __SPELLABILITY_H__
#include "spell.h"
#include "hasAbility.h"
#include "state.h"
#include <string>
#include <memory>
class GameController;
class Player;

class Banish: public Spell, public HasAbilityWithTarget, public HasAbilityWithTargetRitual {
    Banish(GameController* gameController, Player* owner, 
    std::string name = "Banish", int cost = 2) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility(std::unique_ptr<Minion>& target) override;
    bool useAbility(std::unique_ptr<Ritual>& target) override;
};

class Unsummon: public Spell, public HasAbilityWithTarget {
    Unsummon(GameController* gameController, Player* owner, 
    std::string name = "Unsummon", int cost = 1) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility(std::unique_ptr<Minion>& target) override;
};

class Recharge: public Spell, public HasAbilityWithTargetRitual {
    Recharge(GameController* gameController, Player* owner, 
    std::string name = "Recharge", int cost = 1) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility(std::unique_ptr<Ritual>& target) override;
};

class Disenchant: public Spell, public HasAbilityWithTarget {
    Disenchant(GameController* gameController, Player* owner, 
    std::string name = "Disenchant", int cost = 1) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility(std::unique_ptr<Minion>& target) override;
};

class RaiseDead: public Spell, public HasAbilityNoTarget {
    RaiseDead(GameController* gameController, Player* owner, 
    std::string name = "Raise Dead", int cost = 1) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility() override;
};

class Blizzard: public Spell, public HasAbilityNoTarget {
    Blizzard(GameController* gameController, Player* owner, 
    std::string name = "Blizzard", int cost = 3) :
    Spell{name, cost, gameController, owner}{}

    std::string getDescription() override;
    bool useAbility() override;
};

#endif // __SPEABILITY_H__