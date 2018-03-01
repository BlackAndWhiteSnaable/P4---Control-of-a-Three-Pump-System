#ifndef RTW_HEADER_pump_test_model_cap_host_h_
#define RTW_HEADER_pump_test_model_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} pump_test_model_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void pump_test_model_host_InitializeDataMapInfo
    (pump_test_model_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_pump_test_model_cap_host_h_ */

/* EOF: pump_test_model_capi_host.h */
