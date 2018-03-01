/*
 * pump_test_model_data.c
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

#include "pump_test_model.h"
#include "pump_test_model_private.h"

/* Block parameters (auto storage) */
P_pump_test_model_T pump_test_model_P = {
  10.0,                                /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  0.0,                                 /* Mask Parameter: PIDController_LowerSaturationLi
                                        * Referenced by:
                                        *   '<S2>/Saturate'
                                        *   '<S7>/DeadZone'
                                        */
  50.0,                                /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_UpperSaturationLi
                                        * Referenced by:
                                        *   '<S2>/Saturate'
                                        *   '<S7>/DeadZone'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/ZeroGain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  0                                    /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S7>/Memory'
                                        */
};
