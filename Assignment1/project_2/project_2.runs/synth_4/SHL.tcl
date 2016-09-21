# 
# Synthesis run script generated by Vivado
# 

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/project_2/project_2.cache/wt [current_project]
set_property parent.project_path C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/project_2/project_2.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/ADD.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/SUB.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/MUL.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/COMP.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/MUX2x1.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/SHR.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/SHL.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/REG.v
  C:/Users/abigailfrancis/Documents/474/Assignment1/Assignment1/Circuit1.v
}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}

synth_design -top SHL -part xc7a100tcsg324-1 -generic DATAWIDTH = 32


write_checkpoint -force -noxdef SHL.dcp

catch { report_utilization -file SHL_utilization_synth.rpt -pb SHL_utilization_synth.pb }
