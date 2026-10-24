; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F2C2
.include "src/rom/event_command_macros.inc"
event_3F0_command_F2C2:
    event_wait 0
event_3F0_command_F2C4:
    event_return 
event_3F0_command_F2C5:
    event_end 
event_3F1_command_F2C6:
    event_end 
event_3F2_command_F2C7:
    event_end 
event_3F3_command_F2C8:
    event_end 
event_3F4_command_F2C9:
    event_end 
event_3F5_command_F2CA:
    event_end 
event_3F6_command_F2CB:
    event_end 
event_3F7_command_F2CC:
    event_end 
event_3F8_command_F2CD:
    event_end 
event_3F9_command_F2CE:
    event_end 
event_3FA_command_F2CF:
    event_end 
event_3FB_command_F2D0:
    event_end 
event_3FC_command_F2D1:
    event_end 
event_3FD_command_F2D2:
    event_end 
event_3FE_command_F2D3:
    event_end 
event_3FF_command_F2D4:
    event_jump 1277
