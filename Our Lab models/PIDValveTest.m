%% Notes
% Changed name
% Changed rtwbuild to 'PIDValveTest'
% Changed PIDfile output filename

%% clear
clc;clearvars -except ZNKp ZNTd ZNTi
%% SETUP workspace variables to be used in simulation
CV01 = 100;     %This will be manipulated by the Random Integer Generator
CV01t = 0.5;    %wait 0.5 sec?
simstop = 60*1;
name = ['PID'];

setpoint=1;
%% SIMULATE
for i=1:3
    Kp=ZNKp(i);
    Ki=ZNTi(i);
    Kd=ZNTd(i);
    Kn=0;
    %make sure this fits with simulink!!
    targetfile = ['E:\PID.dat'];

    rtwbuild('PIDValveTest');   % Build and download application.

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

    PIDfile = ['PIDdata/PIDValveTestData' name(1:i) '.dat'];
    %rename file
    movefile('PID.dat',PIDfile);
end