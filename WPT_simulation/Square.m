classdef Square
    %   SolWireCoil Class to contain necessary data and functions for a single layer wire solenoid coil
    %   The properties include geometric properties (diameters, fill
    %   factor, spacings etc) as well as derived/electromagnetic properties
    %   (inductance, series resistance, Q factor). These properties are
    %   generated on instantiation of the coil by the constructor.
    
    properties
        %Geometric properties
        dout;
        din;
        fillfact;
        w;
        s;
        n;
        %Derived properties
        L;
        Rs;
        Q;
        C;
        CP;
        coilZ;
        fSRF;
        %Frequency
        f;
    end
    
    methods
        %Constructor
        function coilobj = Square(p)
            %NOTE: sourceres is a minimum resistance supplied by the user,
            %that should be based on the source resistance for the Tx coil,
            %or tracks connecting to the load for the Rx coil. A typical
            %value for standard PCB traces could be something in the region
            %of 0.01 Ohms, for 1oz copper traces to and from the coil in
            %the region of 10 squares in size. For otherwise very high Q
            %coils, this can dominate the loss and should be included.
            coilobj.dout = p(1);


            coilobj.fillfact = p(3);
            coilobj.w = p(4);
            coilobj.s = p(5);
            coilobj.n = p(6);
            coilobj.L = p(7);
            coilobj.Rs = p(8);
            coilobj.Q = p(9);
            coilobj.C = p(10);
            coilobj.CP = p(11);
            coilobj.coilZ = p(12);
            coilobj.fSRF = p(13);
            coilobj.f = p(14);
           
          
        end
    end
    
end


