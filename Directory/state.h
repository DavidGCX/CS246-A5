#ifndef __STATE_H__
#define __STATE_H__



enum class StateInfo {
    onTurnStart,
    onTurnEnd,
    onMinionEnter,
    onMinionExit
};

enum class State {
    onDeck,
    onHand,
    onBoard,
    onGraveYard,
    removeFromTheGame
};

#endif // __STATE_H__