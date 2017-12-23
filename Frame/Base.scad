use <castor.scad>

//Base constants
thickness=3;

//Castor constants
BallSize = 11.9;
TotalHeight = 28.7-0.1+7.4/2+1.7/2;
BallProtrude = .25;
CastorHeigh = TotalHeight - (BallSize*BallProtrude);
//END Castor constants

module only_x(){
    children();
    mirror([0,1,0])
        children();
}

module only_y(){
    children();
    mirror([1,0,0])
        children();
}
module mirror_x_y(){
    only_x(){
        children();
        mirror([1,0,0])
            children();
    }
}

//line follower and front ir support
translate([-31.9/2,50.3,0]){
    difference(){
        union(){
            translate([0,1.5,0])
                cube([31.9,7.7-3,TotalHeight-2+1.7/2]);
            translate([20,2,0])
            cube([6.8,5.7,TotalHeight-2]);
        }
        
        translate([2.7,7.7/2,30.3-10])
            cylinder($fn = 100,h=50, d=2.1);
            
        translate([-2.7+31.9,7.7/2,30.3-10])
            cylinder($fn = 100,h=50, d=2.1);

        translate([31.9/2+9,10,13])
        rotate([90,0,0])
            cylinder($fn = 100,h=15, d=2.1);
        
        translate([(31.9-20)/2-1,-1,-1])
            cube([31.9-20+5+1,7.7+2,TotalHeight]);
        translate([(31.9)/2-6,-1,-1+17])
            cube([31.9-20+5,7.7+2,TotalHeight]);
    }
}



union(){
    
    //main Y beams
    
    translate([-1.5,-93/2,0])
        cube([3,93-8,4]);

    only_y(){
        
    translate([6,-116/2,0])
        cube([3,116-8,4]);
    translate([6+6+5,-116/2,0])
        cube([3,116,4]);
        
    }

difference(){
    union(){
        //Without mirrors elements
        
        // main structure
        translate([0,0,1.25]){
            cube([116/3,116,2.5],true);
            cube([116,116/3,2.5],true);
        }
        
        //main X beams        
        translate([-30-14,-23.5-1,0])
            cube([60+28,47+2,4]);

        //Castor supports
        translate([0,-51.5,0])
            castor(BallSize,TotalHeight + thickness,false);

        translate([0,43.5,0])
            castor(BallSize,TotalHeight + thickness,false);       
        //END Without mirrors elements
    
        only_x(){
          
        }
            
        only_y(){
           // 5cm IR supports
           rotate([0,0,45]){
                translate([-31.9/2,50.3+7.3,0]){
                    difference(){
                        translate([20+2.5,2,0])
                            cube([4.8,5.7-1,16]);

                        translate([31.9/2+9,10,13])
                            rotate([90,0,0])
                            cylinder($fn = 100,h=15, d=2.2);
                    }
                }
           }

        //orange pi support
        translate([-20,-58,0])
            cube([15,3,20]);

         
        }
        
        
        mirror_x_y(){

        // main structure            
        translate([116/6,116/6,0]){
            cylinder($fn = 100,h=2.5, d=116*2/3);
        }
      
        }

    } //END union

    // Difference elements

        //Without mirrors elements
    
        //Castor holes
        translate([0,43.5,-1]){
            cylinder($fn = 20,h=40, d=3.2);
            
            translate([0,0,3])
                cylinder($fn = 20,h=40, d=5.5);
            }

            translate([0,-51.5,-1]){
                cylinder($fn = 20,h=40, d=3.2);
            translate([0,0,3])
                cylinder($fn = 20,h=40, d=5.5);
        }
        
        // line follower wires holes
        translate([-10,54,-1])
        cube([20,5,6]);
        
        //END Without mirrors elements
    
    only_x(){

       
        translate([0,30,0]){
            cube([40,15-4,7], true);
            cube([60,15/2,7], true);
        }
       
        translate([-5,116/2,-2])
            cube([10,10,TotalHeight + thickness+5]); 

    }
    only_y(){
        //Motor holes
        translate([30+7,0,0]){
            cube([14.2,20.2,10], true);    
                translate([6.95+10,0,0])
                    cube([20,35,10], true);    
        }
        //wire holes
        translate([12+8,-46-20,-1])
            cube([2,20,7]);
        
        //battery holder holes
        translate([31/2,11.5,-1]){
            cylinder($fn = 20,h=7, d=2.2);
            translate([0,1.75,0])
                cube([2.2,1.5+2.5,20], true);
            translate([0,3.5,0])
                cylinder($fn = 20,h=7, d=2.2);
        }
        
        translate([31/2,-11.5-7,-1]){
            cylinder($fn = 20,h=7, d=2.2);
            translate([0,-1.75,0])
                cube([2.2,1.5+2.5,20], true);
            translate([0,-3.5,0])
                cylinder($fn = 20,h=7, d=2.2);
        }
        
        //orange pi support holes
        rotate([90,0,0])
           translate([-16,16,50])
            cylinder($fn = 100,h=10, d=3.2);
         
    }
    mirror_x_y(){


        translate([46,30,-1])
            cube([20,2,7]);
        
        //holes near motors
        translate([51,23,-1])
            cylinder($fn = 20,h=40, d=3.2);

        // PCB support            
        rotate([0,0,45])
        translate([0,50,-1])
            cylinder($fn = 20,h=40, d=3.2);      
    
        translate([42,42,-1])
            cylinder($fn = 20,h=40, d=3.2);      
        
        //clamp servo support holes
        translate([30,116/2-13,-1])
            cylinder($fn = 20,h=40, d=3.2)
        
        //wheels frame holes
        translate([51,23,-1])
            cylinder($fn = 20,h=40, d=3.2);      
        
        //motor bracket holes
        translate([25.25,15,-1])
            cylinder($fn = 20,h=7, d=3.1);

    }

}//END difference
}