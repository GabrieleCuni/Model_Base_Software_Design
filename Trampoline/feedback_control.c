/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
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

#include "feedback_control.h"

/* Named constants for Chart: '<Root>/Chart' */
#define feedback_IN_DISCONNECTED_SENSOR ((uint8_T)3U)
#define feedback_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_con_IN_TRIG_SIGNAL_OFF ((uint8_T)1U)
#define feedback_cont_IN_BLINK_OUTRANGE ((uint8_T)2U)
#define feedback_cont_IN_TRIG_SIGNAL_ON ((uint8_T)2U)
#define feedback_contr_IN_BLINK_INRANGE ((uint8_T)1U)
#define feedback_control_IN_ECHO_DOWN  ((uint8_T)1U)
#define feedback_control_IN_ECHO_UP    ((uint8_T)2U)
#define feedback_control_IN_LED_OFF    ((uint8_T)1U)
#define feedback_control_IN_LED_ON     ((uint8_T)2U)

extern real_T rt_roundd(real_T u);

/* Forward declaration for local functions */
static void feedback_co_exit_atomic_ECHO_UP(uint16_T *feedback_control_Y_Level,
  D_Work_feedback_control *feedback_control_DWork);

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

real_T rt_roundd(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/Chart' */
static void feedback_co_exit_atomic_ECHO_UP(uint16_T *feedback_control_Y_Level,
  D_Work_feedback_control *feedback_control_DWork)
{
  real_T tmp_0;
  int32_T tmp;

  /* Exit 'ECHO_UP': '<S1>:49' */
  feedback_control_DWork->measures[feedback_control_DWork->index - 1] =
    feedback_control_DWork->echo_pulse_duration_us / 58.0;
  tmp_0 = rt_roundd((((feedback_control_DWork->measures[0] +
                       feedback_control_DWork->measures[1]) +
                      feedback_control_DWork->measures[2]) +
                     feedback_control_DWork->measures[3]) / 4.0);
  if (tmp_0 < 65536.0) {
    if (tmp_0 >= 0.0) {
      /* Outport: '<Root>/Level' */
      *feedback_control_Y_Level = (uint16_T)tmp_0;
    } else {
      /* Outport: '<Root>/Level' */
      *feedback_control_Y_Level = 0U;
    }
  } else {
    /* Outport: '<Root>/Level' */
    *feedback_control_Y_Level = MAX_uint16_T;
  }

  tmp = (int32_T)(feedback_control_DWork->index + 1U);
  if ((feedback_control_DWork->index + 1U) > 255U) {
    tmp = 255;
  }

  feedback_control_DWork->index = (uint8_T)tmp;
  if (feedback_control_DWork->index > 4) {
    feedback_control_DWork->index = 1U;
  }
}

/* Model step function */
void feedback_control_step(RT_MODEL_feedback_control *const feedback_control_M,
  boolean_T feedback_control_U_echo_signal, boolean_T
  *feedback_control_Y_trig_signal, uint16_T *feedback_control_Y_Level, boolean_T
  *feedback_control_Y_Led)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/echo_signal'
   *  Outport: '<Root>/Level'
   */
  if (feedback_control_DWork->temporalCounter_i1 < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i1++;
  }

  if (feedback_control_DWork->temporalCounter_i2 < 8191U) {
    feedback_control_DWork->temporalCounter_i2++;
  }

  if (feedback_control_DWork->temporalCounter_i3 < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i3++;
  }

  /* Gateway: Chart */
  /* During: Chart */
  if (feedback_control_DWork->is_active_c3_feedback_control == 0U) {
    /* Entry: Chart */
    feedback_control_DWork->is_active_c3_feedback_control = 1U;

    /* Entry Internal: Chart */
    /* Entry 'PROCESSING_LOGIC': '<S1>:6' */
    /* Entry Internal 'PROCESSING_LOGIC': '<S1>:6' */
    /* Transition: '<S1>:177' */
    feedback_control_DWork->is_PROCESSING_LOGIC =
      feedback_cont_IN_TRIG_SIGNAL_ON;
    feedback_control_DWork->temporalCounter_i1 = 0U;

    /* Outport: '<Root>/trig_signal' */
    /* Entry 'TRIG_SIGNAL_ON': '<S1>:77' */
    *feedback_control_Y_trig_signal = true;

    /* Entry Internal 'MONITORING_LOGIC': '<S1>:60' */
    /* Transition: '<S1>:178' */
    feedback_control_DWork->is_MONITORING_LOGIC =
      feedback_IN_DISCONNECTED_SENSOR;

    /* Entry 'DISCONNECTED_SENSOR': '<S1>:104' */
    /* Entry Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
    /* Transition: '<S1>:167' */
    feedback_control_DWork->is_DISCONNECTED_SENSOR = feedback_control_IN_LED_ON;
    feedback_control_DWork->temporalCounter_i3 = 0U;

    /* Outport: '<Root>/Led' */
    /* Entry 'LED_ON': '<S1>:144' */
    *feedback_control_Y_Led = true;
  } else {
    /* During 'PROCESSING_LOGIC': '<S1>:6' */
    if (feedback_control_DWork->is_PROCESSING_LOGIC ==
        feedback_con_IN_TRIG_SIGNAL_OFF) {
      /* Outport: '<Root>/trig_signal' */
      *feedback_control_Y_trig_signal = false;

      /* During 'TRIG_SIGNAL_OFF': '<S1>:79' */
      if (feedback_control_DWork->temporalCounter_i2 >= 6000U) {
        /* Transition: '<S1>:84' */
        /* Exit Internal 'TRIG_SIGNAL_OFF': '<S1>:79' */
        if (feedback_control_DWork->is_TRIG_SIGNAL_OFF ==
            feedback_control_IN_ECHO_UP) {
          feedback_co_exit_atomic_ECHO_UP(feedback_control_Y_Level,
            feedback_control_DWork);
          feedback_control_DWork->is_TRIG_SIGNAL_OFF =
            feedback_con_IN_NO_ACTIVE_CHILD;
        } else {
          feedback_control_DWork->is_TRIG_SIGNAL_OFF =
            feedback_con_IN_NO_ACTIVE_CHILD;
        }

        /* Exit 'TRIG_SIGNAL_OFF': '<S1>:79' */
        if (!feedback_control_DWork->echo_up_check) {
          /* Outport: '<Root>/Level' */
          *feedback_control_Y_Level = 0U;
        }

        feedback_control_DWork->is_PROCESSING_LOGIC =
          feedback_cont_IN_TRIG_SIGNAL_ON;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Outport: '<Root>/trig_signal' */
        /* Entry 'TRIG_SIGNAL_ON': '<S1>:77' */
        *feedback_control_Y_trig_signal = true;
      } else if (feedback_control_DWork->is_TRIG_SIGNAL_OFF ==
                 feedback_control_IN_ECHO_DOWN) {
        /* During 'ECHO_DOWN': '<S1>:53' */
        if (feedback_control_U_echo_signal) {
          /* Transition: '<S1>:59' */
          feedback_control_DWork->echo_up_check = true;
          feedback_control_DWork->is_TRIG_SIGNAL_OFF =
            feedback_control_IN_ECHO_UP;
          feedback_control_DWork->temporalCounter_i1 = 0U;

          /* Entry 'ECHO_UP': '<S1>:49' */
          feedback_control_DWork->echo_pulse_duration_us = ((real_T)
            feedback_control_DWork->temporalCounter_i1) * 10.0;
        }
      } else {
        /* During 'ECHO_UP': '<S1>:49' */
        if (!feedback_control_U_echo_signal) {
          /* Transition: '<S1>:54' */
          feedback_co_exit_atomic_ECHO_UP(feedback_control_Y_Level,
            feedback_control_DWork);
          feedback_control_DWork->is_TRIG_SIGNAL_OFF =
            feedback_control_IN_ECHO_DOWN;
        } else {
          feedback_control_DWork->echo_pulse_duration_us = ((real_T)
            feedback_control_DWork->temporalCounter_i1) * 10.0;
        }
      }
    } else {
      /* Outport: '<Root>/trig_signal' */
      *feedback_control_Y_trig_signal = true;

      /* During 'TRIG_SIGNAL_ON': '<S1>:77' */
      if (feedback_control_DWork->temporalCounter_i1 >= 2U) {
        /* Transition: '<S1>:83' */
        feedback_control_DWork->is_PROCESSING_LOGIC =
          feedback_con_IN_TRIG_SIGNAL_OFF;
        feedback_control_DWork->temporalCounter_i2 = 0U;

        /* Outport: '<Root>/trig_signal' */
        /* Entry 'TRIG_SIGNAL_OFF': '<S1>:79' */
        *feedback_control_Y_trig_signal = false;
        feedback_control_DWork->echo_up_check = false;

        /* Entry Internal 'TRIG_SIGNAL_OFF': '<S1>:79' */
        /* Transition: '<S1>:126' */
        feedback_control_DWork->is_TRIG_SIGNAL_OFF =
          feedback_control_IN_ECHO_DOWN;
      }
    }

    /* During 'MONITORING_LOGIC': '<S1>:60' */
    switch (feedback_control_DWork->is_MONITORING_LOGIC) {
     case feedback_contr_IN_BLINK_INRANGE:
      /* During 'BLINK_INRANGE': '<S1>:62' */
      if (((*feedback_control_Y_Level) < 10) || ((*feedback_control_Y_Level) >
           100)) {
        /* Transition: '<S1>:107' */
        /* Exit Internal 'BLINK_INRANGE': '<S1>:62' */
        feedback_control_DWork->is_BLINK_INRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_MONITORING_LOGIC =
          feedback_cont_IN_BLINK_OUTRANGE;

        /* Entry 'BLINK_OUTRANGE': '<S1>:103' */
        /* Entry Internal 'BLINK_OUTRANGE': '<S1>:103' */
        /* Transition: '<S1>:166' */
        feedback_control_DWork->is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/Led' */
        /* Entry 'LED_ON': '<S1>:115' */
        *feedback_control_Y_Led = true;
      } else if (feedback_control_DWork->is_BLINK_INRANGE ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = false;

        /* During 'LED_OFF': '<S1>:110' */
        if (feedback_control_DWork->temporalCounter_i3 >= ((uint32_T)ceil(((0.1F
                - ((((real32_T)(*feedback_control_Y_Level)) * 0.1F) / 100.0F)) /
               1.0E-5) - 1.0000000000000002E-13))) {
          /* Transition: '<S1>:113' */
          feedback_control_DWork->is_BLINK_INRANGE = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_ON': '<S1>:108' */
          *feedback_control_Y_Led = true;
        }
      } else {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = true;

        /* During 'LED_ON': '<S1>:108' */
        if (feedback_control_DWork->temporalCounter_i3 >= ((uint32_T)ceil
             ((((((real32_T)(*feedback_control_Y_Level)) * 0.1F) / 100.0F) /
               1.0E-5) - 1.0000000000000002E-13))) {
          /* Transition: '<S1>:111' */
          feedback_control_DWork->is_BLINK_INRANGE = feedback_control_IN_LED_OFF;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_OFF': '<S1>:110' */
          *feedback_control_Y_Led = false;
        }
      }
      break;

     case feedback_cont_IN_BLINK_OUTRANGE:
      /* During 'BLINK_OUTRANGE': '<S1>:103' */
      if (((*feedback_control_Y_Level) >= 10) && ((*feedback_control_Y_Level) <=
           100)) {
        /* Transition: '<S1>:106' */
        /* Exit Internal 'BLINK_OUTRANGE': '<S1>:103' */
        feedback_control_DWork->is_BLINK_OUTRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_MONITORING_LOGIC =
          feedback_contr_IN_BLINK_INRANGE;

        /* Entry 'BLINK_INRANGE': '<S1>:62' */
        /* Entry Internal 'BLINK_INRANGE': '<S1>:62' */
        /* Transition: '<S1>:125' */
        feedback_control_DWork->is_BLINK_INRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/Led' */
        /* Entry 'LED_ON': '<S1>:108' */
        *feedback_control_Y_Led = true;
      } else if ((*feedback_control_Y_Level) == 0) {
        /* Transition: '<S1>:137' */
        /* Transition: '<S1>:138' */
        /* Exit Internal 'BLINK_OUTRANGE': '<S1>:103' */
        feedback_control_DWork->is_BLINK_OUTRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_MONITORING_LOGIC =
          feedback_IN_DISCONNECTED_SENSOR;

        /* Entry 'DISCONNECTED_SENSOR': '<S1>:104' */
        /* Entry Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        /* Transition: '<S1>:167' */
        feedback_control_DWork->is_DISCONNECTED_SENSOR =
          feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/Led' */
        /* Entry 'LED_ON': '<S1>:144' */
        *feedback_control_Y_Led = true;
      } else if (feedback_control_DWork->is_BLINK_OUTRANGE ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = false;

        /* During 'LED_OFF': '<S1>:117' */
        if (feedback_control_DWork->temporalCounter_i3 >= 25000U) {
          /* Transition: '<S1>:123' */
          feedback_control_DWork->is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_ON': '<S1>:115' */
          *feedback_control_Y_Led = true;
        }
      } else {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = true;

        /* During 'LED_ON': '<S1>:115' */
        if (feedback_control_DWork->temporalCounter_i3 >= 25000U) {
          /* Transition: '<S1>:122' */
          feedback_control_DWork->is_BLINK_OUTRANGE =
            feedback_control_IN_LED_OFF;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_OFF': '<S1>:117' */
          *feedback_control_Y_Led = false;
        }
      }
      break;

     default:
      /* During 'DISCONNECTED_SENSOR': '<S1>:104' */
      if (((*feedback_control_Y_Level) != 0) && (((*feedback_control_Y_Level) <
            10) || ((*feedback_control_Y_Level) > 100))) {
        /* Transition: '<S1>:157' */
        /* Transition: '<S1>:173' */
        /* Exit Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        feedback_control_DWork->is_DISCONNECTED_SENSOR =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_MONITORING_LOGIC =
          feedback_cont_IN_BLINK_OUTRANGE;

        /* Entry 'BLINK_OUTRANGE': '<S1>:103' */
        /* Entry Internal 'BLINK_OUTRANGE': '<S1>:103' */
        /* Transition: '<S1>:166' */
        feedback_control_DWork->is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/Led' */
        /* Entry 'LED_ON': '<S1>:115' */
        *feedback_control_Y_Led = true;
      } else if (((*feedback_control_Y_Level) >= 10) &&
                 ((*feedback_control_Y_Level) <= 100)) {
        /* Transition: '<S1>:175' */
        /* Transition: '<S1>:176' */
        /* Exit Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        feedback_control_DWork->is_DISCONNECTED_SENSOR =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork->is_MONITORING_LOGIC =
          feedback_contr_IN_BLINK_INRANGE;

        /* Entry 'BLINK_INRANGE': '<S1>:62' */
        /* Entry Internal 'BLINK_INRANGE': '<S1>:62' */
        /* Transition: '<S1>:125' */
        feedback_control_DWork->is_BLINK_INRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork->temporalCounter_i3 = 0U;

        /* Outport: '<Root>/Led' */
        /* Entry 'LED_ON': '<S1>:108' */
        *feedback_control_Y_Led = true;
      } else if (feedback_control_DWork->is_DISCONNECTED_SENSOR ==
                 feedback_control_IN_LED_OFF) {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = false;

        /* During 'LED_OFF': '<S1>:147' */
        if (feedback_control_DWork->temporalCounter_i3 >= 50000U) {
          /* Transition: '<S1>:143' */
          feedback_control_DWork->is_DISCONNECTED_SENSOR =
            feedback_control_IN_LED_ON;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_ON': '<S1>:144' */
          *feedback_control_Y_Led = true;
        }
      } else {
        /* Outport: '<Root>/Led' */
        *feedback_control_Y_Led = true;

        /* During 'LED_ON': '<S1>:144' */
        if (feedback_control_DWork->temporalCounter_i3 >= 50000U) {
          /* Transition: '<S1>:146' */
          feedback_control_DWork->is_DISCONNECTED_SENSOR =
            feedback_control_IN_LED_OFF;
          feedback_control_DWork->temporalCounter_i3 = 0U;

          /* Outport: '<Root>/Led' */
          /* Entry 'LED_OFF': '<S1>:147' */
          *feedback_control_Y_Led = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, boolean_T *feedback_control_U_echo_signal, boolean_T
  *feedback_control_Y_trig_signal, uint16_T *feedback_control_Y_Level, boolean_T
  *feedback_control_Y_Led)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)feedback_control_DWork, 0,
                sizeof(D_Work_feedback_control));

  /* external inputs */
  *feedback_control_U_echo_signal = false;

  /* external outputs */
  (*feedback_control_Y_trig_signal) = false;
  (*feedback_control_Y_Level) = 0U;
  (*feedback_control_Y_Led) = false;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  feedback_control_DWork->is_MONITORING_LOGIC = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->is_BLINK_INRANGE = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->is_BLINK_OUTRANGE = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->is_DISCONNECTED_SENSOR =
    feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->temporalCounter_i3 = 0U;
  feedback_control_DWork->is_PROCESSING_LOGIC = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->is_TRIG_SIGNAL_OFF = feedback_con_IN_NO_ACTIVE_CHILD;
  feedback_control_DWork->temporalCounter_i2 = 0U;
  feedback_control_DWork->temporalCounter_i1 = 0U;
  feedback_control_DWork->is_active_c3_feedback_control = 0U;
  feedback_control_DWork->measures[0] = 0.0;
  feedback_control_DWork->measures[1] = 0.0;
  feedback_control_DWork->measures[2] = 0.0;
  feedback_control_DWork->measures[3] = 0.0;
  feedback_control_DWork->index = 1U;

  /* SystemInitialize for Outport: '<Root>/Level' incorporates:
   *  Chart: '<Root>/Chart'
   */
  *feedback_control_Y_Level = 0U;
}

/* Model terminate function */
void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(feedback_control_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
