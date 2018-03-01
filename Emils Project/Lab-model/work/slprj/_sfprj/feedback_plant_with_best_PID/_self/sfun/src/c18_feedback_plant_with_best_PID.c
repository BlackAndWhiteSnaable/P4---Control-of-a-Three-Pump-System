/* Include files */

#include "feedback_plant_with_best_PID_sfun.h"
#include "c18_feedback_plant_with_best_PID.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "feedback_plant_with_best_PID_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c18_debug_family_names[10] = { "test", "k", "i", "str",
  "Error", "nargin", "nargout", "chk", "sensnames", "stop" };

/* Function Declarations */
static void initialize_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void initialize_params_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void enable_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void disable_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void set_sim_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_st);
static void finalize_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void sf_gateway_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void mdl_start_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void c18_chartstep_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void initSimStructsc18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_b_stop, const char_T *c18_identifier);
static real_T c18_b_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, char_T
  c18_inData_data[], int32_T c18_inData_sizes[2]);
static void c18_c_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, char_T c18_y_data[],
   int32_T c18_y_sizes[2]);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, char_T c18_outData_data[],
  int32_T c18_outData_sizes[2]);
static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, char_T
  c18_inData_data[], int32_T c18_inData_sizes[2]);
static void c18_d_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, char_T c18_y_data[],
   int32_T c18_y_sizes[2]);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, char_T c18_outData_data[],
  int32_T c18_outData_sizes[2]);
static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c18_inData_data[], int32_T c18_inData_sizes[2]);
static void c18_e_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y_data[],
   int32_T c18_y_sizes[2]);
static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, real_T c18_outData_data[],
  int32_T c18_outData_sizes[2]);
static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_f_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, uint8_T c18_y[124]);
static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_h_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_g_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_h_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_feedback_plant_with_best_PID, const char_T
   *c18_identifier);
static uint8_T c18_i_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc18_feedback_plant_with_best_PID(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_feedback_plant_with_best_PID = 0U;
}

static void initialize_params_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  real_T c18_hoistedGlobal;
  real_T c18_u;
  const mxArray *c18_b_y = NULL;
  uint8_T c18_b_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(2, 1), false);
  c18_hoistedGlobal = *chartInstance->c18_stop;
  c18_u = c18_hoistedGlobal;
  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_hoistedGlobal =
    chartInstance->c18_is_active_c18_feedback_plant_with_best_PID;
  c18_b_u = c18_b_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_st)
{
  const mxArray *c18_u;
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  *chartInstance->c18_stop = c18_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("stop", c18_u, 0)), "stop");
  chartInstance->c18_is_active_c18_feedback_plant_with_best_PID =
    c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c18_feedback_plant_with_best_PID", c18_u, 1)),
    "is_active_c18_feedback_plant_with_best_PID");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_feedback_plant_with_best_PID(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  int32_T c18_i0;
  int32_T c18_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
  for (c18_i0 = 0; c18_i0 < 124; c18_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_sensnames)[c18_i0], 1U,
                          1U, 0U, chartInstance->c18_sfEvent, false);
  }

  for (c18_i1 = 0; c18_i1 < 22; c18_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c18_chk)[c18_i1], 0U, 1U, 0U,
                          chartInstance->c18_sfEvent, false);
  }

  chartInstance->c18_sfEvent = CALL_EVENT;
  c18_chartstep_c18_feedback_plant_with_best_PID(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_feedback_plant_with_best_PIDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c18_stop, 2U, 1U, 0U,
                        chartInstance->c18_sfEvent, false);
}

static void mdl_start_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c18_chartstep_c18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  int32_T c18_i2;
  int32_T c18_i3;
  boolean_T c18_b_chk[22];
  uint32_T c18_debug_family_var_map[10];
  uint8_T c18_b_sensnames[124];
  uint8_T c18_test[124];
  real_T c18_k_data[126];
  int32_T c18_k_sizes[2];
  real_T c18_i;
  char_T c18_str_data[123];
  int32_T c18_str_sizes[2];
  char_T c18_Error_data[140];
  int32_T c18_Error_sizes[2];
  real_T c18_nargin = 2.0;
  real_T c18_nargout = 1.0;
  real_T c18_b_stop;
  int32_T c18_i4;
  int32_T c18_i5;
  int32_T c18_idx;
  boolean_T c18_x[124];
  int32_T c18_i6;
  int32_T c18_i7;
  int32_T c18_iv0[124];
  int32_T c18_ii;
  int32_T c18_ii_sizes[2];
  int32_T c18_b_ii;
  boolean_T c18_b0;
  boolean_T c18_b1;
  int32_T c18_a;
  boolean_T c18_b2;
  int32_T c18_ii_data[124];
  int32_T c18_i8;
  int32_T c18_i_sizes[2];
  int32_T c18_b_i;
  int32_T c18_c_i;
  int32_T c18_loop_ub;
  int32_T c18_i9;
  real_T c18_i_data[124];
  int32_T c18_k;
  int32_T c18_b_k;
  int32_T c18_b_loop_ub;
  int32_T c18_i10;
  int32_T c18_tmp_sizes[2];
  real_T c18_tmp_data[126];
  int32_T c18_c_loop_ub;
  int32_T c18_i11;
  int32_T c18_d_loop_ub;
  int32_T c18_i12;
  int32_T c18_b_k_sizes[2];
  int32_T c18_e_loop_ub;
  int32_T c18_i13;
  real_T c18_b_k_data[126];
  int32_T c18_f_loop_ub;
  int32_T c18_i14;
  int32_T c18_d_i;
  real_T c18_d0;
  real_T c18_d1;
  boolean_T c18_b3;
  boolean_T c18_b4;
  boolean_T c18_b5;
  int32_T c18_i15;
  int32_T c18_i16;
  int32_T c18_s_sizes[2];
  int32_T c18_g_loop_ub;
  int32_T c18_i17;
  int32_T c18_i18;
  uint8_T c18_s_data[123];
  int32_T c18_i19;
  real_T c18_s[2];
  real_T c18_dv0[2];
  int32_T c18_b_tmp_sizes;
  int32_T c18_h_loop_ub;
  int32_T c18_i20;
  int32_T c18_i21;
  char_T c18_b_tmp_data[123];
  int32_T c18_str[2];
  int32_T c18_i_loop_ub;
  int32_T c18_i22;
  int32_T c18_j_loop_ub;
  int32_T c18_i23;
  int32_T c18_i24;
  static char_T c18_cv0[17] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'H', 'I', 'G', 'H', ' ' };

  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_k_loop_ub;
  int32_T c18_i25;
  const mxArray *c18_y = NULL;
  char_T c18_u_data[140];
  int32_T c18_c_u;
  int32_T c18_d_u;
  int32_T c18_l_loop_ub;
  int32_T c18_i26;
  int32_T c18_i27;
  char_T c18_cv1[4];
  static char_T c18_cv2[4] = { '%', 's', '\x0a', '\x00' };

  boolean_T exitg1;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
  for (c18_i2 = 0; c18_i2 < 22; c18_i2++) {
    c18_b_chk[c18_i2] = (*chartInstance->c18_chk)[c18_i2];
  }

  for (c18_i3 = 0; c18_i3 < 124; c18_i3++) {
    c18_b_sensnames[c18_i3] = (*chartInstance->c18_sensnames)[c18_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_test, 0U, c18_g_sf_marshallOut,
    c18_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c18_k_data, (const int32_T *)
    &c18_k_sizes, NULL, 0, 1, (void *)c18_f_sf_marshallOut, (void *)
    c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_i, 2U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c18_str_data, (const int32_T *)
    &c18_str_sizes, NULL, 0, 3, (void *)c18_e_sf_marshallOut, (void *)
    c18_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c18_Error_data, (const int32_T *)
    &c18_Error_sizes, NULL, 0, 4, (void *)c18_d_sf_marshallOut, (void *)
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 5U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 6U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_chk, 7U, c18_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_b_sensnames, 8U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_stop, 9U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
  for (c18_i4 = 0; c18_i4 < 124; c18_i4++) {
    c18_test[c18_i4] = c18_b_sensnames[c18_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  for (c18_i5 = 0; c18_i5 < 124; c18_i5++) {
    c18_x[c18_i5] = ((real_T)c18_test[c18_i5] == 47.0);
  }

  c18_idx = 0;
  for (c18_i6 = 0; c18_i6 < 124; c18_i6++) {
    c18_iv0[c18_i6] = 0;
  }

  for (c18_i7 = 0; c18_i7 < 2; c18_i7++) {
    c18_ii_sizes[c18_i7] = 1 + 123 * c18_i7;
  }

  c18_ii = 1;
  exitg1 = false;
  while ((exitg1 == false) && (c18_ii < 125)) {
    c18_b_ii = c18_ii;
    guard1 = false;
    if (c18_x[c18_b_ii - 1]) {
      c18_a = c18_idx + 1;
      c18_idx = c18_a;
      c18_ii_data[c18_idx - 1] = c18_b_ii;
      if (c18_idx >= 124) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1 == true) {
      c18_ii++;
    }
  }

  c18_b0 = (1 > c18_idx);
  c18_b1 = c18_b0;
  c18_b2 = c18_b1;
  if (c18_b2) {
    c18_i8 = 0;
  } else {
    c18_i8 = c18_idx;
  }

  c18_ii_sizes[1] = c18_i8;
  c18_i_sizes[0] = 1;
  c18_i_sizes[1] = c18_ii_sizes[1];
  c18_b_i = c18_i_sizes[0];
  c18_c_i = c18_i_sizes[1];
  c18_loop_ub = c18_ii_sizes[0] * c18_ii_sizes[1] - 1;
  for (c18_i9 = 0; c18_i9 <= c18_loop_ub; c18_i9++) {
    c18_i_data[c18_i9] = (real_T)c18_ii_data[c18_i9];
  }

  c18_k_sizes[0] = 1;
  c18_k_sizes[1] = c18_i_sizes[1];
  c18_k = c18_k_sizes[0];
  c18_b_k = c18_k_sizes[1];
  c18_b_loop_ub = c18_i_sizes[0] * c18_i_sizes[1] - 1;
  for (c18_i10 = 0; c18_i10 <= c18_b_loop_ub; c18_i10++) {
    c18_k_data[c18_i10] = c18_i_data[c18_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 6);
  c18_tmp_sizes[0] = 1;
  c18_tmp_sizes[1] = 1 + c18_k_sizes[1];
  c18_tmp_data[0] = 0.0;
  c18_c_loop_ub = c18_k_sizes[1] - 1;
  for (c18_i11 = 0; c18_i11 <= c18_c_loop_ub; c18_i11++) {
    c18_tmp_data[c18_tmp_sizes[0] * (c18_i11 + 1)] = c18_k_data[c18_k_sizes[0] *
      c18_i11];
  }

  c18_k_sizes[0] = 1;
  c18_k_sizes[1] = c18_tmp_sizes[1];
  c18_d_loop_ub = c18_tmp_sizes[1] - 1;
  for (c18_i12 = 0; c18_i12 <= c18_d_loop_ub; c18_i12++) {
    c18_k_data[c18_k_sizes[0] * c18_i12] = c18_tmp_data[c18_tmp_sizes[0] *
      c18_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 7);
  c18_b_k_sizes[0] = 1;
  c18_b_k_sizes[1] = c18_k_sizes[1] + 1;
  c18_e_loop_ub = c18_k_sizes[1] - 1;
  for (c18_i13 = 0; c18_i13 <= c18_e_loop_ub; c18_i13++) {
    c18_b_k_data[c18_b_k_sizes[0] * c18_i13] = c18_k_data[c18_k_sizes[0] *
      c18_i13];
  }

  c18_b_k_data[c18_b_k_sizes[0] * c18_k_sizes[1]] = 124.0;
  c18_k_sizes[0] = 1;
  c18_k_sizes[1] = c18_b_k_sizes[1];
  c18_f_loop_ub = c18_b_k_sizes[1] - 1;
  for (c18_i14 = 0; c18_i14 <= c18_f_loop_ub; c18_i14++) {
    c18_k_data[c18_k_sizes[0] * c18_i14] = c18_b_k_data[c18_b_k_sizes[0] *
      c18_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 8);
  c18_b_stop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 9);
  c18_i = 1.0;
  c18_d_i = 0;
  while (c18_d_i < 22) {
    c18_i = 1.0 + (real_T)c18_d_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 10);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c18_b_chk
          [(int32_T)c18_i - 1], 0.0, -1, 0U, !c18_b_chk[(int32_T)c18_i - 1]))) {
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 11);
      c18_d0 = c18_k_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 222, 4, MAX_uint32_T, (int32_T)c18_i, 1,
        c18_k_sizes[1]) - 1] + 1.0;
      c18_d1 = c18_k_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 229, 6, MAX_uint32_T, (int32_T)(c18_i + 1.0), 1,
        c18_k_sizes[1]) - 1] - 1.0;
      c18_b3 = (c18_d0 > c18_d1);
      c18_b4 = c18_b3;
      c18_b5 = c18_b4;
      if (c18_b5) {
        c18_i15 = 1;
        c18_i16 = 0;
      } else {
        c18_i15 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 217, 21, MAX_uint32_T, (int32_T)c18_d0, 1, 124);
        c18_i16 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 217, 21, MAX_uint32_T, (int32_T)c18_d1, 1, 124);
      }

      c18_s_sizes[0] = 1;
      c18_s_sizes[1] = (c18_i16 - c18_i15) + 1;
      c18_g_loop_ub = c18_i16 - c18_i15;
      for (c18_i17 = 0; c18_i17 <= c18_g_loop_ub; c18_i17++) {
        c18_s_data[c18_s_sizes[0] * c18_i17] = c18_test[(c18_i15 + c18_i17) - 1];
      }

      for (c18_i18 = 0; c18_i18 < 2; c18_i18++) {
        c18_s[c18_i18] = (real_T)c18_s_sizes[c18_i18];
      }

      for (c18_i19 = 0; c18_i19 < 2; c18_i19++) {
        c18_dv0[c18_i19] = c18_s[c18_i19];
      }

      c18_str_sizes[0] = 1;
      c18_str_sizes[1] = (int32_T)c18_dv0[1];
      c18_b_tmp_sizes = c18_s_sizes[1];
      c18_h_loop_ub = c18_s_sizes[1] - 1;
      for (c18_i20 = 0; c18_i20 <= c18_h_loop_ub; c18_i20++) {
        c18_b_tmp_data[c18_i20] = (char_T)(int8_T)c18_s_data[c18_i20];
      }

      for (c18_i21 = 0; c18_i21 < 2; c18_i21++) {
        c18_str[c18_i21] = c18_str_sizes[c18_i21];
      }

      c18_str_sizes[0] = 1;
      c18_str_sizes[1] = c18_str[1];
      c18_i_loop_ub = c18_str[1] - 1;
      for (c18_i22 = 0; c18_i22 <= c18_i_loop_ub; c18_i22++) {
        c18_str_data[c18_str_sizes[0] * c18_i22] = c18_b_tmp_data[c18_str[0] *
          c18_i22];
      }

      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 12);
      c18_Error_sizes[0] = 1;
      c18_Error_sizes[1] = c18_str_sizes[1] + 17;
      c18_j_loop_ub = c18_str_sizes[1] - 1;
      for (c18_i23 = 0; c18_i23 <= c18_j_loop_ub; c18_i23++) {
        c18_Error_data[c18_Error_sizes[0] * c18_i23] =
          c18_str_data[c18_str_sizes[0] * c18_i23];
      }

      for (c18_i24 = 0; c18_i24 < 17; c18_i24++) {
        c18_Error_data[c18_Error_sizes[0] * (c18_i24 + c18_str_sizes[1])] =
          c18_cv0[c18_i24];
      }

      sf_mex_printf("%s =\\n", "Error");
      c18_u_sizes[0] = 1;
      c18_u_sizes[1] = c18_Error_sizes[1];
      c18_u = c18_u_sizes[0];
      c18_b_u = c18_u_sizes[1];
      c18_k_loop_ub = c18_Error_sizes[0] * c18_Error_sizes[1] - 1;
      for (c18_i25 = 0; c18_i25 <= c18_k_loop_ub; c18_i25++) {
        c18_u_data[c18_i25] = c18_Error_data[c18_i25];
      }

      c18_y = NULL;
      sf_mex_assign(&c18_y, sf_mex_create("y", c18_u_data, 10, 0U, 1U, 0U, 2,
        c18_u_sizes[0], c18_u_sizes[1]), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c18_y);
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 13);
      c18_u_sizes[0] = 1;
      c18_u_sizes[1] = c18_Error_sizes[1];
      c18_c_u = c18_u_sizes[0];
      c18_d_u = c18_u_sizes[1];
      c18_l_loop_ub = c18_Error_sizes[0] * c18_Error_sizes[1] - 1;
      for (c18_i26 = 0; c18_i26 <= c18_l_loop_ub; c18_i26++) {
        c18_u_data[c18_i26] = c18_Error_data[c18_i26];
      }

      for (c18_i27 = 0; c18_i27 < 4; c18_i27++) {
        c18_cv1[c18_i27] = c18_cv2[c18_i27];
      }

      printf(c18_cv1, &c18_u_data[0]);
      _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 14);
      c18_b_stop++;
    }

    c18_d_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c18_stop = c18_b_stop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c18_sfEvent);
}

static void initSimStructsc18_feedback_plant_with_best_PID
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_b_stop, const char_T *c18_identifier)
{
  real_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_stop),
    &c18_thisId);
  sf_mex_destroy(&c18_b_stop);
  return c18_y;
}

static real_T c18_b_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d2;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d2, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d2;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_stop;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_b_stop = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_stop),
    &c18_thisId);
  sf_mex_destroy(&c18_b_stop);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i28;
  const mxArray *c18_y = NULL;
  uint8_T c18_u[124];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i28 = 0; c18_i28 < 124; c18_i28++) {
    c18_u[c18_i28] = (*(uint8_T (*)[124])c18_inData)[c18_i28];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 3, 0U, 1U, 0U, 1, 124), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i29;
  const mxArray *c18_y = NULL;
  boolean_T c18_u[22];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i29 = 0; c18_i29 < 22; c18_i29++) {
    c18_u[c18_i29] = (*(boolean_T (*)[22])c18_inData)[c18_i29];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 11, 0U, 1U, 0U, 1, 22), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, char_T
  c18_inData_data[], int32_T c18_inData_sizes[2])
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_loop_ub;
  int32_T c18_i30;
  const mxArray *c18_y = NULL;
  char_T c18_u_data[140];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u_sizes[0] = 1;
  c18_u_sizes[1] = c18_inData_sizes[1];
  c18_u = c18_u_sizes[0];
  c18_b_u = c18_u_sizes[1];
  c18_loop_ub = c18_inData_sizes[0] * c18_inData_sizes[1] - 1;
  for (c18_i30 = 0; c18_i30 <= c18_loop_ub; c18_i30++) {
    c18_u_data[c18_i30] = c18_inData_data[c18_i30];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u_data, 10, 0U, 1U, 0U, 2,
    c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_c_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, char_T c18_y_data[],
   int32_T c18_y_sizes[2])
{
  int32_T c18_i31;
  int32_T c18_i32;
  uint32_T c18_uv0[2];
  char_T c18_tmp_data[140];
  boolean_T c18_bv0[2];
  int32_T c18_tmp_sizes[2];
  static boolean_T c18_bv1[2] = { false, true };

  int32_T c18_y;
  int32_T c18_b_y;
  int32_T c18_loop_ub;
  int32_T c18_i33;
  (void)chartInstance;
  for (c18_i31 = 0; c18_i31 < 2; c18_i31++) {
    c18_uv0[c18_i31] = 1U + 139U * (uint32_T)c18_i31;
  }

  for (c18_i32 = 0; c18_i32 < 2; c18_i32++) {
    c18_bv0[c18_i32] = c18_bv1[c18_i32];
  }

  sf_mex_import_vs(c18_parentId, sf_mex_dup(c18_u), c18_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c18_bv0, c18_uv0, c18_tmp_sizes);
  c18_y_sizes[0] = 1;
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_y = c18_y_sizes[0];
  c18_b_y = c18_y_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i33 = 0; c18_i33 <= c18_loop_ub; c18_i33++) {
    c18_y_data[c18_i33] = c18_tmp_data[c18_i33];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, char_T c18_outData_data[],
  int32_T c18_outData_sizes[2])
{
  const mxArray *c18_Error;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  char_T c18_y_data[140];
  int32_T c18_y_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_i34;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_Error = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_Error), &c18_thisId,
    c18_y_data, c18_y_sizes);
  sf_mex_destroy(&c18_Error);
  c18_outData_sizes[0] = 1;
  c18_outData_sizes[1] = c18_y_sizes[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_i34 = 0; c18_i34 <= c18_loop_ub; c18_i34++) {
    c18_outData_data[c18_outData_sizes[0] * c18_i34] = c18_y_data[c18_y_sizes[0]
      * c18_i34];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, char_T
  c18_inData_data[], int32_T c18_inData_sizes[2])
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_loop_ub;
  int32_T c18_i35;
  const mxArray *c18_y = NULL;
  char_T c18_u_data[123];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u_sizes[0] = 1;
  c18_u_sizes[1] = c18_inData_sizes[1];
  c18_u = c18_u_sizes[0];
  c18_b_u = c18_u_sizes[1];
  c18_loop_ub = c18_inData_sizes[0] * c18_inData_sizes[1] - 1;
  for (c18_i35 = 0; c18_i35 <= c18_loop_ub; c18_i35++) {
    c18_u_data[c18_i35] = c18_inData_data[c18_i35];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u_data, 10, 0U, 1U, 0U, 2,
    c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_d_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, char_T c18_y_data[],
   int32_T c18_y_sizes[2])
{
  int32_T c18_i36;
  int32_T c18_i37;
  uint32_T c18_uv1[2];
  char_T c18_tmp_data[123];
  boolean_T c18_bv2[2];
  int32_T c18_tmp_sizes[2];
  static boolean_T c18_bv3[2] = { false, true };

  int32_T c18_y;
  int32_T c18_b_y;
  int32_T c18_loop_ub;
  int32_T c18_i38;
  (void)chartInstance;
  for (c18_i36 = 0; c18_i36 < 2; c18_i36++) {
    c18_uv1[c18_i36] = 1U + 122U * (uint32_T)c18_i36;
  }

  for (c18_i37 = 0; c18_i37 < 2; c18_i37++) {
    c18_bv2[c18_i37] = c18_bv3[c18_i37];
  }

  sf_mex_import_vs(c18_parentId, sf_mex_dup(c18_u), c18_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c18_bv2, c18_uv1, c18_tmp_sizes);
  c18_y_sizes[0] = 1;
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_y = c18_y_sizes[0];
  c18_b_y = c18_y_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i38 = 0; c18_i38 <= c18_loop_ub; c18_i38++) {
    c18_y_data[c18_i38] = c18_tmp_data[c18_i38];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, char_T c18_outData_data[],
  int32_T c18_outData_sizes[2])
{
  const mxArray *c18_str;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  char_T c18_y_data[123];
  int32_T c18_y_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_i39;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_str = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_str), &c18_thisId,
    c18_y_data, c18_y_sizes);
  sf_mex_destroy(&c18_str);
  c18_outData_sizes[0] = 1;
  c18_outData_sizes[1] = c18_y_sizes[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_i39 = 0; c18_i39 <= c18_loop_ub; c18_i39++) {
    c18_outData_data[c18_outData_sizes[0] * c18_i39] = c18_y_data[c18_y_sizes[0]
      * c18_i39];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c18_inData_data[], int32_T c18_inData_sizes[2])
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u_sizes[2];
  int32_T c18_u;
  int32_T c18_b_u;
  int32_T c18_loop_ub;
  int32_T c18_i40;
  const mxArray *c18_y = NULL;
  real_T c18_u_data[126];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u_sizes[0] = 1;
  c18_u_sizes[1] = c18_inData_sizes[1];
  c18_u = c18_u_sizes[0];
  c18_b_u = c18_u_sizes[1];
  c18_loop_ub = c18_inData_sizes[0] * c18_inData_sizes[1] - 1;
  for (c18_i40 = 0; c18_i40 <= c18_loop_ub; c18_i40++) {
    c18_u_data[c18_i40] = c18_inData_data[c18_i40];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u_data, 0, 0U, 1U, 0U, 2,
    c18_u_sizes[0], c18_u_sizes[1]), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_e_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, real_T c18_y_data[],
   int32_T c18_y_sizes[2])
{
  int32_T c18_i41;
  int32_T c18_i42;
  uint32_T c18_uv2[2];
  real_T c18_tmp_data[126];
  boolean_T c18_bv4[2];
  int32_T c18_tmp_sizes[2];
  static boolean_T c18_bv5[2] = { false, true };

  int32_T c18_y;
  int32_T c18_b_y;
  int32_T c18_loop_ub;
  int32_T c18_i43;
  (void)chartInstance;
  for (c18_i41 = 0; c18_i41 < 2; c18_i41++) {
    c18_uv2[c18_i41] = 1U + 125U * (uint32_T)c18_i41;
  }

  for (c18_i42 = 0; c18_i42 < 2; c18_i42++) {
    c18_bv4[c18_i42] = c18_bv5[c18_i42];
  }

  sf_mex_import_vs(c18_parentId, sf_mex_dup(c18_u), c18_tmp_data, 1, 0, 0U, 1,
                   0U, 2, c18_bv4, c18_uv2, c18_tmp_sizes);
  c18_y_sizes[0] = 1;
  c18_y_sizes[1] = c18_tmp_sizes[1];
  c18_y = c18_y_sizes[0];
  c18_b_y = c18_y_sizes[1];
  c18_loop_ub = c18_tmp_sizes[0] * c18_tmp_sizes[1] - 1;
  for (c18_i43 = 0; c18_i43 <= c18_loop_ub; c18_i43++) {
    c18_y_data[c18_i43] = c18_tmp_data[c18_i43];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, real_T c18_outData_data[],
  int32_T c18_outData_sizes[2])
{
  const mxArray *c18_k;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y_data[126];
  int32_T c18_y_sizes[2];
  int32_T c18_loop_ub;
  int32_T c18_i44;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_k = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_k), &c18_thisId,
    c18_y_data, c18_y_sizes);
  sf_mex_destroy(&c18_k);
  c18_outData_sizes[0] = 1;
  c18_outData_sizes[1] = c18_y_sizes[1];
  c18_loop_ub = c18_y_sizes[1] - 1;
  for (c18_i44 = 0; c18_i44 <= c18_loop_ub; c18_i44++) {
    c18_outData_data[c18_outData_sizes[0] * c18_i44] = c18_y_data[c18_y_sizes[0]
      * c18_i44];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i45;
  const mxArray *c18_y = NULL;
  uint8_T c18_u[124];
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i45 = 0; c18_i45 < 124; c18_i45++) {
    c18_u[c18_i45] = (*(uint8_T (*)[124])c18_inData)[c18_i45];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 3, 0U, 1U, 0U, 2, 1, 124),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_f_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId, uint8_T c18_y[124])
{
  uint8_T c18_uv3[124];
  int32_T c18_i46;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_uv3, 1, 3, 0U, 1, 0U, 2, 1,
                124);
  for (c18_i46 = 0; c18_i46 < 124; c18_i46++) {
    c18_y[c18_i46] = c18_uv3[c18_i46];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_test;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  uint8_T c18_y[124];
  int32_T c18_i47;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_test = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_test), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_test);
  for (c18_i47 = 0; c18_i47 < 124; c18_i47++) {
    (*(uint8_T (*)[124])c18_outData)[c18_i47] = c18_y[c18_i47];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray
  *sf_c18_feedback_plant_with_best_PID_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_h_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_g_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i48;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i48, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i48;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_y = c18_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_h_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_b_is_active_c18_feedback_plant_with_best_PID, const char_T
   *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_thisId.bParentIsCell = false;
  c18_y = c18_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_feedback_plant_with_best_PID), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_feedback_plant_with_best_PID);
  return c18_y;
}

static uint8_T c18_i_emlrt_marshallIn
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  chartInstance->c18_chk = (boolean_T (*)[22])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c18_sensnames = (uint8_T (*)[124])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c18_stop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c18_feedback_plant_with_best_PID_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1035884191U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1813340514U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1731170657U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(390017978U);
}

mxArray* sf_c18_feedback_plant_with_best_PID_get_post_codegen_info(void);
mxArray *sf_c18_feedback_plant_with_best_PID_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("K7q6K3kzhv0LaoIEqlpxUD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(22);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(124);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c18_feedback_plant_with_best_PID_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c18_feedback_plant_with_best_PID_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_feedback_plant_with_best_PID_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("printf");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c18_feedback_plant_with_best_PID_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c18_feedback_plant_with_best_PID_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c18_feedback_plant_with_best_PID
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"stop\",},{M[8],M[0],T\"is_active_c18_feedback_plant_with_best_PID\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_feedback_plant_with_best_PID_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance =
      (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _feedback_plant_with_best_PIDMachineNumber_,
           18,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_feedback_plant_with_best_PIDMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _feedback_plant_with_best_PIDMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _feedback_plant_with_best_PIDMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"chk");
          _SFD_SET_DATA_PROPS(1,1,1,0,"sensnames");
          _SFD_SET_DATA_PROPS(2,2,0,1,"stop");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,372);
        _SFD_CV_INIT_EML_IF(0,1,0,183,197,-1,364);
        _SFD_CV_INIT_EML_FOR(0,1,0,158,179,368);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,186,197,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 22U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 124U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _feedback_plant_with_best_PIDMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance =
      (SFc18_feedback_plant_with_best_PIDInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c18_chk);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c18_sensnames);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c18_stop);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "saEXJvRx6DzvXyZ1e9KGg8E";
}

static void sf_opaque_initialize_c18_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_feedback_plant_with_best_PIDInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
  initialize_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  enable_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  disable_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  sf_gateway_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c18_feedback_plant_with_best_PID
  (SimStruct* S)
{
  return get_sim_state_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c18_feedback_plant_with_best_PID(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c18_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_feedback_plant_with_best_PIDInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_feedback_plant_with_best_PID_optimization_info();
    }

    finalize_c18_feedback_plant_with_best_PID
      ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_feedback_plant_with_best_PID
    ((SFc18_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_feedback_plant_with_best_PID(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_feedback_plant_with_best_PID
      ((SFc18_feedback_plant_with_best_PIDInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c18_feedback_plant_with_best_PID(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_feedback_plant_with_best_PID_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 18);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2866672382U));
  ssSetChecksum1(S,(2618999334U));
  ssSetChecksum2(S,(2603949064U));
  ssSetChecksum3(S,(2893552117U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_feedback_plant_with_best_PID(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_feedback_plant_with_best_PID(SimStruct *S)
{
  SFc18_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc18_feedback_plant_with_best_PIDInstanceStruct *)utMalloc
    (sizeof(SFc18_feedback_plant_with_best_PIDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc18_feedback_plant_with_best_PIDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_feedback_plant_with_best_PID;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c18_feedback_plant_with_best_PID(chartInstance);
}

void c18_feedback_plant_with_best_PID_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_feedback_plant_with_best_PID(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_feedback_plant_with_best_PID(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_feedback_plant_with_best_PID(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_feedback_plant_with_best_PID_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
