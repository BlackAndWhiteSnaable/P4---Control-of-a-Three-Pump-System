%% create pumpcurves
%run averageFlow &averagePressure

%plot flow as x, pressure as y
%figure('Name',['Pump curves? run_',num2str(run_num)],'NumberTitle','off')
hold on
for i=1:10
    plot(Flow(i,:),Pres(i,:))
end

flow_10=Flow(1,:)
pres_10=Pres(1,:)
surf(flow_10)