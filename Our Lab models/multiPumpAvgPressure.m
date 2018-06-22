function [ Pres ] = multiPumpAvgPressure( meas )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
Pres=ones(10,11);
for j=[1:10]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        Pres(j,cntr)= avgFromTo(i-5,i,100,meas(j).data(:,6));
    end
end

end

