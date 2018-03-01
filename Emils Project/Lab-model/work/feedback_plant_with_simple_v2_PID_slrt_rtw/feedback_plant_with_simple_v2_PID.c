/*
 * feedback_plant_with_simple_v2_PID.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "feedback_plant_with_simple_v2_PID".
 *
 * Model version              : 1.362
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Aug 25 14:37:08 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "feedback_plant_with_simple_v2_PID_capi.h"
#include "feedback_plant_with_simple_v2_PID.h"
#include "feedback_plant_with_simple_v2_PID_private.h"

/* Block signals (auto storage) */
B_feedback_plant_with_simple_v2_PID_T feedback_plant_with_simple_v2_PID_B;

/* Continuous states */
X_feedback_plant_with_simple_v2_PID_T feedback_plant_with_simple_v2_PID_X;

/* Block states (auto storage) */
DW_feedback_plant_with_simple_v2_PID_T feedback_plant_with_simple_v2_PID_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_feedback_plant_with_simple_v2_PID_T feedback_plant_with_simple_v2_PID_Y;

/* Real-time model */
RT_MODEL_feedback_plant_with_simple_v2_PID_T
  feedback_plant_with_simple_v2_PID_M_;
RT_MODEL_feedback_plant_with_simple_v2_PID_T *const
  feedback_plant_with_simple_v2_PID_M = &feedback_plant_with_simple_v2_PID_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  feedback_plant_with_simple_v2_PID_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  feedback_plant_with_simple_v2_PID_output();
  feedback_plant_with_simple_v2_PID_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  feedback_plant_with_simple_v2_PID_output();
  feedback_plant_with_simple_v2_PID_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void feedback_plant_with_simple_v2_PID_output(void)
{
  real_T y[22];
  real_T t6;
  real_T t12;
  boolean_T b;
  boolean_T c = false;
  uint8_T test[124];
  boolean_T x[124];
  int32_T idx;
  int32_T b_ii;
  static const char_T f[17] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'H', 'I', 'G', 'H', ' ' };

  char_T test_0[124];
  int8_T matches[124];
  int32_T j;
  static const char_T e[15] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'L', 'O', 'W' };

  int32_T i;
  char_T e_0[4];
  char_T d[4];
  int32_T loop_ub;
  int8_T k_data[126];
  char_T Error_data[140];
  int8_T ii_data[124];
  int8_T k_data_0[126];
  char_T Error_data_0[138];
  char_T test_data[123];
  char_T test_data_0[123];
  real_T y_idx_2;
  real_T y_idx_3;
  int32_T tmp;
  int8_T tmp_0;
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* set solver stop time */
    if (!(feedback_plant_with_simple_v2_PID_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                            ((feedback_plant_with_simple_v2_PID_M->Timing.clockTickH0
        + 1) * feedback_plant_with_simple_v2_PID_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                            ((feedback_plant_with_simple_v2_PID_M->Timing.clockTick0
        + 1) * feedback_plant_with_simple_v2_PID_M->Timing.stepSize0 +
        feedback_plant_with_simple_v2_PID_M->Timing.clockTickH0 *
        feedback_plant_with_simple_v2_PID_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    feedback_plant_with_simple_v2_PID_M->Timing.t[0] = rtsiGetT
      (&feedback_plant_with_simple_v2_PID_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* Level2 S-Function Block: '<S13>/src' (adnipcim) */
    {
      SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S13>/transform'
     */
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[0] =
      feedback_plant_with_simple_v2_PID_B.src_o1;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[1] =
      feedback_plant_with_simple_v2_PID_B.src_o2;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[2] =
      feedback_plant_with_simple_v2_PID_B.src_o3;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[3] =
      feedback_plant_with_simple_v2_PID_B.src_o4;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[4] =
      feedback_plant_with_simple_v2_PID_B.src_o5;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[5] =
      feedback_plant_with_simple_v2_PID_B.src_o6;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[6] =
      feedback_plant_with_simple_v2_PID_B.src_o7;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[7] =
      feedback_plant_with_simple_v2_PID_B.src_o8;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[8] =
      feedback_plant_with_simple_v2_PID_B.src_o9;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[9] =
      feedback_plant_with_simple_v2_PID_B.src_o10;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[10] =
      feedback_plant_with_simple_v2_PID_B.src_o11;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[11] =
      feedback_plant_with_simple_v2_PID_B.src_o12;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[12] =
      feedback_plant_with_simple_v2_PID_B.src_o13;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[13] =
      feedback_plant_with_simple_v2_PID_B.src_o14;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[14] =
      feedback_plant_with_simple_v2_PID_B.src_o15;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[15] =
      feedback_plant_with_simple_v2_PID_B.src_o16;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[16] =
      feedback_plant_with_simple_v2_PID_B.src_o17;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[17] =
      feedback_plant_with_simple_v2_PID_B.src_o18;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[18] =
      feedback_plant_with_simple_v2_PID_B.src_o19;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[19] =
      feedback_plant_with_simple_v2_PID_B.src_o20;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[20] =
      feedback_plant_with_simple_v2_PID_B.src_o21;
    feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[21] =
      feedback_plant_with_simple_v2_PID_B.src_o22;

    /* MATLAB Function: '<S13>/transform' */
    /* MATLAB Function 'analogdigital/transform': '<S26>:1' */
    /* '<S26>:1:2' */
    for (i = 0; i < 22; i++) {
      y[i] =
        feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctionI[i] *
        feedback_plant_with_simple_v2_PID_ConstP.transform_gain[i] -
        feedback_plant_with_simple_v2_PID_ConstP.transform_offset[i];
    }

    /* '<S26>:1:3' */
    feedback_plant_with_simple_v2_PID_B.CV01 = y[0];

    /* '<S26>:1:4' */
    feedback_plant_with_simple_v2_PID_B.DPT01 = y[1];

    /* '<S26>:1:5' */
    feedback_plant_with_simple_v2_PID_B.LMGC1 = y[2];

    /* '<S26>:1:6' */
    feedback_plant_with_simple_v2_PID_B.LMGP1 = y[3];

    /* '<S26>:1:7' */
    feedback_plant_with_simple_v2_PID_B.LMGV1 = y[4];

    /* '<S26>:1:8' */
    feedback_plant_with_simple_v2_PID_B.MFM01 = y[5];

    /* '<S26>:1:9' */
    feedback_plant_with_simple_v2_PID_B.PT01 = y[6];

    /* '<S26>:1:10' */
    feedback_plant_with_simple_v2_PID_B.WP01 = y[7];

    /* '<S26>:1:11' */
    feedback_plant_with_simple_v2_PID_B.DPT02 = y[8];

    /* '<S26>:1:12' */
    feedback_plant_with_simple_v2_PID_B.LMGC2 = y[9];

    /* '<S26>:1:13' */
    feedback_plant_with_simple_v2_PID_B.LMGP2 = y[10];

    /* '<S26>:1:14' */
    feedback_plant_with_simple_v2_PID_B.LMGV2 = y[11];

    /* '<S26>:1:15' */
    feedback_plant_with_simple_v2_PID_B.MFM02 = y[12];

    /* '<S26>:1:16' */
    feedback_plant_with_simple_v2_PID_B.PT02 = y[13];

    /* '<S26>:1:17' */
    feedback_plant_with_simple_v2_PID_B.WP02 = y[14];

    /* '<S26>:1:18' */
    feedback_plant_with_simple_v2_PID_B.DPT03 = y[15];

    /* '<S26>:1:19' */
    feedback_plant_with_simple_v2_PID_B.LMGC3 = y[16];

    /* '<S26>:1:20' */
    feedback_plant_with_simple_v2_PID_B.LMGP3 = y[17];

    /* '<S26>:1:21' */
    feedback_plant_with_simple_v2_PID_B.LMGV3 = y[18];

    /* '<S26>:1:22' */
    feedback_plant_with_simple_v2_PID_B.MFM03 = y[19];

    /* '<S26>:1:23' */
    feedback_plant_with_simple_v2_PID_B.PT03 = y[20];

    /* '<S26>:1:24' */
    feedback_plant_with_simple_v2_PID_B.WP03 = y[21];

    /* Outport: '<Root>/sens' */
    feedback_plant_with_simple_v2_PID_Y.sens[0] =
      feedback_plant_with_simple_v2_PID_B.CV01;
    feedback_plant_with_simple_v2_PID_Y.sens[1] =
      feedback_plant_with_simple_v2_PID_B.DPT01;
    feedback_plant_with_simple_v2_PID_Y.sens[2] =
      feedback_plant_with_simple_v2_PID_B.LMGC1;
    feedback_plant_with_simple_v2_PID_Y.sens[3] =
      feedback_plant_with_simple_v2_PID_B.LMGP1;
    feedback_plant_with_simple_v2_PID_Y.sens[4] =
      feedback_plant_with_simple_v2_PID_B.LMGV1;
    feedback_plant_with_simple_v2_PID_Y.sens[5] =
      feedback_plant_with_simple_v2_PID_B.MFM01;
    feedback_plant_with_simple_v2_PID_Y.sens[6] =
      feedback_plant_with_simple_v2_PID_B.PT01;
    feedback_plant_with_simple_v2_PID_Y.sens[7] =
      feedback_plant_with_simple_v2_PID_B.WP01;
    feedback_plant_with_simple_v2_PID_Y.sens[8] =
      feedback_plant_with_simple_v2_PID_B.DPT02;
    feedback_plant_with_simple_v2_PID_Y.sens[9] =
      feedback_plant_with_simple_v2_PID_B.LMGC2;
    feedback_plant_with_simple_v2_PID_Y.sens[10] =
      feedback_plant_with_simple_v2_PID_B.LMGP2;
    feedback_plant_with_simple_v2_PID_Y.sens[11] =
      feedback_plant_with_simple_v2_PID_B.LMGV2;
    feedback_plant_with_simple_v2_PID_Y.sens[12] =
      feedback_plant_with_simple_v2_PID_B.MFM02;
    feedback_plant_with_simple_v2_PID_Y.sens[13] =
      feedback_plant_with_simple_v2_PID_B.PT02;
    feedback_plant_with_simple_v2_PID_Y.sens[14] =
      feedback_plant_with_simple_v2_PID_B.WP02;
    feedback_plant_with_simple_v2_PID_Y.sens[15] =
      feedback_plant_with_simple_v2_PID_B.DPT03;
    feedback_plant_with_simple_v2_PID_Y.sens[16] =
      feedback_plant_with_simple_v2_PID_B.LMGC3;
    feedback_plant_with_simple_v2_PID_Y.sens[17] =
      feedback_plant_with_simple_v2_PID_B.LMGP3;
    feedback_plant_with_simple_v2_PID_Y.sens[18] =
      feedback_plant_with_simple_v2_PID_B.LMGV3;
    feedback_plant_with_simple_v2_PID_Y.sens[19] =
      feedback_plant_with_simple_v2_PID_B.MFM03;
    feedback_plant_with_simple_v2_PID_Y.sens[20] =
      feedback_plant_with_simple_v2_PID_B.PT03;
    feedback_plant_with_simple_v2_PID_Y.sens[21] =
      feedback_plant_with_simple_v2_PID_B.WP03;
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T t = feedback_plant_with_simple_v2_PID_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_with_simple_v2_PID_B.FromWorkspace1 = 0.0;
    } else if (t >= pTimeValues[184]) {
      feedback_plant_with_simple_v2_PID_B.FromWorkspace1 = pDataValues[184];
    } else {
      int_T currTimeIndex =
        feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_with_simple_v2_PID_B.FromWorkspace1 =
        pDataValues[currTimeIndex];
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_IWORK.PrevIndex =
        currTimeIndex;
    }
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T t = feedback_plant_with_simple_v2_PID_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_with_simple_v2_PID_B.FromWorkspace = 0.0;
    } else if (t >= pTimeValues[184]) {
      feedback_plant_with_simple_v2_PID_B.FromWorkspace = pDataValues[184];
    } else {
      int_T currTimeIndex =
        feedback_plant_with_simple_v2_PID_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_with_simple_v2_PID_B.FromWorkspace =
        pDataValues[currTimeIndex];
      feedback_plant_with_simple_v2_PID_DW.FromWorkspace_IWORK.PrevIndex =
        currTimeIndex;
    }
  }

  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* ok to acquire for <S3>/S-Function */
    feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S4>/S-Function */
    feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l.AcquireOK = 1;
  }

  /* ok to acquire for <S5>/S-Function */
  feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* ok to acquire for <S6>/S-Function */
  feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* ok to acquire for <S7>/S-Function */
  feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_n.AcquireOK = 1;
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* ok to acquire for <S8>/S-Function */
    feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_g.AcquireOK = 1;

    /* ok to acquire for <S9>/S-Function */
    feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l4.AcquireOK = 1;
  }

  /* ok to acquire for <S10>/S-Function */
  feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l0.AcquireOK = 1;
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* Sum: '<Root>/Subtract1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    feedback_plant_with_simple_v2_PID_B.Subtract1 =
      feedback_plant_with_simple_v2_PID_B.PT02 - 1.0;

    /* Gain: '<Root>/Gain' */
    feedback_plant_with_simple_v2_PID_B.Gain = 10.0 *
      feedback_plant_with_simple_v2_PID_B.Subtract1;
  }

  /* Sum: '<S11>/Sum' */
  feedback_plant_with_simple_v2_PID_B.PID_Error =
    feedback_plant_with_simple_v2_PID_B.FromWorkspace -
    feedback_plant_with_simple_v2_PID_B.Gain;

  /* Gain: '<S18>/Proportional Gain' */
  feedback_plant_with_simple_v2_PID_B.ProportionalGain = 0.03 *
    feedback_plant_with_simple_v2_PID_B.PID_Error;

  /* Integrator: '<S18>/Integrator' */
  feedback_plant_with_simple_v2_PID_B.Integrator =
    feedback_plant_with_simple_v2_PID_X.Integrator_CSTATE;

  /* Sum: '<S18>/Sum' */
  feedback_plant_with_simple_v2_PID_B.Sum =
    feedback_plant_with_simple_v2_PID_B.ProportionalGain +
    feedback_plant_with_simple_v2_PID_B.Integrator;

  /* Saturate: '<S18>/Saturate' */
  t6 = feedback_plant_with_simple_v2_PID_B.Sum;
  t12 = 0.0;
  y_idx_2 = 1.0;
  if (t6 > y_idx_2) {
    feedback_plant_with_simple_v2_PID_B.Saturate = y_idx_2;
  } else if (t6 < t12) {
    feedback_plant_with_simple_v2_PID_B.Saturate = t12;
  } else {
    feedback_plant_with_simple_v2_PID_B.Saturate = t6;
  }

  /* End of Saturate: '<S18>/Saturate' */
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    /* '<S1>:1:3' */
    feedback_plant_with_simple_v2_PID_B.Q_tot =
      ((feedback_plant_with_simple_v2_PID_B.MFM01 +
        feedback_plant_with_simple_v2_PID_B.MFM02) +
       feedback_plant_with_simple_v2_PID_B.MFM03) * 60.0 * 60.0 / 1000.0;
  }

  /* MATLAB Function: '<S11>/valve_CV_esti_Test' */
  /* MATLAB Function 'Subsystem/valve_CV_esti_Test': '<S23>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:28 */
  /* '<S23>:1:7' */
  feedback_plant_with_simple_v2_PID_B.req_flow = 1.0 / sqrt
    (feedback_plant_with_simple_v2_PID_B.Gain) * sqrt
    (feedback_plant_with_simple_v2_PID_B.FromWorkspace) *
    feedback_plant_with_simple_v2_PID_B.Q_tot;

  /* MATLAB Function: '<S11>/cost_power_1' */
  /* MATLAB Function 'Subsystem/cost_power_1': '<S20>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S20>:1:7' */
  /* '<S20>:1:8' */
  /* '<S20>:1:9' */
  /* '<S20>:1:10' */
  /* '<S20>:1:11' */
  /* '<S20>:1:12' */
  t6 = (rt_powd_snf(feedback_plant_with_simple_v2_PID_B.FromWorkspace,
                    0.53141635766267625) * 467.38516862850241 + rt_powd_snf
        (feedback_plant_with_simple_v2_PID_B.req_flow, 1.2849922003160621) *
        94.275566165207337) - feedback_plant_with_simple_v2_PID_B.FromWorkspace *
    feedback_plant_with_simple_v2_PID_B.req_flow * 3.5900928110138022;

  /* '<S20>:1:13' */
  /* '<S20>:1:14' */
  /* '<S20>:1:15' */
  /* '<S20>:1:16' */
  /* '<S20>:1:17' */
  /* '<S20>:1:18' */
  t12 = (rt_powd_snf(feedback_plant_with_simple_v2_PID_B.FromWorkspace,
                     1.157084314722127) * 6.1329150891835766 + rt_powd_snf
         (feedback_plant_with_simple_v2_PID_B.req_flow, 2.6827906282842031) *
         1.270953547543209) + feedback_plant_with_simple_v2_PID_B.FromWorkspace *
    feedback_plant_with_simple_v2_PID_B.req_flow * 2.6333276809500008;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S20>:1:19' */
    b = true;
  } else {
    /* '<S20>:1:19' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S20>:1:19' */
    c = true;
  } else {
    /* '<S20>:1:19' */
  }

  /* '<S20>:1:19' */
  feedback_plant_with_simple_v2_PID_B.cost_power_1_w_sat = (real_T)b * 50000.0 +
    t12 * (real_T)c;

  /* End of MATLAB Function: '<S11>/cost_power_1' */

  /* MATLAB Function: '<S11>/cost_power_2' */
  /* MATLAB Function 'Subsystem/cost_power_2': '<S21>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S21>:1:7' */
  t12 = feedback_plant_with_simple_v2_PID_B.req_flow * 0.5;

  /* '<S21>:1:8' */
  /* '<S21>:1:9' */
  /* '<S21>:1:10' */
  /* '<S21>:1:11' */
  /* '<S21>:1:12' */
  /* '<S21>:1:13' */
  t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 + rt_powd_snf
        (feedback_plant_with_simple_v2_PID_B.FromWorkspace, 0.53141635766267625)
        * 467.38516862850241) -
    feedback_plant_with_simple_v2_PID_B.FromWorkspace *
    feedback_plant_with_simple_v2_PID_B.req_flow * 1.7950464055069011;

  /* '<S21>:1:14' */
  /* '<S21>:1:15' */
  /* '<S21>:1:16' */
  /* '<S21>:1:17' */
  /* '<S21>:1:18' */
  /* '<S21>:1:19' */
  t12 = (feedback_plant_with_simple_v2_PID_B.FromWorkspace *
         feedback_plant_with_simple_v2_PID_B.req_flow * 1.3166638404750011 +
         rt_powd_snf(feedback_plant_with_simple_v2_PID_B.FromWorkspace,
                     1.157084314722127) * 6.1329150891835766) + rt_powd_snf(t12,
    2.6827906282842031) * 1.270953547543209;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S21>:1:20' */
    b = true;
  } else {
    /* '<S21>:1:20' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S21>:1:20' */
    c = true;
  } else {
    /* '<S21>:1:20' */
    c = false;
  }

  /* '<S21>:1:20' */
  feedback_plant_with_simple_v2_PID_B.cost_power_2_w_sat = t12 * (real_T)c * 2.0
    + (real_T)b * 100000.0;

  /* End of MATLAB Function: '<S11>/cost_power_2' */

  /* MATLAB Function: '<S11>/cost_power_3' */
  /* MATLAB Function 'Subsystem/cost_power_3': '<S22>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S22>:1:7' */
  t12 = feedback_plant_with_simple_v2_PID_B.req_flow * 0.33333333333333331;

  /* '<S22>:1:8' */
  /* '<S22>:1:9' */
  /* '<S22>:1:10' */
  /* '<S22>:1:11' */
  /* '<S22>:1:12' */
  /* '<S22>:1:13' */
  t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 + rt_powd_snf
        (feedback_plant_with_simple_v2_PID_B.FromWorkspace, 0.53141635766267625)
        * 467.38516862850241) -
    feedback_plant_with_simple_v2_PID_B.FromWorkspace *
    feedback_plant_with_simple_v2_PID_B.req_flow * 1.1966976036712671;

  /* '<S22>:1:14' */
  /* '<S22>:1:15' */
  /* '<S22>:1:16' */
  /* '<S22>:1:17' */
  /* '<S22>:1:18' */
  /* '<S22>:1:19' */
  t12 = (feedback_plant_with_simple_v2_PID_B.FromWorkspace *
         feedback_plant_with_simple_v2_PID_B.req_flow * 0.87777589365000042 +
         rt_powd_snf(feedback_plant_with_simple_v2_PID_B.FromWorkspace,
                     1.157084314722127) * 6.1329150891835766) + rt_powd_snf(t12,
    2.6827906282842031) * 1.270953547543209;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S22>:1:20' */
    b = true;
  } else {
    /* '<S22>:1:20' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S22>:1:20' */
    c = true;
  } else {
    /* '<S22>:1:20' */
    c = false;
  }

  /* '<S22>:1:20' */
  feedback_plant_with_simple_v2_PID_B.cost_power_3_w_sat = t12 * (real_T)c * 3.0
    + (real_T)b * 150000.0;

  /* End of MATLAB Function: '<S11>/cost_power_3' */

  /* MATLAB Function: '<S11>/MATLAB Function' */
  /* MATLAB Function 'Subsystem/MATLAB Function': '<S17>:1' */
  /* '<S17>:1:2' */
  feedback_plant_with_simple_v2_PID_B.y = 1.0;
  if (feedback_plant_with_simple_v2_PID_B.cost_power_2_w_sat == 100000.0) {
    /* '<S17>:1:3' */
    /* 2 pumps? */
    /* '<S17>:1:5' */
    feedback_plant_with_simple_v2_PID_B.y = 3.0;
  } else {
    if (feedback_plant_with_simple_v2_PID_B.cost_power_1_w_sat == 50000.0) {
      /* '<S17>:1:6' */
      /* '<S17>:1:7' */
      feedback_plant_with_simple_v2_PID_B.y = 2.0;

      /* 3 pumps?  */
    }
  }

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  /* MATLAB Function 'MATLAB Function1': '<S2>:1' */
  /* '<S2>:1:2' */
  feedback_plant_with_simple_v2_PID_B.WP1 = 0.0;

  /* '<S2>:1:3' */
  feedback_plant_with_simple_v2_PID_B.WP2 = 0.0;

  /* '<S2>:1:4' */
  feedback_plant_with_simple_v2_PID_B.WP3 = 0.0;
  if (feedback_plant_with_simple_v2_PID_B.y == 1.0) {
    /* '<S2>:1:5' */
    /* '<S2>:1:6' */
    feedback_plant_with_simple_v2_PID_B.WP1 =
      feedback_plant_with_simple_v2_PID_B.Saturate;
  } else if (feedback_plant_with_simple_v2_PID_B.y == 2.0) {
    /* '<S2>:1:7' */
    /* '<S2>:1:8' */
    feedback_plant_with_simple_v2_PID_B.WP1 = 1.0;

    /* '<S2>:1:9' */
    feedback_plant_with_simple_v2_PID_B.WP2 =
      feedback_plant_with_simple_v2_PID_B.Saturate;
  } else {
    if (feedback_plant_with_simple_v2_PID_B.y == 3.0) {
      /* '<S2>:1:10' */
      /* '<S2>:1:11' */
      feedback_plant_with_simple_v2_PID_B.WP1 = 1.0;

      /* '<S2>:1:12' */
      feedback_plant_with_simple_v2_PID_B.WP2 = 1.0;

      /* '<S2>:1:13' */
      feedback_plant_with_simple_v2_PID_B.WP3 =
        feedback_plant_with_simple_v2_PID_B.Saturate;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S12>/transform'
   */
  feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[0] =
    feedback_plant_with_simple_v2_PID_B.FromWorkspace1;
  feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[1] =
    feedback_plant_with_simple_v2_PID_B.WP1;
  feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[2] =
    feedback_plant_with_simple_v2_PID_B.WP2;
  feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[3] =
    feedback_plant_with_simple_v2_PID_B.WP3;

  /* MATLAB Function: '<S12>/transform' incorporates:
   *  Constant: '<S12>/gain'
   *  Constant: '<S12>/offset'
   */
  /* MATLAB Function 'actuators/transform': '<S25>:1' */
  /* '<S25>:1:2' */
  t6 = feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[0] *
    10.0 - (-0.0);
  t12 = feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d[1] *
    10.0 - (-0.0);
  y_idx_2 = feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d
    [2] * 10.0 - (-0.0);
  y_idx_3 = feedback_plant_with_simple_v2_PID_B.TmpSignalConversionAtSFunctio_d
    [3] * 10.0 - (-0.0);

  /* '<S25>:1:3' */
  feedback_plant_with_simple_v2_PID_B.CV01_j = t6;

  /* '<S25>:1:4' */
  feedback_plant_with_simple_v2_PID_B.WP01_o = t12;

  /* '<S25>:1:5' */
  feedback_plant_with_simple_v2_PID_B.WP02_l = y_idx_2;

  /* '<S25>:1:6' */
  feedback_plant_with_simple_v2_PID_B.WP03_d = y_idx_3;
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* Level2 S-Function Block: '<S12>/DA_sink' (danipcim) */
    {
      SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* RelationalOperator: '<S28>/max_relop' incorporates:
     *  Constant: '<S28>/max_val'
     */
    feedback_plant_with_simple_v2_PID_B.max_relop[0] =
      (feedback_plant_with_simple_v2_PID_B.CV01 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[1] =
      (feedback_plant_with_simple_v2_PID_B.DPT01 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[2] =
      (feedback_plant_with_simple_v2_PID_B.LMGC1 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[3] =
      (feedback_plant_with_simple_v2_PID_B.LMGP1 <= 4200.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[4] =
      (feedback_plant_with_simple_v2_PID_B.LMGV1 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[5] =
      (feedback_plant_with_simple_v2_PID_B.MFM01 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[6] =
      (feedback_plant_with_simple_v2_PID_B.PT01 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[7] =
      (feedback_plant_with_simple_v2_PID_B.WP01 <= 4200.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[8] =
      (feedback_plant_with_simple_v2_PID_B.DPT02 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[9] =
      (feedback_plant_with_simple_v2_PID_B.LMGC2 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[10] =
      (feedback_plant_with_simple_v2_PID_B.LMGP2 <= 4200.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[11] =
      (feedback_plant_with_simple_v2_PID_B.LMGV2 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[12] =
      (feedback_plant_with_simple_v2_PID_B.MFM02 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[13] =
      (feedback_plant_with_simple_v2_PID_B.PT02 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[14] =
      (feedback_plant_with_simple_v2_PID_B.WP02 <= 4200.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[15] =
      (feedback_plant_with_simple_v2_PID_B.DPT03 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[16] =
      (feedback_plant_with_simple_v2_PID_B.LMGC3 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[17] =
      (feedback_plant_with_simple_v2_PID_B.LMGP3 <= 4200.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[18] =
      (feedback_plant_with_simple_v2_PID_B.LMGV3 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[19] =
      (feedback_plant_with_simple_v2_PID_B.MFM03 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[20] =
      (feedback_plant_with_simple_v2_PID_B.PT03 <= 1050.05);
    feedback_plant_with_simple_v2_PID_B.max_relop[21] =
      (feedback_plant_with_simple_v2_PID_B.WP03 <= 4200.05);

    /* MATLAB Function: '<S15>/err_high' incorporates:
     *  Constant: '<S15>/sname'
     */
    /* MATLAB Function 'terminating_safety/err_high': '<S29>:1' */
    /* '<S29>:1:13' */
    /* '<S29>:1:12' */
    /* test = char(sensnames.'); */
    /* '<S29>:1:4' */
    /* '<S29>:1:5' */
    for (i = 0; i < 124; i++) {
      test[i] = feedback_plant_with_simple_v2_PID_ConstP.sname_Value[i];
      x[i] = (feedback_plant_with_simple_v2_PID_ConstP.sname_Value[i] == 47);
    }

    idx = 0;
    b_ii = 1;
    b = false;
    while ((!b) && (b_ii < 125)) {
      c = false;
      if (x[b_ii - 1]) {
        idx++;
        ii_data[idx - 1] = (int8_T)b_ii;
        if (idx >= 124) {
          b = true;
        } else {
          c = true;
        }
      } else {
        c = true;
      }

      if (c) {
        b_ii++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    /* '<S29>:1:6' */
    /* '<S29>:1:7' */
    k_data[0] = 0;
    for (i = 0; i < idx; i++) {
      k_data[i + 1] = ii_data[i];
    }

    k_data[1 + idx] = 124;

    /* '<S29>:1:8' */
    t6 = 0.0;

    /* '<S29>:1:9' */
    for (idx = 0; idx < 22; idx++) {
      /* '<S29>:1:9' */
      if (!feedback_plant_with_simple_v2_PID_B.max_relop[idx]) {
        /* '<S29>:1:10' */
        if (k_data[idx] + 1 > k_data[1 + idx] - 1) {
          b_ii = 1;
          j = 1;
        } else {
          b_ii = k_data[idx] + 1;
          j = k_data[1 + idx];
        }

        /* '<S29>:1:11' */
        /* '<S29>:1:12' */
        tmp = j - b_ii;
        loop_ub = j - b_ii;
        for (i = 0; i < loop_ub; i++) {
          test_data[i] = (int8_T)test[(b_ii + i) - 1];
        }

        tmp_0 = (int8_T)(j - b_ii);
        for (i = 0; i < tmp; i++) {
          test_data_0[i] = test_data[i];
        }

        tmp = tmp_0;
        for (i = 0; i < tmp; i++) {
          Error_data[i] = test_data_0[i];
        }

        for (i = 0; i < 17; i++) {
          Error_data[i + tmp] = f[i];
        }

        e_0[0] = '%';
        e_0[1] = 's';
        e_0[2] = '\x0a';
        e_0[3] = '\x00';
        printf(e_0, &Error_data[0]);

        /* '<S29>:1:14' */
        t6++;
      }

      /* '<S29>:1:9' */
    }

    feedback_plant_with_simple_v2_PID_B.stop_a = t6;

    /* End of MATLAB Function: '<S15>/err_high' */

    /* Stop: '<S15>/stop' */
    if (feedback_plant_with_simple_v2_PID_B.stop_a != 0.0) {
      rtmSetStopRequested(feedback_plant_with_simple_v2_PID_M, 1);
    }

    /* End of Stop: '<S15>/stop' */

    /* RelationalOperator: '<S27>/min_relop' incorporates:
     *  Constant: '<S27>/min_val'
     */
    feedback_plant_with_simple_v2_PID_B.min_relop[0] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.CV01);
    feedback_plant_with_simple_v2_PID_B.min_relop[1] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.DPT01);
    feedback_plant_with_simple_v2_PID_B.min_relop[2] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGC1);
    feedback_plant_with_simple_v2_PID_B.min_relop[3] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.LMGP1);
    feedback_plant_with_simple_v2_PID_B.min_relop[4] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGV1);
    feedback_plant_with_simple_v2_PID_B.min_relop[5] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.MFM01);
    feedback_plant_with_simple_v2_PID_B.min_relop[6] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.PT01);
    feedback_plant_with_simple_v2_PID_B.min_relop[7] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.WP01);
    feedback_plant_with_simple_v2_PID_B.min_relop[8] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.DPT02);
    feedback_plant_with_simple_v2_PID_B.min_relop[9] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGC2);
    feedback_plant_with_simple_v2_PID_B.min_relop[10] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.LMGP2);
    feedback_plant_with_simple_v2_PID_B.min_relop[11] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGV2);
    feedback_plant_with_simple_v2_PID_B.min_relop[12] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.MFM02);
    feedback_plant_with_simple_v2_PID_B.min_relop[13] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.PT02);
    feedback_plant_with_simple_v2_PID_B.min_relop[14] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.WP02);
    feedback_plant_with_simple_v2_PID_B.min_relop[15] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.DPT03);
    feedback_plant_with_simple_v2_PID_B.min_relop[16] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGC3);
    feedback_plant_with_simple_v2_PID_B.min_relop[17] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.LMGP3);
    feedback_plant_with_simple_v2_PID_B.min_relop[18] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.LMGV3);
    feedback_plant_with_simple_v2_PID_B.min_relop[19] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.MFM03);
    feedback_plant_with_simple_v2_PID_B.min_relop[20] = ((-51.050000000000004) <=
      feedback_plant_with_simple_v2_PID_B.PT03);
    feedback_plant_with_simple_v2_PID_B.min_relop[21] = ((-201.05) <=
      feedback_plant_with_simple_v2_PID_B.WP03);

    /* MATLAB Function: '<S15>/err_low' incorporates:
     *  Constant: '<S15>/sname'
     */
    /* MATLAB Function 'terminating_safety/err_low': '<S30>:1' */
    /* '<S30>:1:12' */
    /* '<S30>:1:11' */
    /* '<S30>:1:3' */
    /* '<S30>:1:4' */
    idx = 0;
    for (b_ii = 0; b_ii < 124; b_ii++) {
      test_0[b_ii] = (int8_T)
        feedback_plant_with_simple_v2_PID_ConstP.sname_Value[b_ii];
      j = 1;
      while ((j <= 1) && (test_0[b_ii] == '/')) {
        j = 2;
      }

      if (j > 1) {
        matches[idx] = (int8_T)(b_ii + 1);
        idx++;
      }
    }

    for (b_ii = 0; b_ii + 1 <= idx; b_ii++) {
      ii_data[b_ii] = matches[b_ii];
    }

    /* '<S30>:1:5' */
    /* '<S30>:1:6' */
    k_data_0[0] = 0;
    for (i = 0; i < idx; i++) {
      k_data_0[i + 1] = ii_data[i];
    }

    k_data_0[1 + idx] = 124;

    /* '<S30>:1:7' */
    t6 = 0.0;

    /* '<S30>:1:8' */
    for (idx = 0; idx < 22; idx++) {
      /* '<S30>:1:8' */
      if (!feedback_plant_with_simple_v2_PID_B.min_relop[idx]) {
        /* '<S30>:1:9' */
        if (k_data_0[idx] + 1 > k_data_0[1 + idx] - 1) {
          b_ii = 1;
          j = 0;
        } else {
          b_ii = k_data_0[idx] + 1;
          j = k_data_0[1 + idx] - 1;
        }

        /* '<S30>:1:10' */
        /* '<S30>:1:11' */
        i = b_ii - 1;
        loop_ub = j - i;
        for (b_ii = 0; b_ii < loop_ub; b_ii++) {
          Error_data_0[b_ii] = test_0[i + b_ii];
        }

        for (b_ii = 0; b_ii < 15; b_ii++) {
          Error_data_0[(b_ii + j) - i] = e[b_ii];
        }

        d[0] = '%';
        d[1] = 's';
        d[2] = '\x0a';
        d[3] = '\x00';
        printf(d, &Error_data_0[0]);

        /* '<S30>:1:13' */
        t6++;
      }

      /* '<S30>:1:8' */
    }

    feedback_plant_with_simple_v2_PID_B.stop = t6;

    /* End of MATLAB Function: '<S15>/err_low' */

    /* Stop: '<S15>/stop1' */
    if (feedback_plant_with_simple_v2_PID_B.stop != 0.0) {
      rtmSetStopRequested(feedback_plant_with_simple_v2_PID_M, 1);
    }

    /* End of Stop: '<S15>/stop1' */
    for (i = 0; i < 22; i++) {
      /* Assertion: '<S27>/Assertion' */
      utAssert(feedback_plant_with_simple_v2_PID_B.min_relop[i]);
    }

    for (i = 0; i < 22; i++) {
      /* Assertion: '<S28>/Assertion' */
      utAssert(feedback_plant_with_simple_v2_PID_B.max_relop[i]);
    }

    /* ok to acquire for <S31>/S-Function */
    feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_go.AcquireOK = 1;
  }

  /* ok to acquire for <S19>/S-Function */
  feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_c.AcquireOK = 1;
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
  }

  /* Gain: '<S24>/ZeroGain' */
  feedback_plant_with_simple_v2_PID_B.ZeroGain = 0.0 *
    feedback_plant_with_simple_v2_PID_B.Sum;

  /* DeadZone: '<S24>/DeadZone' */
  if (feedback_plant_with_simple_v2_PID_B.Sum > 1.0) {
    feedback_plant_with_simple_v2_PID_B.DeadZone =
      feedback_plant_with_simple_v2_PID_B.Sum - 1.0;
  } else if (feedback_plant_with_simple_v2_PID_B.Sum >= 0.0) {
    feedback_plant_with_simple_v2_PID_B.DeadZone = 0.0;
  } else {
    feedback_plant_with_simple_v2_PID_B.DeadZone =
      feedback_plant_with_simple_v2_PID_B.Sum - 0.0;
  }

  /* End of DeadZone: '<S24>/DeadZone' */

  /* RelationalOperator: '<S24>/NotEqual' */
  feedback_plant_with_simple_v2_PID_B.NotEqual =
    (feedback_plant_with_simple_v2_PID_B.ZeroGain !=
     feedback_plant_with_simple_v2_PID_B.DeadZone);

  /* Signum: '<S24>/SignDeltaU' */
  t6 = feedback_plant_with_simple_v2_PID_B.DeadZone;
  if (t6 < 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignDeltaU = -1.0;
  } else if (t6 > 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignDeltaU = 1.0;
  } else if (t6 == 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignDeltaU = 0.0;
  } else {
    feedback_plant_with_simple_v2_PID_B.SignDeltaU = t6;
  }

  /* End of Signum: '<S24>/SignDeltaU' */

  /* DataTypeConversion: '<S24>/DataTypeConv1' */
  t6 = feedback_plant_with_simple_v2_PID_B.SignDeltaU;
  if (t6 < 128.0) {
    if (t6 >= -128.0) {
      tmp_0 = (int8_T)t6;
    } else {
      tmp_0 = MIN_int8_T;
    }
  } else {
    tmp_0 = MAX_int8_T;
  }

  feedback_plant_with_simple_v2_PID_B.DataTypeConv1 = tmp_0;

  /* End of DataTypeConversion: '<S24>/DataTypeConv1' */

  /* Gain: '<S18>/Integral Gain' */
  feedback_plant_with_simple_v2_PID_B.IntegralGain = 0.04 *
    feedback_plant_with_simple_v2_PID_B.PID_Error;

  /* Signum: '<S24>/SignPreIntegrator' */
  t6 = feedback_plant_with_simple_v2_PID_B.IntegralGain;
  if (t6 < 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignPreIntegrator = -1.0;
  } else if (t6 > 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignPreIntegrator = 1.0;
  } else if (t6 == 0.0) {
    feedback_plant_with_simple_v2_PID_B.SignPreIntegrator = 0.0;
  } else {
    feedback_plant_with_simple_v2_PID_B.SignPreIntegrator = t6;
  }

  /* End of Signum: '<S24>/SignPreIntegrator' */

  /* DataTypeConversion: '<S24>/DataTypeConv2' */
  t6 = floor(feedback_plant_with_simple_v2_PID_B.SignPreIntegrator);
  if (rtIsNaN(t6) || rtIsInf(t6)) {
    t6 = 0.0;
  } else {
    t6 = fmod(t6, 256.0);
  }

  feedback_plant_with_simple_v2_PID_B.DataTypeConv2 = (int8_T)(t6 < 0.0 ?
    (int32_T)(int8_T)-(int8_T)(uint8_T)-t6 : (int32_T)(int8_T)(uint8_T)t6);

  /* End of DataTypeConversion: '<S24>/DataTypeConv2' */

  /* RelationalOperator: '<S24>/Equal' */
  feedback_plant_with_simple_v2_PID_B.Equal =
    (feedback_plant_with_simple_v2_PID_B.DataTypeConv1 ==
     feedback_plant_with_simple_v2_PID_B.DataTypeConv2);

  /* Logic: '<S24>/AND' */
  feedback_plant_with_simple_v2_PID_B.AND =
    (feedback_plant_with_simple_v2_PID_B.NotEqual &&
     feedback_plant_with_simple_v2_PID_B.Equal);
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* Memory: '<S24>/Memory' */
    feedback_plant_with_simple_v2_PID_B.Memory =
      feedback_plant_with_simple_v2_PID_DW.Memory_PreviousInput;
  }

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (feedback_plant_with_simple_v2_PID_B.Memory) {
    feedback_plant_with_simple_v2_PID_B.Switch = 0.0;
  } else {
    feedback_plant_with_simple_v2_PID_B.Switch =
      feedback_plant_with_simple_v2_PID_B.IntegralGain;
  }

  /* End of Switch: '<S18>/Switch' */
}

/* Model update function */
void feedback_plant_with_simple_v2_PID_update(void)
{
  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    /* Update for Memory: '<S24>/Memory' */
    feedback_plant_with_simple_v2_PID_DW.Memory_PreviousInput =
      feedback_plant_with_simple_v2_PID_B.AND;
  }

  if (rtmIsMajorTimeStep(feedback_plant_with_simple_v2_PID_M)) {
    rt_ertODEUpdateContinuousStates
      (&feedback_plant_with_simple_v2_PID_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++feedback_plant_with_simple_v2_PID_M->Timing.clockTick0)) {
    ++feedback_plant_with_simple_v2_PID_M->Timing.clockTickH0;
  }

  feedback_plant_with_simple_v2_PID_M->Timing.t[0] = rtsiGetSolverStopTime
    (&feedback_plant_with_simple_v2_PID_M->solverInfo);

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
    if (!(++feedback_plant_with_simple_v2_PID_M->Timing.clockTick1)) {
      ++feedback_plant_with_simple_v2_PID_M->Timing.clockTickH1;
    }

    feedback_plant_with_simple_v2_PID_M->Timing.t[1] =
      feedback_plant_with_simple_v2_PID_M->Timing.clockTick1 *
      feedback_plant_with_simple_v2_PID_M->Timing.stepSize1 +
      feedback_plant_with_simple_v2_PID_M->Timing.clockTickH1 *
      feedback_plant_with_simple_v2_PID_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void feedback_plant_with_simple_v2_PID_derivatives(void)
{
  XDot_feedback_plant_with_simple_v2_PID_T *_rtXdot;
  _rtXdot = ((XDot_feedback_plant_with_simple_v2_PID_T *)
             feedback_plant_with_simple_v2_PID_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S18>/Integrator' */
  _rtXdot->Integrator_CSTATE = feedback_plant_with_simple_v2_PID_B.Switch;
}

/* Model initialize function */
void feedback_plant_with_simple_v2_PID_initialize(void)
{
  /* Level2 S-Function Block: '<S13>/src' (adnipcim) */
  {
    SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 30.0, 60.0, 90.0, 120.0, 150.0, 180.0,
      210.0, 240.0, 270.0, 300.0, 330.0, 360.0, 390.0, 420.0, 450.0, 480.0,
      510.0, 540.0, 570.0, 600.0, 630.0, 660.0, 690.0, 720.0, 750.0, 780.0,
      810.0, 840.0, 870.0, 900.0, 930.0, 960.0, 990.0, 1020.0, 1050.0, 1080.0,
      1110.0, 1140.0, 1170.0, 1200.0, 1230.0, 1260.0, 1290.0, 1320.0, 1350.0,
      1380.0, 1410.0, 1440.0, 1470.0, 1500.0, 1530.0, 1560.0, 1590.0, 1620.0,
      1650.0, 1680.0, 1710.0, 1740.0, 1770.0, 1800.0, 1830.0, 1860.0, 1890.0,
      1920.0, 1950.0, 1980.0, 2010.0, 2040.0, 2070.0, 2100.0, 2130.0, 2160.0,
      2190.0, 2220.0, 2250.0, 2280.0, 2310.0, 2340.0, 2370.0, 2400.0, 2430.0,
      2460.0, 2490.0, 2520.0, 2550.0, 2580.0, 2610.0, 2640.0, 2670.0, 2700.0,
      2730.0, 2760.0, 2790.0, 2820.0, 2850.0, 2880.0, 2910.0, 2940.0, 2970.0,
      3000.0, 3030.0, 3060.0, 3090.0, 3120.0, 3150.0, 3180.0, 3210.0, 3240.0,
      3270.0, 3300.0, 3330.0, 3360.0, 3390.0, 3420.0, 3450.0, 3480.0, 3510.0,
      3540.0, 3570.0, 3600.0, 3630.0, 3660.0, 3690.0, 3720.0, 3750.0, 3780.0,
      3810.0, 3840.0, 3870.0, 3900.0, 3930.0, 3960.0, 3990.0, 4020.0, 4050.0,
      4080.0, 4110.0, 4140.0, 4170.0, 4200.0, 4230.0, 4260.0, 4290.0, 4320.0,
      4350.0, 4380.0, 4410.0, 4440.0, 4470.0, 4500.0, 4530.0, 4560.0, 4590.0,
      4620.0, 4650.0, 4680.0, 4710.0, 4740.0, 4770.0, 4800.0, 4830.0, 4860.0,
      4890.0, 4920.0, 4950.0, 4980.0, 5010.0, 5040.0, 5070.0, 5100.0, 5130.0,
      5160.0, 5190.0, 5220.0, 5250.0, 5280.0, 5310.0, 5340.0, 5370.0, 5400.0,
      5430.0, 5460.0, 5490.0, 5520.0, 5550.0 } ;

    static real_T pDataValues0[] = { 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.15000000000000002, 0.15000000000000002,
      0.15000000000000002, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.41864833798529622, 0.41864833798529622,
      0.41864833798529622, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.52338886271182106, 0.52338886271182106,
      0.52338886271182106, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.59755953142481022, 0.59755953142481022,
      0.59755953142481022, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.65683130654389976,
      0.65683130654389976, 0.65683130654389976, 0.70698783411662014,
      0.70698783411662014, 0.70698783411662014, 0.70698783411662014,
      0.70698783411662014, 0.70698783411662014, 0.70698783411662014,
      0.70698783411662014, 0.70698783411662014, 0.70698783411662014,
      0.70698783411662014, 0.70698783411662014, 0.70698783411662014,
      0.70698783411662014, 0.70698783411662014, 0.70698783411662014,
      0.70698783411662014, 0.75088783746701027, 0.75088783746701027,
      0.75088783746701027, 0.75088783746701027, 0.75088783746701027,
      0.75088783746701027, 0.75088783746701027, 0.75088783746701027,
      0.75088783746701027, 0.75088783746701027, 0.75088783746701027,
      0.75088783746701027, 0.75088783746701027, 0.75088783746701027,
      0.75088783746701027, 0.79017941766931865, 0.79017941766931865,
      0.79017941766931865, 0.79017941766931865, 0.79017941766931865,
      0.79017941766931865, 0.79017941766931865, 0.79017941766931865,
      0.79017941766931865, 0.79017941766931865, 0.79017941766931865,
      0.79017941766931865, 0.8259096180813561, 0.8259096180813561,
      0.8259096180813561, 0.8259096180813561, 0.8259096180813561,
      0.8259096180813561, 0.8259096180813561, 0.8259096180813561,
      0.8259096180813561, 0.8259096180813561, 0.85878998752285618,
      0.85878998752285618, 0.85878998752285618, 0.85878998752285618,
      0.85878998752285618, 0.85878998752285618, 0.85878998752285618,
      0.85878998752285618, 0.88932870306562739, 0.88932870306562739,
      0.88932870306562739, 0.88932870306562739, 0.88932870306562739,
      0.88932870306562739, 0.9179028317687925, 0.9179028317687925,
      0.9179028317687925, 0.9179028317687925, 0.9179028317687925,
      0.94480077544882535, 0.94480077544882535, 0.94480077544882535,
      0.94480077544882535, 0.97024863431865538, 0.97024863431865538,
      0.97024863431865538, 0.99442733643975156, 0.99442733643975156 } ;

    feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_PWORK.TimePtr = (void *)
      pTimeValues0;
    feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_PWORK.DataPtr = (void *)
      pDataValues0;
    feedback_plant_with_simple_v2_PID_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 30.0, 60.0, 90.0, 120.0, 150.0, 180.0,
      210.0, 240.0, 270.0, 300.0, 330.0, 360.0, 390.0, 420.0, 450.0, 480.0,
      510.0, 540.0, 570.0, 600.0, 630.0, 660.0, 690.0, 720.0, 750.0, 780.0,
      810.0, 840.0, 870.0, 900.0, 930.0, 960.0, 990.0, 1020.0, 1050.0, 1080.0,
      1110.0, 1140.0, 1170.0, 1200.0, 1230.0, 1260.0, 1290.0, 1320.0, 1350.0,
      1380.0, 1410.0, 1440.0, 1470.0, 1500.0, 1530.0, 1560.0, 1590.0, 1620.0,
      1650.0, 1680.0, 1710.0, 1740.0, 1770.0, 1800.0, 1830.0, 1860.0, 1890.0,
      1920.0, 1950.0, 1980.0, 2010.0, 2040.0, 2070.0, 2100.0, 2130.0, 2160.0,
      2190.0, 2220.0, 2250.0, 2280.0, 2310.0, 2340.0, 2370.0, 2400.0, 2430.0,
      2460.0, 2490.0, 2520.0, 2550.0, 2580.0, 2610.0, 2640.0, 2670.0, 2700.0,
      2730.0, 2760.0, 2790.0, 2820.0, 2850.0, 2880.0, 2910.0, 2940.0, 2970.0,
      3000.0, 3030.0, 3060.0, 3090.0, 3120.0, 3150.0, 3180.0, 3210.0, 3240.0,
      3270.0, 3300.0, 3330.0, 3360.0, 3390.0, 3420.0, 3450.0, 3480.0, 3510.0,
      3540.0, 3570.0, 3600.0, 3630.0, 3660.0, 3690.0, 3720.0, 3750.0, 3780.0,
      3810.0, 3840.0, 3870.0, 3900.0, 3930.0, 3960.0, 3990.0, 4020.0, 4050.0,
      4080.0, 4110.0, 4140.0, 4170.0, 4200.0, 4230.0, 4260.0, 4290.0, 4320.0,
      4350.0, 4380.0, 4410.0, 4440.0, 4470.0, 4500.0, 4530.0, 4560.0, 4590.0,
      4620.0, 4650.0, 4680.0, 4710.0, 4740.0, 4770.0, 4800.0, 4830.0, 4860.0,
      4890.0, 4920.0, 4950.0, 4980.0, 5010.0, 5040.0, 5070.0, 5100.0, 5130.0,
      5160.0, 5190.0, 5220.0, 5250.0, 5280.0, 5310.0, 5340.0, 5370.0, 5400.0,
      5430.0, 5460.0, 5490.0, 5520.0, 5550.0 } ;

    static real_T pDataValues0[] = { 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0,
      21.0, 23.0, 25.0, 27.0, 29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.0, 43.0,
      45.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0,
      29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.0, 43.0, 45.0, 5.0, 7.0, 9.0, 11.0,
      13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 29.0, 31.0, 33.0, 35.0,
      37.0, 39.0, 41.0, 43.0, 45.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0,
      21.0, 23.0, 25.0, 27.0, 29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.0, 43.0,
      45.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0,
      29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0,
      17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 29.0, 31.0, 33.0, 35.0, 37.0, 5.0, 7.0,
      9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 29.0, 31.0,
      33.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0,
      5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 5.0, 7.0, 9.0,
      11.0, 13.0, 15.0, 17.0, 19.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 5.0, 7.0,
      9.0, 11.0, 13.0, 5.0, 7.0, 9.0, 11.0, 5.0, 7.0, 9.0, 5.0, 7.0 } ;

    feedback_plant_with_simple_v2_PID_DW.FromWorkspace_PWORK.TimePtr = (void *)
      pTimeValues0;
    feedback_plant_with_simple_v2_PID_DW.FromWorkspace_PWORK.DataPtr = (void *)
      pDataValues0;
    feedback_plant_with_simple_v2_PID_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(9)) == 0) {
      if ((i = rl32eDefScope(9,2)) != 0) {
        printf("Error creating scope 9\n");
      } else {
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p5"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p12"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p19"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p3"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p10"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p17"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p4"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p11"));
        rl32eAddSignal(9, rl32eGetSignalNo("analogdigital/transform/p18"));
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo("analogdigital/transform/p5"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p12"),"%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p19"),"%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo("analogdigital/transform/p3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p10"),"%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p17"),"%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo("analogdigital/transform/p4"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p11"),"%15.6f");
        rl32eSetTargetScopeSigFt(9,rl32eGetSignalNo(
          "analogdigital/transform/p18"),"%15.6f");
        rl32eSetScope(9, 4, 25);
        rl32eSetScope(9, 5, 0);
        rl32eSetScope(9, 6, 1);
        rl32eSetScope(9, 0, 0);
        rl32eSetScope(9, 3, rl32eGetSignalNo("analogdigital/transform/p5"));
        rl32eSetScope(9, 1, 0.0);
        rl32eSetScope(9, 2, 0);
        rl32eSetScope(9, 9, 0);
        rl32eSetTargetScope(9, 1, 0.0);
        rl32eSetTargetScope(9, 11, 0.0);
        rl32eSetTargetScope(9, 10, 0.0);
        xpceScopeAcqOK(9,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(9);
    }
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(10)) == 0) {
      if ((i = rl32eDefScope(10,2)) != 0) {
        printf("Error creating scope 10\n");
      } else {
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p1"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p2"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p9"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p16"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p6"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p13"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p20"));
        rl32eAddSignal(10, rl32eGetSignalNo("analogdigital/transform/p14"));
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p1"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p2"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p9"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p16"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p6"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p13"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p20"),"%15.6f");
        rl32eSetTargetScopeSigFt(10,rl32eGetSignalNo(
          "analogdigital/transform/p14"),"%15.6f");
        rl32eSetScope(10, 4, 25);
        rl32eSetScope(10, 5, 0);
        rl32eSetScope(10, 6, 1);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo("analogdigital/transform/p1"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 9, 0);
        rl32eSetTargetScope(10, 1, 0.0);
        rl32eSetTargetScope(10, 11, 0.0);
        rl32eSetTargetScope(10, 10, 0.0);
        xpceScopeAcqOK(10,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,1)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("From Workspace1"));
        rl32eAddSignal(2, rl32eGetSignalNo("MATLAB Function1/p1"));
        rl32eAddSignal(2, rl32eGetSignalNo("MATLAB Function1/p2"));
        rl32eAddSignal(2, rl32eGetSignalNo("MATLAB Function1/p3"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("From Workspace1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        xpceScopeAcqOK(2,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eAddSignal(3, rl32eGetSignalNo("From Workspace"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/PID Controller/Saturate"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/cost_power_1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/cost_power_2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/cost_power_3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Subsystem/MATLAB Function"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain"));
        rl32eSetScope(3, 4, 250);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(8)) == 0) {
      if ((i = rl32eDefScope(8,2)) != 0) {
        printf("Error creating scope 8\n");
      } else {
        rl32eAddSignal(8, rl32eGetSignalNo("From Workspace1"));
        rl32eAddSignal(8, rl32eGetSignalNo("MATLAB Function1/p1"));
        rl32eAddSignal(8, rl32eGetSignalNo("MATLAB Function1/p2"));
        rl32eAddSignal(8, rl32eGetSignalNo("MATLAB Function1/p3"));
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("From Workspace1"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("MATLAB Function1/p1"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("MATLAB Function1/p2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("MATLAB Function1/p3"),
          "%15.6f");
        rl32eSetScope(8, 4, 25);
        rl32eSetScope(8, 5, 0);
        rl32eSetScope(8, 6, 1);
        rl32eSetScope(8, 0, 0);
        rl32eSetScope(8, 3, rl32eGetSignalNo("From Workspace1"));
        rl32eSetScope(8, 1, 0.0);
        rl32eSetScope(8, 2, 0);
        rl32eSetScope(8, 9, 0);
        rl32eSetTargetScope(8, 1, 0.0);
        rl32eSetTargetScope(8, 11, 0.0);
        rl32eSetTargetScope(8, 10, 0.0);
        xpceScopeAcqOK(8,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(8);
    }
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(11)) == 0) {
      if ((i = rl32eDefScope(11,2)) != 0) {
        printf("Error creating scope 11\n");
      } else {
        rl32eAddSignal(11, rl32eGetSignalNo("analogdigital/transform/p8"));
        rl32eAddSignal(11, rl32eGetSignalNo("analogdigital/transform/p15"));
        rl32eAddSignal(11, rl32eGetSignalNo("analogdigital/transform/p22"));
        rl32eSetTargetScopeSigFt(11,rl32eGetSignalNo(
          "analogdigital/transform/p8"),"%15.6f");
        rl32eSetTargetScopeSigFt(11,rl32eGetSignalNo(
          "analogdigital/transform/p15"),"%15.6f");
        rl32eSetTargetScopeSigFt(11,rl32eGetSignalNo(
          "analogdigital/transform/p22"),"%15.6f");
        rl32eSetScope(11, 4, 25);
        rl32eSetScope(11, 5, 0);
        rl32eSetScope(11, 6, 1);
        rl32eSetScope(11, 0, 0);
        rl32eSetScope(11, 3, rl32eGetSignalNo("analogdigital/transform/p8"));
        rl32eSetScope(11, 1, 0.0);
        rl32eSetScope(11, 2, 0);
        rl32eSetScope(11, 9, 0);
        rl32eSetTargetScope(11, 1, 0.0);
        rl32eSetTargetScope(11, 11, 0.0);
        rl32eSetTargetScope(11, 10, 0.0);
        xpceScopeAcqOK(11,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(11);
    }
  }

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("analogdigital/transform/p14"));
        rl32eSetScope(4, 4, 100);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("analogdigital/transform/p14"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 2.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l4.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,2)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eAddSignal(6, rl32eGetSignalNo("From Workspace"));
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/PID Controller/Saturate"));
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/cost_power_1"));
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/cost_power_2"));
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/cost_power_3"));
        rl32eAddSignal(6, rl32eGetSignalNo("Subsystem/MATLAB Function"));
        rl32eAddSignal(6, rl32eGetSignalNo("Gain"));
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Subsystem/Sum"),"%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("From Workspace"),"%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo(
          "Subsystem/PID Controller/Saturate"),"%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Subsystem/cost_power_1"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Subsystem/cost_power_2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Subsystem/cost_power_3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Subsystem/MATLAB Function"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Gain"),"%15.6f");
        rl32eSetScope(6, 4, 25);
        rl32eSetScope(6, 5, 0);
        rl32eSetScope(6, 6, 1);
        rl32eSetScope(6, 0, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 9, 0);
        rl32eSetTargetScope(6, 1, 0.0);
        rl32eSetTargetScope(6, 11, 0.0);
        rl32eSetTargetScope(6, 10, 0.0);
        xpceScopeAcqOK(6,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_l0.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* Level2 S-Function Block: '<S12>/DA_sink' (danipcim) */
  {
    SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S31>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,1)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p1"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p2"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p3"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p4"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p5"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p6"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p7"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p8"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p9"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p10"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p11"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p12"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p13"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p14"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p15"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p16"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p17"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p18"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p19"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p20"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p21"));
        rl32eAddSignal(1, rl32eGetSignalNo("analogdigital/transform/p22"));
        rl32eSetScope(1, 4, 250);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("analogdigital/transform/p1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_go.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S19>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eAddSignal(5, rl32eGetSignalNo("From Workspace"));
        rl32eAddSignal(5, rl32eGetSignalNo("Gain"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Subsystem/Sum"),"%15.6f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("From Workspace"),"%15.6f");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Gain"),"%15.6f");
        rl32eSetScope(5, 4, 25);
        rl32eSetScope(5, 5, 0);
        rl32eSetScope(5, 6, 1);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Subsystem/Sum"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 9, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, 0.0);
        rl32eSetTargetScope(5, 10, 0.0);
        xpceScopeAcqOK(5,
                       &feedback_plant_with_simple_v2_PID_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* InitializeConditions for Integrator: '<S18>/Integrator' */
  feedback_plant_with_simple_v2_PID_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<S24>/Memory' */
  feedback_plant_with_simple_v2_PID_DW.Memory_PreviousInput = false;
}

/* Model terminate function */
void feedback_plant_with_simple_v2_PID_terminate(void)
{
  /* Level2 S-Function Block: '<S13>/src' (adnipcim) */
  {
    SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/DA_sink' (danipcim) */
  {
    SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  feedback_plant_with_simple_v2_PID_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  feedback_plant_with_simple_v2_PID_update();
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
  feedback_plant_with_simple_v2_PID_initialize();
}

void MdlTerminate(void)
{
  feedback_plant_with_simple_v2_PID_terminate();
}

/* Registration function */
RT_MODEL_feedback_plant_with_simple_v2_PID_T *feedback_plant_with_simple_v2_PID
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)feedback_plant_with_simple_v2_PID_M, 0,
                sizeof(RT_MODEL_feedback_plant_with_simple_v2_PID_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                          &feedback_plant_with_simple_v2_PID_M->Timing.simTimeStep);
    rtsiSetTPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo, &rtmGetTPtr
                (feedback_plant_with_simple_v2_PID_M));
    rtsiSetStepSizePtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                       &feedback_plant_with_simple_v2_PID_M->Timing.stepSize0);
    rtsiSetdXPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                 &feedback_plant_with_simple_v2_PID_M->ModelData.derivs);
    rtsiSetContStatesPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                         (real_T **)
                         &feedback_plant_with_simple_v2_PID_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
      &feedback_plant_with_simple_v2_PID_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&feedback_plant_with_simple_v2_PID_M->solverInfo,
       &feedback_plant_with_simple_v2_PID_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&feedback_plant_with_simple_v2_PID_M->solverInfo,
       &feedback_plant_with_simple_v2_PID_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&feedback_plant_with_simple_v2_PID_M->solverInfo,
       &feedback_plant_with_simple_v2_PID_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                          (&rtmGetErrorStatus
      (feedback_plant_with_simple_v2_PID_M)));
    rtsiSetRTModelPtr(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                      feedback_plant_with_simple_v2_PID_M);
  }

  rtsiSetSimTimeStep(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                     MAJOR_TIME_STEP);
  feedback_plant_with_simple_v2_PID_M->ModelData.intgData.y =
    feedback_plant_with_simple_v2_PID_M->ModelData.odeY;
  feedback_plant_with_simple_v2_PID_M->ModelData.intgData.f[0] =
    feedback_plant_with_simple_v2_PID_M->ModelData.odeF[0];
  feedback_plant_with_simple_v2_PID_M->ModelData.intgData.f[1] =
    feedback_plant_with_simple_v2_PID_M->ModelData.odeF[1];
  feedback_plant_with_simple_v2_PID_M->ModelData.intgData.f[2] =
    feedback_plant_with_simple_v2_PID_M->ModelData.odeF[2];
  feedback_plant_with_simple_v2_PID_M->ModelData.contStates = ((real_T *)
    &feedback_plant_with_simple_v2_PID_X);
  rtsiSetSolverData(&feedback_plant_with_simple_v2_PID_M->solverInfo, (void *)
                    &feedback_plant_with_simple_v2_PID_M->ModelData.intgData);
  rtsiSetSolverName(&feedback_plant_with_simple_v2_PID_M->solverInfo,"ode3");
  feedback_plant_with_simple_v2_PID_M->solverInfoPtr =
    (&feedback_plant_with_simple_v2_PID_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      feedback_plant_with_simple_v2_PID_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    feedback_plant_with_simple_v2_PID_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    feedback_plant_with_simple_v2_PID_M->Timing.sampleTimes =
      (&feedback_plant_with_simple_v2_PID_M->Timing.sampleTimesArray[0]);
    feedback_plant_with_simple_v2_PID_M->Timing.offsetTimes =
      (&feedback_plant_with_simple_v2_PID_M->Timing.offsetTimesArray[0]);

    /* task periods */
    feedback_plant_with_simple_v2_PID_M->Timing.sampleTimes[0] = (0.0);
    feedback_plant_with_simple_v2_PID_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    feedback_plant_with_simple_v2_PID_M->Timing.offsetTimes[0] = (0.0);
    feedback_plant_with_simple_v2_PID_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(feedback_plant_with_simple_v2_PID_M,
             &feedback_plant_with_simple_v2_PID_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      feedback_plant_with_simple_v2_PID_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    feedback_plant_with_simple_v2_PID_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(feedback_plant_with_simple_v2_PID_M, 5580.0);
  feedback_plant_with_simple_v2_PID_M->Timing.stepSize0 = 0.01;
  feedback_plant_with_simple_v2_PID_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    feedback_plant_with_simple_v2_PID_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, (NULL));
    rtliSetLogT(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, "tout");
    rtliSetLogX(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, "");
    rtliSetLogXFinal(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(feedback_plant_with_simple_v2_PID_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &feedback_plant_with_simple_v2_PID_Y.sens[0]
      };

      rtliSetLogYSignalPtrs(feedback_plant_with_simple_v2_PID_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        22
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        22
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "feedback_plant_with_simple_v2_PID/sens" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(feedback_plant_with_simple_v2_PID_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(feedback_plant_with_simple_v2_PID_M->rtwLogInfo, "yout");
  }

  feedback_plant_with_simple_v2_PID_M->solverInfoPtr =
    (&feedback_plant_with_simple_v2_PID_M->solverInfo);
  feedback_plant_with_simple_v2_PID_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&feedback_plant_with_simple_v2_PID_M->solverInfo, 0.01);
  rtsiSetSolverMode(&feedback_plant_with_simple_v2_PID_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  feedback_plant_with_simple_v2_PID_M->ModelData.blockIO = ((void *)
    &feedback_plant_with_simple_v2_PID_B);
  (void) memset(((void *) &feedback_plant_with_simple_v2_PID_B), 0,
                sizeof(B_feedback_plant_with_simple_v2_PID_T));

  /* states (continuous) */
  {
    real_T *x = (real_T *) &feedback_plant_with_simple_v2_PID_X;
    feedback_plant_with_simple_v2_PID_M->ModelData.contStates = (x);
    (void) memset((void *)&feedback_plant_with_simple_v2_PID_X, 0,
                  sizeof(X_feedback_plant_with_simple_v2_PID_T));
  }

  /* states (dwork) */
  feedback_plant_with_simple_v2_PID_M->ModelData.dwork = ((void *)
    &feedback_plant_with_simple_v2_PID_DW);
  (void) memset((void *)&feedback_plant_with_simple_v2_PID_DW, 0,
                sizeof(DW_feedback_plant_with_simple_v2_PID_T));

  /* external outputs */
  feedback_plant_with_simple_v2_PID_M->ModelData.outputs =
    (&feedback_plant_with_simple_v2_PID_Y);
  (void) memset(&feedback_plant_with_simple_v2_PID_Y.sens[0], 0,
                22U*sizeof(real_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  feedback_plant_with_simple_v2_PID_InitializeDataMapInfo
    (feedback_plant_with_simple_v2_PID_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.sfcnInfo;
    feedback_plant_with_simple_v2_PID_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (feedback_plant_with_simple_v2_PID_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &feedback_plant_with_simple_v2_PID_M->Sizes.numSampTimes);
    feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(feedback_plant_with_simple_v2_PID_M)[0]);
    feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(feedback_plant_with_simple_v2_PID_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(feedback_plant_with_simple_v2_PID_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(feedback_plant_with_simple_v2_PID_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (feedback_plant_with_simple_v2_PID_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &feedback_plant_with_simple_v2_PID_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (feedback_plant_with_simple_v2_PID_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &feedback_plant_with_simple_v2_PID_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &feedback_plant_with_simple_v2_PID_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &feedback_plant_with_simple_v2_PID_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &feedback_plant_with_simple_v2_PID_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &feedback_plant_with_simple_v2_PID_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &feedback_plant_with_simple_v2_PID_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &feedback_plant_with_simple_v2_PID_M->solverInfoPtr);
  }

  feedback_plant_with_simple_v2_PID_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  2*sizeof(SimStruct));
    feedback_plant_with_simple_v2_PID_M->childSfunctions =
      (&feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);
    feedback_plant_with_simple_v2_PID_M->childSfunctions[0] =
      (&feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.childSFunctions[0]);
    feedback_plant_with_simple_v2_PID_M->childSfunctions[1] =
      (&feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: feedback_plant_with_simple_v2_PID/<S13>/src (adnipcim) */
    {
      SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, feedback_plant_with_simple_v2_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 22);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o12));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o13));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o14));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o15));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o16));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 1);
          ssSetOutputPortSignal(rts, 16, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o17));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 1);
          ssSetOutputPortSignal(rts, 17, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o18));
        }

        /* port 18 */
        {
          _ssSetOutputPortNumDimensions(rts, 18, 1);
          ssSetOutputPortWidth(rts, 18, 1);
          ssSetOutputPortSignal(rts, 18, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o19));
        }

        /* port 19 */
        {
          _ssSetOutputPortNumDimensions(rts, 19, 1);
          ssSetOutputPortWidth(rts, 19, 1);
          ssSetOutputPortSignal(rts, 19, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o20));
        }

        /* port 20 */
        {
          _ssSetOutputPortNumDimensions(rts, 20, 1);
          ssSetOutputPortWidth(rts, 20, 1);
          ssSetOutputPortSignal(rts, 20, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o21));
        }

        /* port 21 */
        {
          _ssSetOutputPortNumDimensions(rts, 21, 1);
          ssSetOutputPortWidth(rts, 21, 1);
          ssSetOutputPortSignal(rts, 21, ((real_T *)
            &feedback_plant_with_simple_v2_PID_B.src_o22));
        }
      }

      /* path info */
      ssSetModelName(rts, "src");
      ssSetPath(rts, "feedback_plant_with_simple_v2_PID/analogdigital/src");
      ssSetRTModel(rts,feedback_plant_with_simple_v2_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.src_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.src_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.src_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.src_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled1);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled3);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled5);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &feedback_plant_with_simple_v2_PID_DW.src_IWORK
                 [0]);
      ssSetPWork(rts, (void **) &feedback_plant_with_simple_v2_PID_DW.src_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 41);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &feedback_plant_with_simple_v2_PID_DW.src_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &feedback_plant_with_simple_v2_PID_DW.src_PWORK);
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
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortConnected(rts, 10, 1);
      _ssSetOutputPortConnected(rts, 11, 1);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 1);
      _ssSetOutputPortConnected(rts, 14, 1);
      _ssSetOutputPortConnected(rts, 15, 1);
      _ssSetOutputPortConnected(rts, 16, 1);
      _ssSetOutputPortConnected(rts, 17, 1);
      _ssSetOutputPortConnected(rts, 18, 1);
      _ssSetOutputPortConnected(rts, 19, 1);
      _ssSetOutputPortConnected(rts, 20, 1);
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

    /* Level2 S-Function Block: feedback_plant_with_simple_v2_PID/<S12>/DA_sink (danipcim) */
    {
      SimStruct *rts = feedback_plant_with_simple_v2_PID_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, feedback_plant_with_simple_v2_PID_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &feedback_plant_with_simple_v2_PID_B.CV01_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &feedback_plant_with_simple_v2_PID_B.WP01_o;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &feedback_plant_with_simple_v2_PID_B.WP02_l;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &feedback_plant_with_simple_v2_PID_B.WP03_d;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DA_sink");
      ssSetPath(rts, "feedback_plant_with_simple_v2_PID/actuators/DA_sink");
      ssSetRTModel(rts,feedback_plant_with_simple_v2_PID_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.DA_sink_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled9);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.DA_sink_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled9);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled1);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled3);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       feedback_plant_with_simple_v2_PID_ConstP.pooled5);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &feedback_plant_with_simple_v2_PID_DW.DA_sink_RWORK[0]);
      ssSetIWork(rts, (int_T *)
                 &feedback_plant_with_simple_v2_PID_DW.DA_sink_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &feedback_plant_with_simple_v2_PID_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &feedback_plant_with_simple_v2_PID_DW.DA_sink_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &feedback_plant_with_simple_v2_PID_DW.DA_sink_IWORK[0]);
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
  }

  /* Initialize Sizes */
  feedback_plant_with_simple_v2_PID_M->Sizes.numContStates = (1);/* Number of continuous states */
  feedback_plant_with_simple_v2_PID_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  feedback_plant_with_simple_v2_PID_M->Sizes.numY = (22);/* Number of model outputs */
  feedback_plant_with_simple_v2_PID_M->Sizes.numU = (0);/* Number of model inputs */
  feedback_plant_with_simple_v2_PID_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  feedback_plant_with_simple_v2_PID_M->Sizes.numSampTimes = (2);/* Number of sample times */
  feedback_plant_with_simple_v2_PID_M->Sizes.numBlocks = (74);/* Number of blocks */
  feedback_plant_with_simple_v2_PID_M->Sizes.numBlockIO = (84);/* Number of block outputs */
  return feedback_plant_with_simple_v2_PID_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
