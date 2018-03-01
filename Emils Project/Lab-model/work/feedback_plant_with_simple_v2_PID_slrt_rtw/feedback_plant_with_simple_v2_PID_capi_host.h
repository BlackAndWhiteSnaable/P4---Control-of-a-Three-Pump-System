#ifndef RTW_HEADER_feedback_plant_with_simple_v2_PID_cap_host_h_
#define RTW_HEADER_feedback_plant_with_simple_v2_PID_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} feedback_plant_with_simple_v2_PID_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void feedback_plant_with_simple_v2_PID_host_InitializeDataMapInfo
    (feedback_plant_with_simple_v2_PID_host_DataMapInfo_T *dataMap, const char
     *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_feedback_plant_with_simple_v2_PID_cap_host_h_ */

/* EOF: feedback_plant_with_simple_v2_PID_capi_host.h */
