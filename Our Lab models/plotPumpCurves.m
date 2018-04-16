%% create pumpcurves
clc
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
[Curve,gof]=    FitPumpCurves(Flow,Pres);
%y = feval(Curve(1),x);

%plot flow as x, pressure as y
figure('Name',['Pump curves run_',num2str(run_num)],'NumberTitle','off')
hold on
for i=1:10
%i = 2;
    name=['WP2 ' num2str(i*10) '%'];
    plot(Flow(:,i),Pres(:,i),'DisplayName',name)
    Speeds(i,i) = [Flow(:,i),Pres(:,i)]
end

legend('show','Location','northeast')
xlabel('Flow [?]')
ylabel('Pressure [?]')

%% prepare Flow for curve fitting
Flow_10 = Flow(:,1);
Flow_20 = Flow(:,2);
Flow_30 = Flow(:,3);
Flow_40 = Flow(:,4);
Flow_50 = Flow(:,5);
Flow_60 = Flow(:,6);
Flow_70 = Flow(:,7);
Flow_80 = Flow(:,8);
Flow_90 = Flow(:,9);
Flow_100 = Flow(:,10);

%% Prepare Pressure for curve fiting
Pres_10 = Pres(:,1);
Pres_20 = Pres(:,2);
Pres_30 = Pres(:,3);
Pres_40 = Pres(:,4);
Pres_50 = Pres(:,5);
Pres_60 = Pres(:,6);
Pres_70 = Pres(:,7);
Pres_80 = Pres(:,8);
Pres_90 = Pres(:,9);
Pres_100 = Pres(:,10);

%% curve fitting for offset
p3=[2.135 2.288 2.529 2.816 3.129 3.524 4.029 4.659 5.294];
speed = 20:10:100;
