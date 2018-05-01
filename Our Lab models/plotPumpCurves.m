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
axis([1.5 7 2.5 7.5])
xlabel('Flow [?]')
ylabel('Pressure [?]')
hold on
for i=2:11
    if mod(i,2)
        style = 'xk';
    else
        style = 'or';
    end
    name=['WP2 ' num2str(i*10 - 10) '%'];
    plot(Flow(:,i),Pres(:,i),style,'DisplayName',name)
end
legend('show','Location','northeast')

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
%% curve fitting for offset parameter
p1=ones(1,10);
p2=ones(1,10);
p3=ones(1,10);

speed = 10:10:100;
%% curve fitting?
for i=[1:10]
%i=2;
    pc = fit(Flow_all(:,i), Pres_all(:,i), 'poly2');
    %plot(pc)
    p1(i) = pc.p1;
    p2(i) = pc.p2;
    p3(i) = pc.p3;
end
%create a model for p1(the first coefficient) data looks fairly linear
p1_model = fit(speed.',p1.','poly1');
a1=p1_model.p1;
b1=p1_model.p2;

%create a model for p2(the second coefficient) data looks fairly linear
p2_model = fit(speed.',p2.','poly1');
a2=p2_model.p1;
b2=p2_model.p2;

%create a model for p3(the third coefficient) data looks fairly quadratic
p3_model = fit(speed.',p3.','poly2');
a3=p3_model.p1;
b3=p3_model.p2;
c3=p3_model.p3;

Q=[0:0.001:8.5];
%figure
%hold on;
for w = speed
    WP2_10 = (a1*w+b1)*Q.^2 + (a2*w+b2)*Q + (a3*w.^2+b3*w+c3);
    plot(Q,WP2_10)
end

x = 1:0.001:7;
for i=[1:10]
    if mod(i,2)
        style = 'r';
    else
        style = 'k';
    end
    func = p1_model * x.^2 + p2_mean * x + p3(i);
    plot(x,func,style)
end