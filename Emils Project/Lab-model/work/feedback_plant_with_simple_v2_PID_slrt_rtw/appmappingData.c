#include "slrtappmapping.h"
#include "./maps/feedback_plant_with_simple_v2_PID.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <feedback_plant_with_simple_v2_PID> */
		{ /* SignalMapInfo */
			feedback_plant_with_simple_v2_PID_BIOMAP,
			feedback_plant_with_simple_v2_PID_LBLMAP,
			feedback_plant_with_simple_v2_PID_SIDMAP,
			feedback_plant_with_simple_v2_PID_SBIO,
			feedback_plant_with_simple_v2_PID_SLBL,
			{0,123},
			82,
		},
		{ /* ParamMapInfo */
			feedback_plant_with_simple_v2_PID_PTIDSMAP,
			feedback_plant_with_simple_v2_PID_PTNAMESMAP,
			feedback_plant_with_simple_v2_PID_SPTMAP,
			{-1,-1},
			0,
		},
		"feedback_plant_with_simple_v2_PID",
		"",
		"feedback_plant_with_simple_v2_PID",
		3,
		feedback_plant_with_simple_v2_PID_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}