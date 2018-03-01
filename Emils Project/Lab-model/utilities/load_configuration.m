% Script that defines parameters for this project

%   Copyright 2012 The MathWorks, Inc.

%% Specify control system sample time
T_sample_control = 1e-2;

%% PID parameter setup 
% We would like the parameters of the PID controller to appear as a
% tunable structure in the generated code. To do this, we must first create
% a bus object - this configures the parameter typedef struct. Then we can
% create a parameter object which makes use of the bus object and defines
% default parameter values.

% Load bus object ready for parameter structure
load_connections('pumpsetup');