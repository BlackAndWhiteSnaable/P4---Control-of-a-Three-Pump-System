%% SETUP
clc;

%% IMPORTING pump data
for pump_amnt=[1:3]
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
clearvars pump_amnt

%% IMPORTING validation data
for pump_amnt=[1:3]
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
        folder = [int2str(pump_amnt) 'PumpVal\run_' int2str(run_num) '\'];
        a = dir([folder '*.dat']);  %find all .dat files
        nfiles = numel(a);   %number of dat files
        for jfile=1:nfiles
            filename = [folder a(jfile).name];
            val(pump_amnt,run_num,jfile)=SimulinkRealTime.utils.getFileScopeData(filename);
            str2find = ['\run_' int2str(run_num) '\'];
            version = extractAfter(filename,str2find);
            version = extractBefore(version,'.dat');
            val(pump_amnt,run_num,jfile).version = version;
        end
    end
end
clearvars pump_amnt

%% cleanup
clearvars a filename folder jfile nfiles str2find version run_num stp

%% 1 pump
n1pump1 = squeeze(meas(1,1,:));
n1p1FLOW = multiPumpAvgFlow(n1pump1);
n1p1POWR = multiPumpAvgPower(n1pump1);
n1p1PRES = multiPumpAvgPressure(n1pump1);
n1val1  = squeeze(val(1,1,:));  % validation data
n1v1FLOW = multiPumpAvgFlow(n1val1);
n1v1POWR = multiPumpAvgPower(n1val1);
n1v1PRES = multiPumpAvgPressure(n1val1);

n1pump2 = squeeze(meas(1,2,:));
n1p2FLOW = multiPumpAvgFlow(n1pump2);
n1p2POWR = multiPumpAvgPower(n1pump2);
n1p2PRES = multiPumpAvgPressure(n1pump2);
n1val2  = squeeze(val(1,2,:));  % validation data
n1v2FLOW = multiPumpAvgFlow(n1val2);
n1v2POWR = multiPumpAvgPower(n1val2);
n1v2PRES = multiPumpAvgPressure(n1val2);

n1pump3 = squeeze(meas(1,3,:));
n1p3FLOW = multiPumpAvgFlow(n1pump3);
n1p3POWR = multiPumpAvgPower(n1pump3);
n1p3PRES = multiPumpAvgPressure(n1pump3);
n1val3  = squeeze(val(1,3,:));  % validation data
n1v3FLOW = multiPumpAvgFlow(n1val3);
n1v3POWR = multiPumpAvgPower(n1val3);
n1v3PRES = multiPumpAvgPressure(n1val3);

%% 1 Pump average
n1pFLOW = cat(3,n1p1FLOW,n1p2FLOW,n1p3FLOW);
n1pFLOW = mean(n1pFLOW,3);

n1pPRES = cat(3,n1p1PRES,n1p2PRES,n1p3PRES);
n1pPRES = mean(n1pPRES,3);

n1pPOWR = cat(3,n1p1POWR,n1p2POWR,n1p3POWR);
n1pPOWR = mean(n1pPOWR,3);

% validation data
n1vFLOW = cat(3,n1v1FLOW,n1v2FLOW,n1v3FLOW);
n1vFLOW = mean(n1vFLOW,3);

n1vPRES = cat(3,n1v1PRES,n1v2PRES,n1v3PRES);
n1vPRES = mean(n1vPRES,3);

n1vPOWR = cat(3,n1v1POWR,n1v2POWR,n1v3POWR);
n1vPOWR = mean(n1vPOWR,3);

%% clearing n1 pump specific variables
clearvars n1p1FLOW n1p1POWR n1p1PRES n1v1FLOW n1v1POWR n1v1PRES
clearvars n1p2FLOW n1p2POWR n1p2PRES n1v2FLOW n1v2POWR n1v2PRES
clearvars n1p3FLOW n1p3POWR n1p3PRES n1v3FLOW n1v3POWR n1v3PRES

%% 2 pumps
n2pump23 =squeeze(meas(2,1,:));
n2p23FLOW = multiPumpAvgFlow(n2pump23);
n2p23POWR = multiPumpAvgPower(n2pump23);
n2p23PRES = multiPumpAvgPressure(n2pump23);
n2val23  = squeeze(val(2,1,:));  % validation data
n2v23FLOW = multiPumpAvgFlow(n2val23);
n2v23POWR = multiPumpAvgPower(n2val23);
n2v23PRES = multiPumpAvgPressure(n2val23);

n2pump13 =squeeze(meas(2,2,:));
n2p13FLOW = multiPumpAvgFlow(n2pump13);
n2p13POWR = multiPumpAvgPower(n2pump13);
n2p13PRES = multiPumpAvgPressure(n2pump13);
n2val13  = squeeze(val(2,2,:));  % validation data
n2v13FLOW = multiPumpAvgFlow(n2val13);
n2v13POWR = multiPumpAvgPower(n2val13);
n2v13PRES = multiPumpAvgPressure(n2val13);

n2pump12 =squeeze(meas(2,3,:));
n2p12FLOW = multiPumpAvgFlow(n2pump12);
n2p12POWR = multiPumpAvgPower(n2pump12);
n2p12PRES = multiPumpAvgPressure(n2pump12);
n2val12  = squeeze(val(2,3,:));  % validation data
n2v12FLOW = multiPumpAvgFlow(n2val12);
n2v12POWR = multiPumpAvgPower(n2val12);
n2v12PRES = multiPumpAvgPressure(n2val12);


%% 2 Pumps average
n2pFLOW = cat(3,n2p12FLOW,n2p23FLOW,n2p13FLOW);
n2pFLOW = mean(n2pFLOW,3);

n2pPRES = cat(3,n2p12PRES,n2p23PRES,n2p13PRES);
n2pPRES = mean(n2pPRES,3);

n2pPOWR = cat(3,n2p12POWR,n2p23POWR,n2p13POWR);
n2pPOWR = mean(n2pPOWR,3);

% validation data
n2vFLOW = cat(3,n2v12FLOW,n2v23FLOW,n2v13FLOW);
n2vFLOW = mean(n2vFLOW,3);

n2vPRES = cat(3,n2v12PRES,n2v23PRES,n2v13PRES);
n2vPRES = mean(n2vPRES,3);

n2vPOWR = cat(3,n2v12POWR,n2v23POWR,n2v13POWR);
n2vPOWR = mean(n2vPOWR,3);

%% clearing n2 pump specific variables
clearvars n2p12FLOW n2p12POWR n2p12PRES n2v12FLOW n2v12POWR n2v12PRES
clearvars n2p23FLOW n2p23POWR n2p23PRES n2v23FLOW n2v23POWR n2v23PRES
clearvars n2p13FLOW n2p13POWR n2p13PRES n2v13FLOW n2v13POWR n2v13PRES

%% 3 pumps (already average)
n3pump123=squeeze(meas(3,1,:));
n3pFLOW = multiPumpAvgFlow(n3pump123);
n3pPOWR = multiPumpAvgPower(n3pump123);
n3pPRES = multiPumpAvgPressure(n3pump123);
n3val123  = squeeze(val(3,1,:));  % validation data
n3vFLOW = multiPumpAvgFlow(n3val123);
n3vPOWR = multiPumpAvgPower(n3val123);
n3vPRES = multiPumpAvgPressure(n3val123);

%% clearing n3 pump specific variables
clearvars n3p123FLOW n3p123POWR n3p123PRES n3v123FLOW n3v123POWR n3v123PRES
% 
% %% cftool 1 pump
% cftool(n1pFLOW, n1pPRES, n1pPOWR);
% 
% %% cftool 2 pumps
% cftool(n2pFLOW, n2pPRES, n2pPOWR);
% 
% %% cftool 3 pumps
% cftool(n3pFLOW, n3pPRES, n3pPOWR);
