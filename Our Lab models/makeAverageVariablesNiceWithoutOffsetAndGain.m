%% prepare Flow for curve fitting
if ~exist('Flow_all','var')
    averageFlow;
end

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
if ~exist('Pres_all','var')
    averagePressure;
end

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
if ~exist('Powr_all','var')
    averagePower;
end

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
if ~exist('Sped_all','var')
    averageSpeed;
end

Sped_10 = Sped(:,2);
Sped_10 = Sped_10 * 720;
Sped_20 = Sped(:,3);
Sped_20 = Sped_20 * 720;
Sped_30 = Sped(:,4);
Sped_30 = Sped_30 * 720;
Sped_40 = Sped(:,5);
Sped_40 = Sped_40 * 720;
Sped_50 = Sped(:,6);
Sped_50 = Sped_50 * 720;
Sped_60 = Sped(:,7);
Sped_60 = Sped_60 * 720;
Sped_70 = Sped(:,8);
Sped_70 = Sped_70 * 720;
Sped_80 = Sped(:,9);
Sped_80 = Sped_80 * 720;
Sped_90 = Sped(:,10);
Sped_90 = Sped_90 * 720;
Sped_100 = Sped(:,11);
Sped_100 = Sped_100 * 720;

Sped_all = [Sped_10 Sped_20 Sped_30 Sped_40 Sped_50 Sped_60 Sped_70 Sped_80 Sped_90 Sped_100];

%% PLOTTING
%{
figure('Name', 'Flow vs. Pressure Without Offset And Gain', 'NumberTitle', 'off', 'Position', [100 100 800 400])
for i = 1:10
    name = [num2str(i * 10) '\%CV01'];
    plot(Flow_all(:, i), Pres_all(:, i),'DisplayName', name);
    grid on;
    hold on;
end
xlabel('Flow $[\frac{m^3}{h}]$','Interpreter','latex', 'fontsize', 18);
ylabel('Pressure [bar]', 'Interpreter', 'latex', 'fontsize', 18);
leg = legend('show','Location','northeast'); 
set(leg,'Interpreter','latex'); 
set(leg,'FontSize',9); 
%}

figure('Name', 'Flow vs. Power Consuption Without Offset And Gain', 'NumberTitle', 'off', 'Position', [400 100 800 400])
for i = 1:10
    name = [num2str(i * 10) '\%CV01'];
    plot(Flow_all(:, i), Powr_all(:, i),'DisplayName', name);
    grid on;
    hold on;
end
xlabel('Flow $[\frac{m^3}{h}]$','Interpreter','latex', 'fontsize', 18);
ylabel('Power Consuption [W]', 'Interpreter', 'latex', 'fontsize', 18);
leg2 = legend('show', 'Location', 'southeast');
set(leg2, 'Interpreter', 'latex');
set(leg2, 'FontSize', 9);

%% CLEANUP
clearvars i
