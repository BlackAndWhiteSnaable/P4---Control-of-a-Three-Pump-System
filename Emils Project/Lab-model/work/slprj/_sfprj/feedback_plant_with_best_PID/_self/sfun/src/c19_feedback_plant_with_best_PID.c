/* Include files */

#include "feedback_plant_with_best_PID_sfun.h"
#include "c19_feedback_plant_with_best_PID.h"
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
static const char * c19_debug_family_names[10] = { "test", "k", "i", "str",
  "Error", "nargin", "nargout", "chk", "sensnames", "stop" };

/* Function Declarations */
static void initialize_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void initialize_params_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void enable_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void disable_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void set_sim_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_st);
static void finalize_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void sf_gateway_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void mdl_start_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void c19_chartstep_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void initSimStructsc19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_b_stop, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, char_T
  c19_inData_data[], int32_T c19_inData_sizes[2]);
static void c19_c_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y_data[],
   int32_T c19_y_sizes[2]);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, char_T c19_outData_data[],
  int32_T c19_outData_sizes[2]);
static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, char_T
  c19_inData_data[], int32_T c19_inData_sizes[2]);
static void c19_d_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y_data[],
   int32_T c19_y_sizes[2]);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, char_T c19_outData_data[],
  int32_T c19_outData_sizes[2]);
static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c19_inData_data[], int32_T c19_inData_sizes[2]);
static void c19_e_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y_data[],
   int32_T c19_y_sizes[2]);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, real_T c19_outData_data[],
  int32_T c19_outData_sizes[2]);
static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_f_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y[124]);
static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_g_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_h_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_feedback_plant_with_best_PID, const char_T
   *c19_identifier);
static uint8_T c19_i_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc19_feedback_plant_with_best_PID(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_is_active_c19_feedback_plant_with_best_PID = 0U;
}

static void initialize_params_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c19_update_debugger_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(2, 1), false);
  c19_hoistedGlobal = *chartInstance->c19_stop;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal =
    chartInstance->c19_is_active_c19_feedback_plant_with_best_PID;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_st)
{
  const mxArray *c19_u;
  chartInstance->c19_doneDoubleBufferReInit = true;
  c19_u = sf_mex_dup(c19_st);
  *chartInstance->c19_stop = c19_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("stop", c19_u, 0)), "stop");
  chartInstance->c19_is_active_c19_feedback_plant_with_best_PID =
    c19_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c19_feedback_plant_with_best_PID", c19_u, 1)),
    "is_active_c19_feedback_plant_with_best_PID");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_feedback_plant_with_best_PID(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  int32_T c19_i0;
  int32_T c19_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c19_sfEvent);
  for (c19_i0 = 0; c19_i0 < 124; c19_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c19_sensnames)[c19_i0], 1U,
                          1U, 0U, chartInstance->c19_sfEvent, false);
  }

  for (c19_i1 = 0; c19_i1 < 22; c19_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c19_chk)[c19_i1], 0U, 1U, 0U,
                          chartInstance->c19_sfEvent, false);
  }

  chartInstance->c19_sfEvent = CALL_EVENT;
  c19_chartstep_c19_feedback_plant_with_best_PID(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_feedback_plant_with_best_PIDMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c19_stop, 2U, 1U, 0U,
                        chartInstance->c19_sfEvent, false);
}

static void mdl_start_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c19_chartstep_c19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  int32_T c19_i2;
  int32_T c19_i3;
  boolean_T c19_b_chk[22];
  uint32_T c19_debug_family_var_map[10];
  uint8_T c19_b_sensnames[124];
  char_T c19_test[124];
  real_T c19_k_data[126];
  int32_T c19_k_sizes[2];
  real_T c19_i;
  char_T c19_str_data[123];
  int32_T c19_str_sizes[2];
  char_T c19_Error_data[138];
  int32_T c19_Error_sizes[2];
  real_T c19_nargin = 2.0;
  real_T c19_nargout = 1.0;
  real_T c19_b_stop;
  int32_T c19_i4;
  int32_T c19_i5;
  uint8_T c19_s[124];
  int32_T c19_i6;
  int32_T c19_match_idx;
  char_T c19_text[124];
  int32_T c19_b_i;
  int32_T c19_new_len;
  int32_T c19_c_i;
  int32_T c19_iv0[2];
  int32_T c19_j;
  int32_T c19_match_out_sizes[2];
  int32_T c19_b_new_len;
  int32_T c19_d_i;
  int32_T c19_matches[124];
  int32_T c19_out_sizes[2];
  int32_T c19_e_i;
  int32_T c19_match_out_data[124];
  int32_T c19_out;
  int32_T c19_b_out;
  int32_T c19_loop_ub;
  int32_T c19_i7;
  real_T c19_out_data[124];
  int32_T c19_k;
  int32_T c19_b_k;
  int32_T c19_b_loop_ub;
  int32_T c19_i8;
  int32_T c19_tmp_sizes[2];
  real_T c19_tmp_data[126];
  int32_T c19_c_loop_ub;
  int32_T c19_i9;
  int32_T c19_d_loop_ub;
  int32_T c19_i10;
  int32_T c19_b_k_sizes[2];
  int32_T c19_e_loop_ub;
  int32_T c19_i11;
  real_T c19_b_k_data[126];
  int32_T c19_f_loop_ub;
  int32_T c19_i12;
  int32_T c19_f_i;
  real_T c19_d0;
  real_T c19_d1;
  boolean_T c19_b0;
  boolean_T c19_b1;
  boolean_T c19_b2;
  int32_T c19_i13;
  int32_T c19_i14;
  int32_T c19_s_sizes[2];
  int32_T c19_g_loop_ub;
  int32_T c19_i15;
  char_T c19_s_data[123];
  int32_T c19_str;
  int32_T c19_b_str;
  int32_T c19_h_loop_ub;
  int32_T c19_i16;
  int32_T c19_i_loop_ub;
  int32_T c19_i17;
  int32_T c19_i18;
  static char_T c19_cv0[15] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'L', 'O', 'W' };

  int32_T c19_u_sizes[2];
  int32_T c19_u;
  int32_T c19_b_u;
  int32_T c19_j_loop_ub;
  int32_T c19_i19;
  const mxArray *c19_y = NULL;
  char_T c19_u_data[138];
  int32_T c19_c_u;
  int32_T c19_d_u;
  int32_T c19_k_loop_ub;
  int32_T c19_i20;
  int32_T c19_i21;
  char_T c19_cv1[4];
  static char_T c19_cv2[4] = { '%', 's', '\x0a', '\x00' };

  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c19_sfEvent);
  for (c19_i2 = 0; c19_i2 < 22; c19_i2++) {
    c19_b_chk[c19_i2] = (*chartInstance->c19_chk)[c19_i2];
  }

  for (c19_i3 = 0; c19_i3 < 124; c19_i3++) {
    c19_b_sensnames[c19_i3] = (*chartInstance->c19_sensnames)[c19_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c19_test, 0U, c19_g_sf_marshallOut,
    c19_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c19_k_data, (const int32_T *)
    &c19_k_sizes, NULL, 0, 1, (void *)c19_f_sf_marshallOut, (void *)
    c19_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_i, 2U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c19_str_data, (const int32_T *)
    &c19_str_sizes, NULL, 0, 3, (void *)c19_e_sf_marshallOut, (void *)
    c19_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c19_Error_data, (const int32_T *)
    &c19_Error_sizes, NULL, 0, 4, (void *)c19_d_sf_marshallOut, (void *)
    c19_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 5U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 6U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_b_chk, 7U, c19_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_b_sensnames, 8U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_stop, 9U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 3);
  for (c19_i4 = 0; c19_i4 < 124; c19_i4++) {
    c19_s[c19_i4] = c19_b_sensnames[c19_i4];
  }

  for (c19_i5 = 0; c19_i5 < 124; c19_i5++) {
    c19_test[c19_i5] = (char_T)(int8_T)c19_s[c19_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 4);
  for (c19_i6 = 0; c19_i6 < 124; c19_i6++) {
    c19_text[c19_i6] = c19_test[c19_i6];
  }

  c19_match_idx = 0;
  for (c19_b_i = 1; c19_b_i < 125; c19_b_i++) {
    c19_c_i = c19_b_i;
    c19_j = 1;
    exitg1 = false;
    while ((exitg1 == false) && (c19_j <= 1)) {
      if (c19_text[c19_c_i - 1] == '/') {
        c19_j = 2;
      } else {
        exitg1 = true;
      }
    }

    if (c19_j > 1) {
      c19_matches[c19_match_idx] = c19_c_i;
      c19_match_idx++;
    }
  }

  c19_new_len = c19_match_idx;
  c19_iv0[0] = 1;
  c19_iv0[1] = c19_new_len;
  c19_match_out_sizes[0] = 1;
  c19_match_out_sizes[1] = c19_iv0[1];
  c19_b_new_len = c19_new_len;
  for (c19_d_i = 1; c19_d_i <= c19_b_new_len; c19_d_i++) {
    c19_e_i = c19_d_i - 1;
    c19_match_out_data[c19_e_i] = c19_matches[c19_e_i];
  }

  c19_out_sizes[0] = 1;
  c19_out_sizes[1] = c19_match_out_sizes[1];
  c19_out = c19_out_sizes[0];
  c19_b_out = c19_out_sizes[1];
  c19_loop_ub = c19_match_out_sizes[0] * c19_match_out_sizes[1] - 1;
  for (c19_i7 = 0; c19_i7 <= c19_loop_ub; c19_i7++) {
    c19_out_data[c19_i7] = (real_T)c19_match_out_data[c19_i7];
  }

  c19_k_sizes[0] = 1;
  c19_k_sizes[1] = c19_out_sizes[1];
  c19_k = c19_k_sizes[0];
  c19_b_k = c19_k_sizes[1];
  c19_b_loop_ub = c19_out_sizes[0] * c19_out_sizes[1] - 1;
  for (c19_i8 = 0; c19_i8 <= c19_b_loop_ub; c19_i8++) {
    c19_k_data[c19_i8] = c19_out_data[c19_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
  c19_tmp_sizes[0] = 1;
  c19_tmp_sizes[1] = 1 + c19_k_sizes[1];
  c19_tmp_data[0] = 0.0;
  c19_c_loop_ub = c19_k_sizes[1] - 1;
  for (c19_i9 = 0; c19_i9 <= c19_c_loop_ub; c19_i9++) {
    c19_tmp_data[c19_tmp_sizes[0] * (c19_i9 + 1)] = c19_k_data[c19_k_sizes[0] *
      c19_i9];
  }

  c19_k_sizes[0] = 1;
  c19_k_sizes[1] = c19_tmp_sizes[1];
  c19_d_loop_ub = c19_tmp_sizes[1] - 1;
  for (c19_i10 = 0; c19_i10 <= c19_d_loop_ub; c19_i10++) {
    c19_k_data[c19_k_sizes[0] * c19_i10] = c19_tmp_data[c19_tmp_sizes[0] *
      c19_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 6);
  c19_b_k_sizes[0] = 1;
  c19_b_k_sizes[1] = c19_k_sizes[1] + 1;
  c19_e_loop_ub = c19_k_sizes[1] - 1;
  for (c19_i11 = 0; c19_i11 <= c19_e_loop_ub; c19_i11++) {
    c19_b_k_data[c19_b_k_sizes[0] * c19_i11] = c19_k_data[c19_k_sizes[0] *
      c19_i11];
  }

  c19_b_k_data[c19_b_k_sizes[0] * c19_k_sizes[1]] = 124.0;
  c19_k_sizes[0] = 1;
  c19_k_sizes[1] = c19_b_k_sizes[1];
  c19_f_loop_ub = c19_b_k_sizes[1] - 1;
  for (c19_i12 = 0; c19_i12 <= c19_f_loop_ub; c19_i12++) {
    c19_k_data[c19_k_sizes[0] * c19_i12] = c19_b_k_data[c19_b_k_sizes[0] *
      c19_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 7);
  c19_b_stop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 8);
  c19_i = 1.0;
  c19_f_i = 0;
  while (c19_f_i < 22) {
    c19_i = 1.0 + (real_T)c19_f_i;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 9);
    if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)c19_b_chk
          [(int32_T)c19_i - 1], 0.0, -1, 0U, !c19_b_chk[(int32_T)c19_i - 1]))) {
      _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
      c19_d0 = c19_k_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 208, 4, MAX_uint32_T, (int32_T)c19_i, 1,
        c19_k_sizes[1]) - 1] + 1.0;
      c19_d1 = c19_k_data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 215, 6, MAX_uint32_T, (int32_T)(c19_i + 1.0), 1,
        c19_k_sizes[1]) - 1] - 1.0;
      c19_b0 = (c19_d0 > c19_d1);
      c19_b1 = c19_b0;
      c19_b2 = c19_b1;
      if (c19_b2) {
        c19_i13 = 1;
        c19_i14 = 0;
      } else {
        c19_i13 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 203, 21, MAX_uint32_T, (int32_T)c19_d0, 1, 124);
        c19_i14 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
          chartInstance->S, 1U, 203, 21, MAX_uint32_T, (int32_T)c19_d1, 1, 124);
      }

      c19_s_sizes[0] = 1;
      c19_s_sizes[1] = (c19_i14 - c19_i13) + 1;
      c19_g_loop_ub = c19_i14 - c19_i13;
      for (c19_i15 = 0; c19_i15 <= c19_g_loop_ub; c19_i15++) {
        c19_s_data[c19_s_sizes[0] * c19_i15] = c19_test[(c19_i13 + c19_i15) - 1];
      }

      c19_str_sizes[0] = 1;
      c19_str_sizes[1] = c19_s_sizes[1];
      c19_str = c19_str_sizes[0];
      c19_b_str = c19_str_sizes[1];
      c19_h_loop_ub = c19_s_sizes[0] * c19_s_sizes[1] - 1;
      for (c19_i16 = 0; c19_i16 <= c19_h_loop_ub; c19_i16++) {
        c19_str_data[c19_i16] = c19_s_data[c19_i16];
      }

      _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 11);
      c19_Error_sizes[0] = 1;
      c19_Error_sizes[1] = c19_str_sizes[1] + 15;
      c19_i_loop_ub = c19_str_sizes[1] - 1;
      for (c19_i17 = 0; c19_i17 <= c19_i_loop_ub; c19_i17++) {
        c19_Error_data[c19_Error_sizes[0] * c19_i17] =
          c19_str_data[c19_str_sizes[0] * c19_i17];
      }

      for (c19_i18 = 0; c19_i18 < 15; c19_i18++) {
        c19_Error_data[c19_Error_sizes[0] * (c19_i18 + c19_str_sizes[1])] =
          c19_cv0[c19_i18];
      }

      sf_mex_printf("%s =\\n", "Error");
      c19_u_sizes[0] = 1;
      c19_u_sizes[1] = c19_Error_sizes[1];
      c19_u = c19_u_sizes[0];
      c19_b_u = c19_u_sizes[1];
      c19_j_loop_ub = c19_Error_sizes[0] * c19_Error_sizes[1] - 1;
      for (c19_i19 = 0; c19_i19 <= c19_j_loop_ub; c19_i19++) {
        c19_u_data[c19_i19] = c19_Error_data[c19_i19];
      }

      c19_y = NULL;
      sf_mex_assign(&c19_y, sf_mex_create("y", c19_u_data, 10, 0U, 1U, 0U, 2,
        c19_u_sizes[0], c19_u_sizes[1]), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c19_y);
      _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 12);
      c19_u_sizes[0] = 1;
      c19_u_sizes[1] = c19_Error_sizes[1];
      c19_c_u = c19_u_sizes[0];
      c19_d_u = c19_u_sizes[1];
      c19_k_loop_ub = c19_Error_sizes[0] * c19_Error_sizes[1] - 1;
      for (c19_i20 = 0; c19_i20 <= c19_k_loop_ub; c19_i20++) {
        c19_u_data[c19_i20] = c19_Error_data[c19_i20];
      }

      for (c19_i21 = 0; c19_i21 < 4; c19_i21++) {
        c19_cv1[c19_i21] = c19_cv2[c19_i21];
      }

      printf(c19_cv1, &c19_u_data[0]);
      _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 13);
      c19_b_stop++;
    }

    c19_f_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c19_stop = c19_b_stop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c19_sfEvent);
}

static void initSimStructsc19_feedback_plant_with_best_PID
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_b_stop, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_stop),
    &c19_thisId);
  sf_mex_destroy(&c19_b_stop);
  return c19_y;
}

static real_T c19_b_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d2;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d2, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d2;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_stop;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_b_stop = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_stop),
    &c19_thisId);
  sf_mex_destroy(&c19_b_stop);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i22;
  const mxArray *c19_y = NULL;
  uint8_T c19_u[124];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i22 = 0; c19_i22 < 124; c19_i22++) {
    c19_u[c19_i22] = (*(uint8_T (*)[124])c19_inData)[c19_i22];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 3, 0U, 1U, 0U, 1, 124), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i23;
  const mxArray *c19_y = NULL;
  boolean_T c19_u[22];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i23 = 0; c19_i23 < 22; c19_i23++) {
    c19_u[c19_i23] = (*(boolean_T (*)[22])c19_inData)[c19_i23];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 11, 0U, 1U, 0U, 1, 22), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, char_T
  c19_inData_data[], int32_T c19_inData_sizes[2])
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u_sizes[2];
  int32_T c19_u;
  int32_T c19_b_u;
  int32_T c19_loop_ub;
  int32_T c19_i24;
  const mxArray *c19_y = NULL;
  char_T c19_u_data[138];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u_sizes[0] = 1;
  c19_u_sizes[1] = c19_inData_sizes[1];
  c19_u = c19_u_sizes[0];
  c19_b_u = c19_u_sizes[1];
  c19_loop_ub = c19_inData_sizes[0] * c19_inData_sizes[1] - 1;
  for (c19_i24 = 0; c19_i24 <= c19_loop_ub; c19_i24++) {
    c19_u_data[c19_i24] = c19_inData_data[c19_i24];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u_data, 10, 0U, 1U, 0U, 2,
    c19_u_sizes[0], c19_u_sizes[1]), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_c_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y_data[],
   int32_T c19_y_sizes[2])
{
  int32_T c19_i25;
  int32_T c19_i26;
  uint32_T c19_uv0[2];
  char_T c19_tmp_data[138];
  boolean_T c19_bv0[2];
  int32_T c19_tmp_sizes[2];
  static boolean_T c19_bv1[2] = { false, true };

  int32_T c19_y;
  int32_T c19_b_y;
  int32_T c19_loop_ub;
  int32_T c19_i27;
  (void)chartInstance;
  for (c19_i25 = 0; c19_i25 < 2; c19_i25++) {
    c19_uv0[c19_i25] = 1U + 137U * (uint32_T)c19_i25;
  }

  for (c19_i26 = 0; c19_i26 < 2; c19_i26++) {
    c19_bv0[c19_i26] = c19_bv1[c19_i26];
  }

  sf_mex_import_vs(c19_parentId, sf_mex_dup(c19_u), c19_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c19_bv0, c19_uv0, c19_tmp_sizes);
  c19_y_sizes[0] = 1;
  c19_y_sizes[1] = c19_tmp_sizes[1];
  c19_y = c19_y_sizes[0];
  c19_b_y = c19_y_sizes[1];
  c19_loop_ub = c19_tmp_sizes[0] * c19_tmp_sizes[1] - 1;
  for (c19_i27 = 0; c19_i27 <= c19_loop_ub; c19_i27++) {
    c19_y_data[c19_i27] = c19_tmp_data[c19_i27];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, char_T c19_outData_data[],
  int32_T c19_outData_sizes[2])
{
  const mxArray *c19_Error;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  char_T c19_y_data[138];
  int32_T c19_y_sizes[2];
  int32_T c19_loop_ub;
  int32_T c19_i28;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_Error = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_Error), &c19_thisId,
    c19_y_data, c19_y_sizes);
  sf_mex_destroy(&c19_Error);
  c19_outData_sizes[0] = 1;
  c19_outData_sizes[1] = c19_y_sizes[1];
  c19_loop_ub = c19_y_sizes[1] - 1;
  for (c19_i28 = 0; c19_i28 <= c19_loop_ub; c19_i28++) {
    c19_outData_data[c19_outData_sizes[0] * c19_i28] = c19_y_data[c19_y_sizes[0]
      * c19_i28];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_e_sf_marshallOut(void *chartInstanceVoid, char_T
  c19_inData_data[], int32_T c19_inData_sizes[2])
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u_sizes[2];
  int32_T c19_u;
  int32_T c19_b_u;
  int32_T c19_loop_ub;
  int32_T c19_i29;
  const mxArray *c19_y = NULL;
  char_T c19_u_data[123];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u_sizes[0] = 1;
  c19_u_sizes[1] = c19_inData_sizes[1];
  c19_u = c19_u_sizes[0];
  c19_b_u = c19_u_sizes[1];
  c19_loop_ub = c19_inData_sizes[0] * c19_inData_sizes[1] - 1;
  for (c19_i29 = 0; c19_i29 <= c19_loop_ub; c19_i29++) {
    c19_u_data[c19_i29] = c19_inData_data[c19_i29];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u_data, 10, 0U, 1U, 0U, 2,
    c19_u_sizes[0], c19_u_sizes[1]), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_d_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y_data[],
   int32_T c19_y_sizes[2])
{
  int32_T c19_i30;
  int32_T c19_i31;
  uint32_T c19_uv1[2];
  char_T c19_tmp_data[123];
  boolean_T c19_bv2[2];
  int32_T c19_tmp_sizes[2];
  static boolean_T c19_bv3[2] = { false, true };

  int32_T c19_y;
  int32_T c19_b_y;
  int32_T c19_loop_ub;
  int32_T c19_i32;
  (void)chartInstance;
  for (c19_i30 = 0; c19_i30 < 2; c19_i30++) {
    c19_uv1[c19_i30] = 1U + 122U * (uint32_T)c19_i30;
  }

  for (c19_i31 = 0; c19_i31 < 2; c19_i31++) {
    c19_bv2[c19_i31] = c19_bv3[c19_i31];
  }

  sf_mex_import_vs(c19_parentId, sf_mex_dup(c19_u), c19_tmp_data, 1, 10, 0U, 1,
                   0U, 2, c19_bv2, c19_uv1, c19_tmp_sizes);
  c19_y_sizes[0] = 1;
  c19_y_sizes[1] = c19_tmp_sizes[1];
  c19_y = c19_y_sizes[0];
  c19_b_y = c19_y_sizes[1];
  c19_loop_ub = c19_tmp_sizes[0] * c19_tmp_sizes[1] - 1;
  for (c19_i32 = 0; c19_i32 <= c19_loop_ub; c19_i32++) {
    c19_y_data[c19_i32] = c19_tmp_data[c19_i32];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, char_T c19_outData_data[],
  int32_T c19_outData_sizes[2])
{
  const mxArray *c19_str;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  char_T c19_y_data[123];
  int32_T c19_y_sizes[2];
  int32_T c19_loop_ub;
  int32_T c19_i33;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_str = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_str), &c19_thisId,
    c19_y_data, c19_y_sizes);
  sf_mex_destroy(&c19_str);
  c19_outData_sizes[0] = 1;
  c19_outData_sizes[1] = c19_y_sizes[1];
  c19_loop_ub = c19_y_sizes[1] - 1;
  for (c19_i33 = 0; c19_i33 <= c19_loop_ub; c19_i33++) {
    c19_outData_data[c19_outData_sizes[0] * c19_i33] = c19_y_data[c19_y_sizes[0]
      * c19_i33];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_f_sf_marshallOut(void *chartInstanceVoid, real_T
  c19_inData_data[], int32_T c19_inData_sizes[2])
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u_sizes[2];
  int32_T c19_u;
  int32_T c19_b_u;
  int32_T c19_loop_ub;
  int32_T c19_i34;
  const mxArray *c19_y = NULL;
  real_T c19_u_data[126];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u_sizes[0] = 1;
  c19_u_sizes[1] = c19_inData_sizes[1];
  c19_u = c19_u_sizes[0];
  c19_b_u = c19_u_sizes[1];
  c19_loop_ub = c19_inData_sizes[0] * c19_inData_sizes[1] - 1;
  for (c19_i34 = 0; c19_i34 <= c19_loop_ub; c19_i34++) {
    c19_u_data[c19_i34] = c19_inData_data[c19_i34];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u_data, 0, 0U, 1U, 0U, 2,
    c19_u_sizes[0], c19_u_sizes[1]), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_e_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, real_T c19_y_data[],
   int32_T c19_y_sizes[2])
{
  int32_T c19_i35;
  int32_T c19_i36;
  uint32_T c19_uv2[2];
  real_T c19_tmp_data[126];
  boolean_T c19_bv4[2];
  int32_T c19_tmp_sizes[2];
  static boolean_T c19_bv5[2] = { false, true };

  int32_T c19_y;
  int32_T c19_b_y;
  int32_T c19_loop_ub;
  int32_T c19_i37;
  (void)chartInstance;
  for (c19_i35 = 0; c19_i35 < 2; c19_i35++) {
    c19_uv2[c19_i35] = 1U + 125U * (uint32_T)c19_i35;
  }

  for (c19_i36 = 0; c19_i36 < 2; c19_i36++) {
    c19_bv4[c19_i36] = c19_bv5[c19_i36];
  }

  sf_mex_import_vs(c19_parentId, sf_mex_dup(c19_u), c19_tmp_data, 1, 0, 0U, 1,
                   0U, 2, c19_bv4, c19_uv2, c19_tmp_sizes);
  c19_y_sizes[0] = 1;
  c19_y_sizes[1] = c19_tmp_sizes[1];
  c19_y = c19_y_sizes[0];
  c19_b_y = c19_y_sizes[1];
  c19_loop_ub = c19_tmp_sizes[0] * c19_tmp_sizes[1] - 1;
  for (c19_i37 = 0; c19_i37 <= c19_loop_ub; c19_i37++) {
    c19_y_data[c19_i37] = c19_tmp_data[c19_i37];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, real_T c19_outData_data[],
  int32_T c19_outData_sizes[2])
{
  const mxArray *c19_k;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y_data[126];
  int32_T c19_y_sizes[2];
  int32_T c19_loop_ub;
  int32_T c19_i38;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_k = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_k), &c19_thisId,
    c19_y_data, c19_y_sizes);
  sf_mex_destroy(&c19_k);
  c19_outData_sizes[0] = 1;
  c19_outData_sizes[1] = c19_y_sizes[1];
  c19_loop_ub = c19_y_sizes[1] - 1;
  for (c19_i38 = 0; c19_i38 <= c19_loop_ub; c19_i38++) {
    c19_outData_data[c19_outData_sizes[0] * c19_i38] = c19_y_data[c19_y_sizes[0]
      * c19_i38];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_g_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i39;
  const mxArray *c19_y = NULL;
  char_T c19_u[124];
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i39 = 0; c19_i39 < 124; c19_i39++) {
    c19_u[c19_i39] = (*(char_T (*)[124])c19_inData)[c19_i39];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 10, 0U, 1U, 0U, 2, 1, 124),
                false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static void c19_f_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId, char_T c19_y[124])
{
  char_T c19_cv3[124];
  int32_T c19_i40;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_cv3, 1, 10, 0U, 1, 0U, 2, 1,
                124);
  for (c19_i40 = 0; c19_i40 < 124; c19_i40++) {
    c19_y[c19_i40] = c19_cv3[c19_i40];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_test;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  char_T c19_y[124];
  int32_T c19_i41;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_test = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_test), &c19_thisId, c19_y);
  sf_mex_destroy(&c19_test);
  for (c19_i41 = 0; c19_i41 < 124; c19_i41++) {
    (*(char_T (*)[124])c19_outData)[c19_i41] = c19_y[c19_i41];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray
  *sf_c19_feedback_plant_with_best_PID_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_h_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_g_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i42;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i42, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i42;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
    chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_h_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_b_is_active_c19_feedback_plant_with_best_PID, const char_T
   *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_thisId.bParentIsCell = false;
  c19_y = c19_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_feedback_plant_with_best_PID), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_feedback_plant_with_best_PID);
  return c19_y;
}

static uint8_T c19_i_emlrt_marshallIn
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance, const
   mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance)
{
  chartInstance->c19_chk = (boolean_T (*)[22])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c19_sensnames = (uint8_T (*)[124])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c19_stop = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c19_feedback_plant_with_best_PID_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1319158840U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3973635065U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2382773924U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(786217806U);
}

mxArray* sf_c19_feedback_plant_with_best_PID_get_post_codegen_info(void);
mxArray *sf_c19_feedback_plant_with_best_PID_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4tbRnbvaG9EonOQAKCD2VH");
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
      sf_c19_feedback_plant_with_best_PID_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_feedback_plant_with_best_PID_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_feedback_plant_with_best_PID_jit_fallback_info(void)
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

mxArray *sf_c19_feedback_plant_with_best_PID_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c19_feedback_plant_with_best_PID_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c19_feedback_plant_with_best_PID
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"stop\",},{M[8],M[0],T\"is_active_c19_feedback_plant_with_best_PID\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_feedback_plant_with_best_PID_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance =
      (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _feedback_plant_with_best_PIDMachineNumber_,
           19,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,353);
        _SFD_CV_INIT_EML_IF(0,1,0,169,183,-1,348);
        _SFD_CV_INIT_EML_FOR(0,1,0,144,165,352);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,172,183,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 22U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 124U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);
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
    SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance =
      (SFc19_feedback_plant_with_best_PIDInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c19_chk);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c19_sensnames);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c19_stop);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s44PCccEXY7of6lUgkorogG";
}

static void sf_opaque_initialize_c19_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_feedback_plant_with_best_PIDInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
  initialize_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  enable_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  disable_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  sf_gateway_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c19_feedback_plant_with_best_PID
  (SimStruct* S)
{
  return get_sim_state_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c19_feedback_plant_with_best_PID(SimStruct*
  S, const mxArray *st)
{
  set_sim_state_c19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c19_feedback_plant_with_best_PID(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_feedback_plant_with_best_PIDInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_feedback_plant_with_best_PID_optimization_info();
    }

    finalize_c19_feedback_plant_with_best_PID
      ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_feedback_plant_with_best_PID
    ((SFc19_feedback_plant_with_best_PIDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_feedback_plant_with_best_PID(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_feedback_plant_with_best_PID
      ((SFc19_feedback_plant_with_best_PIDInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c19_feedback_plant_with_best_PID(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_feedback_plant_with_best_PID_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 19);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(492314983U));
  ssSetChecksum1(S,(1489571534U));
  ssSetChecksum2(S,(2543633724U));
  ssSetChecksum3(S,(4182292430U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_feedback_plant_with_best_PID(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_feedback_plant_with_best_PID(SimStruct *S)
{
  SFc19_feedback_plant_with_best_PIDInstanceStruct *chartInstance;
  chartInstance = (SFc19_feedback_plant_with_best_PIDInstanceStruct *)utMalloc
    (sizeof(SFc19_feedback_plant_with_best_PIDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc19_feedback_plant_with_best_PIDInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_feedback_plant_with_best_PID;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_feedback_plant_with_best_PID;
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
  mdl_start_c19_feedback_plant_with_best_PID(chartInstance);
}

void c19_feedback_plant_with_best_PID_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_feedback_plant_with_best_PID(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_feedback_plant_with_best_PID(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_feedback_plant_with_best_PID(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_feedback_plant_with_best_PID_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
