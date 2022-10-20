#include "cgol.h"

static DWORD * dw_Canvas;
static DWORD * dw_CanvasTemp;
static BOOL b_MouseDown = FALSE;

void MouseDown() {
	b_MouseDown = TRUE;
}

void MouseUp() {
	b_MouseDown = FALSE;
}

unsigned char __stdcall gdmain(win::GDWIN * o_win) 
{
	o_win->i_Width = WIDTH;
	o_win->i_Height = HEIGHT;

	static GDCONSOLE o_console;
	/*o_console.Create();*/
	
	o_win->v_pMouseDown = MouseDown;
	o_win->v_pMouseUp = MouseUp;

	dw_Canvas = (DWORD*)malloc(CANSIZE);
	dw_CanvasTemp = (DWORD*)malloc(CANSIZE);

	if (dw_Canvas == NULL || dw_CanvasTemp == NULL)return FALSE;
	if (memset(dw_Canvas, 0, CANSIZE) == NULL) return FALSE;
	if (memset(dw_CanvasTemp, 0, CANSIZE) == NULL) return FALSE;

	return Initialize(dw_Canvas, dw_CanvasTemp);
} 

unsigned char __stdcall gdupdate(win::GDWIN * o_win)
{
	static unsigned char uc_Return = TRUE;
	static unsigned long long ull_frame=0;

	ull_frame++;


	if (b_MouseDown) 
	{
		GetCursorPosition();
		DrawOntoCanvas(dw_Canvas, o_win->p_CursorPos.x, o_win->p_CursorPos.y);
	}
	
	if(ull_frame % TIMESCALE == 0)
	{
		uc_Return = RenderCall(dw_Canvas,dw_CanvasTemp,o_win);
	}
	
	SetScreenBuffer(dw_Canvas, WIDTH, HEIGHT);

	return uc_Return;
} 

void __stdcall gdclose() 
{
	free(dw_Canvas);
} 