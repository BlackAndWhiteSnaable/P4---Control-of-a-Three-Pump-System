%count number of .dat files in folder
a = dir(['*.dat']);  %find all .dat files
nfiles = numel(a);   %number of dat files
for i=1:nfiles
    movefile(a(i).name,hostfile);
end