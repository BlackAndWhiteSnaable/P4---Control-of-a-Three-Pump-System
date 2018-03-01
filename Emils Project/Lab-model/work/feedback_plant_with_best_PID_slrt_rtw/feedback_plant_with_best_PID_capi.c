/*
 * feedback_plant_with_best_PID_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "feedback_plant_with_best_PID".
 *
 * Model version              : 1.337
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Aug 22 16:05:35 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "feedback_plant_with_best_PID_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "feedback_plant_with_best_PID.h"
#include "feedback_plant_with_best_PID_capi.h"
#include "feedback_plant_with_best_PID_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, TARGET_STRING("MATLAB Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 2, TARGET_STRING("MATLAB Function1/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 2, TARGET_STRING("MATLAB Function1/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 3, 2, TARGET_STRING("MATLAB Function1/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 1 },

  { 4, 0, TARGET_STRING("From Workspace"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 5, 0, TARGET_STRING("From Workspace1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("From Workspace2"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 7, 0, TARGET_STRING("From Workspace3"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 8, 0, TARGET_STRING("From Workspace6"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 9, 0, TARGET_STRING("Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 3, TARGET_STRING("Subsystem/MATLAB Function"),
    TARGET_STRING("pumps_selected"), 0, 0, 0, 0, 0 },

  { 11, 4, TARGET_STRING("Subsystem/cost_power_1"),
    TARGET_STRING("Power_cost_1"), 0, 0, 0, 0, 0 },

  { 12, 5, TARGET_STRING("Subsystem/cost_power_2"),
    TARGET_STRING("Power_cost_2"), 0, 0, 0, 0, 0 },

  { 13, 6, TARGET_STRING("Subsystem/cost_power_3"),
    TARGET_STRING("Power_cost_3"), 0, 0, 0, 0, 0 },

  { 14, 7, TARGET_STRING("Subsystem/valve_CV_esti_Test"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Subsystem/Rate Transition"),
    TARGET_STRING("PID_Ref"), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Subsystem/Sum"),
    TARGET_STRING("PID_Error"), 0, 0, 0, 0, 0 },

  { 17, 8, TARGET_STRING("actuators/transform/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 8, TARGET_STRING("actuators/transform/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 1 },

  { 19, 8, TARGET_STRING("actuators/transform/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 1 },

  { 20, 8, TARGET_STRING("actuators/transform/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 1 },

  { 21, 9, TARGET_STRING("analogdigital/transform/p1"),
    TARGET_STRING("CV01"), 0, 0, 0, 0, 0 },

  { 22, 9, TARGET_STRING("analogdigital/transform/p2"),
    TARGET_STRING("DPT01"), 1, 0, 0, 0, 0 },

  { 23, 9, TARGET_STRING("analogdigital/transform/p3"),
    TARGET_STRING("LMGC1"), 2, 0, 0, 0, 0 },

  { 24, 9, TARGET_STRING("analogdigital/transform/p4"),
    TARGET_STRING("LMGP1"), 3, 0, 0, 0, 0 },

  { 25, 9, TARGET_STRING("analogdigital/transform/p5"),
    TARGET_STRING("LMGV1"), 4, 0, 0, 0, 0 },

  { 26, 9, TARGET_STRING("analogdigital/transform/p6"),
    TARGET_STRING("MFM01"), 5, 0, 0, 0, 0 },

  { 27, 9, TARGET_STRING("analogdigital/transform/p7"),
    TARGET_STRING("PT01"), 6, 0, 0, 0, 0 },

  { 28, 9, TARGET_STRING("analogdigital/transform/p8"),
    TARGET_STRING("WP01"), 7, 0, 0, 0, 0 },

  { 29, 9, TARGET_STRING("analogdigital/transform/p9"),
    TARGET_STRING("DPT02"), 8, 0, 0, 0, 0 },

  { 30, 9, TARGET_STRING("analogdigital/transform/p10"),
    TARGET_STRING("LMGC2"), 9, 0, 0, 0, 0 },

  { 31, 9, TARGET_STRING("analogdigital/transform/p11"),
    TARGET_STRING("LMGP2"), 10, 0, 0, 0, 0 },

  { 32, 9, TARGET_STRING("analogdigital/transform/p12"),
    TARGET_STRING("LMGV2"), 11, 0, 0, 0, 0 },

  { 33, 9, TARGET_STRING("analogdigital/transform/p13"),
    TARGET_STRING("MFM02"), 12, 0, 0, 0, 0 },

  { 34, 9, TARGET_STRING("analogdigital/transform/p14"),
    TARGET_STRING("PT02"), 13, 0, 0, 0, 0 },

  { 35, 9, TARGET_STRING("analogdigital/transform/p15"),
    TARGET_STRING("WP02"), 14, 0, 0, 0, 0 },

  { 36, 9, TARGET_STRING("analogdigital/transform/p16"),
    TARGET_STRING("DPT03"), 15, 0, 0, 0, 0 },

  { 37, 9, TARGET_STRING("analogdigital/transform/p17"),
    TARGET_STRING("LMGC3"), 16, 0, 0, 0, 0 },

  { 38, 9, TARGET_STRING("analogdigital/transform/p18"),
    TARGET_STRING("LMGP3"), 17, 0, 0, 0, 0 },

  { 39, 9, TARGET_STRING("analogdigital/transform/p19"),
    TARGET_STRING("LMGV3"), 18, 0, 0, 0, 0 },

  { 40, 9, TARGET_STRING("analogdigital/transform/p20"),
    TARGET_STRING("MFM03"), 19, 0, 0, 0, 0 },

  { 41, 9, TARGET_STRING("analogdigital/transform/p21"),
    TARGET_STRING("PT03"), 20, 0, 0, 0, 0 },

  { 42, 9, TARGET_STRING("analogdigital/transform/p22"),
    TARGET_STRING("WP03"), 21, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING("analogdigital/src/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 44, 0, TARGET_STRING("analogdigital/src/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 45, 0, TARGET_STRING("analogdigital/src/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 46, 0, TARGET_STRING("analogdigital/src/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 47, 0, TARGET_STRING("analogdigital/src/p5"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 48, 0, TARGET_STRING("analogdigital/src/p6"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 49, 0, TARGET_STRING("analogdigital/src/p7"),
    TARGET_STRING(""), 6, 0, 0, 0, 0 },

  { 50, 0, TARGET_STRING("analogdigital/src/p8"),
    TARGET_STRING(""), 7, 0, 0, 0, 0 },

  { 51, 0, TARGET_STRING("analogdigital/src/p9"),
    TARGET_STRING(""), 8, 0, 0, 0, 0 },

  { 52, 0, TARGET_STRING("analogdigital/src/p10"),
    TARGET_STRING(""), 9, 0, 0, 0, 0 },

  { 53, 0, TARGET_STRING("analogdigital/src/p11"),
    TARGET_STRING(""), 10, 0, 0, 0, 0 },

  { 54, 0, TARGET_STRING("analogdigital/src/p12"),
    TARGET_STRING(""), 11, 0, 0, 0, 0 },

  { 55, 0, TARGET_STRING("analogdigital/src/p13"),
    TARGET_STRING(""), 12, 0, 0, 0, 0 },

  { 56, 0, TARGET_STRING("analogdigital/src/p14"),
    TARGET_STRING(""), 13, 0, 0, 0, 0 },

  { 57, 0, TARGET_STRING("analogdigital/src/p15"),
    TARGET_STRING(""), 14, 0, 0, 0, 0 },

  { 58, 0, TARGET_STRING("analogdigital/src/p16"),
    TARGET_STRING(""), 15, 0, 0, 0, 0 },

  { 59, 0, TARGET_STRING("analogdigital/src/p17"),
    TARGET_STRING(""), 16, 0, 0, 0, 0 },

  { 60, 0, TARGET_STRING("analogdigital/src/p18"),
    TARGET_STRING(""), 17, 0, 0, 0, 0 },

  { 61, 0, TARGET_STRING("analogdigital/src/p19"),
    TARGET_STRING(""), 18, 0, 0, 0, 0 },

  { 62, 0, TARGET_STRING("analogdigital/src/p20"),
    TARGET_STRING(""), 19, 0, 0, 0, 0 },

  { 63, 0, TARGET_STRING("analogdigital/src/p21"),
    TARGET_STRING(""), 20, 0, 0, 0, 0 },

  { 64, 0, TARGET_STRING("analogdigital/src/p22"),
    TARGET_STRING(""), 21, 0, 0, 0, 0 },

  { 65, 10, TARGET_STRING("terminating_safety/err_high"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 66, 11, TARGET_STRING("terminating_safety/err_low"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 67, 0, TARGET_STRING("Subsystem/PID Controller/Integral Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 68, 0, TARGET_STRING("Subsystem/PID Controller/Proportional Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 69, 0, TARGET_STRING("Subsystem/PID Controller/Integrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 70, 0, TARGET_STRING("Subsystem/PID Controller/Saturate"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 71, 0, TARGET_STRING("Subsystem/PID Controller/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 72, 0, TARGET_STRING("Subsystem/PID Controller/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 73, 0, TARGET_STRING(
    "terminating_safety/Check Static  Lower Bound/min_relop"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 74, 0, TARGET_STRING(
    "terminating_safety/Check Static  Upper Bound/max_relop"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 75, 0, TARGET_STRING(
    "Subsystem/PID Controller/Clamping circuit/DataTypeConv1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 76, 0, TARGET_STRING(
    "Subsystem/PID Controller/Clamping circuit/DataTypeConv2"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 77, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/DeadZone"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 78, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/ZeroGain"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 79, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/AND"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 80, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/Memory"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 81, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/Equal"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 82, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/NotEqual"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 83, 0, TARGET_STRING("Subsystem/PID Controller/Clamping circuit/SignDeltaU"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 84, 0, TARGET_STRING(
    "Subsystem/PID Controller/Clamping circuit/SignPreIntegrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Individual block tuning is not valid when inline parameters is *
 * selected. An empty map is produced to provide a consistent     *
 * interface independent  of inlining parameters.                 *
 */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &feedback_plant_with_best_PID_B.Q_tot,/* 0: Signal */
  &feedback_plant_with_best_PID_B.WP1, /* 1: Signal */
  &feedback_plant_with_best_PID_B.WP2, /* 2: Signal */
  &feedback_plant_with_best_PID_B.WP3, /* 3: Signal */
  &feedback_plant_with_best_PID_B.FromWorkspace,/* 4: Signal */
  &feedback_plant_with_best_PID_B.FromWorkspace1,/* 5: Signal */
  &feedback_plant_with_best_PID_B.FromWorkspace2,/* 6: Signal */
  &feedback_plant_with_best_PID_B.FromWorkspace3,/* 7: Signal */
  &feedback_plant_with_best_PID_B.FromWorkspace6,/* 8: Signal */
  &feedback_plant_with_best_PID_B.Gain,/* 9: Signal */
  &feedback_plant_with_best_PID_B.y,   /* 10: Signal */
  &feedback_plant_with_best_PID_B.cost_power_1_w_sat,/* 11: Signal */
  &feedback_plant_with_best_PID_B.cost_power_2_w_sat,/* 12: Signal */
  &feedback_plant_with_best_PID_B.cost_power_3_w_sat,/* 13: Signal */
  &feedback_plant_with_best_PID_B.req_flow,/* 14: Signal */
  &feedback_plant_with_best_PID_B.PID_Ref,/* 15: Signal */
  &feedback_plant_with_best_PID_B.PID_Error,/* 16: Signal */
  &feedback_plant_with_best_PID_B.CV01_j,/* 17: Signal */
  &feedback_plant_with_best_PID_B.WP01_o,/* 18: Signal */
  &feedback_plant_with_best_PID_B.WP02_l,/* 19: Signal */
  &feedback_plant_with_best_PID_B.WP03_d,/* 20: Signal */
  &feedback_plant_with_best_PID_B.CV01,/* 21: Signal */
  &feedback_plant_with_best_PID_B.DPT01,/* 22: Signal */
  &feedback_plant_with_best_PID_B.LMGC1,/* 23: Signal */
  &feedback_plant_with_best_PID_B.LMGP1,/* 24: Signal */
  &feedback_plant_with_best_PID_B.LMGV1,/* 25: Signal */
  &feedback_plant_with_best_PID_B.MFM01,/* 26: Signal */
  &feedback_plant_with_best_PID_B.PT01,/* 27: Signal */
  &feedback_plant_with_best_PID_B.WP01,/* 28: Signal */
  &feedback_plant_with_best_PID_B.DPT02,/* 29: Signal */
  &feedback_plant_with_best_PID_B.LMGC2,/* 30: Signal */
  &feedback_plant_with_best_PID_B.LMGP2,/* 31: Signal */
  &feedback_plant_with_best_PID_B.LMGV2,/* 32: Signal */
  &feedback_plant_with_best_PID_B.MFM02,/* 33: Signal */
  &feedback_plant_with_best_PID_B.PT02,/* 34: Signal */
  &feedback_plant_with_best_PID_B.WP02,/* 35: Signal */
  &feedback_plant_with_best_PID_B.DPT03,/* 36: Signal */
  &feedback_plant_with_best_PID_B.LMGC3,/* 37: Signal */
  &feedback_plant_with_best_PID_B.LMGP3,/* 38: Signal */
  &feedback_plant_with_best_PID_B.LMGV3,/* 39: Signal */
  &feedback_plant_with_best_PID_B.MFM03,/* 40: Signal */
  &feedback_plant_with_best_PID_B.PT03,/* 41: Signal */
  &feedback_plant_with_best_PID_B.WP03,/* 42: Signal */
  &feedback_plant_with_best_PID_B.src_o1,/* 43: Signal */
  &feedback_plant_with_best_PID_B.src_o2,/* 44: Signal */
  &feedback_plant_with_best_PID_B.src_o3,/* 45: Signal */
  &feedback_plant_with_best_PID_B.src_o4,/* 46: Signal */
  &feedback_plant_with_best_PID_B.src_o5,/* 47: Signal */
  &feedback_plant_with_best_PID_B.src_o6,/* 48: Signal */
  &feedback_plant_with_best_PID_B.src_o7,/* 49: Signal */
  &feedback_plant_with_best_PID_B.src_o8,/* 50: Signal */
  &feedback_plant_with_best_PID_B.src_o9,/* 51: Signal */
  &feedback_plant_with_best_PID_B.src_o10,/* 52: Signal */
  &feedback_plant_with_best_PID_B.src_o11,/* 53: Signal */
  &feedback_plant_with_best_PID_B.src_o12,/* 54: Signal */
  &feedback_plant_with_best_PID_B.src_o13,/* 55: Signal */
  &feedback_plant_with_best_PID_B.src_o14,/* 56: Signal */
  &feedback_plant_with_best_PID_B.src_o15,/* 57: Signal */
  &feedback_plant_with_best_PID_B.src_o16,/* 58: Signal */
  &feedback_plant_with_best_PID_B.src_o17,/* 59: Signal */
  &feedback_plant_with_best_PID_B.src_o18,/* 60: Signal */
  &feedback_plant_with_best_PID_B.src_o19,/* 61: Signal */
  &feedback_plant_with_best_PID_B.src_o20,/* 62: Signal */
  &feedback_plant_with_best_PID_B.src_o21,/* 63: Signal */
  &feedback_plant_with_best_PID_B.src_o22,/* 64: Signal */
  &feedback_plant_with_best_PID_B.stop_a,/* 65: Signal */
  &feedback_plant_with_best_PID_B.stop,/* 66: Signal */
  &feedback_plant_with_best_PID_B.IntegralGain,/* 67: Signal */
  &feedback_plant_with_best_PID_B.ProportionalGain,/* 68: Signal */
  &feedback_plant_with_best_PID_B.Integrator,/* 69: Signal */
  &feedback_plant_with_best_PID_B.Saturate,/* 70: Signal */
  &feedback_plant_with_best_PID_B.Sum, /* 71: Signal */
  &feedback_plant_with_best_PID_B.Switch,/* 72: Signal */
  &feedback_plant_with_best_PID_B.min_relop[0],/* 73: Signal */
  &feedback_plant_with_best_PID_B.max_relop[0],/* 74: Signal */
  &feedback_plant_with_best_PID_B.DataTypeConv1,/* 75: Signal */
  &feedback_plant_with_best_PID_B.DataTypeConv2,/* 76: Signal */
  &feedback_plant_with_best_PID_B.DeadZone,/* 77: Signal */
  &feedback_plant_with_best_PID_B.ZeroGain,/* 78: Signal */
  &feedback_plant_with_best_PID_B.AND, /* 79: Signal */
  &feedback_plant_with_best_PID_B.Memory,/* 80: Signal */
  &feedback_plant_with_best_PID_B.Equal,/* 81: Signal */
  &feedback_plant_with_best_PID_B.NotEqual,/* 82: Signal */
  &feedback_plant_with_best_PID_B.SignDeltaU,/* 83: Signal */
  &feedback_plant_with_best_PID_B.SignPreIntegrator,/* 84: Signal */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  22,                                  /* 2 */
  1                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.01, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 85,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 0,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3325341728U,
    3694922335U,
    4230258845U,
    439708369U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  feedback_plant_with_best_PID_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void feedback_plant_with_best_PID_InitializeDataMapInfo
  (RT_MODEL_feedback_plant_with_best_PID_T *const feedback_plant_with_best_PID_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(feedback_plant_with_best_PID_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
                       &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
    (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(feedback_plant_with_best_PID_M->DataMapInfo.mmi,
    (NULL));
  rtwCAPI_SetChildMMIArrayLen(feedback_plant_with_best_PID_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void feedback_plant_with_best_PID_host_InitializeDataMapInfo
    (feedback_plant_with_best_PID_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: feedback_plant_with_best_PID_capi.c */
