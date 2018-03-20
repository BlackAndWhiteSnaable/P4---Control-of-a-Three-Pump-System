#include "slrtappmapping.h"
#include "./maps/firstTest.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <firstTest> */
		{ /* SignalMapInfo */
			firstTest_BIOMAP,
			firstTest_LBLMAP,
			firstTest_SIDMAP,
			firstTest_SBIO,
			firstTest_SLBL,
			{0,26},
			26,
		},
		{ /* ParamMapInfo */
			firstTest_PTIDSMAP,
			firstTest_PTNAMESMAP,
			firstTest_SPTMAP,
			{-1,-1},
			0,
		},
		"firstTest",
		"",
		"firstTest",
		1,
		firstTest_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}