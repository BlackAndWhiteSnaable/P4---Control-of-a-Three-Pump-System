%%Setup correct file (correct valve%)
clc;clear
%simulink file naming:
% 'Pump[1/2/3]Test[WP%start]_[CV01%]'
% ED4 is only working on Pump2, starting from 0%WP

%select valve opening(backpressure)
CV01 = 100; %90, 80, 70, 60, 50, 40, 30, 20, 10

%pumpspeeds to iterate through
WP2 = [0:10:100]';


filename = ['Pump2Test0_' int2str(CV01)];

%%
rtwbuild('Pump2Test');   % Build and download application.

tg = SimulinkRealTime.target;

start(tg);

% Wait until the run is complete.
while strcmp(tg.Status, 'running')
  pause(0.05);
end


SimulinkRealTime.copyFileToHost(targetPath);
%DON'T FORGET LABELING
pump2=SimulinkRealTime.utils.getFileScopeData(file);