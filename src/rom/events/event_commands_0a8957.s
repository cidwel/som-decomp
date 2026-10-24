; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8957
.include "src/rom/event_command_macros.inc"
event_658_command_8957:
    event_screen 1
event_658_command_8959:
    event_warp 255
event_658_command_895B:
    event_end 
event_659_command_895C:
    event_end 
event_65A_command_895D:
    event_end 
event_65B_command_895E:
    event_end 
event_65C_command_895F:
    event_end 
event_65D_command_8960:
    event_end 
event_65E_command_8961:
    event_end 
event_65F_command_8962:
    event_freeze 
event_65F_command_8963:
    event_gather 
event_65F_command_8964:
    event_screen 8
