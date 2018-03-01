/* Include files */

#include "feedback_plant_sfun.h"
#include "c2_feedback_plant.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "feedback_plant_sfun_debug_macros.h"
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
static const char * c2_debug_family_names[28] = { "y", "nargin", "nargout", "u",
  "gain", "offset", "CV01", "DPT01", "LMGC1", "LMGP1", "LMGV1", "MFM01", "PT01",
  "WP01", "DPT02", "LMGC2", "LMGP2", "LMGV2", "MFM02", "PT02", "WP02", "DPT03",
  "LMGC3", "LMGP3", "LMGV3", "MFM03", "PT03", "WP03" };

/* Function Declarations */
static void initialize_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void initialize_params_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance);
static void enable_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void disable_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance);
static void set_sim_state_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void sf_gateway_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void mdl_start_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void initSimStructsc2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_WP03, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[22]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[22]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_feedback_plant, const char_T *
  c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_feedback_plantInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_feedback_plantInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_feedback_plant(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_feedback_plant = 0U;
}

static void initialize_params_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance)
{
  real_T c2_dv0[22];
  int32_T c2_i0;
  real_T c2_dv1[22];
  int32_T c2_i1;
  sf_mex_import_named("gain", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c2_dv0, 0, 0, 0U, 1, 0U, 2, 1, 22);
  for (c2_i0 = 0; c2_i0 < 22; c2_i0++) {
    chartInstance->c2_gain[c2_i0] = c2_dv0[c2_i0];
  }

  sf_mex_import_named("offset", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c2_dv1, 0, 0, 0U, 1, 0U, 2, 1, 22);
  for (c2_i1 = 0; c2_i1 < 22; c2_i1++) {
    chartInstance->c2_offset[c2_i1] = c2_dv1[c2_i1];
  }
}

static void enable_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_feedback_plant
  (SFc2_feedback_plantInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_k_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_l_hoistedGlobal;
  real_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  real_T c2_m_hoistedGlobal;
  real_T c2_n_u;
  const mxArray *c2_n_y = NULL;
  real_T c2_n_hoistedGlobal;
  real_T c2_o_u;
  const mxArray *c2_o_y = NULL;
  real_T c2_o_hoistedGlobal;
  real_T c2_p_u;
  const mxArray *c2_p_y = NULL;
  real_T c2_p_hoistedGlobal;
  real_T c2_q_u;
  const mxArray *c2_q_y = NULL;
  real_T c2_q_hoistedGlobal;
  real_T c2_r_u;
  const mxArray *c2_r_y = NULL;
  real_T c2_r_hoistedGlobal;
  real_T c2_s_u;
  const mxArray *c2_s_y = NULL;
  real_T c2_s_hoistedGlobal;
  real_T c2_t_u;
  const mxArray *c2_t_y = NULL;
  real_T c2_t_hoistedGlobal;
  real_T c2_u_u;
  const mxArray *c2_u_y = NULL;
  real_T c2_u_hoistedGlobal;
  real_T c2_v_u;
  const mxArray *c2_v_y = NULL;
  real_T c2_v_hoistedGlobal;
  real_T c2_w_u;
  const mxArray *c2_w_y = NULL;
  uint8_T c2_w_hoistedGlobal;
  uint8_T c2_x_u;
  const mxArray *c2_x_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(23, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_CV01;
  c2_b_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_DPT01;
  c2_c_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *chartInstance->c2_DPT02;
  c2_d_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *chartInstance->c2_DPT03;
  c2_e_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *chartInstance->c2_LMGC1;
  c2_f_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *chartInstance->c2_LMGC2;
  c2_g_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *chartInstance->c2_LMGC3;
  c2_h_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *chartInstance->c2_LMGP1;
  c2_i_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *chartInstance->c2_LMGP2;
  c2_j_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = *chartInstance->c2_LMGP3;
  c2_k_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = *chartInstance->c2_LMGV1;
  c2_l_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_l_hoistedGlobal = *chartInstance->c2_LMGV2;
  c2_m_u = c2_l_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_m_hoistedGlobal = *chartInstance->c2_LMGV3;
  c2_n_u = c2_m_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  c2_n_hoistedGlobal = *chartInstance->c2_MFM01;
  c2_o_u = c2_n_hoistedGlobal;
  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", &c2_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_o_hoistedGlobal = *chartInstance->c2_MFM02;
  c2_p_u = c2_o_hoistedGlobal;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 14, c2_p_y);
  c2_p_hoistedGlobal = *chartInstance->c2_MFM03;
  c2_q_u = c2_p_hoistedGlobal;
  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", &c2_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 15, c2_q_y);
  c2_q_hoistedGlobal = *chartInstance->c2_PT01;
  c2_r_u = c2_q_hoistedGlobal;
  c2_r_y = NULL;
  sf_mex_assign(&c2_r_y, sf_mex_create("y", &c2_r_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 16, c2_r_y);
  c2_r_hoistedGlobal = *chartInstance->c2_PT02;
  c2_s_u = c2_r_hoistedGlobal;
  c2_s_y = NULL;
  sf_mex_assign(&c2_s_y, sf_mex_create("y", &c2_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 17, c2_s_y);
  c2_s_hoistedGlobal = *chartInstance->c2_PT03;
  c2_t_u = c2_s_hoistedGlobal;
  c2_t_y = NULL;
  sf_mex_assign(&c2_t_y, sf_mex_create("y", &c2_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 18, c2_t_y);
  c2_t_hoistedGlobal = *chartInstance->c2_WP01;
  c2_u_u = c2_t_hoistedGlobal;
  c2_u_y = NULL;
  sf_mex_assign(&c2_u_y, sf_mex_create("y", &c2_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 19, c2_u_y);
  c2_u_hoistedGlobal = *chartInstance->c2_WP02;
  c2_v_u = c2_u_hoistedGlobal;
  c2_v_y = NULL;
  sf_mex_assign(&c2_v_y, sf_mex_create("y", &c2_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 20, c2_v_y);
  c2_v_hoistedGlobal = *chartInstance->c2_WP03;
  c2_w_u = c2_v_hoistedGlobal;
  c2_w_y = NULL;
  sf_mex_assign(&c2_w_y, sf_mex_create("y", &c2_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 21, c2_w_y);
  c2_w_hoistedGlobal = chartInstance->c2_is_active_c2_feedback_plant;
  c2_x_u = c2_w_hoistedGlobal;
  c2_x_y = NULL;
  sf_mex_assign(&c2_x_y, sf_mex_create("y", &c2_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 22, c2_x_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  *chartInstance->c2_CV01 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("CV01", c2_b_u, 0)), "CV01");
  *chartInstance->c2_DPT01 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("DPT01", c2_b_u, 1)), "DPT01");
  *chartInstance->c2_DPT02 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("DPT02", c2_b_u, 2)), "DPT02");
  *chartInstance->c2_DPT03 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("DPT03", c2_b_u, 3)), "DPT03");
  *chartInstance->c2_LMGC1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGC1", c2_b_u, 4)), "LMGC1");
  *chartInstance->c2_LMGC2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGC2", c2_b_u, 5)), "LMGC2");
  *chartInstance->c2_LMGC3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGC3", c2_b_u, 6)), "LMGC3");
  *chartInstance->c2_LMGP1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGP1", c2_b_u, 7)), "LMGP1");
  *chartInstance->c2_LMGP2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGP2", c2_b_u, 8)), "LMGP2");
  *chartInstance->c2_LMGP3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGP3", c2_b_u, 9)), "LMGP3");
  *chartInstance->c2_LMGV1 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGV1", c2_b_u, 10)), "LMGV1");
  *chartInstance->c2_LMGV2 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGV2", c2_b_u, 11)), "LMGV2");
  *chartInstance->c2_LMGV3 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("LMGV3", c2_b_u, 12)), "LMGV3");
  *chartInstance->c2_MFM01 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("MFM01", c2_b_u, 13)), "MFM01");
  *chartInstance->c2_MFM02 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("MFM02", c2_b_u, 14)), "MFM02");
  *chartInstance->c2_MFM03 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("MFM03", c2_b_u, 15)), "MFM03");
  *chartInstance->c2_PT01 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PT01", c2_b_u, 16)), "PT01");
  *chartInstance->c2_PT02 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PT02", c2_b_u, 17)), "PT02");
  *chartInstance->c2_PT03 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("PT03", c2_b_u, 18)), "PT03");
  *chartInstance->c2_WP01 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("WP01", c2_b_u, 19)), "WP01");
  *chartInstance->c2_WP02 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("WP02", c2_b_u, 20)), "WP02");
  *chartInstance->c2_WP03 = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("WP03", c2_b_u, 21)), "WP03");
  chartInstance->c2_is_active_c2_feedback_plant = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c2_feedback_plant",
       c2_b_u, 22)), "is_active_c2_feedback_plant");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_feedback_plant(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T c2_b_u[22];
  int32_T c2_i5;
  real_T c2_b_gain[22];
  uint32_T c2_debug_family_var_map[28];
  real_T c2_b_offset[22];
  real_T c2_y[22];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 22.0;
  real_T c2_b_CV01;
  real_T c2_b_DPT01;
  real_T c2_b_LMGC1;
  real_T c2_b_LMGP1;
  real_T c2_b_LMGV1;
  real_T c2_b_MFM01;
  real_T c2_b_PT01;
  real_T c2_b_WP01;
  real_T c2_b_DPT02;
  real_T c2_b_LMGC2;
  real_T c2_b_LMGP2;
  real_T c2_b_LMGV2;
  real_T c2_b_MFM02;
  real_T c2_b_PT02;
  real_T c2_b_WP02;
  real_T c2_b_DPT03;
  real_T c2_b_LMGC3;
  real_T c2_b_LMGP3;
  real_T c2_b_LMGV3;
  real_T c2_b_MFM03;
  real_T c2_b_PT03;
  real_T c2_b_WP03;
  int32_T c2_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 22; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i2], 0U, 1U, 0U,
                          chartInstance->c2_sfEvent, false);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 22; c2_i3++) {
    c2_b_u[c2_i3] = (*chartInstance->c2_u)[c2_i3];
  }

  for (c2_i4 = 0; c2_i4 < 22; c2_i4++) {
    c2_b_gain[c2_i4] = chartInstance->c2_gain[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 22; c2_i5++) {
    c2_b_offset[c2_i5] = chartInstance->c2_offset[c2_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 28U, 28U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_y, 0U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u, 3U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_gain, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_offset, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_CV01, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_DPT01, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGC1, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGP1, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGV1, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_MFM01, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_PT01, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_WP01, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_DPT02, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGC2, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGP2, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGV2, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_MFM02, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_PT02, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_WP02, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_DPT03, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGC3, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGP3, 23U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_LMGV3, 24U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_MFM03, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_PT03, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_WP03, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  for (c2_i6 = 0; c2_i6 < 22; c2_i6++) {
    c2_y[c2_i6] = c2_b_u[c2_i6] * c2_b_gain[c2_i6] - c2_b_offset[c2_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_b_CV01 = c2_y[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_b_DPT01 = c2_y[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_b_LMGC1 = c2_y[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_b_LMGP1 = c2_y[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_b_LMGV1 = c2_y[4];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_b_MFM01 = c2_y[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_b_PT01 = c2_y[6];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_b_WP01 = c2_y[7];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_b_DPT02 = c2_y[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_b_LMGC2 = c2_y[9];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_b_LMGP2 = c2_y[10];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_b_LMGV2 = c2_y[11];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_b_MFM02 = c2_y[12];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_b_PT02 = c2_y[13];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_b_WP02 = c2_y[14];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_b_DPT03 = c2_y[15];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_b_LMGC3 = c2_y[16];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_b_LMGP3 = c2_y[17];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_b_LMGV3 = c2_y[18];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_b_MFM03 = c2_y[19];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_b_PT03 = c2_y[20];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_b_WP03 = c2_y[21];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c2_CV01 = c2_b_CV01;
  *chartInstance->c2_DPT01 = c2_b_DPT01;
  *chartInstance->c2_LMGC1 = c2_b_LMGC1;
  *chartInstance->c2_LMGP1 = c2_b_LMGP1;
  *chartInstance->c2_LMGV1 = c2_b_LMGV1;
  *chartInstance->c2_MFM01 = c2_b_MFM01;
  *chartInstance->c2_PT01 = c2_b_PT01;
  *chartInstance->c2_WP01 = c2_b_WP01;
  *chartInstance->c2_DPT02 = c2_b_DPT02;
  *chartInstance->c2_LMGC2 = c2_b_LMGC2;
  *chartInstance->c2_LMGP2 = c2_b_LMGP2;
  *chartInstance->c2_LMGV2 = c2_b_LMGV2;
  *chartInstance->c2_MFM02 = c2_b_MFM02;
  *chartInstance->c2_PT02 = c2_b_PT02;
  *chartInstance->c2_WP02 = c2_b_WP02;
  *chartInstance->c2_DPT03 = c2_b_DPT03;
  *chartInstance->c2_LMGC3 = c2_b_LMGC3;
  *chartInstance->c2_LMGP3 = c2_b_LMGP3;
  *chartInstance->c2_LMGV3 = c2_b_LMGV3;
  *chartInstance->c2_MFM03 = c2_b_MFM03;
  *chartInstance->c2_PT03 = c2_b_PT03;
  *chartInstance->c2_WP03 = c2_b_WP03;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_feedback_plantMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_CV01, 1U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_DPT01, 2U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGC1, 3U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGP1, 4U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGV1, 5U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_MFM01, 6U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_PT01, 7U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_WP01, 8U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_DPT02, 9U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGC2, 10U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGP2, 11U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGV2, 12U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_MFM02, 13U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_PT02, 14U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_WP02, 15U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_DPT03, 16U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGC3, 17U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGP3, 18U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_LMGV3, 19U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_MFM03, 20U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_PT03, 21U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_WP03, 22U, 1U, 0U,
                        chartInstance->c2_sfEvent, false);
}

static void mdl_start_c2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_feedback_plant(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_WP03, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_WP03), &c2_thisId);
  sf_mex_destroy(&c2_b_WP03);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_WP03;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_b_WP03 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_WP03), &c2_thisId);
  sf_mex_destroy(&c2_b_WP03);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i7;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[22];
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i7 = 0; c2_i7 < 22; c2_i7++) {
    c2_b_u[c2_i7] = (*(real_T (*)[22])c2_inData)[c2_i7];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 22),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[22])
{
  real_T c2_dv2[22];
  int32_T c2_i8;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                22);
  for (c2_i8 = 0; c2_i8 < 22; c2_i8++) {
    c2_y[c2_i8] = c2_dv2[c2_i8];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_offset;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[22];
  int32_T c2_i9;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_b_offset = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_offset), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_offset);
  for (c2_i9 = 0; c2_i9 < 22; c2_i9++) {
    (*(real_T (*)[22])c2_outData)[c2_i9] = c2_y[c2_i9];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  const mxArray *c2_y = NULL;
  real_T c2_b_u[22];
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i10 = 0; c2_i10 < 22; c2_i10++) {
    c2_b_u[c2_i10] = (*(real_T (*)[22])c2_inData)[c2_i10];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 22), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[22])
{
  real_T c2_dv3[22];
  int32_T c2_i11;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 22);
  for (c2_i11 = 0; c2_i11 < 22; c2_i11++) {
    c2_y[c2_i11] = c2_dv3[c2_i11];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_b_y[22];
  int32_T c2_i12;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId, c2_b_y);
  sf_mex_destroy(&c2_y);
  for (c2_i12 = 0; c2_i12 < 22; c2_i12++) {
    (*(real_T (*)[22])c2_outData)[c2_i12] = c2_b_y[c2_i12];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_feedback_plant_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i13;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i13, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i13;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_feedback_plant, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_feedback_plant), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_feedback_plant);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_feedback_plantInstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_feedback_plantInstanceStruct
  *chartInstance)
{
  chartInstance->c2_CV01 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_u = (real_T (*)[22])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_DPT01 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_LMGC1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_LMGP1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_LMGV1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_MFM01 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_PT01 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_WP01 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c2_DPT02 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c2_LMGC2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c2_LMGP2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c2_LMGV2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c2_MFM02 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
  chartInstance->c2_PT02 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 14);
  chartInstance->c2_WP02 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 15);
  chartInstance->c2_DPT03 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 16);
  chartInstance->c2_LMGC3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 17);
  chartInstance->c2_LMGP3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 18);
  chartInstance->c2_LMGV3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 19);
  chartInstance->c2_MFM03 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 20);
  chartInstance->c2_PT03 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 21);
  chartInstance->c2_WP03 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 22);
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

void sf_c2_feedback_plant_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1002075171U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1846329224U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2337287240U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(486741806U);
}

mxArray* sf_c2_feedback_plant_get_post_codegen_info(void);
mxArray *sf_c2_feedback_plant_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aEj265xry2rNm6l2ov8HlE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(22);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(22);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,22,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_feedback_plant_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_feedback_plant_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_feedback_plant_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_feedback_plant_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_feedback_plant_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_feedback_plant(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"CV01\",},{M[1],M[10],T\"DPT01\",},{M[1],M[17],T\"DPT02\",},{M[1],M[24],T\"DPT03\",},{M[1],M[11],T\"LMGC1\",},{M[1],M[18],T\"LMGC2\",},{M[1],M[25],T\"LMGC3\",},{M[1],M[12],T\"LMGP1\",},{M[1],M[19],T\"LMGP2\",},{M[1],M[26],T\"LMGP3\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"LMGV1\",},{M[1],M[20],T\"LMGV2\",},{M[1],M[27],T\"LMGV3\",},{M[1],M[14],T\"MFM01\",},{M[1],M[21],T\"MFM02\",},{M[1],M[28],T\"MFM03\",},{M[1],M[15],T\"PT01\",},{M[1],M[22],T\"PT02\",},{M[1],M[29],T\"PT03\",},{M[1],M[16],T\"WP01\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[23],T\"WP02\",},{M[1],M[30],T\"WP03\",},{M[8],M[0],T\"is_active_c2_feedback_plant\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 23, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_feedback_plant_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_feedback_plantInstanceStruct *chartInstance =
      (SFc2_feedback_plantInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _feedback_plantMachineNumber_,
           2,
           1,
           1,
           0,
           25,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_feedback_plantMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_feedback_plantMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _feedback_plantMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"CV01");
          _SFD_SET_DATA_PROPS(2,2,0,1,"DPT01");
          _SFD_SET_DATA_PROPS(3,2,0,1,"LMGC1");
          _SFD_SET_DATA_PROPS(4,2,0,1,"LMGP1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"LMGV1");
          _SFD_SET_DATA_PROPS(6,2,0,1,"MFM01");
          _SFD_SET_DATA_PROPS(7,2,0,1,"PT01");
          _SFD_SET_DATA_PROPS(8,2,0,1,"WP01");
          _SFD_SET_DATA_PROPS(9,2,0,1,"DPT02");
          _SFD_SET_DATA_PROPS(10,2,0,1,"LMGC2");
          _SFD_SET_DATA_PROPS(11,2,0,1,"LMGP2");
          _SFD_SET_DATA_PROPS(12,2,0,1,"LMGV2");
          _SFD_SET_DATA_PROPS(13,2,0,1,"MFM02");
          _SFD_SET_DATA_PROPS(14,2,0,1,"PT02");
          _SFD_SET_DATA_PROPS(15,2,0,1,"WP02");
          _SFD_SET_DATA_PROPS(16,2,0,1,"DPT03");
          _SFD_SET_DATA_PROPS(17,2,0,1,"LMGC3");
          _SFD_SET_DATA_PROPS(18,2,0,1,"LMGP3");
          _SFD_SET_DATA_PROPS(19,2,0,1,"LMGV3");
          _SFD_SET_DATA_PROPS(20,2,0,1,"MFM03");
          _SFD_SET_DATA_PROPS(21,2,0,1,"PT03");
          _SFD_SET_DATA_PROPS(22,2,0,1,"WP03");
          _SFD_SET_DATA_PROPS(23,10,0,0,"gain");
          _SFD_SET_DATA_PROPS(24,10,0,0,"offset");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,503);

        {
          unsigned int dimVector[1];
          dimVector[0]= 22U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 22U;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 22U;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _feedback_plantMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_feedback_plantInstanceStruct *chartInstance =
      (SFc2_feedback_plantInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_CV01);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c2_gain);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c2_offset);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_DPT01);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_LMGC1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c2_LMGP1);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c2_LMGV1);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c2_MFM01);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c2_PT01);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_WP01);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c2_DPT02);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c2_LMGC2);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c2_LMGP2);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c2_LMGV2);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c2_MFM02);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c2_PT02);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c2_WP02);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c2_DPT03);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c2_LMGC3);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c2_LMGP3);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c2_LMGV3);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c2_MFM03);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c2_PT03);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c2_WP03);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sZSRYZoCc8B55xIg7DuBLaC";
}

static void sf_opaque_initialize_c2_feedback_plant(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar);
  initialize_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_feedback_plant(void *chartInstanceVar)
{
  enable_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_feedback_plant(void *chartInstanceVar)
{
  disable_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_feedback_plant(void *chartInstanceVar)
{
  sf_gateway_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_feedback_plant(SimStruct* S)
{
  return get_sim_state_c2_feedback_plant((SFc2_feedback_plantInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_feedback_plant(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_feedback_plant(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_feedback_plantInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_feedback_plant_optimization_info();
    }

    finalize_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_feedback_plant(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_feedback_plant((SFc2_feedback_plantInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_feedback_plant(SimStruct *S)
{
  /* Actual parameters from chart:
     gain offset
   */
  const char_T *rtParamNames[] = { "gain", "offset" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for gain*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for offset*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* Set overwritable ports for inplace optimization */
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_feedback_plant_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,22);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=22; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(917719274U));
  ssSetChecksum1(S,(1633658904U));
  ssSetChecksum2(S,(2768706917U));
  ssSetChecksum3(S,(2441390220U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_feedback_plant(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_feedback_plant(SimStruct *S)
{
  SFc2_feedback_plantInstanceStruct *chartInstance;
  chartInstance = (SFc2_feedback_plantInstanceStruct *)utMalloc(sizeof
    (SFc2_feedback_plantInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_feedback_plantInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_feedback_plant;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_feedback_plant;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_feedback_plant;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_feedback_plant;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_feedback_plant;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_feedback_plant;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_feedback_plant;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_feedback_plant;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_feedback_plant;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_feedback_plant;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_feedback_plant;
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
  mdl_start_c2_feedback_plant(chartInstance);
}

void c2_feedback_plant_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_feedback_plant(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_feedback_plant(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_feedback_plant(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_feedback_plant_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
