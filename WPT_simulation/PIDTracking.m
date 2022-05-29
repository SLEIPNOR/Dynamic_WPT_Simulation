function [Tx_loc] = PIDTracking(k_opt,k,p,Tx_loc)
    
    e = k_opt-k;
    d = ceil(p*abs(e));
    
    
    Tx_loc = Tx_loc+d*dir(dir_opt,:);
end