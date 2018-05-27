%% Notes
% Changed name
% Changed rtwbuild to 'PIDValveTest'
% Changed PIDfile output filename

%% clear

if ~exist('ZNKp', 'var')
    ZieglerNichols
end
clearvars -except ZN*
if ZNKp(1)<1
    ZNKp(1) = ZNKp(1) * 10;
end

PIDrun_num = 31;

while exist(['PIDdata/run' num2str(PIDrun_num)], 'dir')
    PIDrun_num = PIDrun_num +1;
end

mkdir(['PIDdata/run' num2str(PIDrun_num)])

clc;%clearvars -except ZNKp ZNTd ZNTi
%% SETUP workspace variables to be used in simulation
CV01 = 20;     %This will be manipulated
CV01t = 0.5;
simstop = 60*1;
name = ['PID'];

setpoint=8;
%% SIMULATE
for i=1:3
    Kp=ZNKp(i);
    Ki=ZNTi(i);
    Kd=ZNTd(i);
    Kn=1;
    %make sure this fits with simulink!!
    targetfile = ['E:\PID.dat'];

    rtwbuild('PIDtestP2');   % Build and download application.

    tg = SimulinkRealTime.target;

    start(tg);
    built_flag = 0;

    % Wait until the target is done runing the simulation.
    % in the meantime we can make sure the correct folder exists
    while strcmp(tg.Status, 'running')
        pause(0.01);
    end

    %download file to host and rename
    SimulinkRealTime.copyFileToHost(targetfile);

    PIDfile = ['PIDdata/run' num2str(PIDrun_num) '/PIDdata' name(1:i) '.dat'];
    %rename file
    movefile('PID.dat',PIDfile)
end
