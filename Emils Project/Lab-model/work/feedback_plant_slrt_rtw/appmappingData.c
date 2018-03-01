#include "slrtappmapping.h"
#include "./maps/feedback_plant.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <feedback_plant> */
		{ /* SignalMapInfo */
			feedback_plant_BIOMAP,
			feedback_plant_LBLMAP,
			feedback_plant_SIDMAP,
			feedback_plant_SBIO,
			feedback_plant_SLBL,
			{0,136},
			95,
		},
		{ /* ParamMapInfo */
			feedback_plant_PTIDSMAP,
			feedback_plant_PTNAMESMAP,
			feedback_plant_SPTMAP,
			{-1,-1},
			0,
		},
		"feedback_plant",
		"",
		"feedback_plant",
		2,
		feedback_plant_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}