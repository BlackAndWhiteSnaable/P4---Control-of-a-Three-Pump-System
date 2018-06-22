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
%% 1 pump
n1pump1 = squeeze(meas(1,1,:));
% n1p1FLOW = multiPumpAvgFlow(n1pump1);
% n1p1POWR = multiPumpAvgPower(n1pump1);
% n1p1PRES = multiPumpAvgPressure(n1pump1);

n1pump2 = squeeze(meas(1,2,:));
% n1p2FLOW = multiPumpAvgFlow(n1pump2);
% n1p2POWR = multiPumpAvgPower(n1pump2);
% n1p2PRES = multiPumpAvgPressure(n1pump2);

n1pump3 = squeeze(meas(1,3,:));
% n1p3FLOW = multiPumpAvgFlow(n1pump3);
% n1p3POWR = multiPumpAvgPower(n1pump3);
% n1p3PRES = multiPumpAvgPressure(n1pump3);

%% 2 pumps
n2pump23 =squeeze(meas(2,1,:));
n2p23FLOW = multiPumpAvgFlow(n2pump23);
n2p23POWR = multiPumpAvgPower(n2pump23);
n2p23PRES = multiPumpAvgPressure(n2pump23);

n2pump13 =squeeze(meas(2,2,:));
n2p13FLOW = multiPumpAvgFlow(n2pump13);
n2p13POWR = multiPumpAvgPower(n2pump13);
n2p13PRES = multiPumpAvgPressure(n2pump13);

n2pump12 =squeeze(meas(2,3,:));
n2p12FLOW = multiPumpAvgFlow(n2pump12);
n2p12POWR = multiPumpAvgPower(n2pump12);
n2p12PRES = multiPumpAvgPressure(n2pump12);

%% 3 pumps
n3pump123=squeeze(meas(3,1,:));
n3p123FLOW = multiPumpAvgFlow(n3pump123);
n3p123POWR = multiPumpAvgPower(n3pump123);
n3p123PRES = multiPumpAvgPressure(n3pump123);
clearvars a filename folder jfile nfiles str2find version run_num stp meas
