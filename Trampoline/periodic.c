#include <stdio.h>
#include <stddef.h>
#include "tpl_os.h"

#include "feedback_control.h"          /* Model's header file */
#include "feedback_plant.h" 
#include "rtwtypes.h"

// Controller ********************************************
static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr = &feedback_control_M_;                /* Real-time model */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/echo_signal' */
static boolean_T feedback_control_U_echo_signal;

/* '<Root>/trig_signal' */
static boolean_T feedback_control_Y_trig_signal;

/* '<Root>/Level' */
static uint16_T feedback_control_Y_Level;

/* '<Root>/Led' */
static boolean_T feedback_control_Y_Led;

// Knob distance
// static uint16_T knobDistance_cm = 8; // cm

// Plant ***************************************************
static RT_MODEL_feedback_plant_T feedback_plant_M_;
static RT_MODEL_feedback_plant_T *const feedback_plant_MPtr = &feedback_plant_M_;/* Real-time model */
static DW_feedback_plant_T feedback_plant_DW;/* Observable states */

/* '<Root>/trig_signal' */
static boolean_T feedback_plant_U_trig_signal;

/* '<Root>/distance_cm' */
static real_T feedback_plant_U_distance_cm;

/* '<Root>/echo_signal' */
static boolean_T feedback_plant_Y_echo_signal;

void setup(){
  /* Controller Pack model data into RTM */
  feedback_control_MPtr->dwork = &feedback_control_DWork;
  /* Controller Initialize model */
  feedback_control_initialize(feedback_control_MPtr,
    &feedback_control_U_echo_signal, &feedback_control_Y_trig_signal,
    &feedback_control_Y_Level, &feedback_control_Y_Led);

  /* Plant Pack model data into RTM */
  feedback_plant_MPtr->dwork = &feedback_plant_DW;

  /* Plant Initialize model */
  feedback_plant_initialize(feedback_plant_MPtr, &feedback_plant_U_trig_signal,
    &feedback_plant_U_distance_cm, &feedback_plant_Y_echo_signal);
}

int main(void)
{
    setup();

    feedback_plant_U_distance_cm = 15;

    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(controller_alarm);
DeclareAlarm(ultrasonicSensor_alarm);

void ultrasonicSensorWriteLevel(uint16_T level){
  static int n_activation = 0;
  n_activation++;
  printf("ultrasonicSensorWriteLevel(%d): %hu\n", n_activation, level);

}


TASK(ultrasonicSensor){ 
  feedback_plant_U_trig_signal = feedback_control_Y_trig_signal;

  feedback_plant_step(feedback_plant_MPtr, feedback_plant_U_trig_signal,
                      feedback_plant_U_distance_cm,
                      &feedback_plant_Y_echo_signal);


  TerminateTask();
}

TASK(controller)
{
  printf("---\r\n");
  // feedback_control_U_echo_signal = ultrasonicSensor(feedback_control_Y_trig_signal);

  feedback_control_U_echo_signal = feedback_plant_Y_echo_signal;

  feedback_control_step(feedback_control_MPtr, feedback_control_U_echo_signal,
                        &feedback_control_Y_trig_signal,
                        &feedback_control_Y_Level, &feedback_control_Y_Led);

  ultrasonicSensorWriteLevel(feedback_control_Y_Level);
  // ultrasonicSensorWriteLed(feedback_control_Y_Led);
  TerminateTask();
}

TASK(stop)
{
  CancelAlarm(controller_alarm);
  CancelAlarm(ultrasonicSensor_alarm);
  printf("Shutdown\r\n");
  ShutdownOS(E_OK);
  TerminateTask();
}
