/*
 * firstTest.c
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

#include "rt_logging_mmi.h"
#include "firstTest_capi.h"
#include "firstTest.h"
#include "firstTest_private.h"

/* Block signals (auto storage) */
B_firstTest_T firstTest_B;

/* Block states (auto storage) */
DW_firstTest_T firstTest_DW;

/* Real-time model */
RT_MODEL_firstTest_T firstTest_M_;
RT_MODEL_firstTest_T *const firstTest_M = &firstTest_M_;

/* Model output function */
static void firstTest_output(void)
{
  real_T currentTime;

  /* Step: '<S2>/Step' */
  currentTime = firstTest_M->Timing.t[0];
  if (currentTime < 5.0) {
    firstTest_B.Step = 0.0;
  } else {
    firstTest_B.Step = 0.01;
  }

  /* End of Step: '<S2>/Step' */

  /* Clock: '<S2>/Clock' */
  firstTest_B.Clock = firstTest_M->Timing.t[0];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Constant'
   */
  firstTest_B.Sum = firstTest_B.Clock - 5.0;

  /* Product: '<S2>/Product' */
  firstTest_B.Product = firstTest_B.Step * firstTest_B.Sum;

  /* Sum: '<S2>/Output' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  firstTest_B.Output = firstTest_B.Product + 0.0;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/pump2offset'
   */
  firstTest_B.Sum_b = firstTest_B.Output + 0.75;

  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[0];
    sfcnOutputs(rts, 1);
  }

  /* ok to acquire for <S4>/S-Function */
  firstTest_DW.SFunction_IWORK.AcquireOK = 1;

  /* Level2 S-Function Block: '<S1>/src' (adnipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }
}

/* Model update function */
static void firstTest_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++firstTest_M->Timing.clockTick0)) {
    ++firstTest_M->Timing.clockTickH0;
  }

  firstTest_M->Timing.t[0] = firstTest_M->Timing.clockTick0 *
    firstTest_M->Timing.stepSize0 + firstTest_M->Timing.clockTickH0 *
    firstTest_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++firstTest_M->Timing.clockTick1)) {
      ++firstTest_M->Timing.clockTickH1;
    }

    firstTest_M->Timing.t[1] = firstTest_M->Timing.clockTick1 *
      firstTest_M->Timing.stepSize1 + firstTest_M->Timing.clockTickH1 *
      firstTest_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void firstTest_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
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
        rl32eAddSignal(10, rl32eGetSignalNo("Sum"));
        rl32eSetScope(10, 4, 2000);
        rl32eSetScope(10, 5, 0);
        rl32eSetScope(10, 6, 1);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo("DA_meas/src/p9"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 9, 0);
        rl32eSetTargetScope(10, 1, 3.0);
        rl32eSetTargetScope(10, 11, -1.0);
        rl32eSetTargetScope(10, 10, 1.0);
        xpceScopeAcqOK(10, &firstTest_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* Level2 S-Function Block: '<S1>/src' (adnipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void firstTest_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/DA_sink' (danipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/src' (adnipcim) */
  {
    SimStruct *rts = firstTest_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  firstTest_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  firstTest_update();
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
  firstTest_initialize();
}

void MdlTerminate(void)
{
  firstTest_terminate();
}

/* Registration function */
RT_MODEL_firstTest_T *firstTest(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)firstTest_M, 0,
                sizeof(RT_MODEL_firstTest_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&firstTest_M->solverInfo,
                          &firstTest_M->Timing.simTimeStep);
    rtsiSetTPtr(&firstTest_M->solverInfo, &rtmGetTPtr(firstTest_M));
    rtsiSetStepSizePtr(&firstTest_M->solverInfo, &firstTest_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&firstTest_M->solverInfo, (&rtmGetErrorStatus
      (firstTest_M)));
    rtsiSetRTModelPtr(&firstTest_M->solverInfo, firstTest_M);
  }

  rtsiSetSimTimeStep(&firstTest_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&firstTest_M->solverInfo,"FixedStepDiscrete");
  firstTest_M->solverInfoPtr = (&firstTest_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = firstTest_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    firstTest_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    firstTest_M->Timing.sampleTimes = (&firstTest_M->Timing.sampleTimesArray[0]);
    firstTest_M->Timing.offsetTimes = (&firstTest_M->Timing.offsetTimesArray[0]);

    /* task periods */
    firstTest_M->Timing.sampleTimes[0] = (0.0);
    firstTest_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    firstTest_M->Timing.offsetTimes[0] = (0.0);
    firstTest_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(firstTest_M, &firstTest_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = firstTest_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    firstTest_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(firstTest_M, 100.0);
  firstTest_M->Timing.stepSize0 = 0.01;
  firstTest_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    firstTest_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(firstTest_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(firstTest_M->rtwLogInfo, (NULL));
    rtliSetLogT(firstTest_M->rtwLogInfo, "tout");
    rtliSetLogX(firstTest_M->rtwLogInfo, "");
    rtliSetLogXFinal(firstTest_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(firstTest_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(firstTest_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(firstTest_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(firstTest_M->rtwLogInfo, 1);
    rtliSetLogY(firstTest_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(firstTest_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(firstTest_M->rtwLogInfo, (NULL));
  }

  firstTest_M->solverInfoPtr = (&firstTest_M->solverInfo);
  firstTest_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&firstTest_M->solverInfo, 0.01);
  rtsiSetSolverMode(&firstTest_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  firstTest_M->blockIO = ((void *) &firstTest_B);
  (void) memset(((void *) &firstTest_B), 0,
                sizeof(B_firstTest_T));

  /* states (dwork) */
  firstTest_M->dwork = ((void *) &firstTest_DW);
  (void) memset((void *)&firstTest_DW, 0,
                sizeof(DW_firstTest_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  firstTest_InitializeDataMapInfo(firstTest_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &firstTest_M->NonInlinedSFcns.sfcnInfo;
    firstTest_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(firstTest_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &firstTest_M->Sizes.numSampTimes);
    firstTest_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(firstTest_M)[0]);
    firstTest_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(firstTest_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,firstTest_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(firstTest_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(firstTest_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(firstTest_M));
    rtssSetStepSizePtr(sfcnInfo, &firstTest_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(firstTest_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &firstTest_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &firstTest_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &firstTest_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &firstTest_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &firstTest_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &firstTest_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &firstTest_M->solverInfoPtr);
  }

  firstTest_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&firstTest_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    firstTest_M->childSfunctions =
      (&firstTest_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    firstTest_M->childSfunctions[0] =
      (&firstTest_M->NonInlinedSFcns.childSFunctions[0]);
    firstTest_M->childSfunctions[1] =
      (&firstTest_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: firstTest/<Root>/DA_sink (danipcim) */
    {
      SimStruct *rts = firstTest_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = firstTest_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = firstTest_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = firstTest_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &firstTest_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, firstTest_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &firstTest_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &firstTest_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &firstTest_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &firstTest_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &firstTest_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &firstTest_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &firstTest_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = (real_T*)&firstTest_ConstB.CV01_input;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &firstTest_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &firstTest_ConstP.pooled1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &firstTest_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &firstTest_B.Sum_b;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &firstTest_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &firstTest_ConstP.pooled1;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DA_sink");
      ssSetPath(rts, "firstTest/DA_sink");
      ssSetRTModel(rts,firstTest_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &firstTest_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)firstTest_ConstP.DA_sink_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)firstTest_ConstP.pooled3);
        ssSetSFcnParam(rts, 2, (mxArray*)firstTest_ConstP.DA_sink_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)firstTest_ConstP.pooled3);
        ssSetSFcnParam(rts, 4, (mxArray*)firstTest_ConstP.pooled5);
        ssSetSFcnParam(rts, 5, (mxArray*)firstTest_ConstP.pooled7);
        ssSetSFcnParam(rts, 6, (mxArray*)firstTest_ConstP.pooled9);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &firstTest_DW.DA_sink_RWORK[0]);
      ssSetIWork(rts, (int_T *) &firstTest_DW.DA_sink_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &firstTest_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &firstTest_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &firstTest_DW.DA_sink_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &firstTest_DW.DA_sink_IWORK[0]);
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

    /* Level2 S-Function Block: firstTest/<S1>/src (adnipcim) */
    {
      SimStruct *rts = firstTest_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = firstTest_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = firstTest_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = firstTest_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &firstTest_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, firstTest_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &firstTest_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &firstTest_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &firstTest_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &firstTest_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &firstTest_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &firstTest_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 22);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &firstTest_B.CV01));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &firstTest_B.DPT01));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &firstTest_B.LMGC1));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &firstTest_B.LMGP1));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &firstTest_B.LMGV1));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &firstTest_B.MFM01));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &firstTest_B.PT01));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &firstTest_B.WP01));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *) &firstTest_B.DPT02));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *) &firstTest_B.LMGC2));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *) &firstTest_B.LMGP2));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *) &firstTest_B.LMGV2));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *) &firstTest_B.MFM02));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *) &firstTest_B.PT02));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((real_T *) &firstTest_B.WP02));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((real_T *) &firstTest_B.DPT03));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 1);
          ssSetOutputPortSignal(rts, 16, ((real_T *) &firstTest_B.LMGC3));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 1);
          ssSetOutputPortSignal(rts, 17, ((real_T *) &firstTest_B.LMGP3));
        }

        /* port 18 */
        {
          _ssSetOutputPortNumDimensions(rts, 18, 1);
          ssSetOutputPortWidth(rts, 18, 1);
          ssSetOutputPortSignal(rts, 18, ((real_T *) &firstTest_B.LMGV3));
        }

        /* port 19 */
        {
          _ssSetOutputPortNumDimensions(rts, 19, 1);
          ssSetOutputPortWidth(rts, 19, 1);
          ssSetOutputPortSignal(rts, 19, ((real_T *) &firstTest_B.MFM03));
        }

        /* port 20 */
        {
          _ssSetOutputPortNumDimensions(rts, 20, 1);
          ssSetOutputPortWidth(rts, 20, 1);
          ssSetOutputPortSignal(rts, 20, ((real_T *) &firstTest_B.PT03));
        }

        /* port 21 */
        {
          _ssSetOutputPortNumDimensions(rts, 21, 1);
          ssSetOutputPortWidth(rts, 21, 1);
          ssSetOutputPortSignal(rts, 21, ((real_T *) &firstTest_B.WP03));
        }
      }

      /* path info */
      ssSetModelName(rts, "src");
      ssSetPath(rts, "firstTest/DA_meas/src");
      ssSetRTModel(rts,firstTest_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &firstTest_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)firstTest_ConstP.src_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)firstTest_ConstP.src_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)firstTest_ConstP.src_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)firstTest_ConstP.src_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)firstTest_ConstP.pooled5);
        ssSetSFcnParam(rts, 5, (mxArray*)firstTest_ConstP.pooled7);
        ssSetSFcnParam(rts, 6, (mxArray*)firstTest_ConstP.pooled9);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &firstTest_DW.src_IWORK[0]);
      ssSetPWork(rts, (void **) &firstTest_DW.src_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &firstTest_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &firstTest_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 41);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &firstTest_DW.src_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &firstTest_DW.src_PWORK);
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
  firstTest_M->Sizes.numContStates = (0);/* Number of continuous states */
  firstTest_M->Sizes.numY = (0);       /* Number of model outputs */
  firstTest_M->Sizes.numU = (0);       /* Number of model inputs */
  firstTest_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  firstTest_M->Sizes.numSampTimes = (2);/* Number of sample times */
  firstTest_M->Sizes.numBlocks = (16); /* Number of blocks */
  firstTest_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  return firstTest_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
