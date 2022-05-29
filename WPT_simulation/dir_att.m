function Tx_no_att = dir_att(Tx_no,t,gain)

    dir = [-1,-1; -1,0; 0,-1; 1,1; 1,0; 0,1; 1,-1; -1,1; 0,0];


    Tx_no_att = gain*dir(t,:)+Tx_no;
    
    
%     k_c(t) = abs(k_opt-k);

    

end