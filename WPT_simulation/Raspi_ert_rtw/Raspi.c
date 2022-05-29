/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi.c
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

/* Block signals (default storage) */
B_Raspi_T Raspi_B;

/* Block states (default storage) */
DW_Raspi_T Raspi_DW;

/* Real-time model */
static RT_MODEL_Raspi_T Raspi_M_;
RT_MODEL_Raspi_T *const Raspi_M = &Raspi_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Raspi_step(void)
{
  real_T k_d_m_tmp_idx_1;
  real_T k_d_m_tmp_idx_2;
  real_T k_diff;
  int32_T rtb_Cr;
  char_T *sErr;
  static const int8_T b[16] = { -1, -1, 0, 1, 1, 0, 1, -1, -1, 0, -1, 1, 0, 1,
    -1, 1 };

  /* Reset subsysRan breadcrumbs */
  srClearBC(Raspi_DW.IfActionSubsystem_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */
  sErr = GetErrorBuffer(&Raspi_DW.UDPReceive_NetworkLib[0U]);
  rtb_Cr = 4;
  LibOutputs_Network(&Raspi_DW.UDPReceive_NetworkLib[0U],
                     &Raspi_B.UDPReceive_o1[0U], &rtb_Cr);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_M, sErr);
    rtmSetStopRequested(Raspi_M, 1);
  }

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */

  /* MATLAB Function: '<Root>/blocker' incorporates:
   *  Delay: '<Root>/Delay3'
   */
  if (Raspi_B.UDPReceive_o1[1] == Raspi_DW.Delay3_DSTATE) {
    rtb_Cr = 0;
  } else {
    Raspi_DW.Delay3_DSTATE = Raspi_B.UDPReceive_o1[1];
    rtb_Cr = 1;
  }

  /* End of MATLAB Function: '<Root>/blocker' */

  /* If: '<Root>/If' incorporates:
   *  Constant: '<S3>/Constant'
   *  Delay: '<Root>/Delay'
   *  Math: '<S3>/Math Function'
   *  Product: '<S3>/Product'
   */
  if (((rt_modd_snf(Raspi_B.UDPReceive_o1[1], Raspi_P.Constant_Value) == 0.0) &&
       (Raspi_B.UDPReceive_o1[0] * Raspi_B.UDPReceive_o1[1] != 0.0) && (rtb_Cr
        != 0)) || ((Raspi_DW.Delay_DSTATE > 1.0) && (rtb_Cr != 0))) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem ' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLAB Function: '<S1>/Controller' incorporates:
     *  Constant: '<S1>/g'
     *  Constant: '<S1>/k_opt'
     *  Delay: '<S1>/Delay1'
     *  Delay: '<S1>/Delay4'
     */
    Raspi_DW.Delay_DSTATE = Raspi_DW.Delay4_DSTATE;
    k_diff = fabs(Raspi_P.k_opt_Value - Raspi_B.UDPReceive_o1[0]) /
      Raspi_P.k_opt_Value;
    if (Raspi_DW.Delay_DSTATE == 0.0) {
      Raspi_DW.Delay_DSTATE++;
      k_d_m_tmp_idx_1 = Raspi_B.UDPReceive_o1[2];
      k_d_m_tmp_idx_2 = Raspi_B.UDPReceive_o1[3];
      Raspi_DW.Delay1_DSTATE[0] = k_diff;
      Raspi_DW.Delay1_DSTATE[1] = k_diff;
      Raspi_DW.Delay1_DSTATE[2] = k_d_m_tmp_idx_1;
      Raspi_DW.Delay1_DSTATE[3] = k_d_m_tmp_idx_1;
      Raspi_DW.Delay1_DSTATE[4] = k_d_m_tmp_idx_2;
      Raspi_DW.Delay1_DSTATE[5] = k_d_m_tmp_idx_2;
    } else if (k_diff < Raspi_DW.Delay1_DSTATE[1]) {
      Raspi_DW.Delay1_DSTATE[1] = k_diff;
      Raspi_DW.Delay1_DSTATE[3] = Raspi_B.UDPReceive_o1[2];
      Raspi_DW.Delay1_DSTATE[5] = Raspi_B.UDPReceive_o1[3];
    }

    k_diff = rt_roundd_snf(Raspi_P.g_Value * Raspi_DW.Delay1_DSTATE[0]);
    if (Raspi_DW.Delay_DSTATE < 10.0) {
      if (Raspi_DW.Delay_DSTATE < 9.0) {
        Raspi_B.Tx_no[0] = (real_T)b[(int32_T)Raspi_DW.Delay_DSTATE - 1] *
          k_diff + Raspi_DW.Delay1_DSTATE[2];
        Raspi_B.Tx_no[1] = (real_T)b[(int32_T)Raspi_DW.Delay_DSTATE + 7] *
          k_diff + Raspi_DW.Delay1_DSTATE[4];
      } else {
        Raspi_B.Tx_no[0] = Raspi_DW.Delay1_DSTATE[3];
        Raspi_B.Tx_no[1] = Raspi_DW.Delay1_DSTATE[5];
      }

      Raspi_DW.Delay_DSTATE++;
    } else {
      Raspi_B.Tx_no[0] = Raspi_DW.Delay1_DSTATE[3];
      Raspi_B.Tx_no[1] = Raspi_DW.Delay1_DSTATE[5];
      Raspi_DW.Delay_DSTATE = 0.0;
    }

    /* End of MATLAB Function: '<S1>/Controller' */

    /* Update for Delay: '<S1>/Delay4' */
    Raspi_DW.Delay4_DSTATE = Raspi_DW.Delay_DSTATE;

    /* Update for S-Function (sdspToNetwork): '<S1>/UDP Send ' */
    sErr = GetErrorBuffer(&Raspi_DW.UDPSend_NetworkLib[0U]);
    LibUpdate_Network(&Raspi_DW.UDPSend_NetworkLib[0U], &Raspi_B.Tx_no[0U], 2);
    if (*sErr != 0) {
      rtmSetErrorStatus(Raspi_M, sErr);
      rtmSetStopRequested(Raspi_M, 1);
    }

    /* End of Update for S-Function (sdspToNetwork): '<S1>/UDP Send ' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem ' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem ' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(Raspi_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem ' */
  }

  /* End of If: '<Root>/If' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Raspi_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0001s, 0.0s] */
    if ((rtmGetTFinal(Raspi_M)!=-1) &&
        !((rtmGetTFinal(Raspi_M)-Raspi_M->Timing.taskTime0) >
          Raspi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Raspi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Raspi_M)) {
      rtmSetErrorStatus(Raspi_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Raspi_M->Timing.taskTime0 =
    ((time_T)(++Raspi_M->Timing.clockTick0)) * Raspi_M->Timing.stepSize0;
}

/* Model initialize function */
void Raspi_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Raspi_M, -1);
  Raspi_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  Raspi_M->Sizes.checksums[0] = (2232390633U);
  Raspi_M->Sizes.checksums[1] = (4232844574U);
  Raspi_M->Sizes.checksums[2] = (1676532445U);
  Raspi_M->Sizes.checksums[3] = (286059761U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Raspi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Raspi_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Raspi_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Raspi_M->extModeInfo,
      &Raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Raspi_M->extModeInfo, Raspi_M->Sizes.checksums);
    rteiSetTPtr(Raspi_M->extModeInfo, rtmGetTPtr(Raspi_M));
  }

  {
    int32_T i;
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */
    sErr = GetErrorBuffer(&Raspi_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&Raspi_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Raspi_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        Raspi_P.UDPReceive_Port, "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Raspi_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Raspi_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Raspi_M, sErr);
        rtmSetStopRequested(Raspi_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */

    /* InitializeConditions for Delay: '<Root>/Delay' */
    Raspi_DW.Delay_DSTATE = Raspi_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay3' */
    Raspi_DW.Delay3_DSTATE = Raspi_P.Delay3_InitialCondition_h;

    /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem ' */
    /* Start for S-Function (sdspToNetwork): '<S1>/UDP Send ' */
    sErr = GetErrorBuffer(&Raspi_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&Raspi_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Raspi_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "172.20.10.2", Raspi_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Raspi_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Raspi_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Raspi_M, sErr);
        rtmSetStopRequested(Raspi_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<S1>/UDP Send ' */

    /* InitializeConditions for Delay: '<S1>/Delay4' */
    Raspi_DW.Delay4_DSTATE = Raspi_P.Delay4_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    for (i = 0; i < 6; i++) {
      Raspi_DW.Delay1_DSTATE[i] = Raspi_P.Delay1_InitialCondition[i];
    }

    /* End of InitializeConditions for Delay: '<S1>/Delay1' */

    /* SystemInitialize for Outport: '<S1>/t' incorporates:
     *  Delay: '<Root>/Delay'
     */
    Raspi_DW.Delay_DSTATE = Raspi_P.t_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem ' */
  }
}

/* Model terminate function */
void Raspi_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */
  sErr = GetErrorBuffer(&Raspi_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&Raspi_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_M, sErr);
    rtmSetStopRequested(Raspi_M, 1);
  }

  LibDestroy(&Raspi_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&Raspi_DW.UDPReceive_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive ' */

  /* Terminate for IfAction SubSystem: '<Root>/If Action Subsystem ' */
  /* Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send ' */
  sErr = GetErrorBuffer(&Raspi_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&Raspi_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_M, sErr);
    rtmSetStopRequested(Raspi_M, 1);
  }

  LibDestroy(&Raspi_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&Raspi_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send ' */
  /* End of Terminate for SubSystem: '<Root>/If Action Subsystem ' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
