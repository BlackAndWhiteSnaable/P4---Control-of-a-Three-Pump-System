%%Setup correct file (correct valve%)
clc;clear
%simulink file naming:
% 'P[1/2/3]_[CV01%]'
% ED4 is only working on Pump2

%select valve opening(backpressure)
for CV01 = [20:10:100]

%valve settling time < 5 seconds
CV01t = 5;
%pumpspeeds to iterate through
WP2 = [0:10:100];
%time intervals from valve settling time, steps of 10 seconds
WPtime = [CV01t:10:100+CV01t];

targetfile = ['E:\P2.dat'];
hostfile =  ['dataFromTarget\run_3\P2_' int2str(CV01) '.dat'];


%%
rtwbuild('Pump2Test');   % Build and download application.

tg = SimulinkRealTime.target;

start(tg);

% Wait until the run is complete.
while strcmp(tg.Status, 'running')
  pause(0.05);
end
%% download file to host and rename

SimulinkRealTime.copyFileToHost(targetfile);
%rename file
movefile('P2.dat',hostfile);
%DON'T FORGET LABELING
pump2=SimulinkRealTime.utils.getFileScopeData(hostfile);
end