// Openscad model for a single wire XSFN connector demonstrator
// Model is a bit rough and need tuning if anything serious is required from this :-)
// Matt Whitcombe

// V1.0 - Rough idea - Aug 2019
// V2.0 - Modified to have card edge connector contacts and Meatball logo - Nov 2019

// Parameters for customizer (only latest non released version of OpenSCAD has this)
include <meatball.scad>

Separation = 15;//[0:30]
Explode_View =0; //[0:1]
Section = 10; 		//[0.0:11.0]  

Render_Plug = 0;	//[0:1] 1=show the Plug
Render_Socket =1;	//[0:1] 1=show the Socket
Render_XSFN =0;		//[0:1] 1=show the XSFN package
Render_Contact =0;  //[0:1] 1=show the spring contacts to the XSFN package
meatball =0;		//[0:1] 1=show the Microchip meatball logo
3D_Print =1;		//[0:1] 1=arrange for 3D printing

/* [Hidden] */
$fn=128; 			// set the number of segments in a circle
fiddle = 0.01; 		// fiddle amount eo ensure correct manifold geometery

// select old_style contact 
old_style = 0;

// XSFN package parameters in mm's
XSFN_Width = 3.5;
XSFN_Depth = 5.0;
XSFN_Height = 0.35;
XSFN_Contact_Pad_Width = 1.1;
XSFN_Contact_Pad_Length = 4.6;
XSFN_Contact_Gap = 0.9;

// Connector Parameters
Connector_Diameter = 15.0;
Connector_Length = 23.0;


Socket_Wall_Thickness = 3.5;
Socket_Plug_Tollerance = 0.5;
Base_Thickness = 14-7.7-fiddle;
Plug_Depth = 12.0; // amount the plug is inserted into the socket
Socket_Height = Base_Thickness+Plug_Depth;

Flat_Depth = 1.3;

// card contact parameters
card_contact_channel_width = 1.7; 
card_contact_channel_depth = 2.5;
card_contact_channel_height = 8;
card_contact_gap = 0.6;
// Tube connector Parameters
Spiggot_Diameter = 6.0;
Tube_Bore_Dia = 4.0; // size of tubing bore and hole through connector

// This generates the plug
module Round_Plug() 
{
  difference(){
      union(){
        hull(){ // add a chamfer to the front of the connector and blend to back
            translate ([0,0,0.6]) outer_plug_shape(); 
            scale([0.9,0.9,0.3]) outer_plug_shape();
            translate ([0,0,Connector_Length/2]) scale([0.4,0.4,0.25]) outer_plug_shape(); 
        }
        translate ([0,0,Connector_Length/2-0.6]) spiggot(Connector_Length/2);
      }
      union(){
          translate ([0,0,-fiddle]) cylinder (d= Tube_Bore_Dia, h=Connector_Length+(2*fiddle));     // remove the tube bore  
          translate([0,0,-fiddle]) inner_plug_shape(Spiggot_Diameter);
          XSFN_cutout();
          
          // add the microchip meatball
          if (meatball==1)
			rotate ([35,0,90]) translate ([0.2,3.9,13.8]) linear_extrude(height = 2, center = true, convexity = 10) scale ([0.12,0.12,1]) Meatball();
      }
  }
    
}

//This generates the socket
module Socket()
{
   difference(){
        cylinder (d= Connector_Diameter + Socket_Wall_Thickness + Socket_Plug_Tollerance*2, h=Socket_Height);
    
        union(){
			translate ([0,0,Base_Thickness])
            difference(){
                 scale ([1.05,1.05,2]) outer_plug_shape();
				 translate([0,0,-Socket_Plug_Tollerance])scale ([0.95,0.95,1])inner_plug_shape(Spiggot_Diameter*1.15); // scale to .95 as that looks ok
            }
			
            translate([0,0,-fiddle]) cylinder (d=Tube_Bore_Dia,h=Socket_Height+2*fiddle); // remove the bore
            
			if (old_style==1){ // old way of contact.
				translate ([0.84,0,10]) XSFN_cutout();
				translate([0,XSFN_Contact_Gap+XSFN_Contact_Pad_Width/2 - 0.5,0]) contact_channel();
				translate([0,-XSFN_Contact_Gap-XSFN_Contact_Pad_Width/2+0.5,0]) contact_channel();
        	}else{ // new card edge conector contact 
				translate([(Connector_Diameter/2)-card_contact_channel_depth/2,card_contact_gap/2,Base_Thickness]) card_edge_channel();
				translate([(Connector_Diameter/2)-card_contact_channel_depth/2,-card_contact_channel_width-card_contact_gap/2,Base_Thickness])card_edge_channel();
			
			}
		}
   }
   if (old_style==1)
   // add the bump cylinder for the contact wire
	translate([(Connector_Diameter + Socket_Wall_Thickness + Socket_Plug_Tollerance*2)/2 -1.5,(XSFN_Width+1)/2,14]) rotate([90,0,0]) cylinder(d=2,h=XSFN_Width+1);
}

module Socket_top(){
	difference(){
		Socket();
		union(){
			translate([0,0,Base_Thickness-1.1]) scale ([1.05,1.05,0.1]) outer_plug_shape();
			translate([0,0,-fiddle-1]) cylinder(d=Connector_Diameter + Socket_Wall_Thickness + Socket_Plug_Tollerance*3,h=Base_Thickness+fiddle*2);
			cylinder(d=Connector_Diameter-Flat_Depth*2,h=Connector_Length);
			translate([(Connector_Diameter/2)-card_contact_channel_depth/2,-(card_contact_gap+card_contact_channel_width*2+1.4)/2,Base_Thickness-1])cube([card_contact_channel_depth+2.15,card_contact_gap+card_contact_channel_width*2+1.4,1.05]);
		}
	}
}


module Socket_bottom(){
    union(){
	difference(){
		Socket();
		union(){
			translate([0,0,Base_Thickness-1]) difference(){
				difference(){
					cylinder(d=Connector_Diameter + Socket_Wall_Thickness + Socket_Plug_Tollerance*3,h=Connector_Length);
					cylinder(d=Connector_Diameter-Flat_Depth*2,h=Connector_Length);
				}
				translate([0,0,-fiddle]) scale ([1.03,1.03,0.09]) outer_plug_shape();
				translate([(Connector_Diameter/2)-card_contact_channel_depth/2,-(card_contact_gap+card_contact_channel_width*2+1)/2,-0.049])cube([card_contact_channel_depth+2,card_contact_gap+card_contact_channel_width*2+1,1.05]);		
			}
		}
	}
    translate([0,6,-2])
    cylinder(d=2, h=2);
    translate([0,-6,-2])
    cylinder(d=2, h=2);
    }
    
}


module card_edge_channel()
{
	translate([0,0,0]) cube([card_contact_channel_depth,card_contact_channel_width,card_contact_channel_height]); // channel for contact spring is 2.5mm x 1.7mm with a depth of 7.7mm
	translate([1.3,(card_contact_channel_width-1.5)/2,card_contact_channel_height-14.5]) cube([0.6,1.5,14]); // length of contact inside connector, PCB pin is not included
}
// Models below this are used in the construction on the Socket and Plug modules above.
module contact_channel()
{
        translate([(Connector_Diameter + Socket_Wall_Thickness + Socket_Plug_Tollerance*2)/2 -1.65,0,-1.0]) cylinder(d=1.2,h=Socket_Height);   
}

module inner_plug_shape(hole_diameter)
{
    difference(){
        translate ([0,0,0]) scale([0.7,0.7,1]) outer_plug_shape();
        cylinder (d=hole_diameter,h=Connector_Length);// leave a cylinder of material in the middle
    }    
}

module outer_plug_shape()
{
    difference(){
        cylinder (d= Connector_Diameter, h=Connector_Length/2);
        translate([Connector_Diameter/2-Flat_Depth,-Connector_Diameter/2,-fiddle])  cube([Connector_Diameter,Connector_Diameter,Connector_Length+fiddle*2]);
    }
}
module spiggot(length)
{
    cylinder (d= Spiggot_Diameter, h=length);
}

module Spring_Contact(){
	
	 color("yellow") difference(){
		union(){
			translate([0.4,1.5,10])rotate ([90,0,0])cylinder(d=4.0,h=1.5);
			cube([0.4,1.5,14]);
			translate([0.15,0.7,-3.5]) cylinder(d=0.6,h=3.5);
		}
		union(){
			translate ([0.4,1.6,10]) rotate ([90,0,0])cylinder(d=3,h=2);
			translate ([0.4,-2.5,-2.5+10]) cube([5,5,5]);
		}
	}


}
module XSFN_package(){
      
    color("DarkGrey")
        cube([XSFN_Width,XSFN_Depth,XSFN_Height],center=true);
    
    color("Yellow"){
        translate([XSFN_Contact_Gap,0,XSFN_Height/2+fiddle])
            cube([XSFN_Contact_Pad_Width,XSFN_Contact_Pad_Length,XSFN_Height/2],center=true);
        translate([-XSFN_Contact_Gap,0,XSFN_Height/2+fiddle])
            cube([XSFN_Contact_Pad_Width,XSFN_Contact_Pad_Length,XSFN_Height/2],center=true);
    }
}
module XSFN_cutout()
{
    translate([Connector_Diameter/2-Flat_Depth+fiddle,-(XSFN_Width+0.5)/2,1.3]) rotate([0,-90,0]) cube([XSFN_Depth+0.5,XSFN_Width+0.5,XSFN_Height+0.05]);
}


// rendering of the Plug and Socket modules
if(3D_Print ==0)
difference(){
    union(){
		if(Render_Plug ==1) Round_Plug();
        if(Render_XSFN ==1)translate([Connector_Diameter/2-Flat_Depth-0.20,0,1.3+XSFN_Depth/2+0.25]) rotate([90,0,90]) XSFN_package();
        if(Render_Socket ==1)translate ([0,0,Render_Plug*(-6.5-Separation)]){
		 //translate ([0,0,Render_Plug*(-6.5-Separation)]) Socket();
			Socket_bottom();
			translate([0,0,Explode_View*18])Socket_top();
		}
		if(Render_Contact ==1 && Render_Socket==1){
			translate([(Connector_Diameter/2)-(card_contact_channel_depth/2)+1.4,card_contact_gap/2+0.1,Render_Plug*(-6.5-Separation)])Spring_Contact();
			translate([(Connector_Diameter/2)-(card_contact_channel_depth/2)+1.4,-card_contact_channel_width-card_contact_gap/2+0.1,Render_Plug*(-6.5-Separation)])Spring_Contact();
		}
		
	}
    translate([-Connector_Diameter,Section,-50]) cube([50,50,100]); // have a big cube to section the connector so we can see inside
}else{ // arrange for 3D printing.

	if(Render_Socket ==1){
		Socket_bottom();
		translate ([22,0,18.29]) rotate([180,0,0]) Socket_top();
	}
	
	if(Render_Plug==1){
		translate([0,Render_Socket*22,0])
		Round_Plug();
	
	}
	
}


