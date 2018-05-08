%%
clc;clear
% OPEN THE SIMULINK FILE TO SAVE
% name of the outputfile
out = 'StepresponseTest';

% chapter for this to appear in
chapter = '04ExperimentsAndLabWork';


%% DON'T CHANGE ANYTHING BELOW
fileloc = ['../Report/figures/' chapter '/' out];
print('-f','-deps',fileloc)