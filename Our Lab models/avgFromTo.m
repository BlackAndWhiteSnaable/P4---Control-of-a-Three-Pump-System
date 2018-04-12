function [ avg ] = avgFromTo( t0, t1, fs, data )
%avgFromTo Outputs the average of a specific range on given data
%   t0 is the starting time; t1 the stop time; fs the sampling frequency
%   data is the data in vector format
data = data(t0*fs:t1*fs);
avg = mean(data);
end
