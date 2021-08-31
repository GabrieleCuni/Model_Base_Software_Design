/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
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

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#include <stddef.h>
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_Ultrasonic.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

#include "feedback_control_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[3];
} BlockIO_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_feed obj; /* '<Root>/Moving Average' */
  codertarget_arduinobase_blocks_ obj_p;/* '<Root>/Digital Output' */
  codertarget_arduinobase_interna obj_l;/* '<Root>/Ultrasonic Sensor' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart1' */
  uint8_T is_active_c1_feedback_control;/* '<Root>/Chart1' */
  uint8_T is_c1_feedback_control;      /* '<Root>/Chart1' */
  uint8_T is_BLINK_OUTRANGE;           /* '<Root>/Chart1' */
  uint8_T is_BLINK_INRANGE;            /* '<Root>/Chart1' */
  uint8_T is_DISCONNECTED_SENSOR;      /* '<Root>/Chart1' */
} D_Work_feedback_control;

/* Parameters (default storage) */
struct Parameters_feedback_control_ {
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_feedback_control feedback_control_P;

/* Block signals (default storage) */
extern BlockIO_feedback_control feedback_control_B;

/* Block states (default storage) */
extern D_Work_feedback_control feedback_control_DWork;

/* External function called from main */
extern void feedback_control_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void feedback_control_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void feedback_control_initialize(void);
extern void feedback_control_step0(void);
extern void feedback_control_step1(void);
extern void feedback_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_feedback_control *const feedback_control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<S1>'   : 'feedback_control/Chart1'
 * '<S2>'   : 'feedback_control/Unit conversion'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
