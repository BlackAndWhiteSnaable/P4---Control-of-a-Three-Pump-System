/*
 * pump_test_model_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pump_test_model".
 *
 * Model version              : 1.107
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Aug 22 15:54:19 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "pump_test_model_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "pump_test_model.h"
#include "pump_test_model_capi.h"
#include "pump_test_model_private.h"
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
    TARGET_STRING("pumps_selected"), 0, 0, 0, 0, 0 },

  { 1, 2, TARGET_STRING("cost_power_1"),
    TARGET_STRING("Power_cost_1"), 0, 0, 0, 0, 0 },

  { 2, 3, TARGET_STRING("cost_power_2"),
    TARGET_STRING("Power_cost_2"), 0, 0, 0, 0, 0 },

  { 3, 4, TARGET_STRING("cost_power_3"),
    TARGET_STRING("Power_cost_3"), 0, 0, 0, 0, 0 },

  { 4, 5, TARGET_STRING("valve_CV_esti_Test"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("Rate Transition"),
    TARGET_STRING("PID_Ref"), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("Sum"),
    TARGET_STRING("PID_Error"), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("PID Controller/Integral Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("PID Controller/Proportional Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("PID Controller/Integrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("PID Controller/Saturate"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("PID Controller/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("PID Controller/Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("PID Controller/Clamping circuit/DataTypeConv1"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 14, 0, TARGET_STRING("PID Controller/Clamping circuit/DataTypeConv2"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 15, 0, TARGET_STRING("PID Controller/Clamping circuit/DeadZone"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("PID Controller/Clamping circuit/ZeroGain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("PID Controller/Clamping circuit/AND"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 18, 0, TARGET_STRING("PID Controller/Clamping circuit/Memory"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 19, 0, TARGET_STRING("PID Controller/Clamping circuit/Equal"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 20, 0, TARGET_STRING("PID Controller/Clamping circuit/NotEqual"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 21, 0, TARGET_STRING("PID Controller/Clamping circuit/SignDeltaU"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("PID Controller/Clamping circuit/SignPreIntegrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 23, TARGET_STRING("PID Controller"),
    TARGET_STRING("P"), 0, 0, 0 },

  { 24, TARGET_STRING("PID Controller"),
    TARGET_STRING("I"), 0, 0, 0 },

  { 25, TARGET_STRING("PID Controller"),
    TARGET_STRING("UpperSaturationLimit"), 0, 0, 0 },

  { 26, TARGET_STRING("PID Controller"),
    TARGET_STRING("LowerSaturationLimit"), 0, 0, 0 },

  { 27, TARGET_STRING("PID Controller/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 28, TARGET_STRING("PID Controller/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 29, TARGET_STRING("PID Controller/Clamping circuit/ZeroGain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 30, TARGET_STRING("PID Controller/Clamping circuit/Memory"),
    TARGET_STRING("X0"), 2, 0, 0 },

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
  &pump_test_model_B.y,                /* 0: Signal */
  &pump_test_model_B.cost_power_1_w_sat,/* 1: Signal */
  &pump_test_model_B.cost_power_2_w_sat,/* 2: Signal */
  &pump_test_model_B.cost_power_3_w_sat,/* 3: Signal */
  &pump_test_model_B.req_flow,         /* 4: Signal */
  &pump_test_model_B.PID_Ref,          /* 5: Signal */
  &pump_test_model_B.PID_Error,        /* 6: Signal */
  &pump_test_model_B.IntegralGain,     /* 7: Signal */
  &pump_test_model_B.ProportionalGain, /* 8: Signal */
  &pump_test_model_B.Integrator,       /* 9: Signal */
  &pump_test_model_B.Saturate,         /* 10: Signal */
  &pump_test_model_B.Sum,              /* 11: Signal */
  &pump_test_model_B.Switch,           /* 12: Signal */
  &pump_test_model_B.DataTypeConv1,    /* 13: Signal */
  &pump_test_model_B.DataTypeConv2,    /* 14: Signal */
  &pump_test_model_B.DeadZone,         /* 15: Signal */
  &pump_test_model_B.ZeroGain,         /* 16: Signal */
  &pump_test_model_B.AND,              /* 17: Signal */
  &pump_test_model_B.Memory,           /* 18: Signal */
  &pump_test_model_B.Equal,            /* 19: Signal */
  &pump_test_model_B.NotEqual,         /* 20: Signal */
  &pump_test_model_B.SignDeltaU,       /* 21: Signal */
  &pump_test_model_B.SignPreIntegrator,/* 22: Signal */
  &pump_test_model_P.PIDController_P,  /* 23: Mask Parameter */
  &pump_test_model_P.PIDController_I,  /* 24: Mask Parameter */
  &pump_test_model_P.PIDController_UpperSaturationLi,/* 25: Mask Parameter */
  &pump_test_model_P.PIDController_LowerSaturationLi,/* 26: Mask Parameter */
  &pump_test_model_P.Constant_Value,   /* 27: Block Parameter */
  &pump_test_model_P.Integrator_IC,    /* 28: Block Parameter */
  &pump_test_model_P.ZeroGain_Gain,    /* 29: Block Parameter */
  &pump_test_model_P.Memory_X0,        /* 30: Block Parameter */
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

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
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
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.0005
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
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
  { rtBlockSignals, 23,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 8,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2607241235U,
    1074451916U,
    3140992310U,
    1925836975U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  pump_test_model_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void pump_test_model_InitializeDataMapInfo(RT_MODEL_pump_test_model_T *const
  pump_test_model_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(pump_test_model_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(pump_test_model_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(pump_test_model_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(pump_test_model_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(pump_test_model_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  pump_test_model_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (pump_test_model_M);
  pump_test_model_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_pump_test_model_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(pump_test_model_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(pump_test_model_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(pump_test_model_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void pump_test_model_host_InitializeDataMapInfo
    (pump_test_model_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: pump_test_model_capi.c */
