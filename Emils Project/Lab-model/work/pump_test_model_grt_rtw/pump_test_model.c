/*
 * pump_test_model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pump_test_model".
 *
 * Model version              : 1.104
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Aug 22 13:34:58 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

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
  pump_test_model_step();
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
  pump_test_model_step();
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

/* Model step function */
void pump_test_model_step(void)
{
  /* local block i/o variables */
  real_T rtb_req_flow;
  real_T rtb_cost_power_3_w_sat;
  real_T rtb_cost_power_2_w_sat;
  real_T rtb_cost_power_1_w_sat;
  real_T rtb_y;
  real_T t6;
  real_T t12;
  boolean_T b;
  boolean_T c;
  real_T varargin_1[3];
  int32_T itmp;
  int32_T ixstart;
  int32_T ix;
  real_T rtb_PID_Error;
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

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/Head'
   *  Inport: '<Root>/Head_Ref'
   */
  rtb_PID_Error = pump_test_model_U.Head_Ref -
    pump_test_model_U.Head_Messurement;

  /* Outport: '<Root>/Pump input ' incorporates:
   *  Gain: '<S2>/Proportional Gain'
   *  Integrator: '<S2>/Integrator'
   *  Sum: '<S2>/Sum'
   */
  pump_test_model_Y.Pumpinput = pump_test_model_P.PIDController_P *
    rtb_PID_Error + pump_test_model_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* MATLAB Function: '<Root>/valve_CV_esti_Test' incorporates:
     *  Inport: '<Root>/H_current'
     *  Inport: '<Root>/Head_Ref'
     *  Inport: '<Root>/Q_current'
     */
    /* MATLAB Function 'valve_CV_esti_Test': '<S6>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     22-Aug-2016 11:17:28 */
    /* '<S6>:1:7' */
    rtb_req_flow = 1.0 / sqrt(pump_test_model_U.H_current) * sqrt
      (pump_test_model_U.Head_Ref) * pump_test_model_U.Q_current;

    /* MATLAB Function: '<Root>/cost_power_1' incorporates:
     *  Inport: '<Root>/Head_Ref'
     */
    /* MATLAB Function 'cost_power_1': '<S3>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     22-Aug-2016 11:17:26 */
    /* '<S3>:1:7' */
    /* '<S3>:1:8' */
    /* '<S3>:1:9' */
    /* '<S3>:1:10' */
    /* '<S3>:1:11' */
    /* '<S3>:1:12' */
    t6 = (rt_powd_snf(pump_test_model_U.Head_Ref, 0.53141635766267625) *
          467.38516862850241 + rt_powd_snf(rtb_req_flow, 1.2849922003160621) *
          94.275566165207337) - pump_test_model_U.Head_Ref * rtb_req_flow *
      3.5900928110138022;

    /* '<S3>:1:13' */
    /* '<S3>:1:14' */
    /* '<S3>:1:15' */
    /* '<S3>:1:16' */
    /* '<S3>:1:17' */
    /* '<S3>:1:18' */
    t12 = (rt_powd_snf(pump_test_model_U.Head_Ref, 1.157084314722127) *
           6.1329150891835766 + rt_powd_snf(rtb_req_flow, 2.6827906282842031) *
           1.270953547543209) + pump_test_model_U.Head_Ref * rtb_req_flow *
      2.6333276809500008;
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
    rtb_cost_power_1_w_sat = (real_T)b * 50000.0 + t12 * (real_T)c;

    /* End of MATLAB Function: '<Root>/cost_power_1' */

    /* MATLAB Function: '<Root>/cost_power_2' incorporates:
     *  Inport: '<Root>/Head_Ref'
     */
    /* MATLAB Function 'cost_power_2': '<S4>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     22-Aug-2016 11:17:26 */
    /* '<S4>:1:7' */
    t12 = rtb_req_flow * 0.5;

    /* '<S4>:1:8' */
    /* '<S4>:1:9' */
    /* '<S4>:1:10' */
    /* '<S4>:1:11' */
    /* '<S4>:1:12' */
    /* '<S4>:1:13' */
    t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 +
          rt_powd_snf(pump_test_model_U.Head_Ref, 0.53141635766267625) *
          467.38516862850241) - pump_test_model_U.Head_Ref * rtb_req_flow *
      1.7950464055069011;

    /* '<S4>:1:14' */
    /* '<S4>:1:15' */
    /* '<S4>:1:16' */
    /* '<S4>:1:17' */
    /* '<S4>:1:18' */
    /* '<S4>:1:19' */
    t12 = (pump_test_model_U.Head_Ref * rtb_req_flow * 1.3166638404750011 +
           rt_powd_snf(pump_test_model_U.Head_Ref, 1.157084314722127) *
           6.1329150891835766) + rt_powd_snf(t12, 2.6827906282842031) *
      1.270953547543209;
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
    rtb_cost_power_2_w_sat = t12 * (real_T)c * 2.0 + (real_T)b * 100000.0;

    /* End of MATLAB Function: '<Root>/cost_power_2' */

    /* MATLAB Function: '<Root>/cost_power_3' incorporates:
     *  Inport: '<Root>/Head_Ref'
     */
    /* MATLAB Function 'cost_power_3': '<S5>:1' */
    /*     This function was generated by the Symbolic Math Toolbox version 7.0. */
    /*     22-Aug-2016 11:17:26 */
    /* '<S5>:1:7' */
    t12 = rtb_req_flow * 0.33333333333333331;

    /* '<S5>:1:8' */
    /* '<S5>:1:9' */
    /* '<S5>:1:10' */
    /* '<S5>:1:11' */
    /* '<S5>:1:12' */
    /* '<S5>:1:13' */
    t6 = (rt_powd_snf(t12, 1.2849922003160621) * 94.275566165207337 +
          rt_powd_snf(pump_test_model_U.Head_Ref, 0.53141635766267625) *
          467.38516862850241) - pump_test_model_U.Head_Ref * rtb_req_flow *
      1.1966976036712671;

    /* '<S5>:1:14' */
    /* '<S5>:1:15' */
    /* '<S5>:1:16' */
    /* '<S5>:1:17' */
    /* '<S5>:1:18' */
    /* '<S5>:1:19' */
    t12 = (pump_test_model_U.Head_Ref * rtb_req_flow * 0.87777589365000042 +
           rt_powd_snf(pump_test_model_U.Head_Ref, 1.157084314722127) *
           6.1329150891835766) + rt_powd_snf(t12, 2.6827906282842031) *
      1.270953547543209;
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
    rtb_cost_power_3_w_sat = t12 * (real_T)c * 3.0 + (real_T)b * 150000.0;

    /* End of MATLAB Function: '<Root>/cost_power_3' */

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S1>:1' */
    /* '<S1>:1:3' */
    varargin_1[0] = rtb_cost_power_1_w_sat;
    varargin_1[1] = rtb_cost_power_2_w_sat;
    varargin_1[2] = rtb_cost_power_3_w_sat;
    ixstart = 1;
    t6 = rtb_cost_power_1_w_sat;
    itmp = 1;
    if (rtIsNaN(rtb_cost_power_1_w_sat)) {
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
    rtb_y = itmp;

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* Outport: '<Root>/Signal bus' */
    pump_test_model_Y.Signalbus = 0.0;
  }

  /* Gain: '<S2>/Integral Gain' */
  pump_test_model_B.IntegralGain = pump_test_model_P.PIDController_I *
    rtb_PID_Error;
  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(pump_test_model_M->rtwLogInfo,
                        (pump_test_model_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(pump_test_model_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(pump_test_model_M)!=-1) &&
          !((rtmGetTFinal(pump_test_model_M)-
             (((pump_test_model_M->Timing.clockTick1+
                pump_test_model_M->Timing.clockTickH1* 4294967296.0)) * 0.0005))
            > (((pump_test_model_M->Timing.clockTick1+
                 pump_test_model_M->Timing.clockTickH1* 4294967296.0)) * 0.0005)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(pump_test_model_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&pump_test_model_M->solverInfo);

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
       * been executed. The resolution of this integer timer is 0.0005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      pump_test_model_M->Timing.clockTick1++;
      if (!pump_test_model_M->Timing.clockTick1) {
        pump_test_model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void pump_test_model_derivatives(void)
{
  XDot_pump_test_model_T *_rtXdot;
  _rtXdot = ((XDot_pump_test_model_T *) pump_test_model_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = pump_test_model_B.IntegralGain;
}

/* Model initialize function */
void pump_test_model_initialize(void)
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
  pump_test_model_M->ModelData.contStates = ((X_pump_test_model_T *)
    &pump_test_model_X);
  rtsiSetSolverData(&pump_test_model_M->solverInfo, (void *)
                    &pump_test_model_M->ModelData.intgData);
  rtsiSetSolverName(&pump_test_model_M->solverInfo,"ode3");
  rtmSetTPtr(pump_test_model_M, &pump_test_model_M->Timing.tArray[0]);
  rtmSetTFinal(pump_test_model_M, 350.0);
  pump_test_model_M->Timing.stepSize0 = 0.0005;

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
    rtliSetLogFormat(pump_test_model_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(pump_test_model_M->rtwLogInfo, 0);
    rtliSetLogDecimation(pump_test_model_M->rtwLogInfo, 1);
    rtliSetLogY(pump_test_model_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(pump_test_model_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(pump_test_model_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &pump_test_model_B), 0,
                sizeof(B_pump_test_model_T));

  /* states (continuous) */
  {
    (void) memset((void *)&pump_test_model_X, 0,
                  sizeof(X_pump_test_model_T));
  }

  /* states (dwork) */
  (void) memset((void *)&pump_test_model_DW, 0,
                sizeof(DW_pump_test_model_T));

  /* external inputs */
  (void) memset((void *)&pump_test_model_U, 0,
                sizeof(ExtU_pump_test_model_T));

  /* external outputs */
  (void) memset((void *)&pump_test_model_Y, 0,
                sizeof(ExtY_pump_test_model_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(pump_test_model_M->rtwLogInfo, 0.0,
    rtmGetTFinal(pump_test_model_M), pump_test_model_M->Timing.stepSize0,
    (&rtmGetErrorStatus(pump_test_model_M)));

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  pump_test_model_X.Integrator_CSTATE = pump_test_model_P.Integrator_IC;
}

/* Model terminate function */
void pump_test_model_terminate(void)
{
  /* (no terminate code required) */
}
