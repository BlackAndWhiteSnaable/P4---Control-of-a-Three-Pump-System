%%
clc;clear
% OPEN THE FIGURE TO SAVE
% name of the outputfile
out = input('Name for the output file: ','s');

% chapter for this to appear in
chapter = input('Chapter name including number: ','s');
folder = ['../Report/figures/' chapter '/'];

%making sure the folder exists, to not get errors
if exist(folder,'dir')~=7
    mkdir(folder)
end

%% DON'T CHANGE ANYTHING BELOW
fileloc = [folder out];
print('-f','-depsc',fileloc)