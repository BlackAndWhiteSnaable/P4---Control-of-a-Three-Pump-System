#ifndef __c2_feedback_plant_h__
#define __c2_feedback_plant_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_feedback_plantInstanceStruct
#define typedef_SFc2_feedback_plantInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_feedback_plant;
  real_T c2_gain[22];
  real_T c2_offset[22];
  real_T *c2_CV01;
  real_T (*c2_u)[22];
  real_T *c2_DPT01;
  real_T *c2_LMGC1;
  real_T *c2_LMGP1;
  real_T *c2_LMGV1;
  real_T *c2_MFM01;
  real_T *c2_PT01;
  real_T *c2_WP01;
  real_T *c2_DPT02;
  real_T *c2_LMGC2;
  real_T *c2_LMGP2;
  real_T *c2_LMGV2;
  real_T *c2_MFM02;
  real_T *c2_PT02;
  real_T *c2_WP02;
  real_T *c2_DPT03;
  real_T *c2_LMGC3;
  real_T *c2_LMGP3;
  real_T *c2_LMGV3;
  real_T *c2_MFM03;
  real_T *c2_PT03;
  real_T *c2_WP03;
} SFc2_feedback_plantInstanceStruct;

#endif                                 /*typedef_SFc2_feedback_plantInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_feedback_plant_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_feedback_plant_get_check_sum(mxArray *plhs[]);
extern void c2_feedback_plant_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
