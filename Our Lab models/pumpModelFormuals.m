%% DEFINE
%modelling formulas from report in respect to flow and coefficients
a1 = -0.0219;
a2 = 0.04042;
a3 = 1.887;
a4 = -1.204;

b1 = -0.01448;
b2 = -0.04474;
b3 = 1.959;
b4 = -1.613;

c1 = -0.01396;
c2 = -0.04269;
c3 = 1.672;
c4 = -1.522;

d1 = -0.01503;
d2 = -0.0149;
d3 = 1.28;
d4 = -1.2;

e1 = -0.02551;
e2 = 0.1022;
e3 = 0.6613;
e4 = -0.6496;

f1 = -0.02052;
f2 = 0.06226;
f3 = 0.5714;
f4 = -0.6048;

g1 = -0.007921;
g2 = -0.05997;
g3 = 0.813;
g4 = -0.9205;

h1 = -0.03462;
h2 = 0.1974;
h3 = -0.1365;
h4 = 0.04156;

k1 = -0.08058;
k2 = 0.5428;
k3 = -1.088;
k4 = 0.8301;

l1 = -0.1628;
l2 = 1.1;
l3 = -2.408;
l4 = 1.832;

simulatedHeadWithCurveFit = zeros(10, 10);
simulatedPowerWithCurveFit = zeros(10, 10);

%% FORMULAS
%{
head = a1 * flow^2 + a2 * flow + a3;
power = b1 * flow^3 + b2 * flow^2 + b3 * flow + b4;
%}

%% COMPUTATION
for i = 1:10
    simulatedPowerWithCurveFit(i,10) = (a1 * Flow(i,11)^3) + (a2 * Flow(i,11)^2) + (a3 * Flow(i,11)) + a4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,9) = (b1 * Flow(i,10)^3) + (b2 * Flow(i,10)^2) + (b3 * Flow(i,10)) + b4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,8) = (c1 * Flow(i,9)^3) + (c2 * Flow(i,9)^2) + (c3 * Flow(i,9)) + c4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,7) = (d1 * Flow(i,8)^3) + (d2 * Flow(i,8)^2) + (d3 * Flow(i,8)) + d4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,6) = (e1 * Flow(i,7)^3) + (e2 * Flow(i,7)^2) + (e3 * Flow(i,7)) + e4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,5) = (f1 * Flow(i,6)^3) + (f2 * Flow(i,6)^2) + (f3 * Flow(i,6)) + f4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,4) = (g1 * Flow(i,5)^3) + (g2 * Flow(i,5)^2) + (g3 * Flow(i,5)) + g4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,3) = (h1 * Flow(i,4)^3) + (h2 * Flow(i,4)^2) + (h3 * Flow(i,4)) + h4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,2) = (k1 * Flow(i,3)^3) + (k2 * Flow(i,3)^2) + (k3 * Flow(i,3)) + k4;
end
for i = 1:10
    simulatedPowerWithCurveFit(i,1) = (l1 * Flow(i,2)^3) + (l2 * Flow(i,2)^2) + (l3 * Flow(i,2)) + l4;
end

%% PLOTTING
figure('Name', 'Measured Power', 'NumberTitle', 'Off');
for j = 2:11
    name = [num2str(j*10-10) '% CV01'];
    plot(Powr(:,j),'DisplayName', name);
    hold on;
    grid on;
end
legend('show');

figure('Name', 'Power With Individual Formulas For Each Percentage', 'NumberTitle', 'Off');
for j = 1:10
    name = [num2str(j*10) '% CV01'];
    plot(simulatedPowerWithCurveFit(:,j),'DisplayName', name);
    hold on;
    grid on;
end
legend('show');

figure('Name', 'Power With Same Formula For Each Percentage', 'NumberTitle', 'Off');
for j = 1:10
    name = [num2str(j*10) '% CV01'];
    plot(simulatedPowerWithSurfaceFit(:,j),'DisplayName', name);
    hold on;
    grid on;
end
legend('show');
