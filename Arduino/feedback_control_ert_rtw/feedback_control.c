/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.130
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Tue Jun 22 12:53:43 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "feedback_control.h"
#include "feedback_control_private.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define feedback_IN_DISCONNECTED_SENSOR ((uint8_T)3U)
#define feedback_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_cont_IN_BLINK_OUTRANGE ((uint8_T)2U)
#define feedback_contr_IN_BLINK_INRANGE ((uint8_T)1U)
#define feedback_control_IN_LED_OFF    ((uint8_T)1U)
#define feedback_control_IN_LED_ON     ((uint8_T)2U)

/* Block signals (default storage) */
BlockIO_feedback_control feedback_control_B;

/* Block states (default storage) */
D_Work_feedback_control feedback_control_DWork;

/* Real-time model */
static RT_MODEL_feedback_control feedback_control_M_;
RT_MODEL_feedback_control *const feedback_control_M = &feedback_control_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void feedback_control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(feedback_control_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (feedback_control_M->Timing.TaskCounters.TID[1])++;
  if ((feedback_control_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    feedback_control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void feedback_control_step0(void)      /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void feedback_control_step1(void)      /* Sample time: [0.1s, 0.0s] */
{
  g_dsp_private_SlidingWindowAver *obj;
  real_T csum;
  real_T cumRevIndex;
  real_T rtb_distance_cm;
  real_T z;
  uint32_T duration;
  boolean_T rtb_led;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (feedback_control_DWork.obj_l.TunablePropsChanged) {
    feedback_control_DWork.obj_l.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 4, 5, 10);

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLABSystem: '<Root>/Ultrasonic Sensor'
   */
  rtb_distance_cm = ((((real_T)duration) * 0.000343) / 2.0) *
    feedback_control_P.Constant_Value;

  /* MATLABSystem: '<Root>/Moving Average' */
  if (feedback_control_DWork.obj.TunablePropsChanged) {
    feedback_control_DWork.obj.TunablePropsChanged = false;
  }

  obj = feedback_control_DWork.obj.pStatistic;
  if (obj->isInitialized != 1L) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1L;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  feedback_control_B.csumrev[0] = obj->pCumSumRev[0];
  feedback_control_B.csumrev[1] = obj->pCumSumRev[1];
  feedback_control_B.csumrev[2] = obj->pCumSumRev[2];
  csum += rtb_distance_cm;
  z = feedback_control_B.csumrev[((int16_T)cumRevIndex) - 1] + csum;
  feedback_control_B.csumrev[((int16_T)cumRevIndex) - 1] = rtb_distance_cm;
  if (cumRevIndex != 3.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    feedback_control_B.csumrev[1] += feedback_control_B.csumrev[2];
    feedback_control_B.csumrev[0] += feedback_control_B.csumrev[1];
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = feedback_control_B.csumrev[0];
  obj->pCumSumRev[1] = feedback_control_B.csumrev[1];
  obj->pCumSumRev[2] = feedback_control_B.csumrev[2];
  obj->pCumRevIndex = cumRevIndex;
  rtb_distance_cm = z / 4.0;

  /* End of MATLABSystem: '<Root>/Moving Average' */

  /* Chart: '<Root>/Chart1' */
  if (feedback_control_DWork.temporalCounter_i1 < MAX_uint32_T) {
    feedback_control_DWork.temporalCounter_i1++;
  }

  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (feedback_control_DWork.is_active_c1_feedback_control == 0U) {
    /* Entry: Chart1 */
    feedback_control_DWork.is_active_c1_feedback_control = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:177' */
    feedback_control_DWork.is_c1_feedback_control =
      feedback_IN_DISCONNECTED_SENSOR;

    /* Entry 'DISCONNECTED_SENSOR': '<S1>:104' */
    /* Entry Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
    /* Transition: '<S1>:167' */
    feedback_control_DWork.is_DISCONNECTED_SENSOR = feedback_control_IN_LED_ON;
    feedback_control_DWork.temporalCounter_i1 = 0UL;

    /* Entry 'LED_ON': '<S1>:144' */
    rtb_led = true;
  } else {
    switch (feedback_control_DWork.is_c1_feedback_control) {
     case feedback_contr_IN_BLINK_INRANGE:
      /* During 'BLINK_INRANGE': '<S1>:62' */
      if ((rtb_distance_cm < 10.0) || (rtb_distance_cm > 100.0)) {
        /* Transition: '<S1>:107' */
        /* Exit Internal 'BLINK_INRANGE': '<S1>:62' */
        feedback_control_DWork.is_BLINK_INRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork.is_c1_feedback_control =
          feedback_cont_IN_BLINK_OUTRANGE;

        /* Entry 'BLINK_OUTRANGE': '<S1>:103' */
        /* Entry Internal 'BLINK_OUTRANGE': '<S1>:103' */
        /* Transition: '<S1>:166' */
        feedback_control_DWork.is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork.temporalCounter_i1 = 0UL;

        /* Entry 'LED_ON': '<S1>:115' */
        rtb_led = true;
      } else if (feedback_control_DWork.is_BLINK_INRANGE ==
                 feedback_control_IN_LED_OFF) {
        rtb_led = false;

        /* During 'LED_OFF': '<S1>:110' */
        if (feedback_control_DWork.temporalCounter_i1 >= ((0.1F - ((((real32_T)
                 rtb_distance_cm) * 0.1F) / 100.0F)) * 10.0F)) {
          /* Transition: '<S1>:113' */
          feedback_control_DWork.is_BLINK_INRANGE = feedback_control_IN_LED_ON;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_ON': '<S1>:108' */
          rtb_led = true;
        }
      } else {
        rtb_led = true;

        /* During 'LED_ON': '<S1>:108' */
        if (feedback_control_DWork.temporalCounter_i1 >= (((((real32_T)
                rtb_distance_cm) * 0.1F) / 100.0F) * 10.0F)) {
          /* Transition: '<S1>:111' */
          feedback_control_DWork.is_BLINK_INRANGE = feedback_control_IN_LED_OFF;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_OFF': '<S1>:110' */
          rtb_led = false;
        }
      }
      break;

     case feedback_cont_IN_BLINK_OUTRANGE:
      /* During 'BLINK_OUTRANGE': '<S1>:103' */
      if ((rtb_distance_cm >= 10.0) && (rtb_distance_cm <= 100.0)) {
        /* Transition: '<S1>:106' */
        /* Exit Internal 'BLINK_OUTRANGE': '<S1>:103' */
        feedback_control_DWork.is_BLINK_OUTRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork.is_c1_feedback_control =
          feedback_contr_IN_BLINK_INRANGE;

        /* Entry 'BLINK_INRANGE': '<S1>:62' */
        /* Entry Internal 'BLINK_INRANGE': '<S1>:62' */
        /* Transition: '<S1>:125' */
        feedback_control_DWork.is_BLINK_INRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork.temporalCounter_i1 = 0UL;

        /* Entry 'LED_ON': '<S1>:108' */
        rtb_led = true;
      } else if (rtb_distance_cm == 0.0) {
        /* Transition: '<S1>:137' */
        /* Transition: '<S1>:138' */
        /* Exit Internal 'BLINK_OUTRANGE': '<S1>:103' */
        feedback_control_DWork.is_BLINK_OUTRANGE =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork.is_c1_feedback_control =
          feedback_IN_DISCONNECTED_SENSOR;

        /* Entry 'DISCONNECTED_SENSOR': '<S1>:104' */
        /* Entry Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        /* Transition: '<S1>:167' */
        feedback_control_DWork.is_DISCONNECTED_SENSOR =
          feedback_control_IN_LED_ON;
        feedback_control_DWork.temporalCounter_i1 = 0UL;

        /* Entry 'LED_ON': '<S1>:144' */
        rtb_led = true;
      } else if (feedback_control_DWork.is_BLINK_OUTRANGE ==
                 feedback_control_IN_LED_OFF) {
        rtb_led = false;

        /* During 'LED_OFF': '<S1>:117' */
        if (feedback_control_DWork.temporalCounter_i1 >= 2.5F) {
          /* Transition: '<S1>:123' */
          feedback_control_DWork.is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_ON': '<S1>:115' */
          rtb_led = true;
        }
      } else {
        rtb_led = true;

        /* During 'LED_ON': '<S1>:115' */
        if (feedback_control_DWork.temporalCounter_i1 >= 2.5F) {
          /* Transition: '<S1>:122' */
          feedback_control_DWork.is_BLINK_OUTRANGE = feedback_control_IN_LED_OFF;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_OFF': '<S1>:117' */
          rtb_led = false;
        }
      }
      break;

     default:
      /* During 'DISCONNECTED_SENSOR': '<S1>:104' */
      if ((rtb_distance_cm != 0.0) && ((rtb_distance_cm < 10.0) ||
           (rtb_distance_cm > 100.0))) {
        /* Transition: '<S1>:157' */
        /* Transition: '<S1>:173' */
        /* Exit Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        feedback_control_DWork.is_DISCONNECTED_SENSOR =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork.is_c1_feedback_control =
          feedback_cont_IN_BLINK_OUTRANGE;

        /* Entry 'BLINK_OUTRANGE': '<S1>:103' */
        /* Entry Internal 'BLINK_OUTRANGE': '<S1>:103' */
        /* Transition: '<S1>:166' */
        feedback_control_DWork.is_BLINK_OUTRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork.temporalCounter_i1 = 0UL;

        /* Entry 'LED_ON': '<S1>:115' */
        rtb_led = true;
      } else if ((rtb_distance_cm >= 10.0) && (rtb_distance_cm <= 100.0)) {
        /* Transition: '<S1>:175' */
        /* Transition: '<S1>:176' */
        /* Exit Internal 'DISCONNECTED_SENSOR': '<S1>:104' */
        feedback_control_DWork.is_DISCONNECTED_SENSOR =
          feedback_con_IN_NO_ACTIVE_CHILD;
        feedback_control_DWork.is_c1_feedback_control =
          feedback_contr_IN_BLINK_INRANGE;

        /* Entry 'BLINK_INRANGE': '<S1>:62' */
        /* Entry Internal 'BLINK_INRANGE': '<S1>:62' */
        /* Transition: '<S1>:125' */
        feedback_control_DWork.is_BLINK_INRANGE = feedback_control_IN_LED_ON;
        feedback_control_DWork.temporalCounter_i1 = 0UL;

        /* Entry 'LED_ON': '<S1>:108' */
        rtb_led = true;
      } else if (feedback_control_DWork.is_DISCONNECTED_SENSOR ==
                 feedback_control_IN_LED_OFF) {
        rtb_led = false;

        /* During 'LED_OFF': '<S1>:147' */
        if (feedback_control_DWork.temporalCounter_i1 >= 5UL) {
          /* Transition: '<S1>:143' */
          feedback_control_DWork.is_DISCONNECTED_SENSOR =
            feedback_control_IN_LED_ON;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_ON': '<S1>:144' */
          rtb_led = true;
        }
      } else {
        rtb_led = true;

        /* During 'LED_ON': '<S1>:144' */
        if (feedback_control_DWork.temporalCounter_i1 >= 5UL) {
          /* Transition: '<S1>:146' */
          feedback_control_DWork.is_DISCONNECTED_SENSOR =
            feedback_control_IN_LED_OFF;
          feedback_control_DWork.temporalCounter_i1 = 0UL;

          /* Entry 'LED_OFF': '<S1>:147' */
          rtb_led = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)rtb_led);
}

/* Model initialize function */
void feedback_control_initialize(void)
{
  {
    dsp_simulink_MovingAverage_feed *obj;
    g_dsp_private_SlidingWindowAver *obj_0;

    /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
    feedback_control_DWork.obj_l.isInitialized = 1L;
    MW_UltrasonicSetup(4, 5);
    feedback_control_DWork.obj_l.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    feedback_control_DWork.obj.matlabCodegenIsDeleted = true;
    feedback_control_DWork.obj.isInitialized = 0L;
    feedback_control_DWork.obj.NumChannels = -1L;
    feedback_control_DWork.obj.matlabCodegenIsDeleted = false;
    obj = &feedback_control_DWork.obj;
    feedback_control_DWork.obj.isSetupComplete = false;
    feedback_control_DWork.obj.isInitialized = 1L;
    feedback_control_DWork.obj.NumChannels = 1L;
    obj->_pobj0.isInitialized = 0L;
    feedback_control_DWork.obj.pStatistic = &obj->_pobj0;
    feedback_control_DWork.obj.isSetupComplete = true;
    feedback_control_DWork.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Moving Average' */
    obj_0 = feedback_control_DWork.obj.pStatistic;
    if (obj_0->isInitialized == 1L) {
      obj_0->pCumSum = 0.0;
      obj_0->pCumSumRev[0] = 0.0;
      obj_0->pCumSumRev[1] = 0.0;
      obj_0->pCumSumRev[2] = 0.0;
      obj_0->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Moving Average' */

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    feedback_control_DWork.obj_p.matlabCodegenIsDeleted = false;
    feedback_control_DWork.obj_p.isInitialized = 1L;
    digitalIOSetup(13, 1);
    feedback_control_DWork.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void feedback_control_terminate(void)
{
  g_dsp_private_SlidingWindowAver *obj;

  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
  if (!feedback_control_DWork.obj.matlabCodegenIsDeleted) {
    feedback_control_DWork.obj.matlabCodegenIsDeleted = true;
    if ((feedback_control_DWork.obj.isInitialized == 1L) &&
        (feedback_control_DWork.obj.isSetupComplete)) {
      obj = feedback_control_DWork.obj.pStatistic;
      if (obj->isInitialized == 1L) {
        obj->isInitialized = 2L;
      }

      feedback_control_DWork.obj.NumChannels = -1L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Moving Average' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!feedback_control_DWork.obj_p.matlabCodegenIsDeleted) {
    feedback_control_DWork.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
