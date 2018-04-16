%% SETUP
clc
x = [0:0.001:7];
%% WP2 10%
%% WP2 20%
%% WP2 30%
%% WP2 40%
%% WP2 50%
%% WP2 60%
%% WP2 70%
%% WP2 80%


%% WP2 90%
%Coefficients (with 95% confidence bounds):
p1 =     -0.1949;%  (-0.2009, -0.1889)
p2 =      0.9503;%  (0.8948, 1.006)
p3 =       5.294;%  (5.174, 5.415)
%Linear model Poly2:
f9 = p1*x.^2 + p2*x + p3;

plot(x,f9,'--')

%% WP2 100%