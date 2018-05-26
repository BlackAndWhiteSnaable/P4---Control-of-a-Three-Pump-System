%% check if everything exists
clc;clear
if ~(exist('ZNKp','var'))
    clear
    ZieglerNichols %US if using ultimate sensitivity
end

PIDrun_num = input('PIDrun_num?');
%TYPE = input('P(1), PI(2) or PID(3)?');
text = 'PID';

for TYPE=1:3
if TYPE == 1
    file = ['PIDdata/run' num2str(PIDrun_num) '/PIDdataP.dat'];
elseif TYPE == 2
    file = ['PIDdata/run' num2str(PIDrun_num) '/PIDdataPI.dat'];
else
    file = ['PIDdata/run' num2str(PIDrun_num) '/PIDdataPID.dat'];
end

%% import data (.dat) into workspace
meas=SimulinkRealTime.utils.getFileScopeData(file);
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


%% figure
figure('Position',[400*TYPE-350 0 800 400])
ax=gca;
title(text(1:TYPE),'Interpreter','latex')
axis([0 30 -5 20])
xlabel('Time [$s$]','Interpreter','latex');
ylabel('Q [$\frac{m^3}{s}$]','Interpreter','latex');
yyaxis right
plot(time,input,':>k','MarkerIndices',100:500:length(time),'DisplayName','$\omega P_{in}$','markers',12)
ylabel('$\omega$P [$\%$]','Interpreter','latex');
axis([0 30 -7.5 30])
ax.YColor = 'k';
yyaxis left
ax.YColor = 'k';

set(gca,'fontsize',16);
hold on; grid on;

plot(time,ref,'-or','MarkerIndices',100:500:length(time),'DisplayName','$Q_{ref}$','markers',12)
plot(time,mfm01+mfm02+mfm03,':^k','MarkerIndices',100:500:length(time),'DisplayName','$Q_{tot}$','markers',12)
%plot(time,error./10,':xk','MarkerIndices',100:500:length(time),'DisplayName','$Q_{error}$','markers',12)

%plot(time,dpt02,'DisplayName','dpt')
%plot(time,lmgp2,'DisplayName','lmgp')

%plot(time,wp002,'DisplayName','wp002')
leg = legend('Location','southeast');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);
end

stop()
%% only for step response
A = mean(mfm03(20*100:end));
A_plot = ones(numel(time),1)*A;
plot(time,A_plot,'-or','MarkerIndices',250:500:length(time),'DisplayName','Final Value')
plot(time,(time/R)-(1/R),'-^r','MarkerIndices',1:50:length(time),'DisplayName','Slope')

ax=gca;
yyaxis right
plot(time,ref*10,'-k','MarkerIndices',1:50:length(time),'DisplayName','step input')

ylabel('$\omega$P [$\%$]','Interpreter','latex');
axis([0 20 -1 25])
ax.YColor = 'k';

leg = legend('Location','southeast');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);