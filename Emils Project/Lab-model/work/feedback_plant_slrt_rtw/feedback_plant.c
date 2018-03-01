/*
 * feedback_plant.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "feedback_plant".
 *
 * Model version              : 1.348
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Sun Oct 16 17:14:45 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "feedback_plant_capi.h"
#include "feedback_plant.h"
#include "feedback_plant_private.h"

/* Block signals (auto storage) */
B_feedback_plant_T feedback_plant_B;

/* Continuous states */
X_feedback_plant_T feedback_plant_X;

/* Block states (auto storage) */
DW_feedback_plant_T feedback_plant_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_feedback_plant_T feedback_plant_Y;

/* Real-time model */
RT_MODEL_feedback_plant_T feedback_plant_M_;
RT_MODEL_feedback_plant_T *const feedback_plant_M = &feedback_plant_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  feedback_plant_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  feedback_plant_output();
  feedback_plant_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  feedback_plant_output();
  feedback_plant_derivatives();

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
void feedback_plant_output(void)
{
  real_T y[22];
  uint8_T test[124];
  boolean_T x[124];
  int32_T idx;
  int32_T b_ii;
  static const char_T f[17] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'H', 'I', 'G', 'H', ' ' };

  boolean_T exitg1;
  char_T test_0[124];
  int8_T matches[124];
  int32_T j;
  static const char_T e[15] = { ':', ' ', 'V', 'A', 'L', 'U', 'E', ' ', 'T', 'O',
    'O', ' ', 'L', 'O', 'W' };

  boolean_T c;
  real_T powerVector[3];
  real_T varargin_1[3];
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
  real_T y_idx_0;
  real_T y_idx_1;
  real_T y_idx_2;
  real_T y_idx_3;
  int32_T tmp;
  int8_T tmp_0;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* set solver stop time */
    if (!(feedback_plant_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&feedback_plant_M->solverInfo,
                            ((feedback_plant_M->Timing.clockTickH0 + 1) *
        feedback_plant_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&feedback_plant_M->solverInfo,
                            ((feedback_plant_M->Timing.clockTick0 + 1) *
        feedback_plant_M->Timing.stepSize0 +
        feedback_plant_M->Timing.clockTickH0 *
        feedback_plant_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(feedback_plant_M)) {
    feedback_plant_M->Timing.t[0] = rtsiGetT(&feedback_plant_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* Level2 S-Function Block: '<S10>/src' (adnipcim) */
    {
      SimStruct *rts = feedback_plant_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  MATLAB Function: '<S10>/transform'
     */
    feedback_plant_B.TmpSignalConversionAtSFunctionI[0] =
      feedback_plant_B.src_o1;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[1] =
      feedback_plant_B.src_o2;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[2] =
      feedback_plant_B.src_o3;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[3] =
      feedback_plant_B.src_o4;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[4] =
      feedback_plant_B.src_o5;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[5] =
      feedback_plant_B.src_o6;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[6] =
      feedback_plant_B.src_o7;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[7] =
      feedback_plant_B.src_o8;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[8] =
      feedback_plant_B.src_o9;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[9] =
      feedback_plant_B.src_o10;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[10] =
      feedback_plant_B.src_o11;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[11] =
      feedback_plant_B.src_o12;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[12] =
      feedback_plant_B.src_o13;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[13] =
      feedback_plant_B.src_o14;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[14] =
      feedback_plant_B.src_o15;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[15] =
      feedback_plant_B.src_o16;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[16] =
      feedback_plant_B.src_o17;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[17] =
      feedback_plant_B.src_o18;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[18] =
      feedback_plant_B.src_o19;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[19] =
      feedback_plant_B.src_o20;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[20] =
      feedback_plant_B.src_o21;
    feedback_plant_B.TmpSignalConversionAtSFunctionI[21] =
      feedback_plant_B.src_o22;

    /* MATLAB Function: '<S10>/transform' */
    /* MATLAB Function 'analogdigital/transform': '<S16>:1' */
    /* '<S16>:1:2' */
    for (i = 0; i < 22; i++) {
      y[i] = feedback_plant_B.TmpSignalConversionAtSFunctionI[i] *
        feedback_plant_ConstP.transform_gain[i] -
        feedback_plant_ConstP.transform_offset[i];
    }

    /* '<S16>:1:3' */
    feedback_plant_B.CV01 = y[0];

    /* '<S16>:1:4' */
    feedback_plant_B.DPT01 = y[1];

    /* '<S16>:1:5' */
    feedback_plant_B.LMGC1 = y[2];

    /* '<S16>:1:6' */
    feedback_plant_B.LMGP1 = y[3];

    /* '<S16>:1:7' */
    feedback_plant_B.LMGV1 = y[4];

    /* '<S16>:1:8' */
    feedback_plant_B.MFM01 = y[5];

    /* '<S16>:1:9' */
    feedback_plant_B.PT01 = y[6];

    /* '<S16>:1:10' */
    feedback_plant_B.WP01 = y[7];

    /* '<S16>:1:11' */
    feedback_plant_B.DPT02 = y[8];

    /* '<S16>:1:12' */
    feedback_plant_B.LMGC2 = y[9];

    /* '<S16>:1:13' */
    feedback_plant_B.LMGP2 = y[10];

    /* '<S16>:1:14' */
    feedback_plant_B.LMGV2 = y[11];

    /* '<S16>:1:15' */
    feedback_plant_B.MFM02 = y[12];

    /* '<S16>:1:16' */
    feedback_plant_B.PT02 = y[13];

    /* '<S16>:1:17' */
    feedback_plant_B.WP02 = y[14];

    /* '<S16>:1:18' */
    feedback_plant_B.DPT03 = y[15];

    /* '<S16>:1:19' */
    feedback_plant_B.LMGC3 = y[16];

    /* '<S16>:1:20' */
    feedback_plant_B.LMGP3 = y[17];

    /* '<S16>:1:21' */
    feedback_plant_B.LMGV3 = y[18];

    /* '<S16>:1:22' */
    feedback_plant_B.MFM03 = y[19];

    /* '<S16>:1:23' */
    feedback_plant_B.PT03 = y[20];

    /* '<S16>:1:24' */
    feedback_plant_B.WP03 = y[21];

    /* Outport: '<Root>/sens' */
    feedback_plant_Y.sens[0] = feedback_plant_B.CV01;
    feedback_plant_Y.sens[1] = feedback_plant_B.DPT01;
    feedback_plant_Y.sens[2] = feedback_plant_B.LMGC1;
    feedback_plant_Y.sens[3] = feedback_plant_B.LMGP1;
    feedback_plant_Y.sens[4] = feedback_plant_B.LMGV1;
    feedback_plant_Y.sens[5] = feedback_plant_B.MFM01;
    feedback_plant_Y.sens[6] = feedback_plant_B.PT01;
    feedback_plant_Y.sens[7] = feedback_plant_B.WP01;
    feedback_plant_Y.sens[8] = feedback_plant_B.DPT02;
    feedback_plant_Y.sens[9] = feedback_plant_B.LMGC2;
    feedback_plant_Y.sens[10] = feedback_plant_B.LMGP2;
    feedback_plant_Y.sens[11] = feedback_plant_B.LMGV2;
    feedback_plant_Y.sens[12] = feedback_plant_B.MFM02;
    feedback_plant_Y.sens[13] = feedback_plant_B.PT02;
    feedback_plant_Y.sens[14] = feedback_plant_B.WP02;
    feedback_plant_Y.sens[15] = feedback_plant_B.DPT03;
    feedback_plant_Y.sens[16] = feedback_plant_B.LMGC3;
    feedback_plant_Y.sens[17] = feedback_plant_B.LMGP3;
    feedback_plant_Y.sens[18] = feedback_plant_B.LMGV3;
    feedback_plant_Y.sens[19] = feedback_plant_B.MFM03;
    feedback_plant_Y.sens[20] = feedback_plant_B.PT03;
    feedback_plant_Y.sens[21] = feedback_plant_B.WP03;
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T t = feedback_plant_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_DW.FromWorkspace1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_DW.FromWorkspace1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_B.FromWorkspace1 = 0.0;
    } else if (t >= pTimeValues[20]) {
      feedback_plant_B.FromWorkspace1 = pDataValues[20];
    } else {
      int_T currTimeIndex = feedback_plant_DW.FromWorkspace1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_B.FromWorkspace1 = pDataValues[currTimeIndex];
      feedback_plant_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T t = feedback_plant_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_DW.FromWorkspace_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_B.FromWorkspace = 0.0;
    } else if (t >= pTimeValues[482]) {
      feedback_plant_B.FromWorkspace = pDataValues[482];
    } else {
      int_T currTimeIndex = feedback_plant_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_B.FromWorkspace = pDataValues[currTimeIndex];
      feedback_plant_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T t = feedback_plant_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_DW.FromWorkspace2_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_DW.FromWorkspace2_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_B.FromWorkspace2 = 0.0;
    } else if (t >= pTimeValues[482]) {
      feedback_plant_B.FromWorkspace2 = pDataValues[482];
    } else {
      int_T currTimeIndex = feedback_plant_DW.FromWorkspace2_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_B.FromWorkspace2 = pDataValues[currTimeIndex];
      feedback_plant_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* FromWorkspace: '<Root>/From Workspace3' */
  {
    real_T t = feedback_plant_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      feedback_plant_DW.FromWorkspace3_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      feedback_plant_DW.FromWorkspace3_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      feedback_plant_B.FromWorkspace3 = 0.0;
    } else if (t >= pTimeValues[482]) {
      feedback_plant_B.FromWorkspace3 = pDataValues[482];
    } else {
      int_T currTimeIndex = feedback_plant_DW.FromWorkspace3_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      feedback_plant_B.FromWorkspace3 = pDataValues[currTimeIndex];
      feedback_plant_DW.FromWorkspace3_IWORK.PrevIndex = currTimeIndex;
    }
  }

  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* ok to acquire for <S2>/S-Function */
    feedback_plant_DW.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S3>/S-Function */
    feedback_plant_DW.SFunction_IWORK_l.AcquireOK = 1;
  }

  /* ok to acquire for <S4>/S-Function */
  feedback_plant_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* ok to acquire for <S5>/S-Function */
  feedback_plant_DW.SFunction_IWORK_o.AcquireOK = 1;

  /* ok to acquire for <S6>/S-Function */
  feedback_plant_DW.SFunction_IWORK_n.AcquireOK = 1;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* ok to acquire for <S7>/S-Function */
    feedback_plant_DW.SFunction_IWORK_g.AcquireOK = 1;

    /* ok to acquire for <S8>/S-Function */
    feedback_plant_DW.SFunction_IWORK_l4.AcquireOK = 1;
  }

  /* Gain: '<Root>/Gain4' */
  feedback_plant_B.Gain4 = 1.0 * feedback_plant_B.FromWorkspace1;

  /* Gain: '<Root>/Gain2' */
  feedback_plant_B.Gain2 = 1.0 * feedback_plant_B.FromWorkspace;

  /* Gain: '<Root>/Gain' */
  feedback_plant_B.Gain = 1.0 * feedback_plant_B.FromWorkspace2;

  /* Gain: '<Root>/Gain1' */
  feedback_plant_B.Gain1 = 1.0 * feedback_plant_B.FromWorkspace3;

  /* SignalConversion: '<S15>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S9>/transform'
   */
  feedback_plant_B.TmpSignalConversionAtSFunctio_d[0] = feedback_plant_B.Gain4;
  feedback_plant_B.TmpSignalConversionAtSFunctio_d[1] = feedback_plant_B.Gain2;
  feedback_plant_B.TmpSignalConversionAtSFunctio_d[2] = feedback_plant_B.Gain;
  feedback_plant_B.TmpSignalConversionAtSFunctio_d[3] = feedback_plant_B.Gain1;

  /* MATLAB Function: '<S9>/transform' incorporates:
   *  Constant: '<S9>/gain'
   *  Constant: '<S9>/offset'
   */
  /* MATLAB Function 'actuators/transform': '<S15>:1' */
  /* '<S15>:1:2' */
  y_idx_0 = feedback_plant_B.TmpSignalConversionAtSFunctio_d[0] * 10.0 - (-0.0);
  y_idx_1 = feedback_plant_B.TmpSignalConversionAtSFunctio_d[1] * 10.0 - (-0.0);
  y_idx_2 = feedback_plant_B.TmpSignalConversionAtSFunctio_d[2] * 10.0 - (-0.0);
  y_idx_3 = feedback_plant_B.TmpSignalConversionAtSFunctio_d[3] * 10.0 - (-0.0);

  /* '<S15>:1:3' */
  feedback_plant_B.CV01_j = y_idx_0;

  /* '<S15>:1:4' */
  feedback_plant_B.WP01_o = y_idx_1;

  /* '<S15>:1:5' */
  feedback_plant_B.WP02_l = y_idx_2;

  /* '<S15>:1:6' */
  feedback_plant_B.WP03_d = y_idx_3;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* Level2 S-Function Block: '<S9>/DA_sink' (danipcim) */
    {
      SimStruct *rts = feedback_plant_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* RelationalOperator: '<S23>/max_relop' incorporates:
     *  Constant: '<S23>/max_val'
     */
    feedback_plant_B.max_relop[0] = (feedback_plant_B.CV01 <= 1050.05);
    feedback_plant_B.max_relop[1] = (feedback_plant_B.DPT01 <= 1050.05);
    feedback_plant_B.max_relop[2] = (feedback_plant_B.LMGC1 <= 1050.05);
    feedback_plant_B.max_relop[3] = (feedback_plant_B.LMGP1 <= 4200.05);
    feedback_plant_B.max_relop[4] = (feedback_plant_B.LMGV1 <= 1050.05);
    feedback_plant_B.max_relop[5] = (feedback_plant_B.MFM01 <= 1050.05);
    feedback_plant_B.max_relop[6] = (feedback_plant_B.PT01 <= 1050.05);
    feedback_plant_B.max_relop[7] = (feedback_plant_B.WP01 <= 4200.05);
    feedback_plant_B.max_relop[8] = (feedback_plant_B.DPT02 <= 1050.05);
    feedback_plant_B.max_relop[9] = (feedback_plant_B.LMGC2 <= 1050.05);
    feedback_plant_B.max_relop[10] = (feedback_plant_B.LMGP2 <= 4200.05);
    feedback_plant_B.max_relop[11] = (feedback_plant_B.LMGV2 <= 1050.05);
    feedback_plant_B.max_relop[12] = (feedback_plant_B.MFM02 <= 1050.05);
    feedback_plant_B.max_relop[13] = (feedback_plant_B.PT02 <= 1050.05);
    feedback_plant_B.max_relop[14] = (feedback_plant_B.WP02 <= 4200.05);
    feedback_plant_B.max_relop[15] = (feedback_plant_B.DPT03 <= 1050.05);
    feedback_plant_B.max_relop[16] = (feedback_plant_B.LMGC3 <= 1050.05);
    feedback_plant_B.max_relop[17] = (feedback_plant_B.LMGP3 <= 4200.05);
    feedback_plant_B.max_relop[18] = (feedback_plant_B.LMGV3 <= 1050.05);
    feedback_plant_B.max_relop[19] = (feedback_plant_B.MFM03 <= 1050.05);
    feedback_plant_B.max_relop[20] = (feedback_plant_B.PT03 <= 1050.05);
    feedback_plant_B.max_relop[21] = (feedback_plant_B.WP03 <= 4200.05);

    /* MATLAB Function: '<S13>/err_high' incorporates:
     *  Constant: '<S13>/sname'
     */
    /* MATLAB Function 'terminating_safety/err_high': '<S24>:1' */
    /* '<S24>:1:13' */
    /* '<S24>:1:12' */
    /* test = char(sensnames.'); */
    /* '<S24>:1:4' */
    /* '<S24>:1:5' */
    for (i = 0; i < 124; i++) {
      test[i] = feedback_plant_ConstP.sname_Value[i];
      x[i] = (feedback_plant_ConstP.sname_Value[i] == 47);
    }

    idx = 0;
    b_ii = 1;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 125)) {
      c = false;
      if (x[b_ii - 1]) {
        idx++;
        ii_data[idx - 1] = (int8_T)b_ii;
        if (idx >= 124) {
          exitg1 = true;
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

    /* '<S24>:1:6' */
    /* '<S24>:1:7' */
    k_data[0] = 0;
    for (i = 0; i < idx; i++) {
      k_data[i + 1] = ii_data[i];
    }

    k_data[1 + idx] = 124;

    /* '<S24>:1:8' */
    y_idx_0 = 0.0;

    /* '<S24>:1:9' */
    for (idx = 0; idx < 22; idx++) {
      /* '<S24>:1:9' */
      if (!feedback_plant_B.max_relop[idx]) {
        /* '<S24>:1:10' */
        if (k_data[idx] + 1 > k_data[1 + idx] - 1) {
          b_ii = 1;
          j = 1;
        } else {
          b_ii = k_data[idx] + 1;
          j = k_data[1 + idx];
        }

        /* '<S24>:1:11' */
        /* '<S24>:1:12' */
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

        /* '<S24>:1:14' */
        y_idx_0++;
      }

      /* '<S24>:1:9' */
    }

    feedback_plant_B.stop_a = y_idx_0;

    /* End of MATLAB Function: '<S13>/err_high' */

    /* Stop: '<S13>/stop' */
    if (feedback_plant_B.stop_a != 0.0) {
      rtmSetStopRequested(feedback_plant_M, 1);
    }

    /* End of Stop: '<S13>/stop' */

    /* RelationalOperator: '<S22>/min_relop' incorporates:
     *  Constant: '<S22>/min_val'
     */
    feedback_plant_B.min_relop[0] = ((-51.050000000000004) <=
      feedback_plant_B.CV01);
    feedback_plant_B.min_relop[1] = ((-51.050000000000004) <=
      feedback_plant_B.DPT01);
    feedback_plant_B.min_relop[2] = ((-51.050000000000004) <=
      feedback_plant_B.LMGC1);
    feedback_plant_B.min_relop[3] = ((-201.05) <= feedback_plant_B.LMGP1);
    feedback_plant_B.min_relop[4] = ((-51.050000000000004) <=
      feedback_plant_B.LMGV1);
    feedback_plant_B.min_relop[5] = ((-51.050000000000004) <=
      feedback_plant_B.MFM01);
    feedback_plant_B.min_relop[6] = ((-51.050000000000004) <=
      feedback_plant_B.PT01);
    feedback_plant_B.min_relop[7] = ((-201.05) <= feedback_plant_B.WP01);
    feedback_plant_B.min_relop[8] = ((-51.050000000000004) <=
      feedback_plant_B.DPT02);
    feedback_plant_B.min_relop[9] = ((-51.050000000000004) <=
      feedback_plant_B.LMGC2);
    feedback_plant_B.min_relop[10] = ((-201.05) <= feedback_plant_B.LMGP2);
    feedback_plant_B.min_relop[11] = ((-51.050000000000004) <=
      feedback_plant_B.LMGV2);
    feedback_plant_B.min_relop[12] = ((-51.050000000000004) <=
      feedback_plant_B.MFM02);
    feedback_plant_B.min_relop[13] = ((-51.050000000000004) <=
      feedback_plant_B.PT02);
    feedback_plant_B.min_relop[14] = ((-201.05) <= feedback_plant_B.WP02);
    feedback_plant_B.min_relop[15] = ((-51.050000000000004) <=
      feedback_plant_B.DPT03);
    feedback_plant_B.min_relop[16] = ((-51.050000000000004) <=
      feedback_plant_B.LMGC3);
    feedback_plant_B.min_relop[17] = ((-201.05) <= feedback_plant_B.LMGP3);
    feedback_plant_B.min_relop[18] = ((-51.050000000000004) <=
      feedback_plant_B.LMGV3);
    feedback_plant_B.min_relop[19] = ((-51.050000000000004) <=
      feedback_plant_B.MFM03);
    feedback_plant_B.min_relop[20] = ((-51.050000000000004) <=
      feedback_plant_B.PT03);
    feedback_plant_B.min_relop[21] = ((-201.05) <= feedback_plant_B.WP03);

    /* MATLAB Function: '<S13>/err_low' incorporates:
     *  Constant: '<S13>/sname'
     */
    /* MATLAB Function 'terminating_safety/err_low': '<S25>:1' */
    /* '<S25>:1:12' */
    /* '<S25>:1:11' */
    /* '<S25>:1:3' */
    /* '<S25>:1:4' */
    idx = 0;
    for (b_ii = 0; b_ii < 124; b_ii++) {
      test_0[b_ii] = (int8_T)feedback_plant_ConstP.sname_Value[b_ii];
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

    /* '<S25>:1:5' */
    /* '<S25>:1:6' */
    k_data_0[0] = 0;
    for (i = 0; i < idx; i++) {
      k_data_0[i + 1] = ii_data[i];
    }

    k_data_0[1 + idx] = 124;

    /* '<S25>:1:7' */
    y_idx_0 = 0.0;

    /* '<S25>:1:8' */
    for (idx = 0; idx < 22; idx++) {
      /* '<S25>:1:8' */
      if (!feedback_plant_B.min_relop[idx]) {
        /* '<S25>:1:9' */
        if (k_data_0[idx] + 1 > k_data_0[1 + idx] - 1) {
          b_ii = 1;
          j = 0;
        } else {
          b_ii = k_data_0[idx] + 1;
          j = k_data_0[1 + idx] - 1;
        }

        /* '<S25>:1:10' */
        /* '<S25>:1:11' */
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

        /* '<S25>:1:13' */
        y_idx_0++;
      }

      /* '<S25>:1:8' */
    }

    feedback_plant_B.stop = y_idx_0;

    /* End of MATLAB Function: '<S13>/err_low' */

    /* Stop: '<S13>/stop1' */
    idx = 1;
    if (feedback_plant_B.stop != 0.0) {
      rtmSetStopRequested(feedback_plant_M, 1);
    }

    /* End of Stop: '<S13>/stop1' */
    for (i = 0; i < 22; i++) {
      /* Assertion: '<S22>/Assertion' */
      utAssert(feedback_plant_B.min_relop[i]);
    }

    for (i = 0; i < 22; i++) {
      /* Assertion: '<S23>/Assertion' */
      utAssert(feedback_plant_B.max_relop[i]);
    }

    /* ok to acquire for <S26>/S-Function */
    feedback_plant_DW.SFunction_IWORK_go.AcquireOK = 1;

    /* Gain: '<Root>/Gain3' */
    feedback_plant_B.Gain3 = 10.0 * feedback_plant_B.PT02;

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    /* '<S1>:1:3' */
    feedback_plant_B.Q_tot = ((feedback_plant_B.MFM01 + feedback_plant_B.MFM02)
      + feedback_plant_B.MFM03) * 60.0 * 60.0 / 1000.0;

    /* Saturate: '<Root>/Saturation5' */
    y_idx_0 = feedback_plant_B.Gain3;
    y_idx_1 = 0.001;
    y_idx_2 = 200.0;
    if (y_idx_0 > y_idx_2) {
      feedback_plant_B.Saturation5 = y_idx_2;
    } else if (y_idx_0 < y_idx_1) {
      feedback_plant_B.Saturation5 = y_idx_1;
    } else {
      feedback_plant_B.Saturation5 = y_idx_0;
    }

    /* End of Saturate: '<Root>/Saturation5' */

    /* Product: '<S11>/Divide' incorporates:
     *  Constant: '<S11>/Constant'
     */
    feedback_plant_B.Divide = feedback_plant_B.Q_tot / 1.0;

    /* Saturate: '<S11>/Saturation3' */
    y_idx_0 = feedback_plant_B.Divide;
    y_idx_1 = 0.0;
    y_idx_2 = 15.0;
    if (y_idx_0 > y_idx_2) {
      feedback_plant_B.Saturation3 = y_idx_2;
    } else if (y_idx_0 < y_idx_1) {
      feedback_plant_B.Saturation3 = y_idx_1;
    } else {
      feedback_plant_B.Saturation3 = y_idx_0;
    }

    /* End of Saturate: '<S11>/Saturation3' */

    /* MATLAB Function: '<S11>/cost_power_1' */
    /* MATLAB Function 'best_mode_control/cost_power_1': '<S17>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     14-Oct-2016 11:25:59 */
    /* '<S17>:1:7' */
    y_idx_0 = feedback_plant_B.Saturation5 * feedback_plant_B.Saturation5;

    /* '<S17>:1:8' */
    y_idx_1 = feedback_plant_B.Saturation3 * feedback_plant_B.Saturation3;

    /* '<S17>:1:9' */
    /* '<S17>:1:10' */
    /* '<S17>:1:11' */
    /* '<S17>:1:12' */
    /* '<S17>:1:13' */
    /* '<S17>:1:14' */
    /* '<S17>:1:15' */
    /* '<S17>:1:16' */
    /* '<S17>:1:17' */
    /* '<S17>:1:18' */
    /* '<S17>:1:20' */
    y_idx_0 = ((((((((feedback_plant_B.Saturation5 * 139.69038520365149 +
                      feedback_plant_B.Saturation3 * 34.952252506986163) +
                     feedback_plant_B.Saturation5 * y_idx_1 * 0.1223287779152999)
                    + feedback_plant_B.Saturation3 * y_idx_0 * 0.166325485327369)
                   + feedback_plant_B.Saturation5 * y_idx_0 *
                   0.022266024029947949) + y_idx_1 * 37.70314092453583) -
                 y_idx_0 * 2.5749360250113) - feedback_plant_B.Saturation3 *
                y_idx_1 * 1.742768641280902) - feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation3 * 11.245585477718819) +
      547.30128237731378;
    if (rtIsNaN(y_idx_0)) {
      idx = 2;
      y_idx_0 = 0.0;
    }

    if ((idx < 2) && (0.0 > y_idx_0)) {
      y_idx_0 = 0.0;
    }

    /* '<S17>:1:21' */
    /* '<S17>:1:22' */
    /* '<S17>:1:23' */
    /* '<S17>:1:24' */
    /* '<S17>:1:25' */
    /* '<S17>:1:26' */
    y_idx_1 = ((rt_powd_snf(feedback_plant_B.Saturation5, 1.3862967117730409) *
                2.358991511181789 + rt_powd_snf(feedback_plant_B.Saturation3,
      2.7765198614951019) * 1.3177011886254071) + feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation3 * 2.7732491787879119) +
      27.254204415824969;
    if ((y_idx_0 < 360.0) || (1800.0 < y_idx_1) || (3600.0 < y_idx_0)) {
      /* '<S17>:1:27' */
      exitg1 = true;
    } else {
      /* '<S17>:1:27' */
      exitg1 = false;
    }

    if ((360.0 <= y_idx_0) && (y_idx_1 <= 1800.0) && (y_idx_0 <= 3600.0)) {
      /* '<S17>:1:27' */
      c = true;
    } else {
      /* '<S17>:1:27' */
      c = false;
    }

    /* '<S17>:1:27' */
    feedback_plant_B.cost_power_1_w_sat_i = (real_T)exitg1 * 50000.0 + y_idx_1 *
      (real_T)c;

    /* End of MATLAB Function: '<S11>/cost_power_1' */

    /* Product: '<S11>/Divide5' incorporates:
     *  Constant: '<S11>/Constant'
     */
    feedback_plant_B.Divide5 = feedback_plant_B.cost_power_1_w_sat_i * 1.0;

    /* Product: '<S11>/Divide1' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    feedback_plant_B.Divide1 = feedback_plant_B.Q_tot / 2.0;

    /* Saturate: '<S11>/Saturation4' */
    y_idx_0 = feedback_plant_B.Divide1;
    y_idx_1 = 0.0;
    y_idx_2 = 15.0;
    if (y_idx_0 > y_idx_2) {
      feedback_plant_B.Saturation4 = y_idx_2;
    } else if (y_idx_0 < y_idx_1) {
      feedback_plant_B.Saturation4 = y_idx_1;
    } else {
      feedback_plant_B.Saturation4 = y_idx_0;
    }

    /* End of Saturate: '<S11>/Saturation4' */

    /* MATLAB Function: '<S11>/cost_power_2' */
    /* MATLAB Function 'best_mode_control/cost_power_2': '<S18>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     14-Oct-2016 11:25:59 */
    /* '<S18>:1:7' */
    y_idx_0 = feedback_plant_B.Saturation5 * feedback_plant_B.Saturation5;

    /* '<S18>:1:8' */
    y_idx_1 = feedback_plant_B.Saturation4 * feedback_plant_B.Saturation4;

    /* '<S18>:1:9' */
    /* '<S18>:1:10' */
    /* '<S18>:1:11' */
    /* '<S18>:1:12' */
    /* '<S18>:1:13' */
    /* '<S18>:1:14' */
    /* '<S18>:1:15' */
    /* '<S18>:1:16' */
    /* '<S18>:1:17' */
    /* '<S18>:1:18' */
    /* '<S18>:1:20' */
    y_idx_0 = ((((((((feedback_plant_B.Saturation5 * 139.69038520365149 +
                      feedback_plant_B.Saturation4 * 34.952252506986163) +
                     feedback_plant_B.Saturation5 * y_idx_1 * 0.1223287779152999)
                    + feedback_plant_B.Saturation4 * y_idx_0 * 0.166325485327369)
                   + feedback_plant_B.Saturation5 * y_idx_0 *
                   0.022266024029947949) + y_idx_1 * 37.70314092453583) -
                 y_idx_0 * 2.5749360250113) - feedback_plant_B.Saturation4 *
                y_idx_1 * 1.742768641280902) - feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation4 * 11.245585477718819) +
      547.30128237731378;
    idx = 1;
    if (rtIsNaN(y_idx_0)) {
      idx = 2;
      y_idx_0 = 0.0;
    }

    if ((idx < 2) && (0.0 > y_idx_0)) {
      y_idx_0 = 0.0;
    }

    /* '<S18>:1:21' */
    /* '<S18>:1:22' */
    /* '<S18>:1:23' */
    /* '<S18>:1:24' */
    /* '<S18>:1:25' */
    /* '<S18>:1:26' */
    y_idx_1 = ((rt_powd_snf(feedback_plant_B.Saturation5, 1.3862967117730409) *
                2.358991511181789 + rt_powd_snf(feedback_plant_B.Saturation4,
      2.7765198614951019) * 1.3177011886254071) + feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation4 * 2.7732491787879119) +
      27.254204415824969;
    if ((y_idx_0 < 360.0) || (1800.0 < y_idx_1) || (3600.0 < y_idx_0)) {
      /* '<S18>:1:27' */
      exitg1 = true;
    } else {
      /* '<S18>:1:27' */
      exitg1 = false;
    }

    if ((360.0 <= y_idx_0) && (y_idx_1 <= 1800.0) && (y_idx_0 <= 3600.0)) {
      /* '<S18>:1:27' */
      c = true;
    } else {
      /* '<S18>:1:27' */
      c = false;
    }

    /* '<S18>:1:27' */
    feedback_plant_B.cost_power_1_w_sat_p = (real_T)exitg1 * 50000.0 + y_idx_1 *
      (real_T)c;

    /* End of MATLAB Function: '<S11>/cost_power_2' */

    /* Product: '<S11>/Divide4' incorporates:
     *  Constant: '<S11>/Constant1'
     */
    feedback_plant_B.Divide4 = feedback_plant_B.cost_power_1_w_sat_p * 2.0;

    /* Product: '<S11>/Divide2' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    feedback_plant_B.Divide2 = feedback_plant_B.Q_tot / 3.0;

    /* Saturate: '<S11>/Saturation5' */
    y_idx_0 = feedback_plant_B.Divide2;
    y_idx_1 = 0.0;
    y_idx_2 = 15.0;
    if (y_idx_0 > y_idx_2) {
      feedback_plant_B.Saturation5_g = y_idx_2;
    } else if (y_idx_0 < y_idx_1) {
      feedback_plant_B.Saturation5_g = y_idx_1;
    } else {
      feedback_plant_B.Saturation5_g = y_idx_0;
    }

    /* End of Saturate: '<S11>/Saturation5' */

    /* MATLAB Function: '<S11>/cost_power_3' */
    /* MATLAB Function 'best_mode_control/cost_power_3': '<S19>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     14-Oct-2016 11:25:59 */
    /* '<S19>:1:7' */
    y_idx_0 = feedback_plant_B.Saturation5 * feedback_plant_B.Saturation5;

    /* '<S19>:1:8' */
    y_idx_1 = feedback_plant_B.Saturation5_g * feedback_plant_B.Saturation5_g;

    /* '<S19>:1:9' */
    /* '<S19>:1:10' */
    /* '<S19>:1:11' */
    /* '<S19>:1:12' */
    /* '<S19>:1:13' */
    /* '<S19>:1:14' */
    /* '<S19>:1:15' */
    /* '<S19>:1:16' */
    /* '<S19>:1:17' */
    /* '<S19>:1:18' */
    /* '<S19>:1:20' */
    y_idx_0 = ((((((((feedback_plant_B.Saturation5 * 139.69038520365149 +
                      feedback_plant_B.Saturation5_g * 34.952252506986163) +
                     feedback_plant_B.Saturation5 * y_idx_1 * 0.1223287779152999)
                    + feedback_plant_B.Saturation5_g * y_idx_0 *
                    0.166325485327369) + feedback_plant_B.Saturation5 * y_idx_0 *
                   0.022266024029947949) + y_idx_1 * 37.70314092453583) -
                 y_idx_0 * 2.5749360250113) - feedback_plant_B.Saturation5_g *
                y_idx_1 * 1.742768641280902) - feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation5_g * 11.245585477718819) +
      547.30128237731378;
    idx = 1;
    if (rtIsNaN(y_idx_0)) {
      idx = 2;
      y_idx_0 = 0.0;
    }

    if ((idx < 2) && (0.0 > y_idx_0)) {
      y_idx_0 = 0.0;
    }

    /* '<S19>:1:21' */
    /* '<S19>:1:22' */
    /* '<S19>:1:23' */
    /* '<S19>:1:24' */
    /* '<S19>:1:25' */
    /* '<S19>:1:26' */
    y_idx_1 = ((rt_powd_snf(feedback_plant_B.Saturation5, 1.3862967117730409) *
                2.358991511181789 + rt_powd_snf(feedback_plant_B.Saturation5_g,
      2.7765198614951019) * 1.3177011886254071) + feedback_plant_B.Saturation5 *
               feedback_plant_B.Saturation5_g * 2.7732491787879119) +
      27.254204415824969;
    if ((y_idx_0 < 360.0) || (1800.0 < y_idx_1) || (3600.0 < y_idx_0)) {
      /* '<S19>:1:27' */
      exitg1 = true;
    } else {
      /* '<S19>:1:27' */
      exitg1 = false;
    }

    if ((360.0 <= y_idx_0) && (y_idx_1 <= 1800.0) && (y_idx_0 <= 3600.0)) {
      /* '<S19>:1:27' */
      c = true;
    } else {
      /* '<S19>:1:27' */
      c = false;
    }

    /* '<S19>:1:27' */
    feedback_plant_B.cost_power_1_w_sat = (real_T)exitg1 * 50000.0 + y_idx_1 *
      (real_T)c;

    /* End of MATLAB Function: '<S11>/cost_power_3' */

    /* Product: '<S11>/Divide3' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    feedback_plant_B.Divide3 = feedback_plant_B.cost_power_1_w_sat * 3.0;
  }

  /* Integrator: '<S11>/Integrator' */
  feedback_plant_B.Integrator = feedback_plant_X.Integrator_CSTATE;

  /* Saturate: '<S11>/Saturation2' */
  y_idx_0 = feedback_plant_B.Integrator;
  y_idx_1 = (-200.0);
  y_idx_2 = 200.0;
  if (y_idx_0 > y_idx_2) {
    feedback_plant_B.p1 = y_idx_2;
  } else if (y_idx_0 < y_idx_1) {
    feedback_plant_B.p1 = y_idx_1;
  } else {
    feedback_plant_B.p1 = y_idx_0;
  }

  /* End of Saturate: '<S11>/Saturation2' */

  /* Sum: '<S11>/Sum5' */
  feedback_plant_B.Sum5 = feedback_plant_B.Integrator - feedback_plant_B.p1;

  /* Gain: '<S11>/Gain' */
  feedback_plant_B.Gain_g = 50.0 * feedback_plant_B.Sum5;

  /* Integrator: '<S11>/Integrator2' */
  feedback_plant_B.Integrator2 = feedback_plant_X.Integrator2_CSTATE;

  /* Saturate: '<S11>/Saturation' */
  y_idx_0 = feedback_plant_B.Integrator2;
  y_idx_1 = (-200.0);
  y_idx_2 = 200.0;
  if (y_idx_0 > y_idx_2) {
    feedback_plant_B.p3 = y_idx_2;
  } else if (y_idx_0 < y_idx_1) {
    feedback_plant_B.p3 = y_idx_1;
  } else {
    feedback_plant_B.p3 = y_idx_0;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Sum: '<S11>/Sum3' */
  feedback_plant_B.Sum3 = feedback_plant_B.Integrator2 - feedback_plant_B.p3;

  /* Gain: '<S11>/Gain1' */
  feedback_plant_B.Gain1_m = 50.0 * feedback_plant_B.Sum3;

  /* Integrator: '<S11>/Integrator1' */
  feedback_plant_B.Integrator1 = feedback_plant_X.Integrator1_CSTATE;

  /* Saturate: '<S11>/Saturation1' */
  y_idx_0 = feedback_plant_B.Integrator1;
  y_idx_1 = (-200.0);
  y_idx_2 = 200.0;
  if (y_idx_0 > y_idx_2) {
    feedback_plant_B.p2 = y_idx_2;
  } else if (y_idx_0 < y_idx_1) {
    feedback_plant_B.p2 = y_idx_1;
  } else {
    feedback_plant_B.p2 = y_idx_0;
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* Sum: '<S11>/Sum4' */
  feedback_plant_B.Sum4 = feedback_plant_B.Integrator1 - feedback_plant_B.p2;

  /* Gain: '<S11>/Gain3' */
  feedback_plant_B.Gain3_m = 50.0 * feedback_plant_B.Sum4;
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* MATLAB Function: '<S11>/test ' */
    /* MATLAB Function 'best_mode_control/test ': '<S20>:1' */
    /* '<S20>:1:2' */
    y_idx_0 = feedback_plant_B.Divide4;
    y_idx_1 = feedback_plant_B.Divide3;
    if ((y_idx_0 <= y_idx_1) || rtIsNaN(y_idx_1)) {
      y_idx_1 = y_idx_0;
    }

    feedback_plant_B.sumP1 = y_idx_1 - feedback_plant_B.Divide5;

    /* '<S20>:1:3' */
    y_idx_0 = feedback_plant_B.Divide5;
    y_idx_1 = feedback_plant_B.Divide3;
    if ((y_idx_0 <= y_idx_1) || rtIsNaN(y_idx_1)) {
      y_idx_1 = y_idx_0;
    }

    feedback_plant_B.sumP2 = y_idx_1 - feedback_plant_B.Divide4;

    /* '<S20>:1:4' */
    y_idx_0 = feedback_plant_B.Divide5;
    y_idx_1 = feedback_plant_B.Divide4;
    if ((y_idx_0 <= y_idx_1) || rtIsNaN(y_idx_1)) {
      y_idx_1 = y_idx_0;
    }

    feedback_plant_B.sumP3 = y_idx_1 - feedback_plant_B.Divide3;

    /* End of MATLAB Function: '<S11>/test ' */

    /* UnitDelay: '<S11>/Unit Delay' */
    feedback_plant_B.UnitDelay = feedback_plant_DW.UnitDelay_DSTATE;
  }

  /* Sum: '<S11>/Sum' */
  feedback_plant_B.Sum = feedback_plant_B.sumP1 - feedback_plant_B.Gain_g;

  /* Sum: '<S11>/Sum1' */
  feedback_plant_B.Sum1 = feedback_plant_B.sumP2 - feedback_plant_B.Gain3_m;

  /* Sum: '<S11>/Sum2' */
  feedback_plant_B.Sum2 = feedback_plant_B.sumP3 - feedback_plant_B.Gain1_m;

  /* MATLAB Function: '<S11>/test 1' */
  /* MATLAB Function 'best_mode_control/test 1': '<S21>:1' */
  /* '<S21>:1:2' */
  powerVector[0] = feedback_plant_B.p1;
  powerVector[1] = feedback_plant_B.p2;
  powerVector[2] = feedback_plant_B.p3;

  /* '<S21>:1:3' */
  varargin_1[0] = feedback_plant_B.p1;
  varargin_1[1] = feedback_plant_B.p2;
  varargin_1[2] = feedback_plant_B.p3;
  idx = 1;
  y_idx_0 = varargin_1[0];
  j = 1;
  if (rtIsNaN(varargin_1[0])) {
    b_ii = 2;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 4)) {
      idx = b_ii;
      if (!rtIsNaN(varargin_1[b_ii - 1])) {
        y_idx_0 = varargin_1[b_ii - 1];
        j = b_ii;
        exitg1 = true;
      } else {
        b_ii++;
      }
    }
  }

  if (idx < 3) {
    while (idx + 1 < 4) {
      if (varargin_1[idx] > y_idx_0) {
        y_idx_0 = varargin_1[idx];
        j = idx + 1;
      }

      idx++;
    }
  }

  if (j == feedback_plant_B.UnitDelay) {
    /* '<S21>:1:4' */
    /* '<S21>:1:5' */
    feedback_plant_B.y = j;
  } else if (fabs(powerVector[j - 1] - powerVector[(int32_T)
                  feedback_plant_B.UnitDelay - 1]) > 10.0) {
    /* '<S21>:1:7' */
    /* '<S21>:1:8' */
    feedback_plant_B.y = j;
  } else {
    /* '<S21>:1:10' */
    feedback_plant_B.y = feedback_plant_B.UnitDelay;
  }

  /* End of MATLAB Function: '<S11>/test 1' */
}

/* Model update function */
void feedback_plant_update(void)
{
  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    /* Update for UnitDelay: '<S11>/Unit Delay' */
    feedback_plant_DW.UnitDelay_DSTATE = feedback_plant_B.y;
  }

  if (rtmIsMajorTimeStep(feedback_plant_M)) {
    rt_ertODEUpdateContinuousStates(&feedback_plant_M->solverInfo);
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
  if (!(++feedback_plant_M->Timing.clockTick0)) {
    ++feedback_plant_M->Timing.clockTickH0;
  }

  feedback_plant_M->Timing.t[0] = rtsiGetSolverStopTime
    (&feedback_plant_M->solverInfo);

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
    if (!(++feedback_plant_M->Timing.clockTick1)) {
      ++feedback_plant_M->Timing.clockTickH1;
    }

    feedback_plant_M->Timing.t[1] = feedback_plant_M->Timing.clockTick1 *
      feedback_plant_M->Timing.stepSize1 + feedback_plant_M->Timing.clockTickH1 *
      feedback_plant_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void feedback_plant_derivatives(void)
{
  XDot_feedback_plant_T *_rtXdot;
  _rtXdot = ((XDot_feedback_plant_T *) feedback_plant_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE = feedback_plant_B.Sum;

  /* Derivatives for Integrator: '<S11>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = feedback_plant_B.Sum2;

  /* Derivatives for Integrator: '<S11>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = feedback_plant_B.Sum1;
}

/* Model initialize function */
void feedback_plant_initialize(void)
{
  /* Level2 S-Function Block: '<S10>/src' (adnipcim) */
  {
    SimStruct *rts = feedback_plant_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 460.0, 920.0, 1380.0, 1840.0, 2300.0,
      2760.0, 3220.0, 3680.0, 4140.0, 4600.0, 5060.0, 5520.0, 5980.0, 6440.0,
      6900.0, 7360.0, 7820.0, 8280.0, 8740.0, 9200.0 } ;

    static real_T pDataValues0[] = { 0.040000000000000008, 0.057600000000000012,
      0.078400000000000011, 0.1024, 0.1296, 0.16000000000000003, 0.1936,
      0.23040000000000005, 0.27040000000000003, 0.31360000000000005,
      0.3600000000000001, 0.4096, 0.46239999999999992, 0.5184, 0.5776,
      0.64000000000000012, 0.70559999999999989, 0.7744, 0.8464, 0.9216, 1.0 } ;

    feedback_plant_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    feedback_plant_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    feedback_plant_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0,
      140.0, 160.0, 180.0, 200.0, 220.0, 240.0, 260.0, 280.0, 300.0, 320.0,
      340.0, 360.0, 380.0, 400.0, 420.0, 440.0, 460.0, 480.0, 500.0, 520.0,
      540.0, 560.0, 580.0, 600.0, 620.0, 640.0, 660.0, 680.0, 700.0, 720.0,
      740.0, 760.0, 780.0, 800.0, 820.0, 840.0, 860.0, 880.0, 900.0, 920.0,
      940.0, 960.0, 980.0, 1000.0, 1020.0, 1040.0, 1060.0, 1080.0, 1100.0,
      1120.0, 1140.0, 1160.0, 1180.0, 1200.0, 1220.0, 1240.0, 1260.0, 1280.0,
      1300.0, 1320.0, 1340.0, 1360.0, 1380.0, 1400.0, 1420.0, 1440.0, 1460.0,
      1480.0, 1500.0, 1520.0, 1540.0, 1560.0, 1580.0, 1600.0, 1620.0, 1640.0,
      1660.0, 1680.0, 1700.0, 1720.0, 1740.0, 1760.0, 1780.0, 1800.0, 1820.0,
      1840.0, 1860.0, 1880.0, 1900.0, 1920.0, 1940.0, 1960.0, 1980.0, 2000.0,
      2020.0, 2040.0, 2060.0, 2080.0, 2100.0, 2120.0, 2140.0, 2160.0, 2180.0,
      2200.0, 2220.0, 2240.0, 2260.0, 2280.0, 2300.0, 2320.0, 2340.0, 2360.0,
      2380.0, 2400.0, 2420.0, 2440.0, 2460.0, 2480.0, 2500.0, 2520.0, 2540.0,
      2560.0, 2580.0, 2600.0, 2620.0, 2640.0, 2660.0, 2680.0, 2700.0, 2720.0,
      2740.0, 2760.0, 2780.0, 2800.0, 2820.0, 2840.0, 2860.0, 2880.0, 2900.0,
      2920.0, 2940.0, 2960.0, 2980.0, 3000.0, 3020.0, 3040.0, 3060.0, 3080.0,
      3100.0, 3120.0, 3140.0, 3160.0, 3180.0, 3200.0, 3220.0, 3240.0, 3260.0,
      3280.0, 3300.0, 3320.0, 3340.0, 3360.0, 3380.0, 3400.0, 3420.0, 3440.0,
      3460.0, 3480.0, 3500.0, 3520.0, 3540.0, 3560.0, 3580.0, 3600.0, 3620.0,
      3640.0, 3660.0, 3680.0, 3700.0, 3720.0, 3740.0, 3760.0, 3780.0, 3800.0,
      3820.0, 3840.0, 3860.0, 3880.0, 3900.0, 3920.0, 3940.0, 3960.0, 3980.0,
      4000.0, 4020.0, 4040.0, 4060.0, 4080.0, 4100.0, 4120.0, 4140.0, 4160.0,
      4180.0, 4200.0, 4220.0, 4240.0, 4260.0, 4280.0, 4300.0, 4320.0, 4340.0,
      4360.0, 4380.0, 4400.0, 4420.0, 4440.0, 4460.0, 4480.0, 4500.0, 4520.0,
      4540.0, 4560.0, 4580.0, 4600.0, 4620.0, 4640.0, 4660.0, 4680.0, 4700.0,
      4720.0, 4740.0, 4760.0, 4780.0, 4800.0, 4820.0, 4840.0, 4860.0, 4880.0,
      4900.0, 4920.0, 4940.0, 4960.0, 4980.0, 5000.0, 5020.0, 5040.0, 5060.0,
      5080.0, 5100.0, 5120.0, 5140.0, 5160.0, 5180.0, 5200.0, 5220.0, 5240.0,
      5260.0, 5280.0, 5300.0, 5320.0, 5340.0, 5360.0, 5380.0, 5400.0, 5420.0,
      5440.0, 5460.0, 5480.0, 5500.0, 5520.0, 5540.0, 5560.0, 5580.0, 5600.0,
      5620.0, 5640.0, 5660.0, 5680.0, 5700.0, 5720.0, 5740.0, 5760.0, 5780.0,
      5800.0, 5820.0, 5840.0, 5860.0, 5880.0, 5900.0, 5920.0, 5940.0, 5960.0,
      5980.0, 6000.0, 6020.0, 6040.0, 6060.0, 6080.0, 6100.0, 6120.0, 6140.0,
      6160.0, 6180.0, 6200.0, 6220.0, 6240.0, 6260.0, 6280.0, 6300.0, 6320.0,
      6340.0, 6360.0, 6380.0, 6400.0, 6420.0, 6440.0, 6460.0, 6480.0, 6500.0,
      6520.0, 6540.0, 6560.0, 6580.0, 6600.0, 6620.0, 6640.0, 6660.0, 6680.0,
      6700.0, 6720.0, 6740.0, 6760.0, 6780.0, 6800.0, 6820.0, 6840.0, 6860.0,
      6880.0, 6900.0, 6920.0, 6940.0, 6960.0, 6980.0, 7000.0, 7020.0, 7040.0,
      7060.0, 7080.0, 7100.0, 7120.0, 7140.0, 7160.0, 7180.0, 7200.0, 7220.0,
      7240.0, 7260.0, 7280.0, 7300.0, 7320.0, 7340.0, 7360.0, 7380.0, 7400.0,
      7420.0, 7440.0, 7460.0, 7480.0, 7500.0, 7520.0, 7540.0, 7560.0, 7580.0,
      7600.0, 7620.0, 7640.0, 7660.0, 7680.0, 7700.0, 7720.0, 7740.0, 7760.0,
      7780.0, 7800.0, 7820.0, 7840.0, 7860.0, 7880.0, 7900.0, 7920.0, 7940.0,
      7960.0, 7980.0, 8000.0, 8020.0, 8040.0, 8060.0, 8080.0, 8100.0, 8120.0,
      8140.0, 8160.0, 8180.0, 8200.0, 8220.0, 8240.0, 8260.0, 8280.0, 8300.0,
      8320.0, 8340.0, 8360.0, 8380.0, 8400.0, 8420.0, 8440.0, 8460.0, 8480.0,
      8500.0, 8520.0, 8540.0, 8560.0, 8580.0, 8600.0, 8620.0, 8640.0, 8660.0,
      8680.0, 8700.0, 8720.0, 8740.0, 8760.0, 8780.0, 8800.0, 8820.0, 8840.0,
      8860.0, 8880.0, 8900.0, 8920.0, 8940.0, 8960.0, 8980.0, 9000.0, 9020.0,
      9040.0, 9060.0, 9080.0, 9100.0, 9120.0, 9140.0, 9160.0, 9180.0, 9200.0,
      9220.0, 9240.0, 9260.0, 9280.0, 9300.0, 9320.0, 9340.0, 9360.0, 9380.0,
      9400.0, 9420.0, 9440.0, 9460.0, 9480.0, 9500.0, 9520.0, 9540.0, 9560.0,
      9580.0, 9600.0, 9620.0, 9640.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    feedback_plant_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    feedback_plant_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    feedback_plant_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0,
      140.0, 160.0, 180.0, 200.0, 220.0, 240.0, 260.0, 280.0, 300.0, 320.0,
      340.0, 360.0, 380.0, 400.0, 420.0, 440.0, 460.0, 480.0, 500.0, 520.0,
      540.0, 560.0, 580.0, 600.0, 620.0, 640.0, 660.0, 680.0, 700.0, 720.0,
      740.0, 760.0, 780.0, 800.0, 820.0, 840.0, 860.0, 880.0, 900.0, 920.0,
      940.0, 960.0, 980.0, 1000.0, 1020.0, 1040.0, 1060.0, 1080.0, 1100.0,
      1120.0, 1140.0, 1160.0, 1180.0, 1200.0, 1220.0, 1240.0, 1260.0, 1280.0,
      1300.0, 1320.0, 1340.0, 1360.0, 1380.0, 1400.0, 1420.0, 1440.0, 1460.0,
      1480.0, 1500.0, 1520.0, 1540.0, 1560.0, 1580.0, 1600.0, 1620.0, 1640.0,
      1660.0, 1680.0, 1700.0, 1720.0, 1740.0, 1760.0, 1780.0, 1800.0, 1820.0,
      1840.0, 1860.0, 1880.0, 1900.0, 1920.0, 1940.0, 1960.0, 1980.0, 2000.0,
      2020.0, 2040.0, 2060.0, 2080.0, 2100.0, 2120.0, 2140.0, 2160.0, 2180.0,
      2200.0, 2220.0, 2240.0, 2260.0, 2280.0, 2300.0, 2320.0, 2340.0, 2360.0,
      2380.0, 2400.0, 2420.0, 2440.0, 2460.0, 2480.0, 2500.0, 2520.0, 2540.0,
      2560.0, 2580.0, 2600.0, 2620.0, 2640.0, 2660.0, 2680.0, 2700.0, 2720.0,
      2740.0, 2760.0, 2780.0, 2800.0, 2820.0, 2840.0, 2860.0, 2880.0, 2900.0,
      2920.0, 2940.0, 2960.0, 2980.0, 3000.0, 3020.0, 3040.0, 3060.0, 3080.0,
      3100.0, 3120.0, 3140.0, 3160.0, 3180.0, 3200.0, 3220.0, 3240.0, 3260.0,
      3280.0, 3300.0, 3320.0, 3340.0, 3360.0, 3380.0, 3400.0, 3420.0, 3440.0,
      3460.0, 3480.0, 3500.0, 3520.0, 3540.0, 3560.0, 3580.0, 3600.0, 3620.0,
      3640.0, 3660.0, 3680.0, 3700.0, 3720.0, 3740.0, 3760.0, 3780.0, 3800.0,
      3820.0, 3840.0, 3860.0, 3880.0, 3900.0, 3920.0, 3940.0, 3960.0, 3980.0,
      4000.0, 4020.0, 4040.0, 4060.0, 4080.0, 4100.0, 4120.0, 4140.0, 4160.0,
      4180.0, 4200.0, 4220.0, 4240.0, 4260.0, 4280.0, 4300.0, 4320.0, 4340.0,
      4360.0, 4380.0, 4400.0, 4420.0, 4440.0, 4460.0, 4480.0, 4500.0, 4520.0,
      4540.0, 4560.0, 4580.0, 4600.0, 4620.0, 4640.0, 4660.0, 4680.0, 4700.0,
      4720.0, 4740.0, 4760.0, 4780.0, 4800.0, 4820.0, 4840.0, 4860.0, 4880.0,
      4900.0, 4920.0, 4940.0, 4960.0, 4980.0, 5000.0, 5020.0, 5040.0, 5060.0,
      5080.0, 5100.0, 5120.0, 5140.0, 5160.0, 5180.0, 5200.0, 5220.0, 5240.0,
      5260.0, 5280.0, 5300.0, 5320.0, 5340.0, 5360.0, 5380.0, 5400.0, 5420.0,
      5440.0, 5460.0, 5480.0, 5500.0, 5520.0, 5540.0, 5560.0, 5580.0, 5600.0,
      5620.0, 5640.0, 5660.0, 5680.0, 5700.0, 5720.0, 5740.0, 5760.0, 5780.0,
      5800.0, 5820.0, 5840.0, 5860.0, 5880.0, 5900.0, 5920.0, 5940.0, 5960.0,
      5980.0, 6000.0, 6020.0, 6040.0, 6060.0, 6080.0, 6100.0, 6120.0, 6140.0,
      6160.0, 6180.0, 6200.0, 6220.0, 6240.0, 6260.0, 6280.0, 6300.0, 6320.0,
      6340.0, 6360.0, 6380.0, 6400.0, 6420.0, 6440.0, 6460.0, 6480.0, 6500.0,
      6520.0, 6540.0, 6560.0, 6580.0, 6600.0, 6620.0, 6640.0, 6660.0, 6680.0,
      6700.0, 6720.0, 6740.0, 6760.0, 6780.0, 6800.0, 6820.0, 6840.0, 6860.0,
      6880.0, 6900.0, 6920.0, 6940.0, 6960.0, 6980.0, 7000.0, 7020.0, 7040.0,
      7060.0, 7080.0, 7100.0, 7120.0, 7140.0, 7160.0, 7180.0, 7200.0, 7220.0,
      7240.0, 7260.0, 7280.0, 7300.0, 7320.0, 7340.0, 7360.0, 7380.0, 7400.0,
      7420.0, 7440.0, 7460.0, 7480.0, 7500.0, 7520.0, 7540.0, 7560.0, 7580.0,
      7600.0, 7620.0, 7640.0, 7660.0, 7680.0, 7700.0, 7720.0, 7740.0, 7760.0,
      7780.0, 7800.0, 7820.0, 7840.0, 7860.0, 7880.0, 7900.0, 7920.0, 7940.0,
      7960.0, 7980.0, 8000.0, 8020.0, 8040.0, 8060.0, 8080.0, 8100.0, 8120.0,
      8140.0, 8160.0, 8180.0, 8200.0, 8220.0, 8240.0, 8260.0, 8280.0, 8300.0,
      8320.0, 8340.0, 8360.0, 8380.0, 8400.0, 8420.0, 8440.0, 8460.0, 8480.0,
      8500.0, 8520.0, 8540.0, 8560.0, 8580.0, 8600.0, 8620.0, 8640.0, 8660.0,
      8680.0, 8700.0, 8720.0, 8740.0, 8760.0, 8780.0, 8800.0, 8820.0, 8840.0,
      8860.0, 8880.0, 8900.0, 8920.0, 8940.0, 8960.0, 8980.0, 9000.0, 9020.0,
      9040.0, 9060.0, 9080.0, 9100.0, 9120.0, 9140.0, 9160.0, 9180.0, 9200.0,
      9220.0, 9240.0, 9260.0, 9280.0, 9300.0, 9320.0, 9340.0, 9360.0, 9380.0,
      9400.0, 9420.0, 9440.0, 9460.0, 9480.0, 9500.0, 9520.0, 9540.0, 9560.0,
      9580.0, 9600.0, 9620.0, 9640.0 } ;

    static real_T pDataValues0[] = { 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98 } ;

    feedback_plant_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    feedback_plant_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    feedback_plant_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace3' */
  {
    static real_T pTimeValues0[] = { 0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0,
      140.0, 160.0, 180.0, 200.0, 220.0, 240.0, 260.0, 280.0, 300.0, 320.0,
      340.0, 360.0, 380.0, 400.0, 420.0, 440.0, 460.0, 480.0, 500.0, 520.0,
      540.0, 560.0, 580.0, 600.0, 620.0, 640.0, 660.0, 680.0, 700.0, 720.0,
      740.0, 760.0, 780.0, 800.0, 820.0, 840.0, 860.0, 880.0, 900.0, 920.0,
      940.0, 960.0, 980.0, 1000.0, 1020.0, 1040.0, 1060.0, 1080.0, 1100.0,
      1120.0, 1140.0, 1160.0, 1180.0, 1200.0, 1220.0, 1240.0, 1260.0, 1280.0,
      1300.0, 1320.0, 1340.0, 1360.0, 1380.0, 1400.0, 1420.0, 1440.0, 1460.0,
      1480.0, 1500.0, 1520.0, 1540.0, 1560.0, 1580.0, 1600.0, 1620.0, 1640.0,
      1660.0, 1680.0, 1700.0, 1720.0, 1740.0, 1760.0, 1780.0, 1800.0, 1820.0,
      1840.0, 1860.0, 1880.0, 1900.0, 1920.0, 1940.0, 1960.0, 1980.0, 2000.0,
      2020.0, 2040.0, 2060.0, 2080.0, 2100.0, 2120.0, 2140.0, 2160.0, 2180.0,
      2200.0, 2220.0, 2240.0, 2260.0, 2280.0, 2300.0, 2320.0, 2340.0, 2360.0,
      2380.0, 2400.0, 2420.0, 2440.0, 2460.0, 2480.0, 2500.0, 2520.0, 2540.0,
      2560.0, 2580.0, 2600.0, 2620.0, 2640.0, 2660.0, 2680.0, 2700.0, 2720.0,
      2740.0, 2760.0, 2780.0, 2800.0, 2820.0, 2840.0, 2860.0, 2880.0, 2900.0,
      2920.0, 2940.0, 2960.0, 2980.0, 3000.0, 3020.0, 3040.0, 3060.0, 3080.0,
      3100.0, 3120.0, 3140.0, 3160.0, 3180.0, 3200.0, 3220.0, 3240.0, 3260.0,
      3280.0, 3300.0, 3320.0, 3340.0, 3360.0, 3380.0, 3400.0, 3420.0, 3440.0,
      3460.0, 3480.0, 3500.0, 3520.0, 3540.0, 3560.0, 3580.0, 3600.0, 3620.0,
      3640.0, 3660.0, 3680.0, 3700.0, 3720.0, 3740.0, 3760.0, 3780.0, 3800.0,
      3820.0, 3840.0, 3860.0, 3880.0, 3900.0, 3920.0, 3940.0, 3960.0, 3980.0,
      4000.0, 4020.0, 4040.0, 4060.0, 4080.0, 4100.0, 4120.0, 4140.0, 4160.0,
      4180.0, 4200.0, 4220.0, 4240.0, 4260.0, 4280.0, 4300.0, 4320.0, 4340.0,
      4360.0, 4380.0, 4400.0, 4420.0, 4440.0, 4460.0, 4480.0, 4500.0, 4520.0,
      4540.0, 4560.0, 4580.0, 4600.0, 4620.0, 4640.0, 4660.0, 4680.0, 4700.0,
      4720.0, 4740.0, 4760.0, 4780.0, 4800.0, 4820.0, 4840.0, 4860.0, 4880.0,
      4900.0, 4920.0, 4940.0, 4960.0, 4980.0, 5000.0, 5020.0, 5040.0, 5060.0,
      5080.0, 5100.0, 5120.0, 5140.0, 5160.0, 5180.0, 5200.0, 5220.0, 5240.0,
      5260.0, 5280.0, 5300.0, 5320.0, 5340.0, 5360.0, 5380.0, 5400.0, 5420.0,
      5440.0, 5460.0, 5480.0, 5500.0, 5520.0, 5540.0, 5560.0, 5580.0, 5600.0,
      5620.0, 5640.0, 5660.0, 5680.0, 5700.0, 5720.0, 5740.0, 5760.0, 5780.0,
      5800.0, 5820.0, 5840.0, 5860.0, 5880.0, 5900.0, 5920.0, 5940.0, 5960.0,
      5980.0, 6000.0, 6020.0, 6040.0, 6060.0, 6080.0, 6100.0, 6120.0, 6140.0,
      6160.0, 6180.0, 6200.0, 6220.0, 6240.0, 6260.0, 6280.0, 6300.0, 6320.0,
      6340.0, 6360.0, 6380.0, 6400.0, 6420.0, 6440.0, 6460.0, 6480.0, 6500.0,
      6520.0, 6540.0, 6560.0, 6580.0, 6600.0, 6620.0, 6640.0, 6660.0, 6680.0,
      6700.0, 6720.0, 6740.0, 6760.0, 6780.0, 6800.0, 6820.0, 6840.0, 6860.0,
      6880.0, 6900.0, 6920.0, 6940.0, 6960.0, 6980.0, 7000.0, 7020.0, 7040.0,
      7060.0, 7080.0, 7100.0, 7120.0, 7140.0, 7160.0, 7180.0, 7200.0, 7220.0,
      7240.0, 7260.0, 7280.0, 7300.0, 7320.0, 7340.0, 7360.0, 7380.0, 7400.0,
      7420.0, 7440.0, 7460.0, 7480.0, 7500.0, 7520.0, 7540.0, 7560.0, 7580.0,
      7600.0, 7620.0, 7640.0, 7660.0, 7680.0, 7700.0, 7720.0, 7740.0, 7760.0,
      7780.0, 7800.0, 7820.0, 7840.0, 7860.0, 7880.0, 7900.0, 7920.0, 7940.0,
      7960.0, 7980.0, 8000.0, 8020.0, 8040.0, 8060.0, 8080.0, 8100.0, 8120.0,
      8140.0, 8160.0, 8180.0, 8200.0, 8220.0, 8240.0, 8260.0, 8280.0, 8300.0,
      8320.0, 8340.0, 8360.0, 8380.0, 8400.0, 8420.0, 8440.0, 8460.0, 8480.0,
      8500.0, 8520.0, 8540.0, 8560.0, 8580.0, 8600.0, 8620.0, 8640.0, 8660.0,
      8680.0, 8700.0, 8720.0, 8740.0, 8760.0, 8780.0, 8800.0, 8820.0, 8840.0,
      8860.0, 8880.0, 8900.0, 8920.0, 8940.0, 8960.0, 8980.0, 9000.0, 9020.0,
      9040.0, 9060.0, 9080.0, 9100.0, 9120.0, 9140.0, 9160.0, 9180.0, 9200.0,
      9220.0, 9240.0, 9260.0, 9280.0, 9300.0, 9320.0, 9340.0, 9360.0, 9380.0,
      9400.0, 9420.0, 9440.0, 9460.0, 9480.0, 9500.0, 9520.0, 9540.0, 9560.0,
      9580.0, 9600.0, 9620.0, 9640.0 } ;

    static real_T pDataValues0[] = { 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98, 0.1, 0.14, 0.18, 0.22, 0.26,
      0.30000000000000004, 0.33999999999999997, 0.38, 0.42000000000000004,
      0.45999999999999996, 0.5, 0.54, 0.58, 0.62, 0.65999999999999992, 0.7, 0.74,
      0.78, 0.82, 0.86, 0.9, 0.94, 0.98 } ;

    feedback_plant_DW.FromWorkspace3_PWORK.TimePtr = (void *) pTimeValues0;
    feedback_plant_DW.FromWorkspace3_PWORK.DataPtr = (void *) pDataValues0;
    feedback_plant_DW.FromWorkspace3_IWORK.PrevIndex = 0;
  }

  /* S-Function Block: <S2>/S-Function (scblock) */
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
        xpceScopeAcqOK(9, &feedback_plant_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(9);
    }
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
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
        xpceScopeAcqOK(10, &feedback_plant_DW.SFunction_IWORK_l.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,1)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Gain4"));
        rl32eAddSignal(2, rl32eGetSignalNo("Gain2"));
        rl32eAddSignal(2, rl32eGetSignalNo("Gain"));
        rl32eAddSignal(2, rl32eGetSignalNo("Gain1"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Gain4"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        xpceScopeAcqOK(2, &feedback_plant_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("best_mode_control/test 1"));
        rl32eAddSignal(3, rl32eGetSignalNo("best_mode_control/Divide5"));
        rl32eAddSignal(3, rl32eGetSignalNo("best_mode_control/Divide4"));
        rl32eAddSignal(3, rl32eGetSignalNo("best_mode_control/Divide3"));
        rl32eSetScope(3, 4, 250);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("best_mode_control/test 1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3, &feedback_plant_DW.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(8)) == 0) {
      if ((i = rl32eDefScope(8,2)) != 0) {
        printf("Error creating scope 8\n");
      } else {
        rl32eAddSignal(8, rl32eGetSignalNo("Gain4"));
        rl32eAddSignal(8, rl32eGetSignalNo("Gain2"));
        rl32eAddSignal(8, rl32eGetSignalNo("Gain"));
        rl32eAddSignal(8, rl32eGetSignalNo("Gain1"));
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Gain4"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Gain2"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Gain"),"%15.6f");
        rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Gain1"),"%15.6f");
        rl32eSetScope(8, 4, 25);
        rl32eSetScope(8, 5, 0);
        rl32eSetScope(8, 6, 1);
        rl32eSetScope(8, 0, 0);
        rl32eSetScope(8, 3, rl32eGetSignalNo("Gain4"));
        rl32eSetScope(8, 1, 0.0);
        rl32eSetScope(8, 2, 0);
        rl32eSetScope(8, 9, 0);
        rl32eSetTargetScope(8, 1, 0.0);
        rl32eSetTargetScope(8, 11, 0.0);
        rl32eSetTargetScope(8, 10, 0.0);
        xpceScopeAcqOK(8, &feedback_plant_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(8);
    }
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
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
        xpceScopeAcqOK(11, &feedback_plant_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(11);
    }
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
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
        xpceScopeAcqOK(4, &feedback_plant_DW.SFunction_IWORK_l4.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* Level2 S-Function Block: '<S9>/DA_sink' (danipcim) */
  {
    SimStruct *rts = feedback_plant_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S26>/S-Function (scblock) */
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
        xpceScopeAcqOK(1, &feedback_plant_DW.SFunction_IWORK_go.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  feedback_plant_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S11>/Integrator2' */
  feedback_plant_X.Integrator2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S11>/Integrator1' */
  feedback_plant_X.Integrator1_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  feedback_plant_DW.UnitDelay_DSTATE = 1.0;
}

/* Model terminate function */
void feedback_plant_terminate(void)
{
  /* Level2 S-Function Block: '<S10>/src' (adnipcim) */
  {
    SimStruct *rts = feedback_plant_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/DA_sink' (danipcim) */
  {
    SimStruct *rts = feedback_plant_M->childSfunctions[1];
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
  feedback_plant_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  feedback_plant_update();
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
  feedback_plant_initialize();
}

void MdlTerminate(void)
{
  feedback_plant_terminate();
}

/* Registration function */
RT_MODEL_feedback_plant_T *feedback_plant(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)feedback_plant_M, 0,
                sizeof(RT_MODEL_feedback_plant_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&feedback_plant_M->solverInfo,
                          &feedback_plant_M->Timing.simTimeStep);
    rtsiSetTPtr(&feedback_plant_M->solverInfo, &rtmGetTPtr(feedback_plant_M));
    rtsiSetStepSizePtr(&feedback_plant_M->solverInfo,
                       &feedback_plant_M->Timing.stepSize0);
    rtsiSetdXPtr(&feedback_plant_M->solverInfo,
                 &feedback_plant_M->ModelData.derivs);
    rtsiSetContStatesPtr(&feedback_plant_M->solverInfo, (real_T **)
                         &feedback_plant_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&feedback_plant_M->solverInfo,
      &feedback_plant_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&feedback_plant_M->solverInfo, (&rtmGetErrorStatus
      (feedback_plant_M)));
    rtsiSetRTModelPtr(&feedback_plant_M->solverInfo, feedback_plant_M);
  }

  rtsiSetSimTimeStep(&feedback_plant_M->solverInfo, MAJOR_TIME_STEP);
  feedback_plant_M->ModelData.intgData.y = feedback_plant_M->ModelData.odeY;
  feedback_plant_M->ModelData.intgData.f[0] = feedback_plant_M->ModelData.odeF[0];
  feedback_plant_M->ModelData.intgData.f[1] = feedback_plant_M->ModelData.odeF[1];
  feedback_plant_M->ModelData.intgData.f[2] = feedback_plant_M->ModelData.odeF[2];
  feedback_plant_M->ModelData.contStates = ((real_T *) &feedback_plant_X);
  rtsiSetSolverData(&feedback_plant_M->solverInfo, (void *)
                    &feedback_plant_M->ModelData.intgData);
  rtsiSetSolverName(&feedback_plant_M->solverInfo,"ode3");
  feedback_plant_M->solverInfoPtr = (&feedback_plant_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = feedback_plant_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    feedback_plant_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    feedback_plant_M->Timing.sampleTimes =
      (&feedback_plant_M->Timing.sampleTimesArray[0]);
    feedback_plant_M->Timing.offsetTimes =
      (&feedback_plant_M->Timing.offsetTimesArray[0]);

    /* task periods */
    feedback_plant_M->Timing.sampleTimes[0] = (0.0);
    feedback_plant_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    feedback_plant_M->Timing.offsetTimes[0] = (0.0);
    feedback_plant_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(feedback_plant_M, &feedback_plant_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = feedback_plant_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    feedback_plant_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(feedback_plant_M, 9660.0);
  feedback_plant_M->Timing.stepSize0 = 0.01;
  feedback_plant_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    feedback_plant_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(feedback_plant_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(feedback_plant_M->rtwLogInfo, (NULL));
    rtliSetLogT(feedback_plant_M->rtwLogInfo, "tout");
    rtliSetLogX(feedback_plant_M->rtwLogInfo, "");
    rtliSetLogXFinal(feedback_plant_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(feedback_plant_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(feedback_plant_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(feedback_plant_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(feedback_plant_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &feedback_plant_Y.sens[0]
      };

      rtliSetLogYSignalPtrs(feedback_plant_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
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
        "feedback_plant/sens" };

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

      rtliSetLogYSignalInfo(feedback_plant_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(feedback_plant_M->rtwLogInfo, "yout");
  }

  feedback_plant_M->solverInfoPtr = (&feedback_plant_M->solverInfo);
  feedback_plant_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&feedback_plant_M->solverInfo, 0.01);
  rtsiSetSolverMode(&feedback_plant_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  feedback_plant_M->ModelData.blockIO = ((void *) &feedback_plant_B);
  (void) memset(((void *) &feedback_plant_B), 0,
                sizeof(B_feedback_plant_T));

  /* states (continuous) */
  {
    real_T *x = (real_T *) &feedback_plant_X;
    feedback_plant_M->ModelData.contStates = (x);
    (void) memset((void *)&feedback_plant_X, 0,
                  sizeof(X_feedback_plant_T));
  }

  /* states (dwork) */
  feedback_plant_M->ModelData.dwork = ((void *) &feedback_plant_DW);
  (void) memset((void *)&feedback_plant_DW, 0,
                sizeof(DW_feedback_plant_T));

  /* external outputs */
  feedback_plant_M->ModelData.outputs = (&feedback_plant_Y);
  (void) memset(&feedback_plant_Y.sens[0], 0,
                22U*sizeof(real_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  feedback_plant_InitializeDataMapInfo(feedback_plant_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &feedback_plant_M->NonInlinedSFcns.sfcnInfo;
    feedback_plant_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(feedback_plant_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &feedback_plant_M->Sizes.numSampTimes);
    feedback_plant_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (feedback_plant_M)[0]);
    feedback_plant_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (feedback_plant_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,feedback_plant_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(feedback_plant_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(feedback_plant_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (feedback_plant_M));
    rtssSetStepSizePtr(sfcnInfo, &feedback_plant_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(feedback_plant_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &feedback_plant_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &feedback_plant_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &feedback_plant_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &feedback_plant_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &feedback_plant_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &feedback_plant_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &feedback_plant_M->solverInfoPtr);
  }

  feedback_plant_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&feedback_plant_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    feedback_plant_M->childSfunctions =
      (&feedback_plant_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    feedback_plant_M->childSfunctions[0] =
      (&feedback_plant_M->NonInlinedSFcns.childSFunctions[0]);
    feedback_plant_M->childSfunctions[1] =
      (&feedback_plant_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: feedback_plant/<S10>/src (adnipcim) */
    {
      SimStruct *rts = feedback_plant_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = feedback_plant_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = feedback_plant_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = feedback_plant_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &feedback_plant_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, feedback_plant_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &feedback_plant_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &feedback_plant_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &feedback_plant_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &feedback_plant_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &feedback_plant_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 22);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &feedback_plant_B.src_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &feedback_plant_B.src_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &feedback_plant_B.src_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &feedback_plant_B.src_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &feedback_plant_B.src_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &feedback_plant_B.src_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &feedback_plant_B.src_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &feedback_plant_B.src_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 1);
          ssSetOutputPortSignal(rts, 8, ((real_T *) &feedback_plant_B.src_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real_T *) &feedback_plant_B.src_o10));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real_T *) &feedback_plant_B.src_o11));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real_T *) &feedback_plant_B.src_o12));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((real_T *) &feedback_plant_B.src_o13));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((real_T *) &feedback_plant_B.src_o14));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((real_T *) &feedback_plant_B.src_o15));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((real_T *) &feedback_plant_B.src_o16));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 1);
          ssSetOutputPortSignal(rts, 16, ((real_T *) &feedback_plant_B.src_o17));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 1);
          ssSetOutputPortSignal(rts, 17, ((real_T *) &feedback_plant_B.src_o18));
        }

        /* port 18 */
        {
          _ssSetOutputPortNumDimensions(rts, 18, 1);
          ssSetOutputPortWidth(rts, 18, 1);
          ssSetOutputPortSignal(rts, 18, ((real_T *) &feedback_plant_B.src_o19));
        }

        /* port 19 */
        {
          _ssSetOutputPortNumDimensions(rts, 19, 1);
          ssSetOutputPortWidth(rts, 19, 1);
          ssSetOutputPortSignal(rts, 19, ((real_T *) &feedback_plant_B.src_o20));
        }

        /* port 20 */
        {
          _ssSetOutputPortNumDimensions(rts, 20, 1);
          ssSetOutputPortWidth(rts, 20, 1);
          ssSetOutputPortSignal(rts, 20, ((real_T *) &feedback_plant_B.src_o21));
        }

        /* port 21 */
        {
          _ssSetOutputPortNumDimensions(rts, 21, 1);
          ssSetOutputPortWidth(rts, 21, 1);
          ssSetOutputPortSignal(rts, 21, ((real_T *) &feedback_plant_B.src_o22));
        }
      }

      /* path info */
      ssSetModelName(rts, "src");
      ssSetPath(rts, "feedback_plant/analogdigital/src");
      ssSetRTModel(rts,feedback_plant_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &feedback_plant_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)feedback_plant_ConstP.src_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)feedback_plant_ConstP.src_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)feedback_plant_ConstP.src_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)feedback_plant_ConstP.src_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)feedback_plant_ConstP.pooled1);
        ssSetSFcnParam(rts, 5, (mxArray*)feedback_plant_ConstP.pooled3);
        ssSetSFcnParam(rts, 6, (mxArray*)feedback_plant_ConstP.pooled5);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &feedback_plant_DW.src_IWORK[0]);
      ssSetPWork(rts, (void **) &feedback_plant_DW.src_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &feedback_plant_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &feedback_plant_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 41);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &feedback_plant_DW.src_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &feedback_plant_DW.src_PWORK);
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

    /* Level2 S-Function Block: feedback_plant/<S9>/DA_sink (danipcim) */
    {
      SimStruct *rts = feedback_plant_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = feedback_plant_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = feedback_plant_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = feedback_plant_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &feedback_plant_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, feedback_plant_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &feedback_plant_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &feedback_plant_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &feedback_plant_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &feedback_plant_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &feedback_plant_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &feedback_plant_B.CV01_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &feedback_plant_B.WP01_o;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_M->NonInlinedSFcns.Sfcn1.UPtrs2;
          sfcnUPtrs[0] = &feedback_plant_B.WP02_l;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &feedback_plant_M->NonInlinedSFcns.Sfcn1.UPtrs3;
          sfcnUPtrs[0] = &feedback_plant_B.WP03_d;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "DA_sink");
      ssSetPath(rts, "feedback_plant/actuators/DA_sink");
      ssSetRTModel(rts,feedback_plant_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &feedback_plant_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)feedback_plant_ConstP.DA_sink_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)feedback_plant_ConstP.pooled8);
        ssSetSFcnParam(rts, 2, (mxArray*)feedback_plant_ConstP.DA_sink_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)feedback_plant_ConstP.pooled8);
        ssSetSFcnParam(rts, 4, (mxArray*)feedback_plant_ConstP.pooled1);
        ssSetSFcnParam(rts, 5, (mxArray*)feedback_plant_ConstP.pooled3);
        ssSetSFcnParam(rts, 6, (mxArray*)feedback_plant_ConstP.pooled5);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &feedback_plant_DW.DA_sink_RWORK[0]);
      ssSetIWork(rts, (int_T *) &feedback_plant_DW.DA_sink_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &feedback_plant_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &feedback_plant_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &feedback_plant_DW.DA_sink_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &feedback_plant_DW.DA_sink_IWORK[0]);
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
  feedback_plant_M->Sizes.numContStates = (3);/* Number of continuous states */
  feedback_plant_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  feedback_plant_M->Sizes.numY = (22); /* Number of model outputs */
  feedback_plant_M->Sizes.numU = (0);  /* Number of model inputs */
  feedback_plant_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  feedback_plant_M->Sizes.numSampTimes = (2);/* Number of sample times */
  feedback_plant_M->Sizes.numBlocks = (86);/* Number of blocks */
  feedback_plant_M->Sizes.numBlockIO = (97);/* Number of block outputs */
  return feedback_plant_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
