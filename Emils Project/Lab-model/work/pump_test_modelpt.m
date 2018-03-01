function pt=pump_test_modelpt
pt = [];

  
pt(1).blockname = 'PID Controller';
pt(1).paramname = 'P';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(1).isStruct  = false;
pt(1).symbol     = 'pump_test_model_P.PIDController_P';
pt(1).baseaddr   = '&pump_test_model_P.PIDController_P';
pt(1).dtname     = 'real_T';

pt(getlenPT) = pt(1);


  
pt(2).blockname = 'PID Controller';
pt(2).paramname = 'I';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';
pt(2).isStruct  = false;
pt(2).symbol     = 'pump_test_model_P.PIDController_I';
pt(2).baseaddr   = '&pump_test_model_P.PIDController_I';
pt(2).dtname     = 'real_T';



  
pt(3).blockname = 'PID Controller';
pt(3).paramname = 'UpperSaturationLimit';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';
pt(3).isStruct  = false;
pt(3).symbol     = 'pump_test_model_P.PIDController_UpperSaturationLi';
pt(3).baseaddr   = '&pump_test_model_P.PIDController_UpperSaturationLi';
pt(3).dtname     = 'real_T';



  
pt(4).blockname = 'PID Controller';
pt(4).paramname = 'LowerSaturationLimit';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';
pt(4).isStruct  = false;
pt(4).symbol     = 'pump_test_model_P.PIDController_LowerSaturationLi';
pt(4).baseaddr   = '&pump_test_model_P.PIDController_LowerSaturationLi';
pt(4).dtname     = 'real_T';



  
pt(5).blockname = 'PID Controller/Constant';
pt(5).paramname = 'Value';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';
pt(5).isStruct  = false;
pt(5).symbol     = 'pump_test_model_P.Constant_Value';
pt(5).baseaddr   = '&pump_test_model_P.Constant_Value';
pt(5).dtname     = 'real_T';



  
pt(6).blockname = 'PID Controller/Integrator';
pt(6).paramname = 'InitialCondition';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';
pt(6).isStruct  = false;
pt(6).symbol     = 'pump_test_model_P.Integrator_IC';
pt(6).baseaddr   = '&pump_test_model_P.Integrator_IC';
pt(6).dtname     = 'real_T';



  
pt(7).blockname = 'PID Controller/Clamping circuit/ZeroGain';
pt(7).paramname = 'Gain';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';
pt(7).isStruct  = false;
pt(7).symbol     = 'pump_test_model_P.ZeroGain_Gain';
pt(7).baseaddr   = '&pump_test_model_P.ZeroGain_Gain';
pt(7).dtname     = 'real_T';



  
pt(8).blockname = 'PID Controller/Clamping circuit/Memory';
pt(8).paramname = 'X0';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_BOOLEAN';
pt(8).ndims     = '2';
pt(8).size      = '[]';
pt(8).isStruct  = false;
pt(8).symbol     = 'pump_test_model_P.Memory_X0';
pt(8).baseaddr   = '&pump_test_model_P.Memory_X0';
pt(8).dtname     = 'boolean_T';


function len = getlenPT
len = 8;

