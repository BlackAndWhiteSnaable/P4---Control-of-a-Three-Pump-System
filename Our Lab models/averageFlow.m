clc
%if pump2_meas doesn't exist, make it
if ~exist('pump2_meas', 'var')
    plotCompareFlow;
end
%clears all unnecessary variables
clearvars abs_max abs_min cntr i j name x_blank Flow

%% gather average between two timestamps
Flow=ones(10,11);
for j=[1:10]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        Flow(j,cntr)= avgFromTo(i-5,i,100,pump2_meas(j).data(:,8));
    end
end
%% cleanup
clearvars cntr i j