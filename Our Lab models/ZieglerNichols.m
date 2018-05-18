%% clear
clc
%% gather these values from unit step response
x1 = 1.53;
x2 = 4.15; %start and endtime of slope
y1 = 0.2123;
y2 = 1.507; %start and end value of slope

inpuT = 0.5; %unit step input time
reacT = 1.2500; %reaction time


%% 
deltax = x2-x1;
deltay = y2-y1;

R = deltax/deltay; %slope
L = reacT - inpuT; %lag from input to first reaction

%%
ZNKp = [0,0,0];
ZNTi = [0,0,0];
ZNTd = [0,0,0];

% P
ZNKp(1) = 1/ (R*L);

% PI
ZNKp(2) = 0.9/ (R*L);
ZNTi(2) = L / 0.3;

% PID
ZNKp(3) = 1.2 / (R * L);
ZNTi(3) = 2 * L;
ZNTd(3) = 0.5 * L;

clearvars -except ZN* R L