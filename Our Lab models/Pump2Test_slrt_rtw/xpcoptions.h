#ifndef __Pump2Test_XPCOPTIONS_H___
#define __Pump2Test_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "Pump2Test.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  0
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void Pump2Test_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_Pump2Test_T *
  const Pump2Test_M)
{
  real_T ratio = newBaseRateStepSize / 0.01;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  Pump2Test_M->Timing.stepSize0 = Pump2Test_M->Timing.stepSize0 * ratio;
  Pump2Test_M->Timing.stepSize1 = Pump2Test_M->Timing.stepSize1 * ratio;
  Pump2Test_M->Timing.stepSize = Pump2Test_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  Pump2Test_ChangeStepSize(stepSize, Pump2Test_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(Pump2Test_M, errMsg);
}

#endif                                 /* __Pump2Test_XPCOPTIONS_H___ */
