difference(){
    union(){
        cube([14,66,5], center = true);
        translate ([0,14,-2.5])
            cylinder(h=5+14+1, d= 9, $fn=100);
    }
    
    rotate([0,90,0])
    translate([0,30,-8])
        cylinder(d=3.2, h = 16, $fn=100);
    
    mirror([0,1,0])
        rotate([0,90,0])
        translate([0,30,-8])
            cylinder(d=3.2, h = 16, $fn=100);
    
    translate([(-14+11.7)/2-.5,-23/2+2+0.5,0])
    cube([11.7+1,23,7], true);

    translate([0,19.5-14,-3.5])
    cylinder(h=7, d= 3.2, $fn=100);
    
    translate([0,-9.5-14,-3.5])
    cylinder(h=7, d= 3.2, $fn=100);
    
    translate ([0,14,-2.5-1])
        cylinder(h=5+14+2+1, d= 2.9, $fn=100);
}

