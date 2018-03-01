load('data4')
value_P = exp_struct.Data.LMGP1.Data +exp_struct.Data.LMGP2.Data + exp_struct.Data.LMGP3.Data;
value_RPM = exp_struct.Data.WP01.Data;
value_H = exp_struct.Data.DPT01.Data * 10;
value_Q = ((exp_struct.Data.MFM01.Data + exp_struct.Data.MFM02.Data + exp_struct.Data.MFM03.Data) * 60 * 60)/1000;
value_CV = exp_struct.Exc.CV01.Data;
value_CV_DPT = exp_struct.Data.PT02.Data-exp_struct.Data.PT03.Data;


steps = (length(value_P)-1)/(100*30);
steadyVec = [];
for i = 0:1:steps
    steadyVec = [steadyVec [(20+30*i)*100:1:( 28 + 30*i)*100].'];
end
steadyVec = steadyVec(:,2:end);
mean_Q = mean(value_Q(steadyVec));
mean_P = mean(value_P(steadyVec));
mean_H = mean(value_H(steadyVec));
mean_RPM = mean(value_RPM(steadyVec));
mean_CV = mean(value_CV(steadyVec));
mean_CV_DPT = mean(value_CV_DPT(steadyVec));
figure(105)
hold on;
plot3(mean_H,mean_Q,mean_P,'k*');
hold off;
figure(402)
plot(value_Q(steadyVec))