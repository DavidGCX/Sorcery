#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include "adaptor.h"
#include "ascii_graphics.h"
#include <memory>
#include "card.h"
#include "minion.h"
#include <string>
class Player;
class Minion;
class TextDisplay : public Adaptor {
        const int NUM_LINES = 11;
        const int NUM_CHARS = 165;
        std::vector<std::string> generateMinion(std::unique_ptr<Minion>* minion);
        std::vector<std::string> generateMinion(Minion* minion);
        std::vector<std::string> generateCard(std::unique_ptr<Card>* card);
        std::vector<std::string> generateEnchantment(std::unique_ptr<Enchantment>& enchantment);
        void printRow(const std::vector<std::vector<std::string>>& v);
        void printTopBorder();
        void printBottomBorder();
        void printBoard(std::unique_ptr<Player>& playerOne,std::unique_ptr<Player>& playerTwo);
    public:
        void printHand(std::unique_ptr<Player>& player) override;
        void printEnchantments(std::unique_ptr<Minion>& minion) override;
        TextDisplay(){};
        void refresh(std::unique_ptr<Player>& playerOne,std::unique_ptr<Player>& playerTwo) override;
};

#endif
