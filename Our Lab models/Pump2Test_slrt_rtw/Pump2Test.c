/*
 * Pump2Test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pump2Test".
 *
 * Model version              : 1.379
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Mar 20 15:41:21 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "Pump2Test_capi.h"
#include "Pump2Test.h"
#include "Pump2Test_private.h"

/* Block signals (auto storage) */
B_Pump2Test_T Pump2Test_B;

/* Block states (auto storage) */
DW_Pump2Test_T Pump2Test_DW;

/* Real-time model */
RT_MODEL_Pump2Test_T Pump2Test_M_;
RT_MODEL_Pump2Test_T *const Pump2Test_M = &Pump2Test_M_;

/* Model output function */
static void Pump2Test_output(void)
{
  real_T *lastU;
  real_T lastTime;

  /* ok to acquire for <S1>/S-Function */
  Pump2Test_DW.SFunction_IWORK.AcquireOK = 1;

  /* Clock: '<S6>/Clock' */
  Pump2Test_B.Clock = Pump2Test_M->Timing.t[0];

  /* Lookup: '<S6>/Look-Up Table' */
  Pump2Test_B.LookUpTable = rt_Lookup(Pump2Test_ConstP.LookUpTable_XData, 24,
    Pump2Test_B.Clock, Pump2Test_ConstP.LookUpTable_YData);

  /* Gain: '<Root>/%2WP02' */
  Pump2Test_B.uWP02 = 0.1 * Pump2Test_B.LookUpTable;

  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[0];
    sfcnOutputs(rts, 1);
  }

  /* ok to acquire for <S5>/S-Function */
  Pump2Test_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* Level2 S-Function Block: '<S2>/src' (adnipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }

  /* Derivative: '<S6>/Derivative' */
  if ((Pump2Test_DW.TimeStampA >= Pump2Test_M->Timing.t[0]) &&
      (Pump2Test_DW.TimeStampB >= Pump2Test_M->Timing.t[0])) {
    Pump2Test_B.Derivative = 0.0;
  } else {
    lastTime = Pump2Test_DW.TimeStampA;
    lastU = &Pump2Test_DW.LastUAtTimeA;
    if (Pump2Test_DW.TimeStampA < Pump2Test_DW.TimeStampB) {
      if (Pump2Test_DW.TimeStampB < Pump2Test_M->Timing.t[0]) {
        lastTime = Pump2Test_DW.TimeStampB;
        lastU = &Pump2Test_DW.LastUAtTimeB;
      }
    } else {
      if (Pump2Test_DW.TimeStampA >= Pump2Test_M->Timing.t[0]) {
        lastTime = Pump2Test_DW.TimeStampB;
        lastU = &Pump2Test_DW.LastUAtTimeB;
      }
    }

    lastTime = Pump2Test_M->Timing.t[0] - lastTime;
    Pump2Test_B.Derivative = (Pump2Test_B.LookUpTable - *lastU) / lastTime;
  }

  /* End of Derivative: '<S6>/Derivative' */
}

/* Model update function */
static void Pump2Test_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S6>/Derivative' */
  if (Pump2Test_DW.TimeStampA == (rtInf)) {
    Pump2Test_DW.TimeStampA = Pump2Test_M->Timing.t[0];
    lastU = &Pump2Test_DW.LastUAtTimeA;
  } else if (Pump2Test_DW.TimeStampB == (rtInf)) {
    Pump2Test_DW.TimeStampB = Pump2Test_M->Timing.t[0];
    lastU = &Pump2Test_DW.LastUAtTimeB;
  } else if (Pump2Test_DW.TimeStampA < Pump2Test_DW.TimeStampB) {
    Pump2Test_DW.TimeStampA = Pump2Test_M->Timing.t[0];
    lastU = &Pump2Test_DW.LastUAtTimeA;
  } else {
    Pump2Test_DW.TimeStampB = Pump2Test_M->Timing.t[0];
    lastU = &Pump2Test_DW.LastUAtTimeB;
  }

  *lastU = Pump2Test_B.LookUpTable;

  /* End of Update for Derivative: '<S6>/Derivative' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Pump2Test_M->Timing.clockTick0)) {
    ++Pump2Test_M->Timing.clockTickH0;
  }

  Pump2Test_M->Timing.t[0] = Pump2Test_M->Timing.clockTick0 *
    Pump2Test_M->Timing.stepSize0 + Pump2Test_M->Timing.clockTickH0 *
    Pump2Test_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Pump2Test_M->Timing.clockTick1)) {
      ++Pump2Test_M->Timing.clockTickH1;
    }

    Pump2Test_M->Timing.t[1] = Pump2Test_M->Timing.clockTick1 *
      Pump2Test_M->Timing.stepSize1 + Pump2Test_M->Timing.clockTickH1 *
      Pump2Test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void Pump2Test_initialize(void)
{
  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("DA_meas/src/p9"));
        rl32eAddSignal(1, rl32eGetSignalNo("DA_meas/src/p11"));
        rl32eAddSignal(1, rl32eGetSignalNo("DA_meas/src/p13"));
        rl32eAddSignal(1, rl32eGetSignalNo("DA_meas/src/p15"));
        rl32eAddSignal(1, rl32eGetSignalNo("%2WP02"));
        rl32eSetScope(1, 4, 2000);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "E:\\P2.dat", 1, 512, 0, 536870912);
        rl32eSetScope (1, 10, 1);
        rl32eSetScope(1, 3, rl32eGetSignalNo("DA_meas/src/p9"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1, &Pump2Test_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(10)) == 0) {
      if ((i = rl32eDefScope(10,2)) != 0) {
        printf("Error creating scope 10\n");
      } else {
        rl32eAddSignal(10, rl32eGetSignalNo("DA_meas/src/p9"));
        rl32eAddSignal(10, rl32eGetSignalNo("DA_meas/src/p11"));
        rl32eAddSignal(10, rl32eGetSignalNo("DA_meas/src/p13"));
        rl32eAddSignal(10, rl32eGetSignalNo("DA_meas/src/p15"));
        rl32eAddSignal(10, rl32eGetSignalNo("%2WP02"));
        rl32eSetScope(10, 4, 10500);
        rl32eSetScope(10, 5, 0);
        rl32eSetScope(10, 6, 1);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo("DA_meas/src/p9"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 9, 0);
        rl32eSetTargetScope(10, 1, 3.0);
        rl32eSetTargetScope(10, 11, -1.0);
        rl32eSetTargetScope(10, 10, 11.0);
        xpceScopeAcqOK(10, &Pump2Test_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* Level2 S-Function Block: '<S2>/src' (adnipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  Pump2Test_DW.TimeStampA = (rtInf);
  Pump2Test_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
static void Pump2Test_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/src' (adnipcim) */
  {
    SimStruct *rts = Pump2Test_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Pump2Test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pump2Test_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Pump2Test_initialize();
}

void MdlTerminate(void)
{
  Pump2Test_terminate();
}

/* Registration function */
RT_MODEL_Pump2Test_T *Pump2Test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Pump2Test_M, 0,
                sizeof(RT_MODEL_Pump2Test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pump2Test_M->solverInfo,
                          &Pump2Test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pump2Test_M->solverInfo, &rtmGetTPtr(Pump2Test_M));
    rtsiSetStepSizePtr(&Pump2Test_M->solverInfo, &Pump2Test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Pump2Test_M->solverInfo, (&rtmGetErrorStatus
      (Pump2Test_M)));
    rtsiSetRTModelPtr(&Pump2Test_M->solverInfo, Pump2Test_M);
  }

  rtsiSetSimTimeStep(&Pump2Test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Pump2Test_M->solverInfo,"FixedStepDiscrete");
  Pump2Test_M->solverInfoPtr = (&Pump2Test_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pump2Test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Pump2Test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pump2Test_M->Timing.sampleTimes = (&Pump2Test_M->Timing.sampleTimesArray[0]);
    Pump2Test_M->Timing.offsetTimes = (&Pump2Test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pump2Test_M->Timing.sampleTimes[0] = (0.0);
    Pump2Test_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Pump2Test_M->Timing.offsetTimes[0] = (0.0);
    Pump2Test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Pump2Test_M, &Pump2Test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pump2Test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Pump2Test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pump2Test_M, 105.0);
  Pump2Test_M->Timing.stepSize0 = 0.01;
  Pump2Test_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Pump2Test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Pump2Test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Pump2Test_M->rtwLogInfo, (NULL));
    rtliSetLogT(Pump2Test_M->rtwLogInfo, "tout");
    rtliSetLogX(Pump2Test_M->rtwLogInfo, "");
    rtliSetLogXFinal(Pump2Test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Pump2Test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Pump2Test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Pump2Test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Pump2Test_M->rtwLogInfo, 1);
    rtliSetLogY(Pump2Test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Pump2Test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Pump2Test_M->rtwLogInfo, (NULL));
  }

  Pump2Test_M->solverInfoPtr = (&Pump2Test_M->solverInfo);
  Pump2Test_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Pump2Test_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Pump2Test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Pump2Test_M->blockIO = ((void *) &Pump2Test_B);
  (void) memset(((void *) &Pump2Test_B), 0,
                sizeof(B_Pump2Test_T));

  /* states (dwork) */
  Pump2Test_M->dwork = ((void *) &Pump2Test_DW);
  (void) memset((void *)&Pump2Test_DW, 0,
                sizeof(DW_Pump2Test_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  Pump2Test_InitializeDataMapInfo(Pump2Test_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Pump2Test_M->NonInlinedSFcns.sfcnInfo;
    Pump2Test_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Pump2Test_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Pump2Test_M->Sizes.numSampTimes);
    Pump2Test_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Pump2Test_M)[0]);
    Pump2Test_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(Pump2Test_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Pump2Test_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Pump2Test_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Pump2Test_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Pump2Test_M));
    rtssSetStepSizePtr(sfcnInfo, &Pump2Test_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Pump2Test_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &Pump2Test_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Pump2Test_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Pump2Test_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Pump2Test_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Pump2Test_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Pump2Test_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Pump2Test_M->solverInfoPtr);
  }

  Pump2Test_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&Pump2Test_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    Pump2Test_M->childSfunctions =
      (&Pump2Test_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    Pump2Test_M->childSfunctions[0] =
      (&Pump2Test_M->NonInlinedSFcns.childSFunctions[0]);
    Pump2Test_M->childSfunctions[1] =
      (&Pump2Test_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: Pump2Test/<Root>/DA_sink (danipcim) */
    {
      SimStruct *rts = Pump2Test_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Pump2Test_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Pump2Test_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Pump2Test_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pump2Test_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Pump2Test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pump2Test_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pump2Test_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Pump2Test_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pump2Test_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Pump2Test_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &Pump2Test_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pump2Test_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = (real_T*)&Pump2Test_ConstB.CV01_input;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pump2Test_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &Pump2Test_ConstP.pooled2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pump2Test_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &Pump2Test_B.uWP02;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Pump2Test_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &Pump2Test_ConstP.pooled2;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DA_sink");
      ssSetPath(rts, "Pump2Test/DA_sink");
      ssSetRTModel(rts,Pump2Test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pump2Test_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pump2Test_ConstP.DA_sink_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Pump2Test_ConstP.pooled3);
        ssSetSFcnParam(rts, 2, (mxArray*)Pump2Test_ConstP.DA_sink_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Pump2Test_ConstP.pooled3);
        ssSetSFcnParam(rts, 4, (mxArray*)Pump2Test_ConstP.pooled5);
        ssSetSFcnParam(rts, 5, (mxArray*)Pump2Test_ConstP.pooled7);
        ssSetSFcnParam(rts, 6, (mxArray*)Pump2Test_ConstP.pooled9);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &Pump2Test_DW.DA_sink_RWORK[0]);
      ssSetIWork(rts, (int_T *) &Pump2Test_DW.DA_sink_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Pump2Test_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Pump2Test_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Pump2Test_DW.DA_sink_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Pump2Test_DW.DA_sink_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: Pump2Test/<S2>/src (adnipcim) */
    {
      SimStruct *rts = Pump2Test_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Pump2Test_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Pump2Test_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Pump2Test_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Pump2Test_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Pump2Test_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Pump2Test_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Pump2Test_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Pump2Test_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Pump2Test_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Pump2Test_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Pump2Test_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 22);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Pump2Test_B.CV01));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &Pump2Test_B.DPT01));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &Pump2Test_B.LMGC1));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &Pump2Test_B.LMGP1));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &Pump2Test_B.LMGV1));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &Pump2Test_B.MFM01));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &Pump2Test_B.PT01));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &Pump2Test_B.WP01));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *) &Pump2Test_B.DPT02));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *) &Pump2Test_B.LMGC2));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *) &Pump2Test_B.LMGP2));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *) &Pump2Test_B.LMGV2));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *) &Pump2Test_B.MFM02));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *) &Pump2Test_B.PT02));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((real_T *) &Pump2Test_B.WP02));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((real_T *) &Pump2Test_B.DPT03));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 1);
          ssSetOutputPortSignal(rts, 16, ((real_T *) &Pump2Test_B.LMGC3));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 1);
          ssSetOutputPortSignal(rts, 17, ((real_T *) &Pump2Test_B.LMGP3));
        }

        /* port 18 */
        {
          _ssSetOutputPortNumDimensions(rts, 18, 1);
          ssSetOutputPortWidth(rts, 18, 1);
          ssSetOutputPortSignal(rts, 18, ((real_T *) &Pump2Test_B.LMGV3));
        }

        /* port 19 */
        {
          _ssSetOutputPortNumDimensions(rts, 19, 1);
          ssSetOutputPortWidth(rts, 19, 1);
          ssSetOutputPortSignal(rts, 19, ((real_T *) &Pump2Test_B.MFM03));
        }

        /* port 20 */
        {
          _ssSetOutputPortNumDimensions(rts, 20, 1);
          ssSetOutputPortWidth(rts, 20, 1);
          ssSetOutputPortSignal(rts, 20, ((real_T *) &Pump2Test_B.PT03));
        }

        /* port 21 */
        {
          _ssSetOutputPortNumDimensions(rts, 21, 1);
          ssSetOutputPortWidth(rts, 21, 1);
          ssSetOutputPortSignal(rts, 21, ((real_T *) &Pump2Test_B.WP03));
        }
      }

      /* path info */
      ssSetModelName(rts, "src");
      ssSetPath(rts, "Pump2Test/DA_meas/src");
      ssSetRTModel(rts,Pump2Test_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Pump2Test_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Pump2Test_ConstP.src_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Pump2Test_ConstP.src_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Pump2Test_ConstP.src_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Pump2Test_ConstP.src_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)Pump2Test_ConstP.pooled5);
        ssSetSFcnParam(rts, 5, (mxArray*)Pump2Test_ConstP.pooled7);
        ssSetSFcnParam(rts, 6, (mxArray*)Pump2Test_ConstP.pooled9);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &Pump2Test_DW.src_IWORK[0]);
      ssSetPWork(rts, (void **) &Pump2Test_DW.src_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Pump2Test_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Pump2Test_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 41);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &Pump2Test_DW.src_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &Pump2Test_DW.src_PWORK);
      }

      /* registration */
      adnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 0);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 0);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 0);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 0);
      _ssSetOutputPortConnected(rts, 14, 1);
      _ssSetOutputPortConnected(rts, 15, 1);
      _ssSetOutputPortConnected(rts, 16, 0);
      _ssSetOutputPortConnected(rts, 17, 1);
      _ssSetOutputPortConnected(rts, 18, 0);
      _ssSetOutputPortConnected(rts, 19, 1);
      _ssSetOutputPortConnected(rts, 20, 0);
      _ssSetOutputPortConnected(rts, 21, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 13, 0);
      _ssSetOutputPortBeingMerged(rts, 14, 0);
      _ssSetOutputPortBeingMerged(rts, 15, 0);
      _ssSetOutputPortBeingMerged(rts, 16, 0);
      _ssSetOutputPortBeingMerged(rts, 17, 0);
      _ssSetOutputPortBeingMerged(rts, 18, 0);
      _ssSetOutputPortBeingMerged(rts, 19, 0);
      _ssSetOutputPortBeingMerged(rts, 20, 0);
      _ssSetOutputPortBeingMerged(rts, 21, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  Pump2Test_M->Sizes.numContStates = (0);/* Number of continuous states */
  Pump2Test_M->Sizes.numY = (0);       /* Number of model outputs */
  Pump2Test_M->Sizes.numU = (0);       /* Number of model inputs */
  Pump2Test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Pump2Test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Pump2Test_M->Sizes.numBlocks = (13); /* Number of blocks */
  Pump2Test_M->Sizes.numBlockIO = (26);/* Number of block outputs */
  return Pump2Test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
