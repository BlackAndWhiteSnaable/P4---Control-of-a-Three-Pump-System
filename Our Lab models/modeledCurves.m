%% DEFINE VARIABLES AND MATRICES
modeledFlow = zeros(10, 10);
modeledPressure = zeros(10, 10);

x1 = -0.08434;
x2 = 0.7071;
x3 = 7.826;

y1 = -0.2143;
y2 = 0.5312;
y3 = 46.99;
y4 = -35.93;

%% FORMULAS
%{
head = a0 * Speed ^ 2 + a1 * Speed * Flow + a2 * Flow ^ 2;
pressure = b0 * Speed ^ 3 + b1 * Speed ^ 2 * Flow + b2 * Speed * Flow ^ 2 + b3 * Flow ^ 3;
%}

%% BUILDING MATRICES
for i = 1:10
    for j = 1:10
        a0 = (x3 / Sped_all(j,4) ^ 2);
        a1 = (x2 / Sped_all(j,4));
        a2 = x1;
        modeledPressure(i,j) = a0 * Sped_all(i,j) ^ 2 + a1 * Flow_all(i,j) * Sped_all(i,j) + a2 * Flow_all(i,j) ^ 2;
    end
end

for i = 1:10
    for j = 1:10
        b0 = (y4 / Sped_all(j,4) ^ 3);
        b1 = (y3 / Sped_all(j,4) ^ 2);
        b2 = (y2 / Sped_all(j,4));
        b3 = y1;
        modeledPower(i,j) = b0 * Sped_all(i,j) ^ 3 + b1 * Sped_all(i,j) ^ 2 * Flow_all(i,j) + b2 * Sped_all(i,j) * Flow_all(i,j) ^ 2 + b3 * Flow_all(i,j) ^ 3;
    end
end

%% PLOTTING
figure('Name', 'Flow vs. Modeled Pressure For One Pump', 'NumberTitle', 'off');
for i = 1:10
    name = [num2str(i * 10) '% CV01'];
    plot(Flow_all(:,i), modeledPressure(:,i), 'DisplayName', name);
    hold on;
    grid on;
end
xlabel('Flow', 'Interpreter', 'latex');
ylabel('Modeled Pressure', 'Interpreter', 'latex');
legend('show');

figure('Name', 'Flow vs. Modeled Power For One Pump', 'NumberTitle', 'off');
for i = 1:10
    name = [num2str(i * 10) '% CV01'];
    plot(Flow_all(:,i), modeledPower(:,i), 'DisplayName', name);
    hold on;
    grid on;
end
xlabel('Flow', 'Interpreter', 'latex');
ylabel('Modeled Power', 'Interpreter', 'latex');
legend('show');