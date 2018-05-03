%% calculate optimal gains
clc;clear
%gather these values from steady oscillations
Ku = 350;
Pu = 3.38;

ZNKp = [0,0,0];
ZNTi = [0,0,0];
ZNTd = [0,0,0];

% P
ZNKp(1) = 0.5 * Ku;

% PI
ZNKp(2) = 0.45 * Ku;
ZNTi(2) = Pu / 1.2;

% PID
ZNKp(3) = 1.6 * Ku;
ZNTi(3) = 0.5 * Pu;
ZNTd(3) = 0.125 * Pu;