%% SETUP
%clc;
clearvars -except pump2_meas run_num
    
%% PLOTTING
% plot all speed curves
figure
for j = 1:numel(pump2_meas)
    name = [num2str(j*10) '% CV01']
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,3),'DisplayName',name)
    axis([0 pump2_meas(1).data(end,end) pump2_meas(1).data(1,3) pump2_meas(j).data(end,3)])
    hold on; grid on
end
title('Flow Comparison')
xlabel('time [s]')
ylabel('MFM02')
legend('show','Location','northwest')