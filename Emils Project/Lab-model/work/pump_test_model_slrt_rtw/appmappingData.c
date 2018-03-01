#include "slrtappmapping.h"
#include "./maps/pump_test_model.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <pump_test_model> */
		{ /* SignalMapInfo */
			pump_test_model_BIOMAP,
			pump_test_model_LBLMAP,
			pump_test_model_SIDMAP,
			pump_test_model_SBIO,
			pump_test_model_SLBL,
			{0,22},
			23,
		},
		{ /* ParamMapInfo */
			pump_test_model_PTIDSMAP,
			pump_test_model_PTNAMESMAP,
			pump_test_model_SPTMAP,
			{0,7},
			8,
		},
		"pump_test_model",
		"",
		"pump_test_model",
		3,
		pump_test_model_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}