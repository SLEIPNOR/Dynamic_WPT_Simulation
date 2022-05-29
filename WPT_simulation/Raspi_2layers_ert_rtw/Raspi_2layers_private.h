/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi_2layers_private.h
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

#ifndef RTW_HEADER_Raspi_2layers_private_h_
#define RTW_HEADER_Raspi_2layers_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Raspi_2layers.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void Raspi_2_IfActionSubsystem2_Init(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, DW_IfActionSubsystem2_Raspi_2_T *localDW,
  P_IfActionSubsystem2_Raspi_2l_T *localP);
extern void Raspi_2layer_IfActionSubsystem2(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, const real_T rtu_Tx_no[2], DW_IfActionSubsystem2_Raspi_2_T
  *localDW);
extern void Raspi_2_IfActionSubsystem2_Term(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, DW_IfActionSubsystem2_Raspi_2_T *localDW);

#endif                                 /* RTW_HEADER_Raspi_2layers_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
