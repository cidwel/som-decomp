; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE2B
.include "src/rom/event_command_macros.inc"
event_319_command_CE2B:
    event_jump 255
event_319_command_CE2D:
    event_jump 783
event_319_command_CE2F:
    event_jump 787
event_319_command_CE31:
    event_end 
event_31A_command_CE32:
    event_end 
event_31B_command_CE33:
    event_end 
event_31C_command_CE34:
    event_end 
event_31D_command_CE35:
    event_end 
event_31E_command_CE36:
    event_end 
event_31F_command_CE37:
    event_end 
event_320_command_CE38:
    event_set_flag 249, 0
event_320_command_CE3B:
    event_call 816
