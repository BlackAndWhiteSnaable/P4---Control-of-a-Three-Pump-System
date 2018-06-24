function [ Powr ] = multiPumpAvgPower( meas )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
Powr=ones(numel(meas),11);
for j=[1:numel(meas)]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        power1 = avgFromTo(i-5,i,100,meas(j).data(:,4));
        power2 = avgFromTo(i-5,i,100,meas(j).data(:,11)); %make sure those are the correct indices
        power3 = avgFromTo(i-5,i,100,meas(j).data(:,18));
        Powr(j,cntr)= power1 + power2 + power3;
    end
end

end

