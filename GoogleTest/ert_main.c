#include <iostream>
#include <gtest/gtest.h>

/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>              /* This ert_main.c example uses printf/fflush */
#include "feedback_control.h"          /* Model's header file */
#include "rtwtypes.h"

static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr =
  &feedback_control_M_;                /* Real-time model */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/echo_signal' */
static boolean_T feedback_control_U_echo_signal;

/* '<Root>/trig_signal' */
static boolean_T feedback_control_Y_trig_signal;

/* '<Root>/Level' */
static uint16_T feedback_control_Y_Level;

/* '<Root>/Led' */
static boolean_T feedback_control_Y_Led;

int countLines(){
    int count=0;
    unsigned char number;
    FILE *fr;
    fr = fopen("./Data/input_stimuli.txt", "r");

    // if( fr == NULL ) {
    //     printf("Errore in apertura del file");
    //     fflush(stdout);
    //     exit(1);
    // }

    while( fscanf(fr, "%hhu", &number) != EOF ){
        count++;
    }    
    fclose(fr);
    // printf("Lines: %d", count);
    return count;
}

boolean_T* readVectBoolean(char *fileName, int n){
    int i, count = 0; // 4800001
    boolean_T number, *array;
    
    FILE *fr;
    fr = fopen(fileName, "r");

    // if( fr == NULL ) {
    //     printf("Errore in apertura del file");
    //     fflush(stdout);
    //     exit(1);
    // }

    array = (boolean_T*) malloc((sizeof(boolean_T)*n));

    while( fscanf(fr, "%hhu", &number) != EOF ){
        array[count] = number;
        count++;
    }    
    fclose(fr);

    return array;
}

uint16_T* readVectUint16(char *fileName, int n){
    int i, count = 0; // 4800001
    uint16_T number, *array;
    
    FILE *fr;
    fr = fopen(fileName, "r");

    // if( fr == NULL ) {
    //     printf("Errore in apertura del file");
    //     fflush(stdout);
    //     exit(1);
    // }

    array = (uint16_T*) malloc((sizeof(uint16_T)*n));

    while( fscanf(fr, "%hhu", &number) != EOF ){
        array[count] = number;
        count++;
    }    
    fclose(fr);

    return array;
}

TEST(UnitTest, test1){
    int i, n = countLines();

    boolean_T *input_stimuli_test = readVectBoolean("./Data/input_stimuli.txt", n);
    uint16_T *expected_output_distance = readVectUint16("./Data/expected_output_distance.txt", n);
    boolean_T *expected_output_trig = readVectBoolean("./Data/expected_output_trig.txt", n);
    boolean_T *expected_output_led = readVectBoolean("./Data/expected_output_led.txt", n);
    
    RT_MODEL_feedback_control *const feedback_control_M = feedback_control_MPtr;
    /* Pack model data into RTM */
    feedback_control_M->dwork = &feedback_control_DWork;
    /* Initialize model */
    feedback_control_initialize(feedback_control_M,
        &feedback_control_U_echo_signal, &feedback_control_Y_trig_signal,
        &feedback_control_Y_Level, &feedback_control_Y_Led);

    for(i=0; i<n; i++){
        feedback_control_U_echo_signal = input_stimuli_test[i];

        /* Step the model */
        feedback_control_step(feedback_control_M, feedback_control_U_echo_signal,
                            &feedback_control_Y_trig_signal,
                            &feedback_control_Y_Level, &feedback_control_Y_Led);

        EXPECT_EQ(feedback_control_Y_trig_signal, expected_output_trig[i]);
        EXPECT_EQ(feedback_control_Y_Level, expected_output_distance[i]);
        EXPECT_EQ(feedback_control_Y_Led, expected_output_led[i]);
    }
    free(input_stimuli_test);
    free(expected_output_distance);
    free(expected_output_trig);
    free(expected_output_led);
    
}

TEST(UnitTest, Terminate){
  RT_MODEL_feedback_control *const feedback_control_M = feedback_control_MPtr;
  /* Pack model data into RTM */
  feedback_control_M->dwork = &feedback_control_DWork;
  /* Terminate model */
  feedback_control_terminate(feedback_control_M);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
// fflush((NULL));
