%% SETUP
%clc;
clearvars -except pump2_meas run_num

    
%% PLOTTING
% plot all power curves
figure('Name',['Power Comparison run',num2str(run_num)],'NumberTitle','off')
for j = 1:numel(pump2_meas)
    %subplot(ceil(numel(pump2_meas)/2),2,j)
    ftit=pump2_meas(j).version; %make sure _ prints
    name = [num2str(j*10) '% CV01']
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,2),'DisplayName',name)
    %plot(1:5,1:5,'DisplayName',ftit)
    axis([0 pump2_meas(1).data(end,end) 0 7])
    hold on; grid on
end
legend('show','Location','northwest')