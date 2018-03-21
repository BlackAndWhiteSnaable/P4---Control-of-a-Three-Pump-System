%%Setup correct file (correct valve%)
clc;clear
%file naming:
% 'P[1/2/3]_[CV01%]'
% ED4 is only working on Pump2

%gets automatically incremented if folder already exists
run_num = 0;

%valve settling time < 5 seconds
CV01t = 5;
%pumpspeeds to iterate through
WP2 = [0:10:100];
%time intervals from valve settling time, steps of 10 seconds
WPtime = [CV01t:10:100+CV01t];

simstop = numel(WPtime)*10+CV01t;

targetfile = ['E:\P2.dat'];
hostfolder = ['dataFromTarget\run_' int2str(run_num) '\'];
%make sure the folder exists
while (exist(hostfolder, 'dir') == 7)
    run_num = run_num + 1;
    hostfolder = ['dataFromTarget\run_' int2str(run_num) '\'];
end

%% select valve opening(backpressure) by for loop
for CV01 = [20:10:100]
hostfile = [hostfolder 'P2_' int2str(CV01) '.dat'];

rtwbuild('Pump2Test');   % Build and download application.

tg = SimulinkRealTime.target;

start(tg);

% Wait until the run is complete.
while strcmp(tg.Status, 'running')
  pause(0.01);
end
%% download file to host and rename

SimulinkRealTime.copyFileToHost(targetfile);
%rename file
movefile('P2.dat',hostfile);

% import into workspace
pump2=SimulinkRealTime.utils.getFileScopeData(hostfile);
end