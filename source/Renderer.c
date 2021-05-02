
#include "Renderer.h"

#include <gba_video.h>

void Renderer_FillScreen(const u16 color)
{
    const u32 fillColor = ((u32)color | ((u32)color << 16));
    const u32 num = (SCREEN_WIDTH * SCREEN_HEIGHT) / 2;
    u32* const v = (u32*)VRAM;
    for (u32 i = 0; i < num; ++i)
    {
        v[i] = fillColor;
    }
}
