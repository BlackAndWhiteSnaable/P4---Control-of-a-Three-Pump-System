%%
clc
% OPEN THE FIGURE TO SAVE
user = sprintf('Please open the figure you want to save')
% name of the outputfile
out = input('Name for the output file: ','s');

% chapter for this to appear in
chapter = 'presentation'; %input('Chapter name including number: ','s');
folder = ['../Report/figures/' chapter '/'];

%making sure the folder exists, to not get errors
if exist(folder,'dir')~=7
    mkdir(folder)
end

%% DON'T CHANGE ANYTHING BELOW
fileloc = [folder out];
print('-f','-dsvg',fileloc)

%% CLEANUP
clearvars out user folder chapter fileloc