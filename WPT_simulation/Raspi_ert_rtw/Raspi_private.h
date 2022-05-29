/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi_private.h
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

#ifndef RTW_HEADER_Raspi_private_h_
#define RTW_HEADER_Raspi_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);

#endif                                 /* RTW_HEADER_Raspi_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
