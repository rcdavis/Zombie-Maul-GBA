
#include "MainMenuState.h"

#include <gba_dma.h>
#include <gba_input.h>
#include <gba_video.h>

#include "textures/MenuBG.h"

void InitMainMenuState(GameState* const state)
{
    SetMode(MODE_3 | BG2_ENABLE);

    state->curState = MAIN_MENU;
    state->nextState = UNKNOWN;
    state->update = UpdateMainMenuState;
    state->render = RenderMainMenuState;
}

void UpdateMainMenuState(GameState* state)
{
    const u16 upKeys = keysUp();
    if (upKeys & KEY_A)
    {
        state->nextState = PLAY;
    }
}

void RenderMainMenuState(GameState* state)
{
    dmaCopy(MenuBGBitmap, (void*)VRAM, MenuBGBitmapLen);
}