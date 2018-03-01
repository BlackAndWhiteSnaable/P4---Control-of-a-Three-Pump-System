function [ output_args ] = matlabFunctionFromString(blck, contents)
%MATLABFUNCTIONFROMFILE Summary of this function goes here
%   Detailed explanation goes here

C = strsplit(blck,'/');

load_system(C(1));

S = sfroot;
B = S.find('Path',blck ,'-isa','Stateflow.EMChart');

%for i = 1:numel(contents);
B.Script = contents;
%end

%Anything that matches workspace variables are parameters
%children = B.getChildren();

output_args = B.Script;

%B.setChildren();

%for i = 1:numel(children);
%   if evalin('base', ['exist(''' children(i).Name ''')']) == 1
%      display(children(i).Name);
%      children(i).Scope = 'Parameter';
%   end
%end
    
save_system(C(1));
    
end

