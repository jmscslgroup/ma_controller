//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ma_controller.h
//
// Code generated for Simulink model 'ma_controller'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Aug  5 18:23:22 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ma_controller_h_
#define RTW_HEADER_ma_controller_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "ma_controller_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_ma_controller_T {
  SL_Bus_ma_controller_geometry_msgs_Twist In1;// '<S10>/In1'
  SL_Bus_ma_controller_geometry_msgs_Twist In1_a;// '<S9>/In1'
  SL_Bus_ma_controller_geometry_msgs_Twist BusAssignment1;// '<S1>/Bus Assignment1' 
};

// Block states (default storage) for system '<Root>'
struct DW_ma_controller_T {
  dsp_simulink_MovingAverage_ma_T obj; // '<Root>/Moving Average'
  ros_slroscpp_internal_block_P_T obj_f;// '<S8>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_g;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_d;// '<S3>/SourceBlock'
};

// Parameters (default storage)
struct P_ma_controller_T_ {
  SL_Bus_ma_controller_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S5>/Constant'

  SL_Bus_ma_controller_geometry_msgs_Twist Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                               //  Referenced by: '<S7>/Constant'

  SL_Bus_ma_controller_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S9>/Out1'

  SL_Bus_ma_controller_geometry_msgs_Twist Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                               //  Referenced by: '<S3>/Constant'

  SL_Bus_ma_controller_geometry_msgs_Twist Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                        //  Referenced by: '<S10>/Out1'

  SL_Bus_ma_controller_geometry_msgs_Twist Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                               //  Referenced by: '<S4>/Constant'

  real_T MovingAverage_ForgettingFactor;// Expression: 0.9
                                           //  Referenced by: '<Root>/Moving Average'

};

// Real-time Model Data Structure
struct tag_RTM_ma_controller_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ma_controller_T ma_controller_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_ma_controller_T ma_controller_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_ma_controller_T ma_controller_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ma_controller_initialize(void);
  extern void ma_controller_step(void);
  extern void ma_controller_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ma_controller_T *const ma_controller_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ma_controller'
//  '<S1>'   : 'ma_controller/Publish Region1'
//  '<S2>'   : 'ma_controller/Publish Region2'
//  '<S3>'   : 'ma_controller/Subscribe4'
//  '<S4>'   : 'ma_controller/Subscribe5'
//  '<S5>'   : 'ma_controller/Publish Region1/Blank Message1'
//  '<S6>'   : 'ma_controller/Publish Region1/Publish1'
//  '<S7>'   : 'ma_controller/Publish Region2/Blank Message1'
//  '<S8>'   : 'ma_controller/Publish Region2/Publish1'
//  '<S9>'   : 'ma_controller/Subscribe4/Enabled Subsystem'
//  '<S10>'  : 'ma_controller/Subscribe5/Enabled Subsystem'

#endif                                 // RTW_HEADER_ma_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
