%% calculate optimal gains
clc;clear
%gather these values from steady oscillations
R = 1.9074;
L = 0.77;


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