%% SETUP
%clc;
clearvars -except pump2_meas run_num
    
%% PLOTTING
% plot all speed curves
figure
for j = 1:numel(pump2_meas)
    name = ['test', num2str(j)];
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,5),'DisplayName',name)
    axis([0 pump2_meas(1).data(end,end) pump2_meas(1).data(1,5) pump2_meas(1).data(end,5)])
    hold on; grid on
end
title('Given Speed Comparison')
xlabel('time [s]')
ylabel('WP02(input)')
legend('show','Location','northwest')