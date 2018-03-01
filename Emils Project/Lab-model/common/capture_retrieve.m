%% Experiment
function capture_retrieve(talk)
global sampletime;
global cname;
global userdata;

    if nargin == 1 && talk
        msgg = 'Experiment time has elapsed, attempting to retreive data';

        disp(msgg);
        tts(msgg);
    end

    tgt = xpc;
    
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

    % Wait for scope(s) done
    while ~(strcmpi(hsc(1).Status,'finished') | strcmpi(sc.Status,'interrupted'));
    end;
 
    %Get time
    time = hsc(1).Time; 
 
    %Upload / save data
    experiment_data = hsc(1).Data;
    experiment_exc = hsc(2).Data;
    experiment_extra = hsc(3).Data;   
     
    elems_sens = evalin('base','sensors');
    actuators_list = evalin('base','actuators_list');
    actuators_ON_list = evalin('base','actuators_ON_list');

    ts_data = matrixtotimeseries(experiment_data, elems_sens, sampletime);
    ts_exc = matrixtotimeseries(experiment_exc, actuators_list, sampletime);
 
    %Save data to mat file
    path = strcat(strrep(userpath, ';', ''), '\captures\');
    savefile = strcat(path ,cname, '.mat');
 
    if ~exist(path, 'dir')
      mkdir(path);
    end
 
    exp_struct.Name = cname;
    exp_struct.Data = ts_data;
    exp_struct.Exc = ts_exc;
    exp_struct.ExtraLog = experiment_extra;
    exp_struct.Creator = getenv('USERNAME');
    exp_struct.DateTime = datestr(datetime('now'));
    exp_struct.UserData = userdata;
    
    assignin('base','exp_struct_return',exp_struct)
    save(savefile, 'exp_struct');
end

function [tscollect] = matrixtotimeseries(data, elems, sampletime)

    lenght = size(data,1)*sampletime-sampletime;

    time = 0:0.01:lenght;

    if(size(data,2)==numel(elems))
        for i = 1:numel(elems)
            tslist{i} = timeseries(data(:,i),time,1,'Name',elems(i).Name);
            tslist{i}.DataInfo.Units = elems(i).DocUnit;
        end
        tscollect = tscollection(tslist); 
    else
        tscollect = data;
    end
    
    
end