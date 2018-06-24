%%user input
user = input('which pumps do you want to plot? [1/2/3/ 12/23/13/ 123]');

%% figure setup
figure
% find min
min_flow1 = min(min(n1pFLOW));
min_flow1 = min_flow1 - 0.5 * min_flow1;
min_pres1 = min(min(n1pPRES));
min_pres1 = min_pres1- 0.5 * min_pres1;
min_powr1 = min(min(n1pPOWR));
min_powr1= min_powr1- 0.5 * min_powr1;

min_flow2 = min(min(n2pFLOW));
min_flow2 = min_flow2 - 0.5 * min_flow2;
min_pres2 = min(min(n2pPRES));
min_pres2 = min_pres2- 0.5 * min_pres2;
min_powr2 = min(min(n2pPOWR));
min_powr2= min_powr2- 0.5 * min_powr2;

min_flow3 = min(min(n3pFLOW));
min_flow3 = min_flow3 - 0.5 * min_flow3;
min_pres3 = min(min(n3pPRES));
min_pres3 = min_pres3- 0.5 * min_pres3;
min_powr3 = min(min(n3pPOWR));
min_powr3= min_powr3- 0.5 * min_powr2;

%find max
max_flow1 = max(max(n1pFLOW));
max_flow1 = max_flow1 + 0.1 * max_flow1;
max_pres1 = max(max(n1pPRES));
max_pres1 = max_pres1 + 0.1 * max_pres1;
max_powr1 = max(max(n1pPOWR));
max_powr1 = max_powr1 + 0.1 * max_powr1;

max_flow2 = max(max(n2pFLOW));
max_flow2 = max_flow2 + 0.1 * max_flow2;
max_pres2 = max(max(n2pPRES));
max_pres2 = max_pres2 + 0.1 * max_pres2;
max_powr2 = max(max(n2pPOWR));
max_powr2 = max_powr2 + 0.1 * max_powr2;

max_flow3 = max(max(n3pFLOW));
max_flow3 = max_flow3 + 0.1 * max_flow3;
max_pres3 = max(max(n3pPRES));
max_pres3 = max_pres3 + 0.1 * max_pres3;
max_powr3 = max(max(n3pPOWR));
max_powr3 = max_powr3 + 0.1 * max_powr2;

% set axis limits according to curves
switch user
    case 1
        plot3(n1pFLOW, n1pPRES, n1pPOWR, 'or')
        hold on
        f1 = plot(n1_fittedmodel); % fit 1
        alpha(f1,.2)
        min_flow = min_flow1; max_flow = max_flow1;
        min_pres = min_pres1; max_pres = max_pres1;
        min_powr = min_powr1; max_powr = max_powr1;
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 2
        plot3(n2pFLOW, n2pPRES, n2pPOWR, 'xr') % plot 2
        hold on
        f2 = plot(n2_fittedmodel); % fit 2
        alpha(f2,.2)
        min_flow = min_flow2; max_flow = max_flow2;
        min_pres = min_pres2; max_pres = max_pres2;
        min_powr = min_powr2; max_powr = max_powr2;
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 3
        plot3(n3pFLOW, n3pPRES, n3pPOWR, 'vr') % plot 3
        hold on
        f3 = plot(n3_fittedmodel); % fit 3
        alpha(f3,.2)
        min_flow = min_flow3; max_flow = max_flow3;
        min_pres = min_pres3; max_pres = max_pres3;
        min_powr = min_powr3; max_powr = max_powr3;
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 12
        plot3(n1pFLOW, n1pPRES, n1pPOWR, 'or')
        hold on
        plot3(n2pFLOW, n2pPRES, n2pPOWR, 'xr') % plot 2
        f1 = plot(n1_fittedmodel); % fit 1
        alpha(f1,.2)
        f2 = plot(n2_fittedmodel); % fit 2
        alpha(f2,.2)
        min_flow = min(min_flow1,min_flow2); max_flow = max(max_flow1,max_flow2);
        min_pres = min(min_pres1,min_pres2); max_pres = max(max_pres1,max_pres2);
        min_powr = min(min_powr1,min_powr2); max_powr = max(max_powr1,max_powr2);
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 23
        plot3(n2pFLOW, n2pPRES, n2pPOWR, 'xr') % plot 2
        hold on
        plot3(n3pFLOW, n3pPRES, n3pPOWR, 'vr') % plot 3
        f2 = plot(n2_fittedmodel); % fit 2
        alpha(f2,.2)
        f3 = plot(n3_fittedmodel); % fit 3
        alpha(f3,.2)
        min_flow = min(min_flow3,min_flow2); max_flow = max(max_flow3,max_flow2);
        min_pres = min(min_pres3,min_pres2); max_pres = max(max_pres3,max_pres2);
        min_powr = min(min_powr3,min_powr2); max_powr = max(max_powr3,max_powr2);
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 13
        plot3(n1pFLOW, n1pPRES, n1pPOWR, 'or')
        hold on
        plot3(n3pFLOW, n3pPRES, n3pPOWR, 'vr') % plot 3
        f1 = plot(n1_fittedmodel); % fit 1
        alpha(f1,.2)
        f3 = plot(n3_fittedmodel); % fit 3
        alpha(f3,.2)
        min_flow = min(min_flow1,min_flow3); max_flow = max(max_flow1,max_flow3);
        min_pres = min(min_pres1,min_pres3); max_pres = max(max_pres1,max_pres3);
        min_powr = min(min_powr1,min_powr3); max_powr = max(max_powr1,max_powr3);
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
    case 123
        plot3(n1pFLOW, n1pPRES, n1pPOWR, 'or')
        hold on
        plot3(n2pFLOW, n2pPRES, n2pPOWR, 'xr') % plot 2
        plot3(n3pFLOW, n3pPRES, n3pPOWR, 'vr') % plot 3
        f1 = plot(n1_fittedmodel); % fit 1
        alpha(f1,.2)
        f2 = plot(n2_fittedmodel); % fit 2
        alpha(f2,.2)
        f3 = plot(n3_fittedmodel); % fit 3
        alpha(f3,.2)
        min_flow = min([min_flow1,min_flow2,min_flow3]); max_flow = max([max_flow1,max_flow2,max_flow3]);
        min_pres = min([min_pres1,min_pres2,min_pres3]); max_pres = max([max_pres1,max_pres2,max_pres3]);
        min_powr = min([min_powr1,min_powr2,min_powr3]); max_powr = max([max_powr1,max_powr2,max_powr3]);
        axis([min_flow max_flow min_pres max_pres min_powr max_powr])
end
xlabel('Flow[$\frac{m^3}{s}$]', 'Interpreter', 'latex','fontsize',18);
ylabel('Pressure[$bar$]', 'Interpreter', 'latex','fontsize',18);
zlabel('Power[$W$]', 'Interpreter', 'latex','fontsize',18);

