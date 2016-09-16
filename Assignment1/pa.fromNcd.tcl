
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name Assignment1 -dir "C:/Users/Brandon/Documents/School/ECE574/Assignment1/planAhead_run_1" -part xc7a100tcsg324-3
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "C:/Users/Brandon/Documents/School/ECE574/Assignment1/Circuit1.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Users/Brandon/Documents/School/ECE574/Assignment1} }
set_property target_constrs_file "Circuit1.ucf" [current_fileset -constrset]
add_files [list {Circuit1.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "C:/Users/Brandon/Documents/School/ECE574/Assignment1/Circuit1.ncd"
if {[catch {read_twx -name results_1 -file "C:/Users/Brandon/Documents/School/ECE574/Assignment1/Circuit1.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"C:/Users/Brandon/Documents/School/ECE574/Assignment1/Circuit1.twx\": $eInfo"
}
