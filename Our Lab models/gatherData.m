%%Setup 
clc;clear
folder_check=0;
% ED4 is only working on Pump2

%gets automatically incremented if folder already exists
run_num = 1;

%valve settling time < 5 seconds
CV01t = 5;
%pumpspeeds to iterate through
WP2 = [0:10:100];
%time intervals from valve settling time, steps of 10 seconds
WPtime = [CV01t:15:150+CV01t];

%don't let the simulation stop before all WP's are tested
simstop = WPtime(end)+(WPtime(end)-WPtime(end-1));

%make sure this fits with simulink!!
targetfile = ['E:\2P.dat'];

%% select valve opening(backpressure) by for loop
for CV01 = [10:10:100]
    rtwbuild('twoP');   % Build and download application.

    tg = SimulinkRealTime.target;

    start(tg);

    % Wait until the target is done runing the simulation.
    % in the meantime we can make sure the correct folder exists
    while strcmp(tg.Status, 'running')
        if folder_check==0

            hostfolder = ['2Pump\run_' int2str(run_num) '\'];
            %make sure the folder doesn't exist
            while (exist(hostfolder, 'dir') == 7)
                run_num = run_num + 1;
                hostfolder = ['2Pump\run_' int2str(run_num) '\'];
            end

            %create the new run_# folder
            mkdir(hostfolder);
            
            
            folder_check = 1;
        end
        %int2str(CV01) makes sure the file has the valve opening % in the name
        hostfile = [hostfolder '2P_' num2str(CV01,'%03d') '.dat'];
        pause(0.01);
    end
    %% download file to host and rename
    SimulinkRealTime.copyFileToHost(targetfile);
    %rename file
    movefile('2P.dat',hostfile);
end

%% CLEANUP
clearvars folder_check run_num CV01t WP2 WPtime simstop targetfile CV01 tg hostfolder hostfile ans