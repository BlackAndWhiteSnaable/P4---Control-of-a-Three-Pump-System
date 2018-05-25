%% SETUP
clc;
if ~exist('pump2_meas', 'var')
    ImportData2Workspace;
end
abs_max = 0; abs_min = 5; x_blank = 0;

time = pump2_meas(1).data(:,end);
    
%% PLOTTING
% plot all power curves
figure('Name',['Power Comparison run',num2str(run_num)],'NumberTitle','off','Position',[200 800 800 400])
for j = 1:numel(pump2_meas)
    name = ['$CV_1 =' num2str(j*10) '\%$'];
    if j == 1
        style = ':v';
    elseif j == numel(pump2_meas)
        style = ':^';
    else
        style = '-';
    end
    plot(time,pump2_meas(j).data(:,7),style,'MarkerIndices',1500:1500:length(time),'DisplayName',name,'markers',12)
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
xlabel('Time[$s$]', 'Interpreter', 'latex','fontsize',18);
ylabel('Power[$W$]', 'Interpreter', 'latex','fontsize',18);
leg = legend('show','Location','northwest');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);

%% cleanup
clearvars abs_max abs_min j name x_blank
