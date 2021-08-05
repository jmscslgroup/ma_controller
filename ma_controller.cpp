//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ma_controller.cpp
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
#include "ma_controller.h"
#include "ma_controller_private.h"

// Block signals (default storage)
B_ma_controller_T ma_controller_B;

// Block states (default storage)
DW_ma_controller_T ma_controller_DW;

// Real-time model
RT_MODEL_ma_controller_T ma_controller_M_ = RT_MODEL_ma_controller_T();
RT_MODEL_ma_controller_T *const ma_controller_M = &ma_controller_M_;

// Model step function
void ma_controller_step(void)
{
  g_dsp_private_ExponentialMovi_T *obj;
  real_T lambda;
  real_T pmLocal;
  real_T pwLocal;
  real_T rtb_Subtract1;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S9>/In1'

  b_varargout_1 = Sub_ma_controller_3.getLatestMessage
    (&ma_controller_B.BusAssignment1);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  if (b_varargout_1) {
    ma_controller_B.In1_a = ma_controller_B.BusAssignment1;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe5'
  // MATLABSystem: '<S4>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'

  b_varargout_1 = Sub_ma_controller_4.getLatestMessage
    (&ma_controller_B.BusAssignment1);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (b_varargout_1) {
    ma_controller_B.In1 = ma_controller_B.BusAssignment1;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe5'

  // Sum: '<Root>/Subtract1'
  rtb_Subtract1 = ma_controller_B.In1_a.Linear.Z + ma_controller_B.In1.Linear.X;

  // BusAssignment: '<S1>/Bus Assignment1' incorporates:
  //   Constant: '<S5>/Constant'

  ma_controller_B.BusAssignment1 = ma_controller_P.Constant_Value;
  ma_controller_B.BusAssignment1.Linear.X = rtb_Subtract1;

  // Outputs for Atomic SubSystem: '<S1>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_ma_controller_14.publish(&ma_controller_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S1>/Publish1'

  // MATLABSystem: '<Root>/Moving Average'
  if (ma_controller_DW.obj.ForgettingFactor !=
      ma_controller_P.MovingAverage_ForgettingFactor) {
    b_varargout_1 = (ma_controller_DW.obj.isInitialized == 1);
    if (b_varargout_1) {
      ma_controller_DW.obj.TunablePropsChanged = true;
    }

    ma_controller_DW.obj.ForgettingFactor =
      ma_controller_P.MovingAverage_ForgettingFactor;
  }

  if (ma_controller_DW.obj.TunablePropsChanged) {
    ma_controller_DW.obj.TunablePropsChanged = false;
    obj = ma_controller_DW.obj.pStatistic;
    b_varargout_1 = (obj->isInitialized == 1);
    if (b_varargout_1) {
      obj->TunablePropsChanged = true;
    }

    ma_controller_DW.obj.pStatistic->ForgettingFactor =
      ma_controller_DW.obj.ForgettingFactor;
  }

  obj = ma_controller_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0;
    obj->pmN = 0.0;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  pwLocal = obj->pwN;
  pmLocal = obj->pmN;
  lambda = obj->plambda;
  rtb_Subtract1 = (1.0 - 1.0 / pwLocal) * pmLocal + 1.0 / pwLocal *
    rtb_Subtract1;
  obj->pwN = lambda * pwLocal + 1.0;
  obj->pmN = rtb_Subtract1;

  // BusAssignment: '<S2>/Bus Assignment1' incorporates:
  //   Constant: '<S7>/Constant'
  //   MATLABSystem: '<Root>/Moving Average'

  ma_controller_B.BusAssignment1 = ma_controller_P.Constant_Value_f;
  ma_controller_B.BusAssignment1.Linear.X = rtb_Subtract1;

  // Outputs for Atomic SubSystem: '<S2>/Publish1'
  // MATLABSystem: '<S8>/SinkBlock'
  Pub_ma_controller_20.publish(&ma_controller_B.BusAssignment1);

  // End of Outputs for SubSystem: '<S2>/Publish1'
}

// Model initialize function
void ma_controller_initialize(void)
{
  {
    g_dsp_private_ExponentialMovi_T *obj;
    real_T varargin_2;
    int32_T i;
    char_T b_zeroDelimTopic_1[16];
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_2[6];
    char_T b_zeroDelimTopic_0[4];
    boolean_T flag;
    static const char_T tmp[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[15] = { 'e', 's', 't', 'i', 'm', 'a', 't', 'e',
      'd', '_', 'v', 'l', 'e', 'a', 'd' };

    static const char_T tmp_1[5] = { 'v', '_', 'r', 'e', 'f' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S9>/Out1' incorporates:
    //   Inport: '<S9>/In1'

    ma_controller_B.In1_a = ma_controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    ma_controller_DW.obj_d.matlabCodegenIsDeleted = false;
    ma_controller_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_ma_controller_3.createSubscriber(&b_zeroDelimTopic[0], 1);
    ma_controller_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe5'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    ma_controller_B.In1 = ma_controller_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    ma_controller_DW.obj_m.matlabCodegenIsDeleted = false;
    ma_controller_DW.obj_m.isInitialized = 1;
    b_zeroDelimTopic_0[0] = 'v';
    b_zeroDelimTopic_0[1] = 'e';
    b_zeroDelimTopic_0[2] = 'l';
    b_zeroDelimTopic_0[3] = '\x00';
    Sub_ma_controller_4.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ma_controller_DW.obj_m.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe5'

    // SystemInitialize for Atomic SubSystem: '<S1>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    ma_controller_DW.obj_g.matlabCodegenIsDeleted = false;
    ma_controller_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[15] = '\x00';
    Pub_ma_controller_14.createPublisher(&b_zeroDelimTopic_1[0], 1);
    ma_controller_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S1>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish1'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    ma_controller_DW.obj_f.matlabCodegenIsDeleted = false;
    ma_controller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimTopic_2[i] = tmp_1[i];
    }

    b_zeroDelimTopic_2[5] = '\x00';
    Pub_ma_controller_20.createPublisher(&b_zeroDelimTopic_2[0], 1);
    ma_controller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish1'

    // Start for MATLABSystem: '<Root>/Moving Average'
    ma_controller_DW.obj.matlabCodegenIsDeleted = true;
    ma_controller_DW.obj.isInitialized = 0;
    ma_controller_DW.obj.NumChannels = -1;
    ma_controller_DW.obj.matlabCodegenIsDeleted = false;
    flag = (ma_controller_DW.obj.isInitialized == 1);
    if (flag) {
      ma_controller_DW.obj.TunablePropsChanged = true;
    }

    ma_controller_DW.obj.ForgettingFactor =
      ma_controller_P.MovingAverage_ForgettingFactor;
    ma_controller_DW.obj.isSetupComplete = false;
    ma_controller_DW.obj.isInitialized = 1;
    ma_controller_DW.obj.NumChannels = 1;
    varargin_2 = ma_controller_DW.obj.ForgettingFactor;
    ma_controller_DW.obj._pobj0.isInitialized = 0;
    flag = (ma_controller_DW.obj._pobj0.isInitialized == 1);
    if (flag) {
      ma_controller_DW.obj._pobj0.TunablePropsChanged = true;
    }

    ma_controller_DW.obj._pobj0.ForgettingFactor = varargin_2;
    ma_controller_DW.obj.pStatistic = &ma_controller_DW.obj._pobj0;
    ma_controller_DW.obj.isSetupComplete = true;
    ma_controller_DW.obj.TunablePropsChanged = false;

    // End of Start for MATLABSystem: '<Root>/Moving Average'

    // InitializeConditions for MATLABSystem: '<Root>/Moving Average'
    obj = ma_controller_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pwN = 1.0;
      obj->pmN = 0.0;
    }

    // End of InitializeConditions for MATLABSystem: '<Root>/Moving Average'
  }
}

// Model terminate function
void ma_controller_terminate(void)
{
  g_dsp_private_ExponentialMovi_T *obj;

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!ma_controller_DW.obj_d.matlabCodegenIsDeleted) {
    ma_controller_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe5'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!ma_controller_DW.obj_m.matlabCodegenIsDeleted) {
    ma_controller_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe5'

  // Terminate for Atomic SubSystem: '<S1>/Publish1'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!ma_controller_DW.obj_g.matlabCodegenIsDeleted) {
    ma_controller_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S1>/Publish1'

  // Terminate for MATLABSystem: '<Root>/Moving Average'
  if (!ma_controller_DW.obj.matlabCodegenIsDeleted) {
    ma_controller_DW.obj.matlabCodegenIsDeleted = true;
    if ((ma_controller_DW.obj.isInitialized == 1) &&
        ma_controller_DW.obj.isSetupComplete) {
      obj = ma_controller_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      ma_controller_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Moving Average'

  // Terminate for Atomic SubSystem: '<S2>/Publish1'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!ma_controller_DW.obj_f.matlabCodegenIsDeleted) {
    ma_controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
