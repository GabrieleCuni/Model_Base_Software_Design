/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.107
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Fri Jun 18 10:43:25 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#include <math.h>
#include <string.h>
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T measures[4];                  /* '<Root>/Chart' */
  real_T echo_pulse_duration_us;       /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint32_T temporalCounter_i3;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i2;         /* '<Root>/Chart' */
  uint8_T is_active_c3_feedback_control;/* '<Root>/Chart' */
  uint8_T is_PROCESSING_LOGIC;         /* '<Root>/Chart' */
  uint8_T is_TRIG_SIGNAL_OFF;          /* '<Root>/Chart' */
  uint8_T is_MONITORING_LOGIC;         /* '<Root>/Chart' */
  uint8_T is_BLINK_OUTRANGE;           /* '<Root>/Chart' */
  uint8_T is_BLINK_INRANGE;            /* '<Root>/Chart' */
  uint8_T is_DISCONNECTED_SENSOR;      /* '<Root>/Chart' */
  uint8_T index;                       /* '<Root>/Chart' */
  boolean_T echo_up_check;             /* '<Root>/Chart' */
} D_Work_feedback_control;

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T * volatile errorStatus;
  D_Work_feedback_control *dwork;
};

/* Model entry point functions */
extern void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, boolean_T *feedback_control_U_echo_signal, boolean_T
  *feedback_control_Y_trig_signal, uint16_T *feedback_control_Y_Level, boolean_T
  *feedback_control_Y_Led);
extern void feedback_control_step(RT_MODEL_feedback_control *const
  feedback_control_M, boolean_T feedback_control_U_echo_signal, boolean_T
  *feedback_control_Y_trig_signal, uint16_T *feedback_control_Y_Level, boolean_T
  *feedback_control_Y_Led);
extern void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M);

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
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/Chart'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
