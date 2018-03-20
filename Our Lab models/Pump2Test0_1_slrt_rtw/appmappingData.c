#include "slrtappmapping.h"
#include "./maps/Pump2Test0_1.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <Pump2Test0_1> */
		{ /* SignalMapInfo */
			Pump2Test0_1_BIOMAP,
			Pump2Test0_1_LBLMAP,
			Pump2Test0_1_SIDMAP,
			Pump2Test0_1_SBIO,
			Pump2Test0_1_SLBL,
			{0,27},
			28,
		},
		{ /* ParamMapInfo */
			Pump2Test0_1_PTIDSMAP,
			Pump2Test0_1_PTNAMESMAP,
			Pump2Test0_1_SPTMAP,
			{-1,-1},
			0,
		},
		"Pump2Test0_1",
		"",
		"Pump2Test0_1",
		1,
		Pump2Test0_1_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}