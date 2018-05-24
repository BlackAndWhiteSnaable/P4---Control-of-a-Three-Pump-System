%% SETUP
clc;
if ~exist('pump2_meas', 'var')
    ImportData2Workspace;
end
abs_max = 0; abs_min = 5; x_blank = 0;
    
%% PLOTTING
% plot all power curves
figure('Name',['Power Comparison run',num2str(run_num)],'NumberTitle','off')
for j = 1:numel(pump2_meas)
    name = [num2str(j*10) '% CV01'];
    plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,7),'DisplayName',name)
    %set the axis to go from absolute minimum-1% to absolute maximum+1%
    if max(pump2_meas(j).data(:,7)) > abs_max
        abs_max = max(pump2_meas(j).data(:,7));
        x_blank = abs_max * 0.01;
    end
    if min(pump2_meas(j).data(:,7)) < abs_min
        abs_min = min(pump2_meas(j).data(:,7));
    end
    axis([0 pump2_meas(1).data(end,end) abs_min-x_blank abs_max+x_blank])
    hold on; grid on
end
xlabel('Time[s]', 'Interpreter', 'latex');
ylabel('Power[watt]', 'Interpreter', 'latex');
legend('show','Location','northwest');

%% cleanup
clearvars abs_max abs_min j name x_blank
