#include "twogd.h"

unsigned char __stdcall gdmain(win::GDWIN *) 
{
	
	return TRUE; 
} 

unsigned char __stdcall gdupdate(win::GDWIN *) 
{
	return 1; 
} 

void __stdcall gdclose() 
{

}