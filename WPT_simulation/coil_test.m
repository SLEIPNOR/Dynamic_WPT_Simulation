res = 100;
freq = linspace(1e6,20e6,res);
coil1 = PCBCoil(100e-3,0.6,3*2500e-6,2500e-6,freq,0,'square',0.01);
coil2 = PCBCoil(1/3*100e-3,0.95,800e-6,1200e-6,freq,0,'square',0.01);

figure
plot(freq/1e6,coil1.Q,'-k','LineWidth',1)

hold on
plot(freq/1e6,coil2.Q,'--r','LineWidth',1)
hold off
legend('Tx','Rx','Location','northwest')
xlabel('Frequecy (MHz)')
ylabel('Q factor')
%%
config = 'SS';
Zload = 3;
singlefreq = 10e6;

coil1 = PCBCoil(100e-3,0.25,3*2500e-6,2500e-6,singlefreq,0,'square',0.01);
coil2 = PCBCoil(1/3*100e-3,0.15,800e-6,1200e-6,singlefreq,0,'square',0.01);

C1 = coil1.C;
C2 = coil2.C;

dists = linspace(0,10e-2,50);
for a=1:50
%     [M(a),k(a)] = mutualLat(coil1,coil2,dists(a),0);
    [M(a),k(a)] = mutualLat(coil1,coil2,0.05,dists(a));
    Zrefl(a) = zrefl(config,coil2.coilZ,M(a),2*pi*singlefreq,Zload,C2);
    Zlink(a) = zlink(config,coil1.coilZ,coil2.coilZ,M(a),2*pi*singlefreq,Zload,C1,C2);
    linkgain(a) = gain(config,coil1.coilZ,coil2.coilZ,M(a),2*pi*singlefreq,Zload,C1,C2,Zlink(a));
    PTE(a) = linkeff(config,linkgain(a),Zlink(a),Zload);
end
%%

figure
%plot(dists*1e3,rad2deg(angle(linkgain)),'-k')
plot(dists*1e2,k,'-k','LineWidth',1)

% set(gca,'ytick',[])
% set(gca,'xtick',[])
% ylabel('coupling factor k')
ylabel('PTE')
xlabel('lateral distance \Delta between Tx and Rx (cm)')

%%
coil2.Rs*sqrt(1+k(1)^2*coil1.Q*coil2.Q)