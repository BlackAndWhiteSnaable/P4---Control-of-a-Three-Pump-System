%%
clc;clear
% OPEN THE SIMULINK FILE TO SAVE
% name of the outputfile
out = 'CLblock';

% chapter for this to appear in
chapter = '04ExperimentsAndLabWork';


%% DON'T CHANGE ANYTHING BELOW
print('-s','-dpdf',out)
crop = ['pdfcrop ' out ' ../Report/figures/' chapter '/' out '.pdf'];
system(crop);
delete([out '.pdf']);