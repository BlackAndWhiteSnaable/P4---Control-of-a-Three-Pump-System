/* Include files */

#include "feedback_plant_with_best_PID_sfun.h"
#include "feedback_plant_with_best_PID_sfun_debug_macros.h"
#include "c18_feedback_plant_with_best_PID.h"
#include "c19_feedback_plant_with_best_PID.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _feedback_plant_with_best_PIDMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void feedback_plant_with_best_PID_initializer(void)
{
}

void feedback_plant_with_best_PID_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_feedback_plant_with_best_PID_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==18) {
    c18_feedback_plant_with_best_PID_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_feedback_plant_with_best_PID_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_feedback_plant_with_best_PID_process_testpoint_info_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "feedback_plant_with_best_PID")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_feedback_plant_with_best_PID_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(543881138U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3135534614U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1716836204U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4101656366U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 18:
        {
          extern void sf_c18_feedback_plant_with_best_PID_get_check_sum(mxArray *
            plhs[]);
          sf_c18_feedback_plant_with_best_PID_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_feedback_plant_with_best_PID_get_check_sum(mxArray *
            plhs[]);
          sf_c19_feedback_plant_with_best_PID_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3520626390U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3934884053U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3841414739U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3215249546U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1630197750U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2765330295U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2506697180U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(61288221U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_feedback_plant_with_best_PID_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 18:
      {
        if (strcmp(aiChksum, "K7q6K3kzhv0LaoIEqlpxUD") == 0) {
          extern mxArray
            *sf_c18_feedback_plant_with_best_PID_get_autoinheritance_info(void);
          plhs[0] = sf_c18_feedback_plant_with_best_PID_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "4tbRnbvaG9EonOQAKCD2VH") == 0) {
          extern mxArray
            *sf_c19_feedback_plant_with_best_PID_get_autoinheritance_info(void);
          plhs[0] = sf_c19_feedback_plant_with_best_PID_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_feedback_plant_with_best_PID_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 18:
      {
        extern const mxArray
          *sf_c18_feedback_plant_with_best_PID_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_feedback_plant_with_best_PID_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_feedback_plant_with_best_PID_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_feedback_plant_with_best_PID_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_feedback_plant_with_best_PID_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 18:
      {
        if (strcmp(tpChksum, "saEXJvRx6DzvXyZ1e9KGg8E") == 0) {
          extern mxArray
            *sf_c18_feedback_plant_with_best_PID_third_party_uses_info(void);
          plhs[0] = sf_c18_feedback_plant_with_best_PID_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "s44PCccEXY7of6lUgkorogG") == 0) {
          extern mxArray
            *sf_c19_feedback_plant_with_best_PID_third_party_uses_info(void);
          plhs[0] = sf_c19_feedback_plant_with_best_PID_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_feedback_plant_with_best_PID_jit_fallback_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 18:
      {
        if (strcmp(tpChksum, "saEXJvRx6DzvXyZ1e9KGg8E") == 0) {
          extern mxArray *sf_c18_feedback_plant_with_best_PID_jit_fallback_info
            (void);
          plhs[0] = sf_c18_feedback_plant_with_best_PID_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "s44PCccEXY7of6lUgkorogG") == 0) {
          extern mxArray *sf_c19_feedback_plant_with_best_PID_jit_fallback_info
            (void);
          plhs[0] = sf_c19_feedback_plant_with_best_PID_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_feedback_plant_with_best_PID_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 18:
      {
        if (strcmp(tpChksum, "saEXJvRx6DzvXyZ1e9KGg8E") == 0) {
          extern mxArray
            *sf_c18_feedback_plant_with_best_PID_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c18_feedback_plant_with_best_PID_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "s44PCccEXY7of6lUgkorogG") == 0) {
          extern mxArray
            *sf_c19_feedback_plant_with_best_PID_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c19_feedback_plant_with_best_PID_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void feedback_plant_with_best_PID_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _feedback_plant_with_best_PIDMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"feedback_plant_with_best_PID","sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _feedback_plant_with_best_PIDMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _feedback_plant_with_best_PIDMachineNumber_,0);
}

void feedback_plant_with_best_PID_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_feedback_plant_with_best_PID_optimization_info(void);
mxArray* load_feedback_plant_with_best_PID_optimization_info(boolean_T isRtwGen,
  boolean_T isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_feedback_plant_with_best_PID_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "feedback_plant_with_best_PID", "feedback_plant_with_best_PID");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_feedback_plant_with_best_PID_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
