
#include "PlayState.h"

#include <gba_dma.h>
#include <gba_input.h>
#include <gba_video.h>

#include "Renderer.h"

void InitPlayState(GameState* const state)
{
    SetMode(MODE_3 | BG2_ENABLE);

    state->curState = PLAY;
    state->nextState = UNKNOWN;
    state->update = UpdatePlayState;
    state->render = RenderPlayState;
}

void UpdatePlayState(GameState* const state)
{
    const u16 upKeys = keysUp();
    if (upKeys & KEY_A)
    {
        state->nextState = MAIN_MENU;
    }
}

void RenderPlayState(GameState* const state)
{
    Renderer_FillScreen(0x0000);
}
