function dist = vertical_dist(Tx_no)
    x = Tx_no(1);
    y = Tx_no(2);
    d = 0.5e-3;

%     dist = d % 1 layer
    if mod(x,2)==1 && mod(y,2)==1
        dist = 4*d;
    
    elseif mod(x,2)==1 && mod(y,2)==0
        dist = 3*d;
    
    elseif mod(x,2)==0 && mod(y,2)==1
        dist = 2*d;
    
    elseif mod(x,2)==0 && mod(y,2)==0
        dist = d;
    
    end
end