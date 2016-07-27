
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name serial_switch -dir "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/working_dir/planAhead_run_2" -part xc6slx9tqg144-2
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/working_dir/top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/working_dir} }
set_property target_constrs_file "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/mojo_constraints.ucf" [current_fileset -constrset]
add_files [list {D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/mojo_constraints.ucf}] -fileset [get_property constrset [current_run]]
link_design
