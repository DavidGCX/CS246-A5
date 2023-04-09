#include <iostream>
#include <sstream>
#include <fstream>
#include "player.h"
#include "gameController.h"
#include "minion.h"
#include "graphicalDisplay.h"
#include "textDisplay.h"

using namespace std;

int main(int argc, const char** argv) {
    bool graphicson = false;
    bool testmode = false;
    string deck1 = "default.deck";
    string deck2 = "default.deck";
    unique_ptr<GameController> gc;
    string player1;
    string player2;
    fstream initfile;
    int count = 1;
    bool init = false;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == "-deck1") {
            deck1 = argv[i+1];
            ++i;
        } else if (argv[i] == "-deck2") {
            deck2 = argv[i+1];
            ++i;
        } else if (argv[i] == "-init") {
            init = true;
            fstream f{argv[i+1]};
            initfile = f;
            ++i;
        } else if (argv[i] == "-testing") {
            testmode = true;
            // set a bool for testing before activation
            // useAbility() should always return true
            // maybe grab the magic cost from the item you're using, compare, then manually add enough to do it if too low

            // in controller, use the bool to determine if the switch case / if statements should check for discard and draw commands

            // bool is to determine if shuffling or not
            gc->setTestMode();
        } else if (argv[i] == "-graphics") {
            // enable the graphics display
            bool graphicson = true;
            gc = make_unique<GameController>(new GraphicalDisplay{}, new TextDisplay{});
        }
    }
    if (graphicson == false) {
        gc = make_unique<GameController>(new TextDisplay{});
    }
    string line;
    while(true) {
        if(init == true) {
            getline(initfile, line);
            if (initfile.eof()) {
                init = false;
            }
        } else {
            getline(cin, s);            
        }
        if (count == 1) {
            gc->attachPlayer(line, 1, deck1);
            ++count;
            continue;
        } else if (count == 2) {
            gc->attachPlayer(line, 2, deck2);
            ++count;
            gc->onTurnStart();
            continue;
        } else {
            istringstream s{line};
            string firstword;
            s >> firstword;
            if (testmode == true) {
                if (firstword) == "draw") {
                    gc->drawCard();
                } else if (firstword == "discard") {
                    int num;
                    s >> num;
                    gc->discardCard(int num);
                }
            }
            if (firstword == "help") {
                cout << "Commands: help -- Display this message." << endl;
                cout << "          end -- End the current player’s turn." << endl;
                cout << "          quit -- End the game." << endl;
                cout << "          attack minion other-minion -- Orders minion to attack other-minion." << endl;
                cout << "          attack minion -- Orders minion to attack the opponent." << endl;
                cout << "          play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player." << endl;
                cout << "          use minion [target-player target-card] -- Use minion’s special ability, optionally targeting target-card owned by target-player." << endl;
                cout << "          inspect minion -- View a minion’s card and all enchantments on that minion." << endl;
                cout << "          hand -- Describe all cards in your hand." << endl;
                cout << "          board -- Describe all cards on the board." << endl;
            } else if (firstword == "end") {
                gc->endTurn();
            } else if (firstword == "quit") {
                break;
            } else if (firstword == "attack") {
                int attacker;
                int target;
                s >> attacker;
                if (!s.eof()) {
                    s >> target;
                    gc->attack(attacker, target);
                } else {
                    gc->attack(attacker);
                }
            } else if (firstword == "play") {
                int card;
                s >> card;
                if (s.eof()) {
                    gc->play(card);
                } else {
                    char target;
                    int player;
                    s >> player;
                    s >> target;
                    gc->play(card, target, player);
                }
            } else if (firstword == "use") {
                int card;
                s >> card;
                if (s.eof()) {
                    gc->use(card);
                } else {
                    int target;
                    int player;
                    s >> target;
                    s >> player;
                    gc->use(card, target, player);
                }
            } else if (firstword == "inspect") {
                int minion;
                s >> minion;
                gc->inspect(minion);
            } else if (firstword == "board") {
                gc->board();
            } else if (firstword == "hand") {
                gc->hand();
            }
        }
    }
    return 0;
}
