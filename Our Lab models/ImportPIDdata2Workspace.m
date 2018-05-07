%% import data (.dat) into workspace
meas=SimulinkRealTime.utils.getFileScopeData(['PIDdata/GainPI.dat']);
cv01  = meas.data(:, 1);

dpt01 = meas.data(:, 2);
lmgc1 = meas.data(:, 3);
lmgp1 = meas.data(:, 4);
lmgv1 = meas.data(:, 5);
mfm01 = meas.data(:, 6);
pt01  = meas.data(:, 7);
wp01  = meas.data(:, 8);

dpt02 = meas.data(:, 9);
lmgc2 = meas.data(:,10);
lmgp2 = meas.data(:,11);
lmgv2 = meas.data(:,12);
mfm02 = meas.data(:,13);
pt02  = meas.data(:,14);
wp02  = meas.data(:,15);

dpt03 = meas.data(:,16);
lmgc3 = meas.data(:,17);
lmgp3 = meas.data(:,18);
lmgv3 = meas.data(:,19);
mfm03 = meas.data(:,20);
pt03  = meas.data(:,21);
wp03  = meas.data(:,22);

ref   = meas.data(:,23);
input = meas.data(:,24);
error = meas.data(:,25);
time  = meas.data(:,26);


% figure()
% xlabel('Time [$s$]','Interpreter','latex');
% ylabel('Q [$\frac{m^{3}}{s}$]','Interpreter','latex');
% title('Results of PI-control','Interpreter','latex')
% set(gca,'fontsize',16);
hold on; grid on;
plot(time,ref,'DisplayName','ref')
plot(time,input,'DisplayName','$\omega$')
%plot(time,error./10,'DisplayName','err')

%plot(time,dpt02)
plot(time,lmgp3,'DisplayName','lmgp')
plot(time,mfm03,'DisplayName','Q')
%plot(time,wp002,'DisplayName','wp002')
leg = legend('Location','southeast');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);
