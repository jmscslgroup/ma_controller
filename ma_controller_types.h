//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ma_controller_types.h
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
#ifndef RTW_HEADER_ma_controller_types_h_
#define RTW_HEADER_ma_controller_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ma_controller_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ma_controller_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_ma_controller_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ma_controller_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ma_controller_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_ma_controller_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ma_controller_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ma_controller_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef struct_g_dsp_private_ExponentialMovi_T
#define struct_g_dsp_private_ExponentialMovi_T

struct g_dsp_private_ExponentialMovi_T
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
};

#endif                                // struct_g_dsp_private_ExponentialMovi_T

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

#ifndef struct_cell_wrap_ma_controller_T
#define struct_cell_wrap_ma_controller_T

struct cell_wrap_ma_controller_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_ma_controller_T

#ifndef struct_dsp_simulink_MovingAverage_ma_T
#define struct_dsp_simulink_MovingAverage_ma_T

struct dsp_simulink_MovingAverage_ma_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_ma_controller_T inputVarSize;
  real_T ForgettingFactor;
  g_dsp_private_ExponentialMovi_T *pStatistic;
  int32_T NumChannels;
  g_dsp_private_ExponentialMovi_T _pobj0;
};

#endif                                // struct_dsp_simulink_MovingAverage_ma_T

// Parameters (default storage)
typedef struct P_ma_controller_T_ P_ma_controller_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ma_controller_T RT_MODEL_ma_controller_T;

#endif                                 // RTW_HEADER_ma_controller_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
