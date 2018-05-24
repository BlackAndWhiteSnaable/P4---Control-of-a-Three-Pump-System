%% SETUP
clc;
if ~(exist('run_num', 'var'))
    % run to import
    run_num = 20;
else
    clearvars -except run_num
end
%% IMPORTING
%count number of .dat files in folder
folder = ['dataFromTarget\run_' int2str(run_num) '\'];
a = dir([folder '*.dat']);  %find all .dat files
n = numel(a);   %number of dat files

for j=1:n
    filename = [folder a(j).name];
    pump2_meas(j)=SimulinkRealTime.utils.getFileScopeData(filename);
    str2find = ['\run_' int2str(run_num) '\'];
    version = extractAfter(filename,str2find);
    version = extractBefore(version,'.dat');
    pump2_meas(j).version = version;
end
clearvars a filename folder j n str2find version