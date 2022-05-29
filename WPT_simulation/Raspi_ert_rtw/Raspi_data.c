/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi_data.c
 *
 * Code generated for Simulink model 'Raspi'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun May 29 01:02:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Raspi.h"
#include "Raspi_private.h"

/* Block parameters (default storage) */
P_Raspi_T Raspi_P = {
  /* Computed Parameter: t_Y0
   * Referenced by: '<S1>/t'
   */
  0.0,

  /* Expression: zeros(8,2)
   * Referenced by: '<S1>/Delay3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: 0.048
   * Referenced by: '<S1>/k_opt'
   */
  0.048,

  /* Expression: 1
   * Referenced by: '<S1>/g'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay4'
   */
  0.0,

  /* Expression: zeros(2,3)
   * Referenced by: '<S1>/Delay1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay3'
   */
  0.0,

  /* Expression: 0.12
   * Referenced by: '<S3>/Constant'
   */
  0.12,

  /* Computed Parameter: UDPSend_Port
   * Referenced by: '<S1>/UDP Send '
   */
  2000,

  /* Computed Parameter: UDPReceive_Port
   * Referenced by: '<Root>/UDP Receive '
   */
  1000
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
