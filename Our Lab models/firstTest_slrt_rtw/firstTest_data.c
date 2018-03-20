/*
 * firstTest_data.c
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

#include "firstTest.h"
#include "firstTest_private.h"

/* Invariant block signals (auto storage) */
const ConstB_firstTest_T firstTest_ConstB = {
  10.0                                 /* '<Root>/%2signal' */
};

/* Constant parameters (auto storage) */
const ConstP_firstTest_T firstTest_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<Root>/PumpSpeed1'
   *   '<Root>/PumpSpeed3'
   *   '<S2>/Constant1'
   *   '<S2>/Step'
   */
  0.0,

  /* Computed Parameter: DA_sink_P1_Size
   * Referenced by: '<Root>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Expression: channel
   * Referenced by: '<Root>/DA_sink'
   */
  { 4.0, 1.0, 2.0, 3.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by: '<Root>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<Root>/DA_sink'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: DA_sink_P3_Size
   * Referenced by: '<Root>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Expression: reset
   * Referenced by: '<Root>/DA_sink'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sampletime)
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  0.01,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: slot)
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  -1.0,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: boardType)
   * Referenced by:
   *   '<Root>/DA_sink'
   *   '<S1>/src'
   */
  29.0,

  /* Computed Parameter: src_P1_Size
   * Referenced by: '<S1>/src'
   */
  { 1.0, 22.0 },

  /* Expression: channel
   * Referenced by: '<S1>/src'
   */
  { 4.0, 17.0, 5.0, 11.0, 8.0, 21.0, 24.0, 1.0, 18.0, 6.0, 12.0, 9.0, 22.0, 25.0,
    2.0, 19.0, 7.0, 13.0, 10.0, 23.0, 26.0, 3.0 },

  /* Computed Parameter: src_P2_Size
   * Referenced by: '<S1>/src'
   */
  { 1.0, 22.0 },

  /* Expression: range
   * Referenced by: '<S1>/src'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: src_P3_Size
   * Referenced by: '<S1>/src'
   */
  { 1.0, 22.0 },

  /* Expression: coupling
   * Referenced by: '<S1>/src'
   */
  { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 },

  /* Computed Parameter: src_P4_Size
   * Referenced by: '<S1>/src'
   */
  { 1.0, 1.0 },

  /* Expression: scantime
   * Referenced by: '<S1>/src'
   */
  5.0E-6
};
