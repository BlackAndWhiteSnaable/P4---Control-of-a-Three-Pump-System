%% prepare Flow for curve fitting
Flow_10 = Flow(:,2);
Flow_20 = Flow(:,3);
Flow_30 = Flow(:,4);
Flow_40 = Flow(:,5);
Flow_50 = Flow(:,6);
Flow_60 = Flow(:,7);
Flow_70 = Flow(:,8);
Flow_80 = Flow(:,9);
Flow_90 = Flow(:,10);
Flow_100 = Flow(:,11);

Flow_all = [Flow_10 Flow_20 Flow_30 Flow_40 Flow_50 Flow_60 Flow_70 Flow_80 Flow_90 Flow_100];
%% Prepare Pressure for curve fiting
Pres_10 = Pres(:,2);
Pres_20 = Pres(:,3);
Pres_30 = Pres(:,4);
Pres_40 = Pres(:,5);
Pres_50 = Pres(:,6);
Pres_60 = Pres(:,7);
Pres_70 = Pres(:,8);
Pres_80 = Pres(:,9);
Pres_90 = Pres(:,10);
Pres_100 = Pres(:,11);

Pres_all = [Pres_10 Pres_20 Pres_30 Pres_40 Pres_50 Pres_60 Pres_70 Pres_80 Pres_90 Pres_100];
%% Prepare Power for curve fitting
Powr_10 = Powr(:,2);
Powr_20 = Powr(:,3);
Powr_30 = Powr(:,4);
Powr_40 = Powr(:,5);
Powr_50 = Powr(:,6);
Powr_60 = Powr(:,7);
Powr_70 = Powr(:,8);
Powr_80 = Powr(:,9);
Powr_90 = Powr(:,10);
Powr_100 = Powr(:,11);

Powr_all = [Powr_10 Powr_20 Powr_30 Powr_40 Powr_50 Powr_60 Powr_70 Powr_80 Powr_90 Powr_100];
%% Prepare Speed for curve fitting
Speed_10 = Speed(:,2);
Speed_20 = Speed(:,3);
Speed_30 = Speed(:,4);
Speed_40 = Speed(:,5);
Speed_50 = Speed(:,6);
Speed_60 = Speed(:,7);
Speed_70 = Speed(:,8);
Speed_80 = Speed(:,9);
Speed_90 = Speed(:,10);
Speed_100 = Speed(:,11);

Speed_all = [Speed_10 Speed_20 Speed_30 Speed_40 Speed_50 Speed_60 Speed_70 Speed_80 Speed_90 Speed_100];

%%PLOTTING

figure('Name', 'Flow vs. Pressure Without Offset And Gain', 'NumberTitle', 'off')
for i = 1:10
    name = [num2str(i * 10) '%CV01'];
    plot(Flow_all(:, i), Pres_all(:, i),'DisplayName', name);
    grid on;
    hold on;
end
xlabel('Flow','Interpreter','latex');
ylabel('Pressure', 'Interpreter', 'latex');
legend('show');

figure('Name', 'Flow vs. Power Consuption Without Offset And Gain', 'NumberTitle', 'off')
for i = 1:10
    name = [num2str(i * 10) '%CV01'];
    plot(Flow_all(:, i), Powr_all(:, i),'DisplayName', name);
    grid on;
    hold on;
end
xlabel('Flow','Interpreter','latex');
ylabel('Power Consuption', 'Interpreter', 'latex');
legend('show');