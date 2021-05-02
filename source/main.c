
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <stdio.h>
#include <stdlib.h>

#include "textures/MenuBG.h"
#include "states/MainMenuState.h"
#include "states/PlayState.h"

GameState state;

void UpdateState();

int main(void)
{
    // the vblank interrupt must be enabled for VBlankIntrWait() to work
    // since the default dispatcher handles the bios flags no vblank handler
    // is required
    irqInit();
    irqEnable(IRQ_VBLANK);

    InitMainMenuState(&state);

    while (true)
    {
        scanKeys();

        UpdateState();

        state.update(&state);

        VBlankIntrWait();

        state.render(&state);
    }
}

void UpdateState()
{
    if (state.nextState != UNKNOWN)
    {
        switch (state.nextState)
        {
        case MAIN_MENU:
            InitMainMenuState(&state);
            break;

        case PLAY:
            InitPlayState(&state);
            break;
        }
    }
}
