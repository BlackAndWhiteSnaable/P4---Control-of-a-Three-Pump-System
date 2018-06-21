%% SETUP
clc;

%% IMPORTING 2 and 3 pump data
for pump_amnt=[2:3]
    % one and two pumps are three options
    % three pumps is one option
    if pump_amnt ~= 3
        stp = 3;
    else
        stp = 1;
    end
    % import all runs
    for run_num = [1:stp]
        %count number of .dat files in folder
        folder = [int2str(pump_amnt) 'Pump\run_' int2str(run_num) '\'];
        a = dir([folder '*.dat']);  %find all .dat files
        nfiles = numel(a);   %number of dat files
        for jfile=1:nfiles
            filename = [folder a(jfile).name];
            meas(pump_amnt,run_num,jfile)=SimulinkRealTime.utils.getFileScopeData(filename);
            str2find = ['\run_' int2str(run_num) '\'];
            version = extractAfter(filename,str2find);
            version = extractBefore(version,'.dat');
            meas(pump_amnt,run_num,jfile).version = version;
        end
    end
end
pump1=meas(1,:,:);
pump2=meas(2,:,:);
pump3=meas(3,:,:);
clearvars a filename folder j n str2find version