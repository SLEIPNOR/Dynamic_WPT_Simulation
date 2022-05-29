function [M,k] = MI(lat,dist,Tp,Rp)

Tx = Square(Tp);
Rx = Square(Rp);
[M, k] =mutualLat(Tx,Rx,dist,lat);

end
