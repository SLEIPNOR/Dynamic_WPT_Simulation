%Script for lateral displacement case mutual inductance calculation, try
%using syms for the integration part. Again only single value dist and lat
%is supported, loop for a vector of displacements.

function [M,k] = mutualLat(coil1,coil2,dist,lat)

    %coil1 and coil2 are coil type objects, dist is the distance from edge
    %to edge between the two coils lat is lateral 
    
    %first check both coils are the same type
    if (~(strcmp(class(coil1),class(coil2))))
        printf('Error in coupling calc, non-identical coil types\n')
        return
    end
    
    mu0 = (4*pi)*1e-7;
    
switch class(coil1)
    
    case 'SolWireCoil'
    
    %determine distance from centre of coil1 turn 1 to centre of coil2 turn 1
    d121 = coil1.p*(coil1.n-1) + dist + coil1.r0 + coil2.r0;
    
    %create distance array for distances between each turn of each coil
    dists = zeros(coil1.n,coil2.n);
    
    %fill dists array
    for a=1:coil1.n
        for b=1:coil2.n
            dists(a,b) = d121 + (coil2.p*(b-1) - coil1.p*(a-1));
        end
    end
    
    %determining kconst and M here makes the assumption that the radii in
    %the coils are identical (i.e. coils are solenoids) a modified method
    %is needed for pancakes and multi-layer solenoids
    
    
    %kconst = sqrt((4*coil1.r.*coil2.r)./(((coil1.r + coil2.r).^2) + dists.^2));
    
    %syms phi x
    
    distssize = size(dists);
    Mlat = zeros(size(dists));
    
    counter = 1;
    
    for a=1:distssize(1)
        for b=1:distssize(2)
            %only need to keep track of progress if using super slow
            %symbolic method. Have replaced this with numeric ellipk and
            %ellipe implementation. Results are the same within 1e-18 in k
            %and 1e-24 in M.
            %keep track of progress as this can take a minute or two
            %printstr = sprintf('Currently processing turn combination %d of %d',counter,distssize(1)*distssize(2));
            %print string
            %fprintf('%s',printstr)
    
            beta = @(phi) atan((lat.*sin(phi))./(coil2.r + lat.*cos(phi)));
    
            blat = @(phi) sqrt(coil2.r.^2 + lat.^2 + 2.*lat.*coil2.r.*cos(phi));
    
            kconst = @(phi) sqrt((4*coil1.r.*blat(phi))./((coil1.r+blat(phi)).^2+dists(a,b).^2));
    
    
            %[K,E] = ellipke(kconst.^2);
    
            %G(x) = symfun((2/x-x)*ellipticK(x.^2)-(2/x)*ellipticE(x.^2),x);
            %G = @(x) (2./x-x).*ellipticK(x.^2)-(2./x).*ellipticE(x.^2);
            G = @(x) (2./(x)-x).*myellipk(x.^2)-(2./(x)).*myellipe(x.^2);
            
    
            %this method is super slow
            %Mlat = ((mu0*coil1.r*coil2.r)/(2*pi))*int((cos(beta)/(sqrt(coil1.r*blat)))*G(kconst),0,2*pi);
    
            %intfunc = @(phi) (cos(beta(phi))./(sqrt(coil1.r.*blat(phi)))).*(G(kconst(phi)));
            %intfunc = @(phi) (cos(atan((lat.*sin(phi))./(coil2.r + lat.*cos(phi))))./(sqrt(coil1.r.*sqrt(coil2.r.^2 + lat.^2 + 2*lat.*coil2.r.*cos(phi))))).*G(sqrt((4*coil1.r*blat(phi))./((coil1.r+blat(phi)).^2+dists(a,b).^2)));
            
            %double integral method, shouldn't need Gfunc
            
            %r12 = @(phi,theta) sqrt(coil1.r.^2 + blat(phi).^2 + dists(a,b)^2 - 2.*coil1.r.*blat(phi).*cos(theta + beta(phi)));
            
            r12 = @(phi,theta) sqrt(coil1.r^2 + coil2.r^2 + dists(a,b)^2 + lat^2 - 2*lat*coil1.r*cos(theta) + 2*lat*coil2.r*cos(phi) - 2*coil1.r*coil2.r*cos(phi - theta));
            
            
            intfunc = @(phi,theta) ((cos(phi - theta))./r12(phi,theta));

            Mlat(a,b) = ((mu0.*coil1.r.*coil2.r)./(4*pi)).*integral2(intfunc,0,2*pi,0,2*pi,'RelTol',1e-9,'AbsTol',1e-14,'method','iterated');
            %Mlat(a,b) = ((mu0*coil1.r*coil2.r)./(2*pi)).*integral(@(phi)intfunc(phi),0,2*pi,'RelTol',0,'AbsTol',1e-12);
            
            counter = counter + 1;
            
            
            %after processed, delete the line with correct number of bsps
            %{
            for c=1:length(printstr)
                fprintf('\b')
            end
            %}
        end
    end
    
    %fprintf('\nDone!\n')
    
    %M = sum(sum(mu0*sqrt(coil1.r*coil2.r).*((2./kconst -kconst).*K - (2./kconst).*E)));
    M = sum(sum(Mlat));
    k = M./sqrt(coil1.L*coil2.L);
    
    
    case  {'PCBCoil','Square'}
        
%     Similar calcs for flat pcb coils, need radius arrays instead of
%     distance array
    
    rads1 = zeros(1,coil1.n);
    rads2 = zeros(1,coil2.n);
    
%     fill radius arrays
    
    for a=1:coil1.n
     
%         rads1(a) = ((coil1.dout-coil1.w)/2)-(a-1)*(coil2.w+coil2.s);

        rads1x = ((coil1.dout-coil1.w)/2)-(a-1)*(coil2.w+coil2.s);
        rads1y = sqrt(rads1x^2+rads1x^2);
        rads1(a) = (rads1x+rads1y)/2;
    end

    for a=1:coil2.n
%         rads2(a) = ((coil2.dout-coil2.w)/2)-(a-1)*(coil2.w+coil2.s);

        rads2x = ((coil2.dout-coil2.w)/2)-(a-1)*(coil2.w+coil2.s);
        rads2y = sqrt(rads2x^2+rads2x^2);
        rads2(a) = (rads2x+rads2y)/2;
    end
        
    
    rads1size = length(rads1);
    rads2size = length(rads2);
    Mlat = zeros([rads1size,rads2size]);
    
%     counter = 1;
    
    for a=1:rads1size
        for b=1:rads2size
    
%             beta = @(phi) atan((lat.*sin(phi))./(rads2(b) + lat.*cos(phi)));
    
%             blat = @(phi) sqrt(rads2(b).^2 + lat.^2 + 2.*lat.*rads2(b).*cos(phi));
    
%             kconst = @(phi) sqrt((4*rads1(a).*blat(phi))./((rads1(a)+blat(phi)).^2 + dist.^2));
            
            r12 = @(phi,theta) sqrt(rads1(a)^2 + rads2(b)^2 + dist^2 + lat^2 - 2*lat*rads1(a)*cos(theta) + 2*lat*rads2(b)*cos(phi) - 2*rads1(a)*rads2(b)*cos(phi - theta));
            
            intfunc = @(phi,theta) ((cos(phi - theta))./r12(phi,theta));

            Mlat(a,b) = ((mu0.*rads1(a).*rads2(b))./(4*pi)).*integral2(intfunc,0,2*pi,0,2*pi,'RelTol',1e-9,'AbsTol',1e-14,'method','iterated');
           
            
%             counter = counter + 1;
            
        end
    end
    
    %fprintf('\nDone!\n')
    
    M = sum(sum(Mlat));
    k = M./sqrt(coil1.L*coil2.L);

    if M < 0

        M=0;
        
    end
    
    
    otherwise
        fprintf('unknown coil type, please check your input\n')
end    
  
function elleout = myellipe(M)
    [~,E] = ellipke(M);
    elleout = E;
end

function ellkout = myellipk(M)
    [K,~] = ellipke(M);
    ellkout = K;
end

end