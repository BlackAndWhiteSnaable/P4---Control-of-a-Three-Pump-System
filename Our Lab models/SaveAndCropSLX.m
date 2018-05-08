%%
clc;clear
% OPEN THE SIMULINK FILE TO SAVE
% name of the outputfile
out = 'C';

% chapter for this to appear in
chapter = '04ExperimentsAndLabWork';


%% DON'T CHANGE ANYTHING BELOW
print('-s','-dpdf',out)
crop = ['pdfcrop ' out ' ../Report/figures/' chapter '/' out '_cropped' '.pdf'];
system(crop);
delete([out '.pdf']);