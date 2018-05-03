%% clear
clc;clearvars -except ZNKp ZNTd ZNTi
%% SETUP workspace variables to be used in simulation
CV01 = 100;
CV01t = 0.5;
simstop = 60*0.5;

setpoint=20;
%% SIMULATE
for i=1:3
    Kp=ZNKp(i);
    Ki=ZNTi(i);
    Kd=ZNTd(i);
    Kn=100;
    %make sure this fits with simulink!!
    targetfile = ['E:\PID.dat'];
    unusedfile = ['E:\unused.dat'];

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
    SimulinkRealTime.copyFileToHost(unusedfile);

    PIDfile = ['PIDdata/PID' num2str(i) '.dat'];
    unusedfile = ['PIDdata/unused' num2str(i) '.dat'];
    %rename file
    movefile('PID.dat',PIDfile);
    movefile('unused.dat',unusedfile);
end


% %% import data (.dat) into workspace
% for i=1:3
%     meas=SimulinkRealTime.utils.getFileScopeData(['PIDdata/PID' num2str(i) '.dat']);
%     ref(i) = meas.data(:,1);
%     inp(i) = meas.data(:,2);
%     err(i) = meas.data(:,3);
% 
%     dpt02(i) = meas.data(:,8);
%     lmgp2(i) = meas.data(:,9);
%     mfm02(i) = meas.data(:,10);
%     wp002(i) = meas.data(:,11);
% 
%     time(i) = meas.data(:,end);
% 
%     figure()
%     hold on; grid on;
%     plot(time(i),ref(i))
%     plot(time(i),inp(i))
%     plot(time(i),err(i))
% 
%     %plot(time(i),dpt02(i)) plot(time(i),lmgp2(i))
%     plot(time(i),mfm02(i))
%     %plot(time(i),wp002(i))
% end