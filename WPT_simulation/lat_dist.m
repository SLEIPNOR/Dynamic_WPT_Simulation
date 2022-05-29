function lat = lat_dist(Tx_no, Rx_loc,d)

    Tx_w = [1/2*d*(Tx_no(1)+1);1/2*d*(Tx_no(2)+1)]; % four layer
%     Tx_w = [1/2*d*(2*Tx_no(1)+1);1/2*d*(2*Tx_no(2)+1)]; % single layer

    lat = norm(Tx_w-Rx_loc);
%     Tx_w
%     Rx_loc
%     lat