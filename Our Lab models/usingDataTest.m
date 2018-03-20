%% NEEDS TO BE RUN INSIDE THE DATA FOLDER
% TODO implement check?
clc;clear;
%% read the data into workspace
% a file consists of a name, a number and an extension
% the name is 3 chars, the extension 4 (including the dot)
f1='C1_';
f1ext='.DAT';
f2='P1_';
f2ext=f1ext;
f3='P2_';
f3ext=f1ext;
f4='P3_';
f4ext=f1ext;
%put all filenames and extensions in arrays
files=[f1,f2,f3,f4]
fExt=[f1ext,f2ext,f3ext,f4ext]
%copy all files to host
for i = 1:numel(files)/2
    file=[files(i*3-2:i*3),int2str(i),fExt(i*4-3:i*4)]
    targetPath=['E:/',file]
    SimulinkRealTime.copyFileToHost(targetPath)
    cv1=SimulinkRealTime.utils.getFileScopeData(file);
end
