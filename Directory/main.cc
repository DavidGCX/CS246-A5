#include <iostream>
#include <sstream>
#include <fstream>
#include "player.h"
#include "gameController.h"
#include "minion.h"
#include "graphicalDisplay.h"/#include "textDisplay.h"
#include <string>

using namespace std;

bool whileloop (istream& s, bool testmode, bool &hasFirstPlayer, bool &hasSecondPlayer, GameController &gc) {
	bool value = false;
	string firstword;
	s >> firstword;
        if (!hasFirstPlayer) {
            //gc->attachPlayer(cmd, 1, deck1);
            hasFirstPlayer = true;
	    cout << "first player done" << endl;
        } else if (!hasSecondPlayer) {
            //gc->attachPlayer(cmd, 2, deck2);
            hasSecondPlayer = true;
	    cout << "second player done" << endl;
        } else {
            if (firstword == "draw") {
                if (testmode) {
			//gc->drawCard();
			cout << "draw" << endl;
		}
            } else if (firstword == "discard") {
                if (testmode) {
                    int num;
                    s >> num;
                    //gc->discardCard(num);
		    cout << "discard" << endl; 
                }
            } else if (firstword == "help") {
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
                //gc->endTurn();
		cout << "end" << endl;
            } else if (firstword == "quit") {
		cout << "quit" << endl;
                value = true;
            } else if (firstword == "attack") {
                int attacker;
                int target;
                s >> attacker;
                if (!s.eof()) {
                    s >> target;
                    //gc->attack(attacker, target);
		    cout << "attack 2 params" << endl;
                } else {
                    //gc->attack(attacker);
		    cout << "attack 1 param" << endl;
                }
                //gc->attack(attacker, target);
            } else if (firstword == "play") {
                int card;
                s >> card;
                if (s.eof()) {
                    //gc->play(card);
		    cout << "play 1 param" << endl;
                } else {
                    char target;
                    int player;
                    s >> player;
                    s >> target;
                    //gc->play(card, player, target);
		    cout << "play 3 params" << endl;
                }
            } else if (firstword == "use") {
                int card;
                s >> card;
                if (s.eof()) {
                    //gc->use(card);
		    cout << "use 1 param" << endl;
                } else {
                    char target;
                    int player;
                    s >> target;
                    s >> player;
                    //gc->use(card,  player, target);
		    cout << "use 3 params" << endl;
                }
            } else if (firstword == "inspect") {
                int minion;
                s >> minion;
                //gc->inspect(minion);
		cout << "inspect" << endl;
            } else if (firstword == "board") {
                //gc->board();
		cout << "board" << endl;
            } else if (firstword == "hand") {
                //gc->hand();
		cout << "hand" << endl;
            }
	}
	return value;
}

int main(int argc, const char* argv[]) {
    bool graphicson = false;
    bool testmode = false;
    string deck1 = "default.deck";
    string deck2 = "default.deck";
    //unique_ptr<GameController> gc;
    string initfile;
    bool init = false;
    for (int i = 1; i < argc; ++i) {
	string arg1 = argv[i];
        if (arg1 == "-deck1") {
            deck1 = argv[i+1];
            ++i;
	    cout << "-deck1" << endl;
        } else if (arg1 == "-deck2") {
            deck2 = argv[i+1];
            ++i;
	    cout << "-deck2" << endl;
        } else if (arg1 == "-init") {
            init = true;
            initfile = argv[i+1];
            ++i;
	    cout << "-init" << endl;
        } else if (arg1 == "-testing") {
            testmode = true;
            //gc->setTestMode();
	    cout << "-testing" << endl;
        } else if (arg1 == "-graphics") {
            bool graphicson = true;
            //gc->attachAdapter(make_unique<GraphicalDisplay>());
            //gc->attachAdapter(make_unique<TextDisplay>());
	    cout << "-graphics" << endl;
        }
    }
    if (graphicson == false) {
        //gc->attachAdapter(make_unique<TextDisplay>());
    }
    fstream f{initfile};
    string cmd;
    bool hasFirstPlayer = false;
    bool hasSecondPlayer = false;
    bool quitting = false;
    while(true) {
    	if(init == true) {
            getline(f, cmd);
            istringstream s{cmd};
            if (f.eof()) {
                init = false;
            }
	    cout << "we on file" << endl;
	    quitting = whileloop(s, testmode, hasFirstPlayer, hasSecondPlayer, gc);
	    if (quitting == true) {
		    break;
            }
    	} else {
            getline(cin, cmd);
            istringstream s{cmd};
	    cout << "we on std input" << endl;
	    quitting = whileloop(s, testmode, hasFirstPlayer, hasSecondPlayer, gc);
	    if (quitting == true) {
		    break;
            }
    	}
    }
    return 0;
}
