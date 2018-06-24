function [ Flow ] = multiPumpAvgFlow( meas )
%multiPumpAvgFlow gives the steady state average flows
%   Detailed explanation goes here
Flow=ones(numel(meas),11);
for j=[1:numel(meas)]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        flow1 = avgFromTo(i-5,i,100,meas(j).data(:,6));
        flow2 = avgFromTo(i-5,i,100,meas(j).data(:,13));
        flow3 = avgFromTo(i-5,i,100,meas(j).data(:,20));
        % add the flows of all three pumps together
        Flow(j,cntr)= flow1 + flow2 + flow3;
    end
end

end