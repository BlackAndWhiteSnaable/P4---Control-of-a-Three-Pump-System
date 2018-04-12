%% SETUP
clc;
%if run_num exists, all other necessary ones should exist
if exist('run_num', 'var')
    clearvars -except pump2_meas run_num Pres Flow
else
    ImportData2Workspace;
    clearvars -except pump2_meas run_num Pres Flow
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
title('Pressure Comparison')
xlabel('time [s]')
ylabel('DPT02')
legend('show','Location','northwest')