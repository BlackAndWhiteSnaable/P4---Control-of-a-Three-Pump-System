function capture_run(capturename, runtime, varargin)
global sampletime;
global cname;
global rtime;
global userdata;
global working_model;

% Input parsing
p = inputParser;
addRequired(p,'capturename',@ischar);
addRequired(p,'runtime',@isnumeric);
addParameter(p,'UserData',[]);
addParameter(p,'ModelName', 'oilrig_setup',@ischar);
parse(p, capturename, runtime, varargin{:});

working_model = p.Results.ModelName;
userdata = p.Results.UserData;
sampletime = 0.01;
cname =  p.Results.capturename;

if strfind(capturename, '/')
    C = strsplit(capturename,'/');
    working_model = C{1};
    cname = C{2};
end

rtime = p.Results.runtime;

load_system(working_model)

%Build capture model
capture_build();

%Start capture experiment
capture_start();

try
    t_old = evalin('base','timer');
    stop(t_old);
catch
    disp('No old timers');
end

t = timer('TimerFcn','capture_retrieve(true)', 'StartDelay', rtime+5);
assignin('base','timer',t);

start(t);

end

%% Compile and upload system
function [tg] = capture_build
global sampletime;
global rtime;
global working_model

tgt = xpc;

save_system(working_model,[],'OverwriteIfChangedOnDisk',true)
load_system(working_model);
save_system(working_model,[],'OverwriteIfChangedOnDisk',true)
open_system(working_model);

set_param(working_model, 'StopTime', num2str(rtime));
set_param(working_model,'RTWVerbose','off'); % Configure for a non-Verbose build.

%set_param('untitled','TLCOptions','-axpcCPUClockPoll=0')
save_system(working_model,[],'OverwriteIfChangedOnDisk',true)
rtwbuild(working_model);                     % Build and download application.

%Set sample times
tg.SampleTime = sampletime;      
tg.StopTime   = rtime;  

end

%% Sample
function capture_start()
    tgt = xpc;
    % Stop model if running
    stop(tgt);                                               

    i = 1;

    % Scope settings
    for j=1:numel(tgt.scopes)
        sc = getscope(tgt, tgt.scopes(j));
        if strcmp(sc.Type,'Host')
            hsc(i) = sc;
            stop(hsc(i));
            hsc(i).NumSamples = (1/tgt.SampleTime) * tgt.StopTime;
            i = i + 1;
        end
    end

    % Start model execution
    start(tgt);

end

%% ffff
