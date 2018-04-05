%% SETUP
%clc;
clearvars -except pump2_meas run_num
    
%% PLOTTING
% plot all speed curves
figure
for j = 1:numel(pump2_meas)
    name = [num2str(j*10) '% CV01']
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,4),'DisplayName',name)
    axis([0 pump2_meas(1).data(end,end) pump2_meas(1).data(1,4) pump2_meas(1).data(end,4)])
    hold on; grid on
end
title('Speed Comparison')
xlabel('time [s]')
ylabel('WP02')
legend('show','Location','northwest')