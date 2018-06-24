function [ Pres ] = multiPumpAvgPressure( meas )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
Pres=ones(numel(meas),11);
for j=[1:numel(meas)]
    cntr = 0;
    for i=[20:15:170]
        %too lazy to change the values of the loop
        cntr = cntr + 1;
        pres1 = avgFromTo(i-5,i,100,meas(j).data(:,2));
        pres2 = avgFromTo(i-5,i,100,meas(j).data(:,9));
        pres3 = avgFromTo(i-5,i,100,meas(j).data(:,16));
        Pres(j,cntr)= max([pres1,pres2,pres3]);
    end
end

end

