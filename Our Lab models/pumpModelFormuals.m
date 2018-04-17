%% DEFINE

%modelling formulas from report in respect to flow and coefficients
a1 = -0.0219;
a2 = 0.04072;
a3 = 1.887;
a4 = -1.204;

b1 = -0.01448;
b2 = -0.04474;
b3 = 1.959;
b4 = -1.613;

b1 = -0.01396;
b2 = -0.04269;
b3 = 1.672;
b4 = -1.522;


head = zeros(10, 10);
power = zeros(10, 10);

%% FORMULAS
%{
head = a1 * flow^2 + a2 * flow + a3;
power = b1 * flow^3 + b2 * flow^2 + b3 * flow + b4;
%}

%% COMPUTATION
for i = 1:10
    power(i,10) = (a1 * Flow(i,11)^3) + (a2 * Flow(i,11)^2) + (a3 * Flow(i,11)) + a4;
end
for i = 1:10
    power(i,9) = (b1 * Flow(i,10)^3) + (b2 * Flow(i,10)^2) + (b3 * Flow(i,10)) + b4;
end
for i = 1:10
    power(i,8) = (b1 * Flow(i,9)^3) + (b2 * Flow(i,9)^2) + (b3 * Flow(i,9)) + b4;
end




