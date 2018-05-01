%%clear
clc;clear
%% SETUP workspace variables to be used in simulation
CV01 = 100;
CV01t = 5;
simstop = 15;

Kp=10;
Ki=1;
Kd=0;
Kn=0;
%make sure this fits with simulink!!
targetfile = ['E:\PID.dat'];
unusedfile = ['E:\unused.dat'];

rtwbuild('PIDtestP2');   % Build and download application.

    tg = SimulinkRealTime.target;

    start(tg);

    % Wait until the target is done runing the simulation.
    % in the meantime we can make sure the correct folder exists
    while strcmp(tg.Status, 'running')
        pause(0.01);
    end
    
    %% download file to host and rename
    SimulinkRealTime.copyFileToHost(targetfile);
    SimulinkRealTime.copyFileToHost(unusedfile);
