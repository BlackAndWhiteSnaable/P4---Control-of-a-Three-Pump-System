%% SETUP
clc;
%if run_num exists, all other necessary ones should exist
if exist('run_num', 'var')
    if ~exist('pump2_meas', 'var')
        ImportData2Workspace
    end
else
    ImportData2Workspace;
end
abs_max = 0; abs_min = 50; x_blank = 0;
    
%% PLOTTING
% plot all pressure curves
figure('Name',['Pressure Comparison run',num2str(run_num)],'NumberTitle','off')
for j = 1:numel(pump2_meas)
    name = [num2str(j*10) '% CV01'];
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,6),'DisplayName',name)
    %set the axis to go from absolute minimum-1% to absolute maximum+1%
    if max(pump2_meas(j).data(:,6)) > abs_max
        abs_max = max(pump2_meas(j).data(:,6));
        x_blank = abs_max * 0.01;
    end
    if min(pump2_meas(j).data(:,6)) < abs_min
        abs_min = min(pump2_meas(j).data(:,6));
    end
    axis([0 pump2_meas(1).data(end,end) abs_min-x_blank abs_max+x_blank])
    hold on; grid on
end
title('Pressure Comparison');
xlabel('Time [s]', 'Interpreter', 'latex');
ylabel('Pressure [bar]', 'Interpreter', 'latex');
legend('show','Location','northwest');
clearvars abs_max abs_min j name x_blank