function [ Powr ] = multiPumpAvgPower( meas )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
Powr=ones(10,11);
for j=[1:10]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        Powr(j,cntr)= avgFromTo(i-5,i,100,meas(j).data(:,7));
    end
end

end

