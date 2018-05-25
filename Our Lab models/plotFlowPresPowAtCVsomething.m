%% make sure all variables exist
% chose run_num to import
run_num = 32;

if ~exist('pump2_meas','var')
    ImportData2Workspace
end

% plot all curves at cv=70
j = 6;

%% label all variables
% time
time = pump2_meas(j).data(:,end);

% flow
flow = pump2_meas(j).data(:,8);

% head
head = pump2_meas(j).data(:,6);

% power
power = pump2_meas(j).data(:,7);

% input speed
speed = pump2_meas(j).data(:,1);

%% create figure
figure('Name',['Flow,Pressure,Power comparison; CV01=',num2str(j)],'NumberTitle','off','Position',[5 50 800 400])
%title(['Stair Response with $CV_1 = ' num2str(j*10) '\%$'],'Interpreter','latex')
hold on; grid on

%% plot Flow
fstyle = '-v';
name_flow = 'Q [$\frac{m^3}{s}$]';
plot(time,flow,fstyle,'MarkerIndices',1500:1500:length(time),'DisplayName',name_flow)

%% plot Pressure
hstyle = '-.x';
name_pres = 'H [$bar$]';
plot(time,head,hstyle,'MarkerIndices',1500:1500:length(time),'DisplayName',name_pres)

%% plot Power
pstyle = '-o';
name_powr = 'P [$kW$]';
plot(time,power/1000,pstyle,'MarkerIndices',1500:1500:length(time),'DisplayName',name_powr)

%% plot input speed
sstyle = '-^';
name = '$\omega P_{2in}$ [$10\%$]';
plot(time,speed/10,sstyle,'MarkerIndices',1500:1500:length(time),'DisplayName',name)

%% set axis
axis([0 170 -0.5 11])

%% label axis
xlabel('Time [$s$]','fontsize',18,'Interpreter','latex')
ylabel('y [$units$]','fontsize',18,'Interpreter','latex')

%% build legend
leg = legend('Location','northwest');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);