/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "feedback_plant.h"            /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_feedback_plant_T feedback_plant_M_;
static RT_MODEL_feedback_plant_T *const feedback_plant_MPtr = &feedback_plant_M_;/* Real-time model */
static DW_feedback_plant_T feedback_plant_DW;/* Observable states */

/* '<Root>/trig_signal' */
static boolean_T feedback_plant_U_trig_signal;

/* '<Root>/distance_cm' */
static real_T feedback_plant_U_distance_cm;

/* '<Root>/echo_signal' */
static boolean_T feedback_plant_Y_echo_signal;

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(RT_MODEL_feedback_plant_T *const feedback_plant_M);
void rt_OneStep(RT_MODEL_feedback_plant_T *const feedback_plant_M)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(feedback_plant_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  feedback_plant_step(feedback_plant_M, feedback_plant_U_trig_signal,
                      feedback_plant_U_distance_cm,
                      &feedback_plant_Y_echo_signal);

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_feedback_plant_T *const feedback_plant_M = feedback_plant_MPtr;

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Pack model data into RTM */
  feedback_plant_M->dwork = &feedback_plant_DW;

  /* Initialize model */
  feedback_plant_initialize(feedback_plant_M, &feedback_plant_U_trig_signal,
    &feedback_plant_U_distance_cm, &feedback_plant_Y_echo_signal);

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 1.0E-5 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep(feedback_plant_M);
   */
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(feedback_plant_M) == (NULL)) {
    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  feedback_plant_terminate(feedback_plant_M);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
