%% SETUP
clc;clear
%specify run number to import into workspace
run_num = 2;

%count number of .dat files in folder
folder = ['dataFromTarget\run_' int2str(run_num) '\'];
a = dir([folder '*.dat']);
n = numel(a);

for i=[1:n]
    filename = [folder a(i).name];
    pump2_meas(i)=SimulinkRealTime.utils.getFileScopeData(filename);
end
