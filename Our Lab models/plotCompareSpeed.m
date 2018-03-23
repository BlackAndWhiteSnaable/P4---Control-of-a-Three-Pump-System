%% SETUP
clearvars -except pump2_meas run_num

%%

    if plt_crv(4)
        %% plot all speed curves
        %figure('Name', 'Speed comparison' ,'NumberTitle','off')
        for j = 1:numel(pump2_meas)
            subplot(ceil(numel(pump2_meas)/2),2,j)
            %    time as x axis           ,forth set of data is speed
            plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,4))
            axis([0 pump2_meas(1).data(end,end) 0 7])
            ftit=strrep(pump2_meas(j).version,'_','\_'); %make sure _ prints
            title(ftit)
            hold on; grid on
        end
    end