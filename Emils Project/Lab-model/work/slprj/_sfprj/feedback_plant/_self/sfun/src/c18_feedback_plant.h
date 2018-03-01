#ifndef __c18_feedback_plant_h__
#define __c18_feedback_plant_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_feedback_plantInstanceStruct
#define typedef_SFc18_feedback_plantInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  boolean_T c18_doneDoubleBufferReInit;
  uint8_T c18_is_active_c18_feedback_plant;
  boolean_T (*c18_chk)[22];
  uint8_T (*c18_sensnames)[124];
  real_T *c18_stop;
} SFc18_feedback_plantInstanceStruct;

#endif                                 /*typedef_SFc18_feedback_plantInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c18_feedback_plant_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_feedback_plant_get_check_sum(mxArray *plhs[]);
extern void c18_feedback_plant_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
