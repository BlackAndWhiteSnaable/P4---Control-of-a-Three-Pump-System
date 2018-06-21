%count number of .dat files in folder
a = dir(['*.dat']);  %find all .dat files
nfiles = numel(a);   %number of dat files
for i=1:nfiles
    old_name = a(i).name;
    new_name = char(strcat('2',extractAfter(old_name,'3')));
    movefile(old_name,new_name);
end