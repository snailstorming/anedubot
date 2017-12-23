// I use PLA and G16 Hardened Carbon Steel Bearing Balls 12mm.
// I used this series in order to check the best BallSize value.
// The BallSize value is at the bottom of every piece.

$fn =  50;

//user adjustable parameters
WallThickness = 2.25; //thickness of the retaining wall
//BallSize = 11.9;  //diameter of  your ball bearing.
BallSize = 11.6;  //diameter of  your ball bearing.
Airgap = .65;  // Gap between ball and wall
BallProtrude = .25; //percentage of ball radius sticking out 
WheelDiameter = 56;  //what size wheels you will use.


for (i=[0:4]){
    BallSize=BallSize + 0.1*i;
    TotalHeight = 23;

    translate ([i*30,0,0])
        castor(BallSize,TotalHeight,true);
}

module castor(BallSize, TotalHeight, text_bsize){
    cylrad = (BallSize/2) + WallThickness + Airgap;
    echo (cylrad);
    
    difference (){
        rotate( a = [0,0,90] ){
            difference(){ 
                cylinder(r1 = cylrad , r2 = cylrad, TotalHeight - (BallSize*BallProtrude));
    
                translate([0,0,TotalHeight - BallSize/2]) 
                    cube(size = [cylrad*2+5, cylrad/2, BallSize*1.25], center = true );
    
                translate([0,0,TotalHeight - (BallSize/2)]) 
                    sphere (BallSize/2+Airgap, $fa=5, $fs=0.1);
                
                if (text_bsize == true){
                    rotate([0,180,0])
                        translate ([0,0,-1])
                            linear_extrude(2)text(text=str(BallSize), size = 5,halign = "center", valign = "center");
                }
            }
        }
        rotate([0,0,0])
            translate ([-cylrad-1,6.5,-1])
                cube ([cylrad*2+2,10,TotalHeight+2]);
        rotate([0,0,180])
            translate ([-cylrad-1,6.5,-1])
                cube ([cylrad*2+2,10,TotalHeight+2]);
    }

}