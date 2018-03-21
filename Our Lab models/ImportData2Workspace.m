%% SETUP
clc;clear
%specify run number to import into workspace
run_num = 1;

%count number of .dat files in folder
folder = ['dataFromTarget\run_' int2str(run_num) '\'];
a = dir([folder '*.dat']);
n = numel(a);

for i=[1:n]
    filename = [folder a(i).name];
    pump2_meas(i)=SimulinkRealTime.utils.getFileScopeData(filename);
    str2find = ['\run_' int2str(run_num) '\'];
    version = extractAfter(filename,str2find);
    version = extractBefore(version,'.dat');
    pump2_meas(i).version = version;
end

%% plot all pressure curves
%figure('Name', 'Pressure comparison' ,'NumberTitle','off')
for i = 1:numel(pump2_meas)
    subplot(ceil(numel(pump2_meas)/2),2,i)
    plot(pump2_meas(i).data(:,end),pump2_meas(i).data(:,1))
    axis([0 pump2_meas(1).data(end,end) 0 7])
    ftit=strrep(pump2_meas(i).version,'_','\_'); %make sure _ prints
    title(ftit)
    hold on; grid on
end


%% plot all power curves
%figure('Name', 'Power comparison' ,'NumberTitle','off')
for i = 1:numel(pump2_meas)
    %plot in two columns
    subplot(ceil(numel(pump2_meas)/2),2,i)
    %    time as x axis           ,second set of data is power
    plot(pump2_meas(i).data(:,end),pump2_meas(i).data(:,2))
    axis([0 pump2_meas(1).data(end,end) 0 7])
    ftit=strrep(pump2_meas(i).version,'_','\_'); %make sure _ prints
    title(ftit)
    hold on; grid on
end

%% plot all flow curves
%figure('Name', 'Flow comparison' ,'NumberTitle','off')
for i = 1:numel(pump2_meas)
    subplot(ceil(numel(pump2_meas)/2),2,i)
    %    time as x axis           ,third set of data is flow
    plot(pump2_meas(i).data(:,end),pump2_meas(i).data(:,3))
    axis([0 pump2_meas(1).data(end,end) 0 7])
    ftit=strrep(pump2_meas(i).version,'_','\_'); %make sure _ prints
    title(ftit)
    hold on; grid on
end

%% plot all speed curves
%figure('Name', 'Speed comparison' ,'NumberTitle','off')
for i = 1:numel(pump2_meas)
    subplot(ceil(numel(pump2_meas)/2),2,i)
    %    time as x axis           ,forth set of data is speed
    plot(pump2_meas(i).data(:,end),pump2_meas(i).data(:,4))
    axis([0 pump2_meas(1).data(end,end) 0 7])
    ftit=strrep(pump2_meas(i).version,'_','\_'); %make sure _ prints
    title(ftit)
    hold on; grid on
end
