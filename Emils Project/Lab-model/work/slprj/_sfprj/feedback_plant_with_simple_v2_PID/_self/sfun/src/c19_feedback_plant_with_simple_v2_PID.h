#ifndef __c19_feedback_plant_with_simple_v2_PID_h__
#define __c19_feedback_plant_with_simple_v2_PID_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_feedback_plant_with_simple_v2_PIDInstanceStruct
#define typedef_SFc19_feedback_plant_with_simple_v2_PIDInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_feedback_plant_with_simple_v2_PID;
  boolean_T (*c19_chk)[22];
  uint8_T (*c19_sensnames)[124];
  real_T *c19_stop;
} SFc19_feedback_plant_with_simple_v2_PIDInstanceStruct;

#endif                                 /*typedef_SFc19_feedback_plant_with_simple_v2_PIDInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c19_feedback_plant_with_simple_v2_PID_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_feedback_plant_with_simple_v2_PID_get_check_sum(mxArray *
  plhs[]);
extern void c19_feedback_plant_with_simple_v2_PID_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
