/*
 * pump_test_model.c
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

#include "rt_logging_mmi.h"
#include "pump_test_model_capi.h"
#include "pump_test_model.h"
#include "pump_test_model_private.h"

/* Block signals (auto storage) */
B_pump_test_model_T pump_test_model_B;

/* Continuous states */
X_pump_test_model_T pump_test_model_X;

/* Block states (auto storage) */
DW_pump_test_model_T pump_test_model_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_pump_test_model_T pump_test_model_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_pump_test_model_T pump_test_model_Y;

/* Real-time model */
RT_MODEL_pump_test_model_T pump_test_model_M_;
RT_MODEL_pump_test_model_T *const pump_test_model_M = &pump_test_model_M_;

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
  pump_test_model_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  pump_test_model_output();
  pump_test_model_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  pump_test_model_output();
  pump_test_model_derivatives();

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
void pump_test_model_output(void)
{
  real_T t6;
  real_T t12;
  boolean_T b;
  boolean_T c;
  real_T varargin_1[3];
  int32_T itmp;
  int32_T ixstart;
  int32_T ix;
  int8_T tmp;
  real_T u2;
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* set solver stop time */
    if (!(pump_test_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&pump_test_model_M->solverInfo,
                            ((pump_test_model_M->Timing.clockTickH0 + 1) *
        pump_test_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&pump_test_model_M->solverInfo,
                            ((pump_test_model_M->Timing.clockTick0 + 1) *
        pump_test_model_M->Timing.stepSize0 +
        pump_test_model_M->Timing.clockTickH0 *
        pump_test_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pump_test_model_M)) {
    pump_test_model_M->Timing.t[0] = rtsiGetT(&pump_test_model_M->solverInfo);
  }

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Inport: '<Root>/Head_Ref'
   */
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    pump_test_model_B.PID_Ref = pump_test_model_U.Head_Ref;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/Head'
   */
  pump_test_model_B.PID_Error = pump_test_model_B.PID_Ref -
    pump_test_model_U.Head_Messurement;

  /* Gain: '<S2>/Proportional Gain' */
  pump_test_model_B.ProportionalGain = pump_test_model_P.PIDController_P *
    pump_test_model_B.PID_Error;

  /* Integrator: '<S2>/Integrator' */
  pump_test_model_B.Integrator = pump_test_model_X.Integrator_CSTATE;

  /* Sum: '<S2>/Sum' */
  pump_test_model_B.Sum = pump_test_model_B.ProportionalGain +
    pump_test_model_B.Integrator;

  /* Saturate: '<S2>/Saturate' */
  t6 = pump_test_model_B.Sum;
  t12 = pump_test_model_P.PIDController_LowerSaturationLi;
  u2 = pump_test_model_P.PIDController_UpperSaturationLi;
  if (t6 > u2) {
    pump_test_model_B.Saturate = u2;
  } else if (t6 < t12) {
    pump_test_model_B.Saturate = t12;
  } else {
    pump_test_model_B.Saturate = t6;
  }

  /* End of Saturate: '<S2>/Saturate' */

  /* Outport: '<Root>/Pump input ' */
  pump_test_model_Y.Pumpinput = pump_test_model_B.Saturate;

  /* MATLAB Function: '<Root>/valve_CV_esti_Test' incorporates:
   *  Inport: '<Root>/Head'
   *  Inport: '<Root>/Q_current'
   */
  /* MATLAB Function 'valve_CV_esti_Test': '<S6>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:28 */
  /* '<S6>:1:7' */
  pump_test_model_B.req_flow = 1.0 / sqrt(pump_test_model_U.Head_Messurement) *
    sqrt(pump_test_model_B.PID_Ref) * pump_test_model_U.Q_current;

  /* MATLAB Function: '<Root>/cost_power_1' */
  /* MATLAB Function 'cost_power_1': '<S3>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S3>:1:7' */
  /* '<S3>:1:8' */
  /* '<S3>:1:9' */
  /* '<S3>:1:10' */
  /* '<S3>:1:11' */
  /* '<S3>:1:12' */
  t6 = (rt_powd_snf(pump_test_model_B.PID_Ref, 0.53141635766267625) *
        467.38516862850241 + rt_powd_snf(pump_test_model_B.req_flow,
         1.2849922003160621) * 94.275566165207337) - pump_test_model_B.PID_Ref *
    pump_test_model_B.req_flow * 3.5900928110138022;

  /* '<S3>:1:13' */
  /* '<S3>:1:14' */
  /* '<S3>:1:15' */
  /* '<S3>:1:16' */
  /* '<S3>:1:17' */
  /* '<S3>:1:18' */
  t12 = (rt_powd_snf(pump_test_model_B.PID_Ref, 1.157084314722127) *
         6.1329150891835766 + rt_powd_snf(pump_test_model_B.req_flow,
          2.6827906282842031) * 1.270953547543209) + pump_test_model_B.PID_Ref *
    pump_test_model_B.req_flow * 2.6333276809500008;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S3>:1:19' */
    b = true;
  } else {
    /* '<S3>:1:19' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S3>:1:19' */
    c = true;
  } else {
    /* '<S3>:1:19' */
    c = false;
  }

  /* '<S3>:1:19' */
  pump_test_model_B.cost_power_1_w_sat = (real_T)b * 50000.0 + t12 * (real_T)c;

  /* End of MATLAB Function: '<Root>/cost_power_1' */

  /* MATLAB Function: '<Root>/cost_power_2' */
  /* MATLAB Function 'cost_power_2': '<S4>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S4>:1:7' */
  t12 = pump_test_model_B.req_flow * 0.5;

  /* '<S4>:1:8' */
  /* '<S4>:1:9' */
  /* '<S4>:1:10' */
  /* '<S4>:1:11' */
  /* '<S4>:1:12' */
  /* '<S4>:1:13' */
  t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 + rt_powd_snf
        (pump_test_model_B.PID_Ref, 0.53141635766267625) * 467.38516862850241) -
    pump_test_model_B.PID_Ref * pump_test_model_B.req_flow * 1.7950464055069011;

  /* '<S4>:1:14' */
  /* '<S4>:1:15' */
  /* '<S4>:1:16' */
  /* '<S4>:1:17' */
  /* '<S4>:1:18' */
  /* '<S4>:1:19' */
  t12 = (pump_test_model_B.PID_Ref * pump_test_model_B.req_flow *
         1.3166638404750011 + rt_powd_snf(pump_test_model_B.PID_Ref,
          1.157084314722127) * 6.1329150891835766) + rt_powd_snf(t12,
    2.6827906282842031) * 1.270953547543209;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S4>:1:20' */
    b = true;
  } else {
    /* '<S4>:1:20' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S4>:1:20' */
    c = true;
  } else {
    /* '<S4>:1:20' */
    c = false;
  }

  /* '<S4>:1:20' */
  pump_test_model_B.cost_power_2_w_sat = t12 * (real_T)c * 2.0 + (real_T)b *
    100000.0;

  /* End of MATLAB Function: '<Root>/cost_power_2' */

  /* MATLAB Function: '<Root>/cost_power_3' */
  /* MATLAB Function 'cost_power_3': '<S5>:1' */
  /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
  /*     22-Aug-2016 11:17:26 */
  /* '<S5>:1:7' */
  t12 = pump_test_model_B.req_flow * 0.33333333333333331;

  /* '<S5>:1:8' */
  /* '<S5>:1:9' */
  /* '<S5>:1:10' */
  /* '<S5>:1:11' */
  /* '<S5>:1:12' */
  /* '<S5>:1:13' */
  t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 + rt_powd_snf
        (pump_test_model_B.PID_Ref, 0.53141635766267625) * 467.38516862850241) -
    pump_test_model_B.PID_Ref * pump_test_model_B.req_flow * 1.1966976036712671;

  /* '<S5>:1:14' */
  /* '<S5>:1:15' */
  /* '<S5>:1:16' */
  /* '<S5>:1:17' */
  /* '<S5>:1:18' */
  /* '<S5>:1:19' */
  t12 = (pump_test_model_B.PID_Ref * pump_test_model_B.req_flow *
         0.87777589365000042 + rt_powd_snf(pump_test_model_B.PID_Ref,
          1.157084314722127) * 6.1329150891835766) + rt_powd_snf(t12,
    2.6827906282842031) * 1.270953547543209;
  if ((t6 <= 1000.0) || (1500.0 < t12) || (3500.0 <= t6)) {
    /* '<S5>:1:20' */
    b = true;
  } else {
    /* '<S5>:1:20' */
    b = false;
  }

  if ((1000.0 < t6) && (t12 <= 1500.0) && (t6 < 3500.0)) {
    /* '<S5>:1:20' */
    c = true;
  } else {
    /* '<S5>:1:20' */
    c = false;
  }

  /* '<S5>:1:20' */
  pump_test_model_B.cost_power_3_w_sat = t12 * (real_T)c * 3.0 + (real_T)b *
    150000.0;

  /* End of MATLAB Function: '<Root>/cost_power_3' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:3' */
  varargin_1[0] = pump_test_model_B.cost_power_1_w_sat;
  varargin_1[1] = pump_test_model_B.cost_power_2_w_sat;
  varargin_1[2] = pump_test_model_B.cost_power_3_w_sat;
  ixstart = 1;
  t6 = varargin_1[0];
  itmp = 1;
  if (rtIsNaN(varargin_1[0])) {
    ix = 2;
    b = false;
    while ((!b) && (ix < 4)) {
      ixstart = ix;
      if (!rtIsNaN(varargin_1[ix - 1])) {
        t6 = varargin_1[ix - 1];
        itmp = ix;
        b = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 3) {
    while (ixstart + 1 < 4) {
      if (varargin_1[ixstart] < t6) {
        t6 = varargin_1[ixstart];
        itmp = ixstart + 1;
      }

      ixstart++;
    }
  }

  /* '<S1>:1:3' */
  pump_test_model_B.y = itmp;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outport: '<Root>/Signal bus' incorporates:
   *  Inport: '<Root>/Head'
   */
  pump_test_model_Y.Signalbus[0] = pump_test_model_B.PID_Error;
  pump_test_model_Y.Signalbus[1] = pump_test_model_B.PID_Ref;
  pump_test_model_Y.Signalbus[2] = pump_test_model_U.Head_Messurement;
  pump_test_model_Y.Signalbus[3] = pump_test_model_B.Saturate;
  pump_test_model_Y.Signalbus[4] = pump_test_model_B.cost_power_1_w_sat;
  pump_test_model_Y.Signalbus[5] = pump_test_model_B.cost_power_2_w_sat;
  pump_test_model_Y.Signalbus[6] = pump_test_model_B.cost_power_3_w_sat;
  pump_test_model_Y.Signalbus[7] = pump_test_model_B.y;
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
  }

  /* Gain: '<S7>/ZeroGain' */
  pump_test_model_B.ZeroGain = pump_test_model_P.ZeroGain_Gain *
    pump_test_model_B.Sum;

  /* DeadZone: '<S7>/DeadZone' */
  if (pump_test_model_B.Sum > pump_test_model_P.PIDController_UpperSaturationLi)
  {
    pump_test_model_B.DeadZone = pump_test_model_B.Sum -
      pump_test_model_P.PIDController_UpperSaturationLi;
  } else if (pump_test_model_B.Sum >=
             pump_test_model_P.PIDController_LowerSaturationLi) {
    pump_test_model_B.DeadZone = 0.0;
  } else {
    pump_test_model_B.DeadZone = pump_test_model_B.Sum -
      pump_test_model_P.PIDController_LowerSaturationLi;
  }

  /* End of DeadZone: '<S7>/DeadZone' */

  /* RelationalOperator: '<S7>/NotEqual' */
  pump_test_model_B.NotEqual = (pump_test_model_B.ZeroGain !=
    pump_test_model_B.DeadZone);

  /* Signum: '<S7>/SignDeltaU' */
  t6 = pump_test_model_B.DeadZone;
  if (t6 < 0.0) {
    pump_test_model_B.SignDeltaU = -1.0;
  } else if (t6 > 0.0) {
    pump_test_model_B.SignDeltaU = 1.0;
  } else if (t6 == 0.0) {
    pump_test_model_B.SignDeltaU = 0.0;
  } else {
    pump_test_model_B.SignDeltaU = t6;
  }

  /* End of Signum: '<S7>/SignDeltaU' */

  /* DataTypeConversion: '<S7>/DataTypeConv1' */
  t6 = pump_test_model_B.SignDeltaU;
  if (t6 < 128.0) {
    if (t6 >= -128.0) {
      tmp = (int8_T)t6;
    } else {
      tmp = MIN_int8_T;
    }
  } else {
    tmp = MAX_int8_T;
  }

  pump_test_model_B.DataTypeConv1 = tmp;

  /* End of DataTypeConversion: '<S7>/DataTypeConv1' */

  /* Gain: '<S2>/Integral Gain' */
  pump_test_model_B.IntegralGain = pump_test_model_P.PIDController_I *
    pump_test_model_B.PID_Error;

  /* Signum: '<S7>/SignPreIntegrator' */
  t6 = pump_test_model_B.IntegralGain;
  if (t6 < 0.0) {
    pump_test_model_B.SignPreIntegrator = -1.0;
  } else if (t6 > 0.0) {
    pump_test_model_B.SignPreIntegrator = 1.0;
  } else if (t6 == 0.0) {
    pump_test_model_B.SignPreIntegrator = 0.0;
  } else {
    pump_test_model_B.SignPreIntegrator = t6;
  }

  /* End of Signum: '<S7>/SignPreIntegrator' */

  /* DataTypeConversion: '<S7>/DataTypeConv2' */
  t6 = pump_test_model_B.SignPreIntegrator;
  if (t6 < 128.0) {
    if (t6 >= -128.0) {
      tmp = (int8_T)t6;
    } else {
      tmp = MIN_int8_T;
    }
  } else {
    tmp = MAX_int8_T;
  }

  pump_test_model_B.DataTypeConv2 = tmp;

  /* End of DataTypeConversion: '<S7>/DataTypeConv2' */

  /* RelationalOperator: '<S7>/Equal' */
  pump_test_model_B.Equal = (pump_test_model_B.DataTypeConv1 ==
    pump_test_model_B.DataTypeConv2);

  /* Logic: '<S7>/AND' */
  pump_test_model_B.AND = (pump_test_model_B.NotEqual && pump_test_model_B.Equal);
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* Memory: '<S7>/Memory' */
    pump_test_model_B.Memory = pump_test_model_DW.Memory_PreviousInput;
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (pump_test_model_B.Memory) {
    pump_test_model_B.Switch = pump_test_model_P.Constant_Value;
  } else {
    pump_test_model_B.Switch = pump_test_model_B.IntegralGain;
  }

  /* End of Switch: '<S2>/Switch' */
}

/* Model update function */
void pump_test_model_update(void)
{
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* Update for Memory: '<S7>/Memory' */
    pump_test_model_DW.Memory_PreviousInput = pump_test_model_B.AND;
  }

  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    rt_ertODEUpdateContinuousStates(&pump_test_model_M->solverInfo);
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
  if (!(++pump_test_model_M->Timing.clockTick0)) {
    ++pump_test_model_M->Timing.clockTickH0;
  }

  pump_test_model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&pump_test_model_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++pump_test_model_M->Timing.clockTick1)) {
      ++pump_test_model_M->Timing.clockTickH1;
    }

    pump_test_model_M->Timing.t[1] = pump_test_model_M->Timing.clockTick1 *
      pump_test_model_M->Timing.stepSize1 +
      pump_test_model_M->Timing.clockTickH1 *
      pump_test_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void pump_test_model_derivatives(void)
{
  XDot_pump_test_model_T *_rtXdot;
  _rtXdot = ((XDot_pump_test_model_T *) pump_test_model_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = pump_test_model_B.Switch;
}

/* Model initialize function */
void pump_test_model_initialize(void)
{
  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  pump_test_model_X.Integrator_CSTATE = pump_test_model_P.Integrator_IC;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  pump_test_model_DW.Memory_PreviousInput = pump_test_model_P.Memory_X0;
}

/* Model terminate function */
void pump_test_model_terminate(void)
{
  /* (no terminate code required) */
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
  pump_test_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pump_test_model_update();
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
  pump_test_model_initialize();
}

void MdlTerminate(void)
{
  pump_test_model_terminate();
}

/* Registration function */
RT_MODEL_pump_test_model_T *pump_test_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pump_test_model_M, 0,
                sizeof(RT_MODEL_pump_test_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pump_test_model_M->solverInfo,
                          &pump_test_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&pump_test_model_M->solverInfo, &rtmGetTPtr(pump_test_model_M));
    rtsiSetStepSizePtr(&pump_test_model_M->solverInfo,
                       &pump_test_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&pump_test_model_M->solverInfo,
                 &pump_test_model_M->ModelData.derivs);
    rtsiSetContStatesPtr(&pump_test_model_M->solverInfo, (real_T **)
                         &pump_test_model_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&pump_test_model_M->solverInfo,
      &pump_test_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pump_test_model_M->solverInfo,
      &pump_test_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&pump_test_model_M->solverInfo,
      &pump_test_model_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&pump_test_model_M->solverInfo,
      &pump_test_model_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&pump_test_model_M->solverInfo, (&rtmGetErrorStatus
      (pump_test_model_M)));
    rtsiSetRTModelPtr(&pump_test_model_M->solverInfo, pump_test_model_M);
  }

  rtsiSetSimTimeStep(&pump_test_model_M->solverInfo, MAJOR_TIME_STEP);
  pump_test_model_M->ModelData.intgData.y = pump_test_model_M->ModelData.odeY;
  pump_test_model_M->ModelData.intgData.f[0] = pump_test_model_M->
    ModelData.odeF[0];
  pump_test_model_M->ModelData.intgData.f[1] = pump_test_model_M->
    ModelData.odeF[1];
  pump_test_model_M->ModelData.intgData.f[2] = pump_test_model_M->
    ModelData.odeF[2];
  pump_test_model_M->ModelData.contStates = ((real_T *) &pump_test_model_X);
  rtsiSetSolverData(&pump_test_model_M->solverInfo, (void *)
                    &pump_test_model_M->ModelData.intgData);
  rtsiSetSolverName(&pump_test_model_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pump_test_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    pump_test_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pump_test_model_M->Timing.sampleTimes =
      (&pump_test_model_M->Timing.sampleTimesArray[0]);
    pump_test_model_M->Timing.offsetTimes =
      (&pump_test_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pump_test_model_M->Timing.sampleTimes[0] = (0.0);
    pump_test_model_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    pump_test_model_M->Timing.offsetTimes[0] = (0.0);
    pump_test_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(pump_test_model_M, &pump_test_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pump_test_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    pump_test_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pump_test_model_M, 350.0);
  pump_test_model_M->Timing.stepSize0 = 0.0005;
  pump_test_model_M->Timing.stepSize1 = 0.0005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    pump_test_model_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(pump_test_model_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(pump_test_model_M->rtwLogInfo, (NULL));
    rtliSetLogT(pump_test_model_M->rtwLogInfo, "tout");
    rtliSetLogX(pump_test_model_M->rtwLogInfo, "");
    rtliSetLogXFinal(pump_test_model_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(pump_test_model_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(pump_test_model_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(pump_test_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(pump_test_model_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &pump_test_model_Y.Pumpinput,
        &pump_test_model_Y.Signalbus[0]
      };

      rtliSetLogYSignalPtrs(pump_test_model_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        8
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        8
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "Pump_Input",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "pump_test_model/Pump input\n",
        "pump_test_model/Signal bus" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
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

      rtliSetLogYSignalInfo(pump_test_model_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(pump_test_model_M->rtwLogInfo, "yout");
  }

  pump_test_model_M->solverInfoPtr = (&pump_test_model_M->solverInfo);
  pump_test_model_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&pump_test_model_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&pump_test_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pump_test_model_M->ModelData.blockIO = ((void *) &pump_test_model_B);
  (void) memset(((void *) &pump_test_model_B), 0,
                sizeof(B_pump_test_model_T));

  /* parameters */
  pump_test_model_M->ModelData.defaultParam = ((real_T *)&pump_test_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &pump_test_model_X;
    pump_test_model_M->ModelData.contStates = (x);
    (void) memset((void *)&pump_test_model_X, 0,
                  sizeof(X_pump_test_model_T));
  }

  /* states (dwork) */
  pump_test_model_M->ModelData.dwork = ((void *) &pump_test_model_DW);
  (void) memset((void *)&pump_test_model_DW, 0,
                sizeof(DW_pump_test_model_T));

  /* external inputs */
  pump_test_model_M->ModelData.inputs = (((void*)&pump_test_model_U));
  (void) memset((void *)&pump_test_model_U, 0,
                sizeof(ExtU_pump_test_model_T));

  /* external outputs */
  pump_test_model_M->ModelData.outputs = (&pump_test_model_Y);
  (void) memset((void *)&pump_test_model_Y, 0,
                sizeof(ExtY_pump_test_model_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  pump_test_model_InitializeDataMapInfo(pump_test_model_M);

  /* Initialize Sizes */
  pump_test_model_M->Sizes.numContStates = (1);/* Number of continuous states */
  pump_test_model_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  pump_test_model_M->Sizes.numY = (9); /* Number of model outputs */
  pump_test_model_M->Sizes.numU = (3); /* Number of model inputs */
  pump_test_model_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  pump_test_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  pump_test_model_M->Sizes.numBlocks = (33);/* Number of blocks */
  pump_test_model_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  pump_test_model_M->Sizes.numBlockPrms = (8);/* Sum of parameter "widths" */
  return pump_test_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
