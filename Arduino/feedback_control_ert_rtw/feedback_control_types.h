/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control_types.h
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

#ifndef RTW_HEADER_feedback_control_types_h_
#define RTW_HEADER_feedback_control_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigitalI
#define typedef_b_arduinodriver_ArduinoDigitalI

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigitalI;

#endif                               /*typedef_b_arduinodriver_ArduinoDigitalI*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_blocks_
#define typedef_codertarget_arduinobase_blocks_

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_blocks_;

#endif                               /*typedef_codertarget_arduinobase_blocks_*/

#ifndef struct_tag_n6PybfofDJX1nilXyEd0pE
#define struct_tag_n6PybfofDJX1nilXyEd0pE

struct tag_n6PybfofDJX1nilXyEd0pE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_n6PybfofDJX1nilXyEd0pE*/

#ifndef typedef_g_dsp_private_SlidingWindowAver
#define typedef_g_dsp_private_SlidingWindowAver

typedef struct tag_n6PybfofDJX1nilXyEd0pE g_dsp_private_SlidingWindowAver;

#endif                               /*typedef_g_dsp_private_SlidingWindowAver*/

#ifndef struct_tag_Hh0aNiR2hzWltgFb36YvQD
#define struct_tag_Hh0aNiR2hzWltgFb36YvQD

struct tag_Hh0aNiR2hzWltgFb36YvQD
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
};

#endif                                 /*struct_tag_Hh0aNiR2hzWltgFb36YvQD*/

#ifndef typedef_codertarget_arduinobase_interna
#define typedef_codertarget_arduinobase_interna

typedef struct tag_Hh0aNiR2hzWltgFb36YvQD codertarget_arduinobase_interna;

#endif                               /*typedef_codertarget_arduinobase_interna*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_feedback_control
#define typedef_cell_wrap_feedback_control

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_feedback_control;

#endif                                 /*typedef_cell_wrap_feedback_control*/

#ifndef struct_tag_i9IfhfSX0XccmEaqGxzasC
#define struct_tag_i9IfhfSX0XccmEaqGxzasC

struct tag_i9IfhfSX0XccmEaqGxzasC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_feedback_control inputVarSize;
  g_dsp_private_SlidingWindowAver *pStatistic;
  int32_T NumChannels;
  g_dsp_private_SlidingWindowAver _pobj0;
};

#endif                                 /*struct_tag_i9IfhfSX0XccmEaqGxzasC*/

#ifndef typedef_dsp_simulink_MovingAverage_feed
#define typedef_dsp_simulink_MovingAverage_feed

typedef struct tag_i9IfhfSX0XccmEaqGxzasC dsp_simulink_MovingAverage_feed;

#endif                               /*typedef_dsp_simulink_MovingAverage_feed*/

/* Parameters (default storage) */
typedef struct Parameters_feedback_control_ Parameters_feedback_control;

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

#endif                                /* RTW_HEADER_feedback_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
