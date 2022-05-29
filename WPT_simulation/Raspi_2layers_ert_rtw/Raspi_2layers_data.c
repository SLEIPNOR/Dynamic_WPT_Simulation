/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi_2layers_data.c
 *
 * Code generated for Simulink model 'Raspi_2layers'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun May 29 01:31:49 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Raspi_2layers.h"
#include "Raspi_2layers_private.h"

/* Block parameters (default storage) */
P_Raspi_2layers_T Raspi_2layers_P = {
  /* Computed Parameter: t_Y0
   * Referenced by: '<S1>/t'
   */
  0.0,

  /* Expression: zeros(8,2)
   * Referenced by: '<S1>/Delay3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: 0
   * Referenced by: '<S1>/Delay4'
   */
  0.0,

  /* Expression: 0.048
   * Referenced by: '<S1>/Constant1'
   */
  0.048,

  /* Expression: 6
   * Referenced by: '<S1>/Constant2'
   */
  6.0,

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

  /* Expression: 0.01
   * Referenced by: '<S3>/Constant'
   */
  0.01,

  /* Computed Parameter: UDPReceive1_Port
   * Referenced by: '<Root>/UDP Receive1'
   */
  1000,

  /* Computed Parameter: UDPReceive2_Port
   * Referenced by: '<Root>/UDP Receive2'
   */
  1100,

  /* Start of '<S1>/If Action Subsystem3' */
  {
    /* Computed Parameter: UDPSend_Port
     * Referenced by: '<S5>/UDP Send'
     */
    2100
  }
  ,

  /* End of '<S1>/If Action Subsystem3' */

  /* Start of '<S1>/If Action Subsystem2' */
  {
    /* Computed Parameter: UDPSend_Port
     * Referenced by: '<S4>/UDP Send'
     */
    2000
  }
  /* End of '<S1>/If Action Subsystem2' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
