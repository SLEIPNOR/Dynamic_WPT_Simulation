/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi_2layers.c
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

/* Block signals (default storage) */
B_Raspi_2layers_T Raspi_2layers_B;

/* Block states (default storage) */
DW_Raspi_2layers_T Raspi_2layers_DW;

/* Real-time model */
static RT_MODEL_Raspi_2layers_T Raspi_2layers_M_;
RT_MODEL_Raspi_2layers_T *const Raspi_2layers_M = &Raspi_2layers_M_;

/*
 * System initialize for action system:
 *    '<S1>/If Action Subsystem2'
 *    '<S1>/If Action Subsystem3'
 */
void Raspi_2_IfActionSubsystem2_Init(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, DW_IfActionSubsystem2_Raspi_2_T *localDW,
  P_IfActionSubsystem2_Raspi_2l_T *localP)
{
  char_T *sErr;

  /* Start for S-Function (sdspToNetwork): '<S4>/UDP Send' */
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  CreateUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr == 0) {
    LibCreate_Network(&localDW->UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                      "172.20.10.2", localP->UDPSend_Port, 8192, 8, 0);
  }

  if (*sErr == 0) {
    LibStart(&localDW->UDPSend_NetworkLib[0U]);
  }

  if (*sErr != 0) {
    DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
    if (*sErr != 0) {
      rtmSetErrorStatus(Raspi_2layers_M, sErr);
      rtmSetStopRequested(Raspi_2layers_M, 1);
    }
  }

  /* End of Start for S-Function (sdspToNetwork): '<S4>/UDP Send' */
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem2'
 *    '<S1>/If Action Subsystem3'
 */
void Raspi_2layer_IfActionSubsystem2(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, const real_T rtu_Tx_no[2], DW_IfActionSubsystem2_Raspi_2_T
  *localDW)
{
  char_T *sErr;

  /* Update for S-Function (sdspToNetwork): '<S4>/UDP Send' */
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &rtu_Tx_no[0U], 2);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S4>/UDP Send' */
}

/*
 * Termination for action system:
 *    '<S1>/If Action Subsystem2'
 *    '<S1>/If Action Subsystem3'
 */
void Raspi_2_IfActionSubsystem2_Term(RT_MODEL_Raspi_2layers_T * const
  Raspi_2layers_M, DW_IfActionSubsystem2_Raspi_2_T *localDW)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspToNetwork): '<S4>/UDP Send' */
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  LibDestroy(&localDW->UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S4>/UDP Send' */
}

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
void Raspi_2layers_step(void)
{
  real_T k_diff;
  int32_T rtb_Cr;
  char_T *sErr;
  static const int8_T b[16] = { -1, -1, 0, 1, 1, 0, 1, -1, -1, 0, -1, 1, 0, 1,
    -1, 1 };

  /* Reset subsysRan breadcrumbs */
  srClearBC(Raspi_2layers_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Raspi_2layers_DW.IfActionSubsystem1_SubsysRanBC);

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
  rtb_Cr = 4;
  LibOutputs_Network(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U],
                     &Raspi_2layers_B.UDPReceive1_o1[0U], &rtb_Cr);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */
  sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
  rtb_Cr = 4;
  LibOutputs_Network(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U],
                     &Raspi_2layers_B.UDPReceive2_o1[0U], &rtb_Cr);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Delay: '<Root>/Delay3'
   *  S-Function (sdspFromNetwork): '<Root>/UDP Receive1'
   */
  Raspi_2layers_B.ip[0] = Raspi_2layers_B.UDPReceive1_o1[0];
  Raspi_2layers_B.ip[1] = Raspi_2layers_B.UDPReceive1_o1[1];
  Raspi_2layers_B.ip[2] = Raspi_2layers_B.UDPReceive1_o1[2];
  Raspi_2layers_B.ip[3] = Raspi_2layers_B.UDPReceive1_o1[3];
  if (Raspi_2layers_B.ip[1] == Raspi_2layers_DW.Delay3_DSTATE) {
    rtb_Cr = 0;
  } else {
    Raspi_2layers_DW.Delay3_DSTATE = Raspi_2layers_B.ip[1];
    rtb_Cr = 1;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* If: '<Root>/If' incorporates:
   *  Constant: '<S3>/Constant'
   *  Delay: '<Root>/Delay'
   *  Math: '<S3>/Math Function'
   *  Product: '<S3>/Product'
   */
  if (((rt_modd_snf(Raspi_2layers_B.ip[1], Raspi_2layers_P.Constant_Value) ==
        0.0) && (Raspi_2layers_B.ip[0] * Raspi_2layers_B.ip[1] != 0.0) &&
       (rtb_Cr != 0)) || ((Raspi_2layers_DW.Delay_DSTATE > 1.0) && (rtb_Cr != 0)))
  {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
     *  Delay: '<S1>/Delay4'
     *  S-Function (sdspFromNetwork): '<Root>/UDP Receive2'
     */
    if (Raspi_2layers_DW.Delay4_DSTATE <= 2.0) {
      Raspi_2layers_B.y[0] = Raspi_2layers_B.ip[0];
      Raspi_2layers_B.y[1] = Raspi_2layers_B.ip[1];
      Raspi_2layers_B.y[2] = Raspi_2layers_B.ip[2];
      Raspi_2layers_B.y[3] = Raspi_2layers_B.ip[3];
    } else {
      Raspi_2layers_B.y[0] = Raspi_2layers_B.UDPReceive2_o1[0];
      Raspi_2layers_B.y[1] = Raspi_2layers_B.UDPReceive2_o1[1];
      Raspi_2layers_B.y[2] = Raspi_2layers_B.UDPReceive2_o1[2];
      Raspi_2layers_B.y[3] = Raspi_2layers_B.UDPReceive2_o1[3];
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function1' */

    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant2'
     *  Delay: '<S1>/Delay1'
     *  Delay: '<S1>/Delay3'
     *  Delay: '<S1>/Delay4'
     */
    Raspi_2layers_B.t = Raspi_2layers_DW.Delay4_DSTATE;
    for (rtb_Cr = 0; rtb_Cr < 6; rtb_Cr++) {
      Raspi_2layers_B.k_d_m[rtb_Cr] = Raspi_2layers_DW.Delay1_DSTATE[rtb_Cr];
    }

    memcpy(&Raspi_2layers_B.Tx_m[0], &Raspi_2layers_DW.Delay3_DSTATE_o[0],
           sizeof(real_T) << 4U);
    k_diff = fabs(Raspi_2layers_P.Constant1_Value - Raspi_2layers_B.y[0]) /
      Raspi_2layers_P.Constant1_Value;
    if (Raspi_2layers_B.t == 0.0) {
      Raspi_2layers_B.t++;
      Raspi_2layers_B.k_d_m[0] = k_diff;
      Raspi_2layers_B.k_d_m[1] = k_diff;
      Raspi_2layers_B.k_d_m[2] = Raspi_2layers_B.y[2];
      Raspi_2layers_B.k_d_m[3] = Raspi_2layers_B.y[2];
      Raspi_2layers_B.k_d_m[4] = Raspi_2layers_B.y[3];
      Raspi_2layers_B.k_d_m[5] = Raspi_2layers_B.y[3];
    } else if (k_diff < Raspi_2layers_B.k_d_m[1]) {
      Raspi_2layers_B.k_d_m[1] = k_diff;
      Raspi_2layers_B.k_d_m[3] = Raspi_2layers_B.y[2];
      Raspi_2layers_B.k_d_m[5] = Raspi_2layers_B.y[3];
    }

    Raspi_2layers_B.G = rt_roundd_snf(Raspi_2layers_P.Constant2_Value *
      Raspi_2layers_B.k_d_m[0]);
    if (Raspi_2layers_B.G > 1.0) {
      Raspi_2layers_B.G = 1.0;
      printf("%s\n", "Gain exceed!!!");
      fflush(stdout);
    }

    if (Raspi_2layers_B.t < 10.0) {
      if (Raspi_2layers_B.t < 9.0) {
        if (Raspi_2layers_B.G == 0.0) {
          Raspi_2layers_B.Tx_no[0] = 0.0;
          Raspi_2layers_B.Tx_no[1] = 0.0;
        } else {
          Raspi_2layers_B.Tx_no[0] = (real_T)b[(int32_T)Raspi_2layers_B.t - 1] *
            Raspi_2layers_B.G + Raspi_2layers_B.k_d_m[2];
          Raspi_2layers_B.Tx_m[(int32_T)Raspi_2layers_B.t - 1] =
            Raspi_2layers_B.Tx_no[0];
          Raspi_2layers_B.Tx_no[1] = (real_T)b[(int32_T)Raspi_2layers_B.t + 7] *
            Raspi_2layers_B.G + Raspi_2layers_B.k_d_m[4];
          Raspi_2layers_B.Tx_m[(int32_T)Raspi_2layers_B.t + 7] =
            Raspi_2layers_B.Tx_no[1];
        }
      } else {
        Raspi_2layers_B.Tx_no[0] = 0.0;
        Raspi_2layers_B.Tx_no[1] = 0.0;
      }

      Raspi_2layers_B.t++;
    } else {
      Raspi_2layers_B.Tx_no[0] = Raspi_2layers_B.k_d_m[3];
      Raspi_2layers_B.Tx_no[1] = Raspi_2layers_B.k_d_m[5];
      Raspi_2layers_B.t = 0.0;
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function' */
    /* If: '<S1>/If1' */
    if (Raspi_2layers_B.t == 0.0) {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      Raspi_2layer_IfActionSubsystem2(Raspi_2layers_M, Raspi_2layers_B.Tx_no,
        &Raspi_2layers_DW.IfActionSubsystem2);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      Raspi_2layer_IfActionSubsystem2(Raspi_2layers_M, Raspi_2layers_B.Tx_no,
        &Raspi_2layers_DW.IfActionSubsystem3);

      /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
    }

    /* End of If: '<S1>/If1' */
    /* Update for Delay: '<S1>/Delay3' */
    memcpy(&Raspi_2layers_DW.Delay3_DSTATE_o[0], &Raspi_2layers_B.Tx_m[0],
           sizeof(real_T) << 4U);

    /* Update for Delay: '<S1>/Delay4' */
    Raspi_2layers_DW.Delay4_DSTATE = Raspi_2layers_B.t;

    /* Update for Delay: '<S1>/Delay1' */
    for (rtb_Cr = 0; rtb_Cr < 6; rtb_Cr++) {
      Raspi_2layers_DW.Delay1_DSTATE[rtb_Cr] = Raspi_2layers_B.k_d_m[rtb_Cr];
    }

    /* End of Update for Delay: '<S1>/Delay1' */
    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(Raspi_2layers_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */
  /* Update for Delay: '<Root>/Delay' */
  Raspi_2layers_DW.Delay_DSTATE = Raspi_2layers_B.t;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Raspi_2layers_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Raspi_2layers_M)!=-1) &&
        !((rtmGetTFinal(Raspi_2layers_M)-Raspi_2layers_M->Timing.taskTime0) >
          Raspi_2layers_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Raspi_2layers_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Raspi_2layers_M)) {
      rtmSetErrorStatus(Raspi_2layers_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Raspi_2layers_M->Timing.taskTime0 =
    ((time_T)(++Raspi_2layers_M->Timing.clockTick0)) *
    Raspi_2layers_M->Timing.stepSize0;
}

/* Model initialize function */
void Raspi_2layers_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Raspi_2layers_M, -1);
  Raspi_2layers_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Raspi_2layers_M->Sizes.checksums[0] = (1031768798U);
  Raspi_2layers_M->Sizes.checksums[1] = (399740300U);
  Raspi_2layers_M->Sizes.checksums[2] = (3031699422U);
  Raspi_2layers_M->Sizes.checksums[3] = (2882087764U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Raspi_2layers_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &Raspi_2layers_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &Raspi_2layers_DW.IfActionSubsystem3.IfActionSubsystem2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Raspi_2layers_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Raspi_2layers_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Raspi_2layers_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Raspi_2layers_M->extModeInfo,
      &Raspi_2layers_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Raspi_2layers_M->extModeInfo,
                        Raspi_2layers_M->Sizes.checksums);
    rteiSetTPtr(Raspi_2layers_M->extModeInfo, rtmGetTPtr(Raspi_2layers_M));
  }

  {
    int32_T i;
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
    sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U], 0,
                        "0.0.0.0", Raspi_2layers_P.UDPReceive1_Port, "0.0.0.0",
                        -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Raspi_2layers_M, sErr);
        rtmSetStopRequested(Raspi_2layers_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */
    sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U], 0,
                        "0.0.0.0", Raspi_2layers_P.UDPReceive2_Port, "0.0.0.0",
                        -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Raspi_2layers_M, sErr);
        rtmSetStopRequested(Raspi_2layers_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */

    /* InitializeConditions for Delay: '<Root>/Delay' */
    Raspi_2layers_DW.Delay_DSTATE = Raspi_2layers_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay3' */
    Raspi_2layers_DW.Delay3_DSTATE = Raspi_2layers_P.Delay3_InitialCondition_f;

    /* InitializeConditions for Delay: '<S1>/Delay3' */
    memcpy(&Raspi_2layers_DW.Delay3_DSTATE_o[0],
           &Raspi_2layers_P.Delay3_InitialCondition[0], sizeof(real_T) << 4U);

    /* InitializeConditions for Delay: '<S1>/Delay4' */
    Raspi_2layers_DW.Delay4_DSTATE = Raspi_2layers_P.Delay4_InitialCondition;

    /* InitializeConditions for Delay: '<S1>/Delay1' */
    for (i = 0; i < 6; i++) {
      Raspi_2layers_DW.Delay1_DSTATE[i] =
        Raspi_2layers_P.Delay1_InitialCondition[i];
    }

    /* End of InitializeConditions for Delay: '<S1>/Delay1' */

    /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem2' */
    Raspi_2_IfActionSubsystem2_Init(Raspi_2layers_M,
      &Raspi_2layers_DW.IfActionSubsystem2, &Raspi_2layers_P.IfActionSubsystem2);

    /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem2' */

    /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem3' */
    Raspi_2_IfActionSubsystem2_Init(Raspi_2layers_M,
      &Raspi_2layers_DW.IfActionSubsystem3, &Raspi_2layers_P.IfActionSubsystem3);

    /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem3' */

    /* SystemInitialize for Outport: '<S1>/t' */
    Raspi_2layers_B.t = Raspi_2layers_P.t_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem1' */
  }
}

/* Model terminate function */
void Raspi_2layers_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  LibDestroy(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&Raspi_2layers_DW.UDPReceive1_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */
  sErr = GetErrorBuffer(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
  LibTerminate(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Raspi_2layers_M, sErr);
    rtmSetStopRequested(Raspi_2layers_M, 1);
  }

  LibDestroy(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&Raspi_2layers_DW.UDPReceive2_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive2' */
  /* Terminate for IfAction SubSystem: '<S1>/If Action Subsystem2' */
  Raspi_2_IfActionSubsystem2_Term(Raspi_2layers_M,
    &Raspi_2layers_DW.IfActionSubsystem2);

  /* End of Terminate for SubSystem: '<S1>/If Action Subsystem2' */

  /* Terminate for IfAction SubSystem: '<S1>/If Action Subsystem3' */
  Raspi_2_IfActionSubsystem2_Term(Raspi_2layers_M,
    &Raspi_2layers_DW.IfActionSubsystem3);

  /* End of Terminate for SubSystem: '<S1>/If Action Subsystem3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
