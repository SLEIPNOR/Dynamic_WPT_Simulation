/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ras.c
 *
 * Code generated for Simulink model 'ras'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr 11 22:06:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ras.h"
#include "ras_private.h"

/* Block signals (default storage) */
B_ras_T ras_B;

/* Block states (default storage) */
DW_ras_T ras_DW;

/* Real-time model */
static RT_MODEL_ras_T ras_M_;
RT_MODEL_ras_T *const ras_M = &ras_M_;

/* Model step function */
void ras_step(void)
{
  real_T t;
  char_T *sErr;
  static const int8_T b[16] = { -1, -1, 0, 1, 1, 0, 1, -1, -1, 0, -1, 1, 0, 1,
    -1, 1 };

  /* Delay: '<Root>/Delay' */
  ras_B.Delay = ras_DW.Delay_DSTATE;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  ras_B.t = ras_B.Delay;
  ras_B.Tx_no_att[0] = (real_T)b[(int32_T)ras_B.t - 1] * ras_P.Constant2_Value +
    ras_P.Constant_Value;
  ras_B.Tx_no_att[1] = (real_T)b[(int32_T)ras_B.t + 7] * ras_P.Constant2_Value +
    ras_P.Constant_Value;
  t = ras_B.t + 1.0;
  if (ras_B.t + 1.0 == 9.0) {
    t = 1.0;
  }

  ras_B.t = t;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  /* Update for Delay: '<Root>/Delay' */
  ras_DW.Delay_DSTATE = ras_B.t;

  /* Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&ras_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&ras_DW.UDPSend_NetworkLib[0U], &ras_B.Tx_no_att[0U], 2);
  if (*sErr != 0) {
    rtmSetErrorStatus(ras_M, sErr);
    rtmSetStopRequested(ras_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<Root>/UDP Send' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rtExtModeUpload(0, (real_T)ras_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    if ((rtmGetTFinal(ras_M)!=-1) &&
        !((rtmGetTFinal(ras_M)-ras_M->Timing.taskTime0) >
          ras_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ras_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ras_M)) {
      rtmSetErrorStatus(ras_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ras_M->Timing.taskTime0 =
    ((time_T)(++ras_M->Timing.clockTick0)) * ras_M->Timing.stepSize0;
}

/* Model initialize function */
void ras_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(ras_M, -1);
  ras_M->Timing.stepSize0 = 5.0E-5;

  /* External mode info */
  ras_M->Sizes.checksums[0] = (2276987274U);
  ras_M->Sizes.checksums[1] = (893384744U);
  ras_M->Sizes.checksums[2] = (28498414U);
  ras_M->Sizes.checksums[3] = (2927992289U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    ras_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ras_M->extModeInfo,
      &ras_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ras_M->extModeInfo, ras_M->Sizes.checksums);
    rteiSetTPtr(ras_M->extModeInfo, rtmGetTPtr(ras_M));
  }

  {
    char_T *sErr;

    /* Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */
    sErr = GetErrorBuffer(&ras_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&ras_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&ras_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "172.20.10.2", ras_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&ras_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&ras_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(ras_M, sErr);
        rtmSetStopRequested(ras_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<Root>/UDP Send' */

    /* InitializeConditions for Delay: '<Root>/Delay' */
    ras_DW.Delay_DSTATE = ras_P.Delay_InitialCondition;
  }
}

/* Model terminate function */
void ras_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
  sErr = GetErrorBuffer(&ras_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&ras_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(ras_M, sErr);
    rtmSetStopRequested(ras_M, 1);
  }

  LibDestroy(&ras_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&ras_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<Root>/UDP Send' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
