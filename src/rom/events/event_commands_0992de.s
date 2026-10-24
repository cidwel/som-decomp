; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $92DE
.include "src/rom/event_command_macros.inc"
event_20A_command_92DE:
    event_end 
event_20B_command_92DF:
    event_set_flag 80, 0
event_20B_command_92E2:
    event_call 1782
event_20B_command_92E4:
    event_change_map 161
event_20B_command_92E6:
    event_call 1987
event_20B_command_92E8:
    event_end 
event_20C_command_92E9:
    event_set_flag 30, 5
event_20C_command_92EC:
    event_set_flag 17, 14
event_20C_command_92EF:
    event_call 1285
event_20C_command_92F1:
    event_jump 523
event_20C_command_92F3:
    event_end 
event_20D_command_92F4:
    event_jump 523
event_20D_command_92F6:
    event_end 
event_20E_command_92F7:
    event_jump 523
event_20E_command_92F9:
    event_end 
