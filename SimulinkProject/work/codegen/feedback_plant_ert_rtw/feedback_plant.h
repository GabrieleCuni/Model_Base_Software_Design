/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_plant.h
 *
 * Code generated for Simulink model 'feedback_plant'.
 *
 * Model version                  : 10.19
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sat Jun 19 12:11:53 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_plant_h_
#define RTW_HEADER_feedback_plant_h_
#include <math.h>
#include <string.h>
#ifndef feedback_plant_COMMON_INCLUDES_
#define feedback_plant_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_plant_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_plant_T RT_MODEL_feedback_plant_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_feedback_plant; /* '<Root>/Chart' */
  uint8_T is_c3_feedback_plant;        /* '<Root>/Chart' */
} DW_feedback_plant_T;

/* Real-time Model Data Structure */
struct tag_RTM_feedback_plant_T {
  const char_T * volatile errorStatus;
  DW_feedback_plant_T *dwork;
};

/* Model entry point functions */
extern void feedback_plant_initialize(RT_MODEL_feedback_plant_T *const
  feedback_plant_M, boolean_T *feedback_plant_U_trig_signal, real_T
  *feedback_plant_U_distance_cm, boolean_T *feedback_plant_Y_echo_signal);
extern void feedback_plant_step(RT_MODEL_feedback_plant_T *const
  feedback_plant_M, boolean_T feedback_plant_U_trig_signal, real_T
  feedback_plant_U_distance_cm, boolean_T *feedback_plant_Y_echo_signal);
extern void feedback_plant_terminate(RT_MODEL_feedback_plant_T *const
  feedback_plant_M);

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
 * '<Root>' : 'feedback_plant'
 * '<S1>'   : 'feedback_plant/Chart'
 * '<S2>'   : 'feedback_plant/Conversion and Bounding'
 */
#endif                                 /* RTW_HEADER_feedback_plant_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
