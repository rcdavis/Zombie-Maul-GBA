
#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

typedef enum
{
    UNKNOWN,
    MAIN_MENU,
    PLAY
} State;

typedef struct
{
    int curState;
    int nextState;

    void (*update)(struct GameState* const);
    void (*render)(struct GameState* const);
} GameState;

#endif
