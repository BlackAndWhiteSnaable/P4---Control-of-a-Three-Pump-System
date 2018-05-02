%% import data (.dat) into workspace
meas=SimulinkRealTime.utils.getFileScopeData(['PIDdata/PID' num2str(500) '.dat']);
ref = meas.data(:,23);
inp = meas.data(:,24);
err = meas.data(:,25);

dpt01 = meas.data(:,2);
lmgp1 = meas.data(:,4);
mfm01 = meas.data(:,6);
wp001 = meas.data(:,8);

dpt02 = meas.data(:,9);
lmgp2 = meas.data(:,11);
mfm02 = meas.data(:,13);
wp002 = meas.data(:,15);

dpt03 = meas.data(:,16);
lmgp3 = meas.data(:,17);
mfm03 = meas.data(:,19);
wp003 = meas.data(:,21);

time = meas.data(:,end);

figure()
hold on; grid on;
plot(time,ref)
%plot(time,inp)
plot(time,err)

%plot(time,dpt02)
%plot(time,lmgp2)
%plot(time,mfm02)
%plot(time,wp002)