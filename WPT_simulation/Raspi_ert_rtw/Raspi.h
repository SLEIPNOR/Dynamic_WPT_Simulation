/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Raspi.h
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

#ifndef RTW_HEADER_Raspi_h_
#define RTW_HEADER_Raspi_h_
#include <float.h>
#include <math.h>
#include <stddef.h>
#ifndef Raspi_COMMON_INCLUDES_
#define Raspi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_work.h"
#include "DAHostLib_Network.h"
#endif                                 /* Raspi_COMMON_INCLUDES_ */

#include "Raspi_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UDPReceive_o1[4];             /* '<Root>/UDP Receive ' */
  real_T Tx_no[2];                     /* '<S1>/Controller' */
} B_Raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay3_DSTATE;                /* '<Root>/Delay3' */
  real_T Delay4_DSTATE;                /* '<S1>/Delay4' */
  real_T Delay1_DSTATE[6];             /* '<S1>/Delay1' */
  real_T UDPReceive_NetworkLib[137];   /* '<Root>/UDP Receive ' */
  real_T UDPSend_NetworkLib[137];      /* '<S1>/UDP Send ' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem ' */
} DW_Raspi_T;

/* Parameters (default storage) */
struct P_Raspi_T_ {
  real_T t_Y0;                         /* Computed Parameter: t_Y0
                                        * Referenced by: '<S1>/t'
                                        */
  real_T Delay3_InitialCondition[16];  /* Expression: zeros(8,2)
                                        * Referenced by: '<S1>/Delay3'
                                        */
  real_T k_opt_Value;                  /* Expression: 0.048
                                        * Referenced by: '<S1>/k_opt'
                                        */
  real_T g_Value;                      /* Expression: 1
                                        * Referenced by: '<S1>/g'
                                        */
  real_T Delay4_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay4'
                                        */
  real_T Delay1_InitialCondition[6];   /* Expression: zeros(2,3)
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay3_InitialCondition_h;    /* Expression: 0
                                        * Referenced by: '<Root>/Delay3'
                                        */
  real_T Constant_Value;               /* Expression: 0.12
                                        * Referenced by: '<S3>/Constant'
                                        */
  int32_T UDPSend_Port;                /* Computed Parameter: UDPSend_Port
                                        * Referenced by: '<S1>/UDP Send '
                                        */
  int32_T UDPReceive_Port;             /* Computed Parameter: UDPReceive_Port
                                        * Referenced by: '<Root>/UDP Receive '
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Raspi_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Raspi_T Raspi_P;

/* Block signals (default storage) */
extern B_Raspi_T Raspi_B;

/* Block states (default storage) */
extern DW_Raspi_T Raspi_DW;

/* Model entry point functions */
extern void Raspi_initialize(void);
extern void Raspi_step(void);
extern void Raspi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Raspi_T *const Raspi_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Cast To Double' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Raspi'
 * '<S1>'   : 'Raspi/If Action Subsystem '
 * '<S2>'   : 'Raspi/blocker'
 * '<S3>'   : 'Raspi/trigger'
 * '<S4>'   : 'Raspi/If Action Subsystem /Controller'
 */
#endif                                 /* RTW_HEADER_Raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
