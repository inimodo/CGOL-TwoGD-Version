#pragma once

#include "twogd.h"

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

// ## Simulation Settings ## //

#define SCALE 100
#define WIDTH  ( 16 * SCALE )
#define HEIGHT ( 9 * SCALE )
#define CANSIZE (WIDTH*HEIGHT*sizeof(DWORD))
#define XY(X,Y) (int)((X)+(Y)*WIDTH)

// Skip this amout of frames before recalculation
#define TIMESCALE 1

// Startup fill: 1 = every Pixel
#define RANDFILL 10

extern unsigned char Initialize(DWORD * dw_Canvas, DWORD * dw_CanvasTemp);
extern unsigned char RenderCall(DWORD * dw_Canvas, DWORD * dw_CanvasTemp, win::GDWIN * o_win);
extern unsigned long long InterrationCounter(win::GDWIN * o_win);
extern int Neighbors(DWORD * dw_Canvas,int x,int y);
extern void DrawOntoCanvas(DWORD * dw_Canvas,int x, int y);

