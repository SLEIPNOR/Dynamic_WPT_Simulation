function Tx_no = Tx_update(k_c,gain,Tx_no)
dir = [0,0; -1,-1; -1,0; 0,-1; 1,1; 1,0; 0,1; 1,-1; -1,1];
[~, index] = min(k_c);
dir_opt = dir(index,:);
Tx_no = Tx_no+ dir_opt*gain;

end