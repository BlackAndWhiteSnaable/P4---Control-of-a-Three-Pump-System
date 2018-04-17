%% create pumpcurves
clc
run_num = 11;
%run averageFlow &averagePressure &averagePower if needed
if ~exist('Pres', 'var')
    averagePressure;
end

if ~exist('Flow', 'var')
    averageFlow;
end

if ~exist('Powr', 'var')
    averagePower;
end
%y = feval(Curve(1),x);

%plot flow as x, pressure as y
figure('Name',['Pump curves run_',num2str(run_num)],'NumberTitle','off')
hold on
for i=2:11
%i = 2;
    name=['WP2 ' num2str(i*10 - 10) '%'];
    stem(Flow(:,i),Pres(:,i),'DisplayName',name)
end

legend('show','Location','northeast')
xlabel('Flow [?]')
ylabel('Pressure [?]')

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

%% curve fitting for offset
p3=[2.135 2.288 2.529 2.816 3.129 3.524 4.029 4.659 5.294];
speed = 20:10:100;
