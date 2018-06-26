% name of the outputfile
folder = ['../Report/figures/presentation/'];

view(3); %firstView
out = [num2str(user) 'PointsFit' ];
fileloc = [folder out];
print('-f','-dsvg',fileloc)

% view([ 0 0]); %FlowPower
% out = [num2str(user) 'FlowPower' ];
% fileloc = [folder out];
% print('-f','-dsvg',fileloc)
% 
% view([90 0]); %PressurePower
% out = [num2str(user) 'PressurePower' ];
% fileloc = [folder out];
% print('-f','-dsvg',fileloc)
% 
% view([0 90]); %FlowPressure
% out = [num2str(user) 'FlowPressure' ];
% fileloc = [folder out];
% print('-f','-dsvg',fileloc)


%% CLEANUP
clearvars out user folder chapter fileloc