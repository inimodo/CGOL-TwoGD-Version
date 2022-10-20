#include "cgol.h"

unsigned char Initialize(DWORD * dw_Canvas, DWORD * dw_CanvasTemp)
{
	srand(rand());
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if(rand()% RANDFILL ==0)(dw_Canvas)[XY(x,y)]=RGB(255,255,255);
		}
	}

	return TRUE;
}
unsigned char RenderCall(DWORD * dw_Canvas,DWORD * dw_CanvasTemp, win::GDWIN * o_win)
{
	InterrationCounter(o_win);

	if (memcpy(dw_CanvasTemp, dw_Canvas, CANSIZE)==NULL) return FALSE;
	if (memset(dw_Canvas, 0, CANSIZE) == NULL) return FALSE;

	for (int x = 1; x < WIDTH-1; x++)
	{
		for (int y = 1; y < HEIGHT-1; y++)
		{
			int i_Neighbors = Neighbors(dw_CanvasTemp, x, y);
			if (dw_CanvasTemp[XY(x,y)] == 0 && i_Neighbors == 3)
			{
				dw_Canvas[XY(x, y)] = RGB(0, 255, 0);
			}
			else if (dw_CanvasTemp[XY(x, y)] != 0 && i_Neighbors < 2)
			{
				dw_Canvas[XY(x, y)] = 0;
			}
			else if (dw_CanvasTemp[XY(x, y)] != 0 && i_Neighbors == 2)
			{
				dw_Canvas[XY(x, y)] = RGB(0, 255, 255);
			}
			else if (dw_CanvasTemp[XY(x, y)] != 0 && i_Neighbors == 3 )
			{
				dw_Canvas[XY(x, y)] = RGB(0, 0, 255);
			}
			else if (dw_CanvasTemp[XY(x, y)] != 0 && i_Neighbors > 3)
			{
				dw_Canvas[XY(x, y)] = 0;
			}
		}
	}

	return TRUE;
}

int Neighbors(DWORD * dw_Canvas, int x, int y)
{
	int i_Neighbors = 0;
	i_Neighbors += dw_Canvas[XY(x-1, y-1)]>0;
	i_Neighbors += dw_Canvas[XY(x, y-1)]>0;
	i_Neighbors += dw_Canvas[XY(x+1, y-1)]>0;

	i_Neighbors += dw_Canvas[XY(x - 1, y)]>0;
	i_Neighbors += dw_Canvas[XY(x + 1, y)]>0;

	i_Neighbors += dw_Canvas[XY(x - 1, y+1)]>0;
	i_Neighbors += dw_Canvas[XY(x, y+1)]>0;
	i_Neighbors += dw_Canvas[XY(x + 1, y+1)]>0;

	return i_Neighbors;
}

void DrawOntoCanvas(DWORD * dw_Canvas, int x, int y)
{
	if (x > 1 && x < WIDTH && y>1 && y < WIDTH) 
	{
		dw_Canvas[XY(x, y)] = RGB(255,255,255);
		dw_Canvas[XY(x+1, y)] = RGB(255,255,255);
		dw_Canvas[XY(x, y+1)] = RGB(255,255,255);
		dw_Canvas[XY(x+1, y+1)] = RGB(255,255,255);
	}
}

unsigned long long InterrationCounter(win::GDWIN * o_win)
{
	static unsigned long long ull_Interration = 0;
	ull_Interration++;

	char c_Buffer[256];
	sprintf(c_Buffer, "Interration: %u", ull_Interration);
	SetWindowTextA(o_win->hd_WindowHandle, c_Buffer);

	return ull_Interration;
}
