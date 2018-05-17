% plot all curves at cv=60
j = 7;

%% offset and gain all relevant curves
% flow
offset_q = ones(numel(pump2_meas(j).data(:,8)),1)*1.8810;
flow = pump2_meas(j).data(:,8);
flow = flow-offset_q;
flow = flow * 2.6691;

% head
offset_h = ones(numel(pump2_meas(j).data(:,8)),1)*2.8343;
head = pump2_meas(j).data(:,6);
head = head - offset_h;
head = head * 5;     %we don't know the gain

%% create figure
figure('Name',['Flow,Pressure,Power comparison; CV01=',num2str(j)],'NumberTitle','off')
title(['Stair Response with $CV_1 = ' num2str(j*10) '\%$'],'Interpreter','latex')
hold on; grid on

%% plot Flow
name_flow = 'Q [$\frac{m^3}{s}$]';
plot(pump2_meas(j).data(:,end),flow,'DisplayName',name_flow)

%% plot Pressure
name_pres = 'H [$m$]';
plot(pump2_meas(j).data(:,end),head,'DisplayName',name_pres)

%% plot Power
name_powr = 'P [$W$]';
plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,7),'DisplayName',name_powr)

%% plot input speed
name = '$\omega P_{2in}$ [$\frac{\%}{10}$]';
plot(pump2_meas(j).data(:,end),pump2_meas(j).data(:,1)/10,'DisplayName',name)


%% build legend
leg = legend('Location','southeast');
set(leg,'Interpreter','latex');
set(leg,'FontSize',12);