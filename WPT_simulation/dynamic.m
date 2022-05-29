% TxArray tracking system
function Rx_loc = dynamic(tdiff,Rx_loc,v_min,v_max)
%  randsrc(1)*
    
    v_x = (v_min(1) + (v_max(1)-v_min(1))*rand(1));

    v_y = randsrc(1)*(v_min(2) + (v_max(2)-v_min(2))*rand(1));

    Rx_loc = Rx_loc + [v_x,v_y] * tdiff;
        
       
    

   
end


