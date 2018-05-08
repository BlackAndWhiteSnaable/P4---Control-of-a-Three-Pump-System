%% DEFINE MATRICES AND VARIABLES
modeledPressure = zeros(10,10);
modeledPower = zeros(10,10);
a2 = -0.0846;
a1 = 0.762;
a0 = 10.63;

b0 = -0.157;
b1 = -1.302;
b2 = 92.48;
b3 = -62.57;



%% BUILD MATRICES BASED ON FORMULAS 
for i = 1:10
    for j = 1:10
        a0 = a0 / Speed_all(j,i) ^ 2;
        a1 = a1 / Speed_all(j,i);
        modeledPressure(i,j) = a2 * Flow_all(i,j) ^ 2 + a1 * Flow_all(i,j) * Speed_all(j,i) + a0 * Speed_all(j,i) ^ 2;
    end
end

for i = 1:10
    for j = 1:10
        b0 = b0 / Speed_all(j,i) ^ 3;
        b1 = b1 / Speed_all(j,i) ^ 2;
        b2 = b2 / Speed_all(j,i) ^ 1;
        modeledPower(i,j) = b3 * Flow_all(i,j) ^ 3 + b2 * Flow_all(i,j) ^ 2 * Speed_all(j,i) + b1 * Flow_all(i,j) * Speed_all(j,i) ^ 2 + b0 * Speed_all(j,i) ^ 3;
    end
end

%% PLOTTING
figure('Name', 'Flow vs. Modeled Pressure', 'NumberTitle', 'off');
for i = 1:10
    name = [num2str(i * 10) '% CV01'];
    plot(Flow_all(:,i), modeledPressure(:,i), 'DisplayName', name);
    hold on;
    grid on;
end
xlabel('Flow', 'Interpreter', 'latex');
ylabel('Modeled Pressure', 'Interpreter', 'latex');
legend('show');

figure('Name', 'Flow vs. Modeled Power', 'NumberTitle', 'off');
for i = 1:10
    name = [num2str(i * 10) '% CV01'];
    plot(Flow_all(:,i), modeledPower(:,i), 'DisplayName', name);
    hold on;
    grid on;
end
xlabel('Flow', 'Interpreter', 'latex');
ylabel('Modeled Power', 'Interpreter', 'latex');
legend('show');