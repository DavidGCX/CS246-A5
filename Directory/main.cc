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
    string initfile;
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
            initfile = argv[i+1];
            ++i;
        } else if (argv[i] == "-testing") {
            testmode = true;
            gc->setTestMode();
        } else if (argv[i] == "-graphics") {
            bool graphicson = true;
            gc->attachAdapter(make_unique<GraphicalDisplay>());
            gc->attachAdapter(make_unique<TextDisplay>());
        }
    }
    if (graphicson == false) {
        gc->attachAdapter(make_unique<TextDisplay>());
    }
    if (init == true) {
        fstream f{initfile};
    }
    string cmd;
    bool hasFirstPlayer = false;
    bool hasSecondPlayer = false;

    while(true) {
        if(init == true) {
            getline(f, cmd);
            istringstream s{cmd};
            if (f.eof()) {
                init = false;
            }
        } else {
            getline(cin, cmd);  
            istringstream s{cmd};        
        }
        if (!hasFirstPlayer) {
            gc->attachPlayer(cmd, 1, deck1);
            hasFirstPlayer = true;
        }
        else if (!hasSecondPlayer) {
            gc->attachPlayer(cmd, 2, deck2);
            hasSecondPlayer = true;
        }
        else {
            if (s == "draw") {
                if (testmode) gc->drawCard();
            }
            else if (s == "discard") {
                if (testmode) {
                    int num;
                    s >> num;
                    gc->discardCard(num);
                }
            }
            else if (s == "help") {
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
            }
            else if (s == "end") {
                gc->endTurn();
            }
            else if (s == "quit") {
                break;
            }
            else if (s == "attack") {
                int attacker;
                int target;
                s >> attacker;
                if (!s.eof()) {
                    s >> target;
                    gc->attack(attacker, target);
                } else {
                    gc->attack(attacker);
                }
                gc->attack(attacker, target);
            } else if (s == "play") {
                int card;
                s >> card;
                if (s.eof()) {
                    gc->play(card);
                } else {
                    char target;
                    int player;
                    s >> player;
                    s >> target;
                    gc->play(card, player, target);
                }
            }  else if (s == "use") {
                int card;
                s >> card;
                if (s.eof()) {
                    gc->use(card);
                } else {
                    char target;
                    int player;
                    s >> target;
                    s >> player;
                    gc->use(card,  player, target);
                }
            } else if (s == "inspect") {
                int minion;
                s >> minion;
                gc->inspect(minion);
            } else if (s == "board") {
                gc->board();
            } else if (s == "hand") {
                gc->hand();
            }
        }
        // if (count == 1) {
        //     gc->attachPlayer(line, 1, deck1);
        //     ++count;
        //     continue;
        // } else if (count == 2) {
        //     gc->attachPlayer(line, 2, deck2);
        //     ++count;
        //     continue;
        // } else {
        //     istringstream s{line};
        //     string firstword;
        //     s >> firstword;
            // if (testmode == true) {
            //     if (firstword == "draw") {
            //         gc->drawCard();
            //     } else if (firstword == "discard") {
            //         int num;
            //         s >> num;
            //         gc->discardCard(num);
            //     }
            // }
            // if (firstword == "help") {
            //     cout << "Commands: help -- Display this message." << endl;
            //     cout << "          end -- End the current player’s turn." << endl;
            //     cout << "          quit -- End the game." << endl;
            //     cout << "          attack minion other-minion -- Orders minion to attack other-minion." << endl;
            //     cout << "          attack minion -- Orders minion to attack the opponent." << endl;
            //     cout << "          play card [target-player target-card] -- Play card, optionally targeting target-card owned by target-player." << endl;
            //     cout << "          use minion [target-player target-card] -- Use minion’s special ability, optionally targeting target-card owned by target-player." << endl;
            //     cout << "          inspect minion -- View a minion’s card and all enchantments on that minion." << endl;
            //     cout << "          hand -- Describe all cards in your hand." << endl;
            //     cout << "          board -- Describe all cards on the board." << endl;
            // } else if (firstword == "end") {
            //     gc->endTurn();
            // } else if (firstword == "quit") {
            //     break;
            // } else if (firstword == "attack") {
            //     int attacker;
            //     int target;
            //     s >> attacker;
            //     if (!s.eof()) {
            //         s >> target;
            //         gc->attack(attacker, target);
            //     } else {
            //         gc->attack(attacker);
            //     }
            // } else if (firstword == "play") {
            //     int card;
            //     s >> card;
            //     if (s.eof()) {
            //         gc->play(card);
            //     } else {
            //         char target;
            //         int player;
            //         s >> player;
            //         s >> target;
            //         gc->play(card, player, target);
            //     }
            // } else if (firstword == "use") {
            //     int card;
            //     s >> card;
            //     if (s.eof()) {
            //         gc->use(card);
            //     } else {
            //         char target;
            //         int player;
            //         s >> target;
            //         s >> player;
            //         gc->use(card,  player, target);
            //     }
            // } else if (firstword == "inspect") {
            //     int minion;
            //     s >> minion;
            //     gc->inspect(minion);
            // } else if (firstword == "board") {
            //     gc->board();
            // } else if (firstword == "hand") {
            //     gc->hand();
            // }
    }
    return 0;
}
