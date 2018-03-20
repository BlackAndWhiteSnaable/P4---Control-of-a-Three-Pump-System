/*
 * firstTest_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "firstTest".
 *
 * Model version              : 1.371
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Mar 20 12:36:42 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "firstTest_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "firstTest.h"
#include "firstTest_capi.h"
#include "firstTest_private.h"
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
  { 0, 0, TARGET_STRING("%2signal"),
    TARGET_STRING("CV01_input"), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("DA_meas/src/p1"),
    TARGET_STRING("CV01"), 0, 0, 0, 0, 2 },

  { 3, 0, TARGET_STRING("DA_meas/src/p2"),
    TARGET_STRING("DPT01"), 1, 0, 0, 0, 2 },

  { 4, 0, TARGET_STRING("DA_meas/src/p3"),
    TARGET_STRING("LMGC1"), 2, 0, 0, 0, 2 },

  { 5, 0, TARGET_STRING("DA_meas/src/p4"),
    TARGET_STRING("LMGP1"), 3, 0, 0, 0, 2 },

  { 6, 0, TARGET_STRING("DA_meas/src/p5"),
    TARGET_STRING("LMGV1"), 4, 0, 0, 0, 2 },

  { 7, 0, TARGET_STRING("DA_meas/src/p6"),
    TARGET_STRING("MFM01"), 5, 0, 0, 0, 2 },

  { 8, 0, TARGET_STRING("DA_meas/src/p7"),
    TARGET_STRING("PT01"), 6, 0, 0, 0, 2 },

  { 9, 0, TARGET_STRING("DA_meas/src/p8"),
    TARGET_STRING("WP01"), 7, 0, 0, 0, 2 },

  { 10, 0, TARGET_STRING("DA_meas/src/p9"),
    TARGET_STRING("DPT02"), 8, 0, 0, 0, 2 },

  { 11, 0, TARGET_STRING("DA_meas/src/p10"),
    TARGET_STRING("LMGC2"), 9, 0, 0, 0, 2 },

  { 12, 0, TARGET_STRING("DA_meas/src/p11"),
    TARGET_STRING("LMGP2"), 10, 0, 0, 0, 2 },

  { 13, 0, TARGET_STRING("DA_meas/src/p12"),
    TARGET_STRING("LMGV2"), 11, 0, 0, 0, 2 },

  { 14, 0, TARGET_STRING("DA_meas/src/p13"),
    TARGET_STRING("MFM02"), 12, 0, 0, 0, 2 },

  { 15, 0, TARGET_STRING("DA_meas/src/p14"),
    TARGET_STRING("PT02"), 13, 0, 0, 0, 2 },

  { 16, 0, TARGET_STRING("DA_meas/src/p15"),
    TARGET_STRING("WP02"), 14, 0, 0, 0, 2 },

  { 17, 0, TARGET_STRING("DA_meas/src/p16"),
    TARGET_STRING("DPT03"), 15, 0, 0, 0, 2 },

  { 18, 0, TARGET_STRING("DA_meas/src/p17"),
    TARGET_STRING("LMGC3"), 16, 0, 0, 0, 2 },

  { 19, 0, TARGET_STRING("DA_meas/src/p18"),
    TARGET_STRING("LMGP3"), 17, 0, 0, 0, 2 },

  { 20, 0, TARGET_STRING("DA_meas/src/p19"),
    TARGET_STRING("LMGV3"), 18, 0, 0, 0, 2 },

  { 21, 0, TARGET_STRING("DA_meas/src/p20"),
    TARGET_STRING("MFM03"), 19, 0, 0, 0, 2 },

  { 22, 0, TARGET_STRING("DA_meas/src/p21"),
    TARGET_STRING("PT03"), 20, 0, 0, 0, 2 },

  { 23, 0, TARGET_STRING("DA_meas/src/p22"),
    TARGET_STRING("WP03"), 21, 0, 0, 0, 2 },

  { 24, 0, TARGET_STRING("Ramp/Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 25, 0, TARGET_STRING("Ramp/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 26, 0, TARGET_STRING("Ramp/Step"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 27, 0, TARGET_STRING("Ramp/Output"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 28, 0, TARGET_STRING("Ramp/Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

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
  (void *) &firstTest_ConstB.CV01_input,/* 0: Signal */
  &firstTest_B.Sum_b,                  /* 1: Signal */
  &firstTest_B.CV01,                   /* 2: Signal */
  &firstTest_B.DPT01,                  /* 3: Signal */
  &firstTest_B.LMGC1,                  /* 4: Signal */
  &firstTest_B.LMGP1,                  /* 5: Signal */
  &firstTest_B.LMGV1,                  /* 6: Signal */
  &firstTest_B.MFM01,                  /* 7: Signal */
  &firstTest_B.PT01,                   /* 8: Signal */
  &firstTest_B.WP01,                   /* 9: Signal */
  &firstTest_B.DPT02,                  /* 10: Signal */
  &firstTest_B.LMGC2,                  /* 11: Signal */
  &firstTest_B.LMGP2,                  /* 12: Signal */
  &firstTest_B.LMGV2,                  /* 13: Signal */
  &firstTest_B.MFM02,                  /* 14: Signal */
  &firstTest_B.PT02,                   /* 15: Signal */
  &firstTest_B.WP02,                   /* 16: Signal */
  &firstTest_B.DPT03,                  /* 17: Signal */
  &firstTest_B.LMGC3,                  /* 18: Signal */
  &firstTest_B.LMGP3,                  /* 19: Signal */
  &firstTest_B.LMGV3,                  /* 20: Signal */
  &firstTest_B.MFM03,                  /* 21: Signal */
  &firstTest_B.PT03,                   /* 22: Signal */
  &firstTest_B.WP03,                   /* 23: Signal */
  &firstTest_B.Clock,                  /* 24: Signal */
  &firstTest_B.Product,                /* 25: Signal */
  &firstTest_B.Step,                   /* 26: Signal */
  &firstTest_B.Output,                 /* 27: Signal */
  &firstTest_B.Sum,                    /* 28: Signal */
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
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
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
  0.0, 0.01
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (NULL), (NULL), -2, 0 },

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
  { rtBlockSignals, 29,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 0,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3800970841U,
    4248707552U,
    4045803712U,
    189385837U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  firstTest_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void firstTest_InitializeDataMapInfo(RT_MODEL_firstTest_T *const firstTest_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(firstTest_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(firstTest_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(firstTest_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(firstTest_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(firstTest_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(firstTest_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(firstTest_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(firstTest_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void firstTest_host_InitializeDataMapInfo(firstTest_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: firstTest_capi.c */
