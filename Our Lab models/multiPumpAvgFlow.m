function [ Flow ] = multiPumpAvgFlow( meas )
%multiPumpAvgFlow gives the steady state average flows
%   Detailed explanation goes here
Flow=ones(10,11);
for j=[1:10]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        Flow(j,cntr)= avgFromTo(i-5,i,100,meas(j).data(:,8));
    end
end

end