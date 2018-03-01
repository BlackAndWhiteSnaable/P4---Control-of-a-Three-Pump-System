/*
 * feedback_plant_data.c
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

#include "feedback_plant.h"
#include "feedback_plant_private.h"

/* Constant parameters (auto storage) */
const ConstP_feedback_plant_T feedback_plant_ConstP = {
  /* Expression: gain
   * Referenced by: '<S10>/transform'
   */
  { 0.1, 1.0638297872340425, 1.0, 200.0, 4.0, 0.74119680851063829,
    0.33244680851063829, 720.0, 1.0638297872340425, 1.0, 200.0, 4.0,
    0.74119680851063829, 1.3297872340425532, 720.0, 1.0638297872340425, 1.0,
    200.0, 4.0, 0.74119680851063829, 0.33244680851063829, 720.0 },

  /* Expression: offset
   * Referenced by: '<S10>/transform'
   */
  { 0.0, 3.0, 0.0, 0.0, -210.0, 1.39345, 0.62499999999999989, 0.0, 3.0, 0.0, 0.0,
    -210.0, 1.39345, 2.4999999999999996, 0.0, 3.0, 0.0, 0.0, -210.0, 1.39345,
    0.62499999999999989, 0.0 },

  /* Computed Parameter: src_P1_Size
   * Referenced by: '<S10>/src'
   */
  { 1.0, 22.0 },

  /* Expression: channel
   * Referenced by: '<S10>/src'
   */
  { 4.0, 17.0, 5.0, 11.0, 8.0, 21.0, 24.0, 1.0, 18.0, 6.0, 12.0, 9.0, 22.0, 25.0,
    2.0, 19.0, 7.0, 13.0, 10.0, 23.0, 26.0, 3.0 },

  /* Computed Parameter: src_P2_Size
   * Referenced by: '<S10>/src'
   */
  { 1.0, 22.0 },

  /* Expression: range
   * Referenced by: '<S10>/src'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: src_P3_Size
   * Referenced by: '<S10>/src'
   */
  { 1.0, 22.0 },

  /* Expression: coupling
   * Referenced by: '<S10>/src'
   */
  { 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0 },

  /* Computed Parameter: src_P4_Size
   * Referenced by: '<S10>/src'
   */
  { 1.0, 1.0 },

  /* Expression: scantime
   * Referenced by: '<S10>/src'
   */
  5.0E-6,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: sampletime)
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  0.01,

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  { 1.0, 2.0 },

  /* Pooled Parameter (Expression: slot)
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  { 3.0, 1.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  { 1.0, 1.0 },

  /* Pooled Parameter (Expression: boardType)
   * Referenced by:
   *   '<S9>/DA_sink'
   *   '<S10>/src'
   */
  29.0,

  /* Computed Parameter: DA_sink_P1_Size
   * Referenced by: '<S9>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Expression: channel
   * Referenced by: '<S9>/DA_sink'
   */
  { 4.0, 1.0, 2.0, 3.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by: '<S9>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S9>/DA_sink'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: DA_sink_P3_Size
   * Referenced by: '<S9>/DA_sink'
   */
  { 1.0, 4.0 },

  /* Expression: reset
   * Referenced by: '<S9>/DA_sink'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /* Expression: sensnames
   * Referenced by: '<S13>/sname'
   */
  { 67U, 86U, 48U, 49U, 47U, 68U, 80U, 84U, 48U, 49U, 47U, 76U, 77U, 71U, 67U,
    49U, 47U, 76U, 77U, 71U, 80U, 49U, 47U, 76U, 77U, 71U, 86U, 49U, 47U, 77U,
    70U, 77U, 48U, 49U, 47U, 80U, 84U, 48U, 49U, 47U, 87U, 80U, 48U, 49U, 47U,
    68U, 80U, 84U, 48U, 50U, 47U, 76U, 77U, 71U, 67U, 50U, 47U, 76U, 77U, 71U,
    80U, 50U, 47U, 76U, 77U, 71U, 86U, 50U, 47U, 77U, 70U, 77U, 48U, 50U, 47U,
    80U, 84U, 48U, 50U, 47U, 87U, 80U, 48U, 50U, 47U, 68U, 80U, 84U, 48U, 51U,
    47U, 76U, 77U, 71U, 67U, 51U, 47U, 76U, 77U, 71U, 80U, 51U, 47U, 76U, 77U,
    71U, 86U, 51U, 47U, 77U, 70U, 77U, 48U, 51U, 47U, 80U, 84U, 48U, 51U, 47U,
    87U, 80U, 48U, 51U }
};
