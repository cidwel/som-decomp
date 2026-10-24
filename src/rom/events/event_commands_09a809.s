; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A809
.include "src/rom/event_command_macros.inc"
event_279_command_A809:
    event_jump 1535
event_279_command_A80B:
    event_end 
event_27A_command_A80C:
    event_end 
event_27B_command_A80D:
    event_end 
event_27C_command_A80E:
    event_increment_flag 36
event_27C_command_A810:
    event_refresh_objects 
event_27C_command_A811:
    event_call 1944
