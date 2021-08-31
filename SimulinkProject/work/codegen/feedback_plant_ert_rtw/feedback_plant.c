/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_plant.c
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

#include "feedback_plant.h"

/* Named constants for Chart: '<Root>/Chart' */
#define feedback_IN_RESPONS_ECHO_SIGNAL ((uint8_T)1U)
#define feedback_pla_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_plant_IN_WAIT_TO_FALL ((uint8_T)2U)
#define feedback_plant_IN_WAIT_TO_RISE ((uint8_T)3U)

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/* Model step function */
void feedback_plant_step(RT_MODEL_feedback_plant_T *const feedback_plant_M,
  boolean_T feedback_plant_U_trig_signal, real_T feedback_plant_U_distance_cm,
  boolean_T *feedback_plant_Y_echo_signal)
{
  DW_feedback_plant_T *feedback_plant_DW = feedback_plant_M->dwork;
  real_T rtb_distance;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Inport: '<Root>/distance_cm'
   */
  if (feedback_plant_U_distance_cm > 400.0) {
    rtb_distance = 400.0;
  } else {
    rtb_distance = feedback_plant_U_distance_cm;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (!(rtb_distance >= 2.0)) {
    rtb_distance = 2.0;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/trig_signal'
   *  Product: '<S2>/Product'
   */
  if (feedback_plant_DW->temporalCounter_i1 < MAX_uint32_T) {
    feedback_plant_DW->temporalCounter_i1++;
  }

  if (feedback_plant_DW->is_active_c3_feedback_plant == 0U) {
    feedback_plant_DW->is_active_c3_feedback_plant = 1U;
    feedback_plant_DW->is_c3_feedback_plant = feedback_plant_IN_WAIT_TO_RISE;
  } else {
    switch (feedback_plant_DW->is_c3_feedback_plant) {
     case feedback_IN_RESPONS_ECHO_SIGNAL:
      if ((uint32_T)((int32_T)feedback_plant_DW->temporalCounter_i1 * 10) >=
          (uint32_T)ceil(rtb_distance * 58.0)) {
        /* Outport: '<Root>/echo_signal' */
        *feedback_plant_Y_echo_signal = false;
        feedback_plant_DW->is_c3_feedback_plant = feedback_plant_IN_WAIT_TO_RISE;
      }
      break;

     case feedback_plant_IN_WAIT_TO_FALL:
      if (!feedback_plant_U_trig_signal) {
        feedback_plant_DW->is_c3_feedback_plant = feedback_plant_IN_WAIT_TO_RISE;
      } else {
        if (feedback_plant_DW->temporalCounter_i1 >= 1U) {
          feedback_plant_DW->is_c3_feedback_plant =
            feedback_IN_RESPONS_ECHO_SIGNAL;
          feedback_plant_DW->temporalCounter_i1 = 0U;

          /* Outport: '<Root>/echo_signal' */
          *feedback_plant_Y_echo_signal = true;
        }
      }
      break;

     default:
      /* case IN_WAIT_TO_RISE: */
      if (feedback_plant_U_trig_signal) {
        feedback_plant_DW->is_c3_feedback_plant = feedback_plant_IN_WAIT_TO_FALL;
        feedback_plant_DW->temporalCounter_i1 = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void feedback_plant_initialize(RT_MODEL_feedback_plant_T *const feedback_plant_M,
  boolean_T *feedback_plant_U_trig_signal, real_T *feedback_plant_U_distance_cm,
  boolean_T *feedback_plant_Y_echo_signal)
{
  DW_feedback_plant_T *feedback_plant_DW = feedback_plant_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)feedback_plant_DW, 0,
                sizeof(DW_feedback_plant_T));

  /* external inputs */
  *feedback_plant_U_trig_signal = false;
  *feedback_plant_U_distance_cm = 0.0;

  /* external outputs */
  (*feedback_plant_Y_echo_signal) = false;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  feedback_plant_DW->temporalCounter_i1 = 0U;
  feedback_plant_DW->is_active_c3_feedback_plant = 0U;
  feedback_plant_DW->is_c3_feedback_plant = feedback_pla_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void feedback_plant_terminate(RT_MODEL_feedback_plant_T *const feedback_plant_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(feedback_plant_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
