%% SETUP
%clc;
clearvars -except pump2_meas run_num
abs_max = 0; abs_min = 5; x_blank = 0;

%% PLOTTING
% plot all speed curves
figure('Name',['Input Speed Comparison run',num2str(run_num)],'NumberTitle','off')
for j = 1:numel(pump2_meas)
    name = [num2str(j*10) '% CV01'];    %what is the name of this plot?
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,1),'DisplayName',name)
    %set the axis to go from absolute minimum-1% to absolute maximum+1%
    if max(pump2_meas(j).data(:,1)) > abs_max
        abs_max = max(pump2_meas(j).data(:,1));
        x_blank = abs_max * 0.01;
    end
    if min(pump2_meas(j).data(:,1)) < abs_min
        abs_min = min(pump2_meas(j).data(:,1));
    end
    axis([0 pump2_meas(1).data(end,end) abs_min-x_blank abs_max+x_blank])
    hold on; grid on
end
title('Input Speed Comparison')
xlabel('time [s]')
ylabel('WP02(input)')
legend('show','Location','northwest')