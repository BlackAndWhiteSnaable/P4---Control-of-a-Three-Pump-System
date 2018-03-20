#include "slrtappmapping.h"
#include "./maps/Pump2Test.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <Pump2Test> */
		{ /* SignalMapInfo */
			Pump2Test_BIOMAP,
			Pump2Test_LBLMAP,
			Pump2Test_SIDMAP,
			Pump2Test_SBIO,
			Pump2Test_SLBL,
			{0,26},
			27,
		},
		{ /* ParamMapInfo */
			Pump2Test_PTIDSMAP,
			Pump2Test_PTNAMESMAP,
			Pump2Test_SPTMAP,
			{-1,-1},
			0,
		},
		"Pump2Test",
		"",
		"Pump2Test",
		1,
		Pump2Test_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}