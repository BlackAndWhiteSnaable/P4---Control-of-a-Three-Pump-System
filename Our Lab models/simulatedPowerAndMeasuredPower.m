%%define coefficients for formula 
p00 = 0.6101;
p10 = -0.2561; 
p01 = -0.4725;  
p20 = -0.2702;  
p11 = 0.2665;  
p02 = 0.03772; 
p30 = 0.04327;  
p21 = 0.006698; 
p12 = 0.007111;

%%create empty matrix for new simulated values
simulatedPowerWithSurfaceFit = zeros(10, 10);

%%calculate new values using formula given by cftool
for i = 1:10
    for j = 2:11
        simulatedPowerWithSurfaceFit(i,j-1) = p00 + p10*Flow(i,j) + p01*Pres(i,j) + p20*Flow(i,j)^2 + p11*Flow(i,j)*Pres(i,j) + p02*Pres(i,j)^2 + p30*Flow(i,j)^3 + p21*Flow(i,j)^2*Pres(i,j) + p12*Flow(i,j)*Pres(i,j)^2;
    end;
end;

%%plot values
figure('Name', 'Simulated Power With Same formula', 'NumberTitle', 'Off')
subplot(1,2,1);
plot(simulatedPowerWithSurfaceFit);
title('Simulated Power');
subplot(1,2,2);
for i = 1:10
    plot(Powr(:,i+1));
    hold on;
end
title('Measured Power');