% plot(out.ScopeData(:,1),out.ScopeData(:,2))
time_lowfre= out.ScopeData(:,1);
k_lowfre = out.ScopeData(:,2);
x_lowfre = out.recordout{1}.Values.Data;
y_lowfre = out.recordout{2}.Values.Data;
%%
figure
% plot(time_1layer,k_1layer,'--','LineWidth',1)
% hold on
plot(time_4layer(2101:2301),k_4layer(2101:2301),'LineWidth',1)

% plot(out.recordout{1}.Values.Data,out.recordout{2}.Values.Data,'Color',[0,0.7,0.9])

ylim([0 0.06])
xlabel('time (s)')
ylabel('coupling factor k')
% legend('single layer Tx array','4-layer Tx array')
%%
% plot(x_1layer,y_1layer,'LineWidth',1)
plot(x_4layer,y_4layer,'LineWidth',1)
grid on
xlabel('X')
ylabel('Y')

%%
config = 'SS';
Zload = 3;
singlefreq = 10e6;
M_4 = k_4layer.*sqrt(coil1.L*coil2.L);
M_1 = k_1layer.*sqrt(coil1.L*coil2.L);
C1 = coil1.C;
C2 = coil2.C;

for a=1:5001

    Zrefl(a) = zrefl(config,coil2.coilZ,M_4(a),2*pi*singlefreq,Zload,C2);
    Zlink(a) = zlink(config,coil1.coilZ,coil2.coilZ,M_4(a),2*pi*singlefreq,Zload,C1,C2);
    linkgain(a) = gain(config,coil1.coilZ,coil2.coilZ,M_4(a),2*pi*singlefreq,Zload,C1,C2,Zlink(a));
    PTE_4(a) = linkeff(config,linkgain(a),Zlink(a),Zload);
end

for a=1:5001

    Zrefl(a) = zrefl(config,coil2.coilZ,M_1(a),2*pi*singlefreq,Zload,C2);
    Zlink(a) = zlink(config,coil1.coilZ,coil2.coilZ,M_1(a),2*pi*singlefreq,Zload,C1,C2);
    linkgain(a) = gain(config,coil1.coilZ,coil2.coilZ,M_1(a),2*pi*singlefreq,Zload,C1,C2,Zlink(a));
    PTE_1(a) = linkeff(config,linkgain(a),Zlink(a),Zload);
end


%%
figure
% plot(time_1layer,PTE_1,'--','LineWidth',1)
% hold on
plot(time_4layer,PTE_4,'LineWidth',1)



ylim([0 0.4])
xlabel('time (s)')
ylabel('PTE')
% legend('single layer Tx array','4-layer Tx array')
%%
a= out.ScopeData1(:,1);
b = out.ScopeData1(:,2);
plot(a,b,'LineWidth',1)
ylim([0 0.06])
xlabel('time (s)')
ylabel('coupling factor k')
%%
plot(out.recordout{1}.Values.Data,out.recordout{2}.Values.Data,'Color',[0,0.7,0.9],'LineWidth',1)


xlabel('X')
ylabel('Y')
grid on
%%
config = 'SS';
Zload = 3;
singlefreq = 10e6;
M_imp = b.*sqrt(coil1.L*coil2.L);
C1 = coil1.C;
C2 = coil2.C;

for a=1:10001

    Zrefl(a) = zrefl(config,coil2.coilZ,M_imp(a),2*pi*singlefreq,Zload,C2);
    Zlink(a) = zlink(config,coil1.coilZ,coil2.coilZ,M_imp(a),2*pi*singlefreq,Zload,C1,C2);
    linkgain(a) = gain(config,coil1.coilZ,coil2.coilZ,M_imp(a),2*pi*singlefreq,Zload,C1,C2,Zlink(a));
    PTE_4(a) = linkeff(config,linkgain(a),Zlink(a),Zload);
end

figure
% plot(time_1layer,PTE_1,'--','LineWidth',1)
% hold on
aa =out.ScopeData(:,1);
plot(aa,PTE_4,'LineWidth',1)



ylim([0 0.4])
xlabel('time (s)')
ylabel('PTE')
